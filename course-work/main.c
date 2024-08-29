#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <unistd.h>

#include "roots.h"
#include "integrals.h"
#include "functions.h"

const float DEFAULT_EPS = 0.001;          // Дефолтное значение eps1 и eps2
const float DEFAULT_LOWER_BOUND = 0.8;    // Дефолтное значение нижней границы интервала для поиска корня
const float DEFAULT_HIGHER_BOUND = 100.0; // Дефолтное значение верхней границы интервала для поиска корня

// Парсинг аргументов командной строки
int get_args(int argc, char *argv[], float *eps1, float *eps2, float *min, float *max, bool *print_roots, bool *print_iter, bool *test)
{
    struct option long_options[] =
        {
            {"help", no_argument, 0, 'h'},
            {"min", required_argument, 0, 0},
            {"max", required_argument, 0, 1},
            {"eps1", required_argument, 0, 2},
            {"eps2", required_argument, 0, 3},
            {"roots", no_argument, 0, 'r'},
            {"iterations", no_argument, 0, 'i'},
            {"test", no_argument, 0, 't'}};

    /* getopt_long stores the option index here. */
    int option_index = 0;
    int c;
    while ((c = getopt_long(argc, argv, "he:rit",
                            long_options, &option_index)) != -1)
    {
        switch (c)
        {
        case 'h':
            printf("Usage: graph [options]\n"
                   "Options:\n"
                   "\t--help, -h          Display this help and exit\n"
                   "\t--eps1              The precision of the root calculations (default %.3f)\n"
                   "\t--eps2              The precision of the integral calculations (default %.3f)\n"
                   "\t--min               Lower bound for root search (default %.1f)\n"
                   "\t--max               Higher bound for root search (default %.1f)\n"
                   "\t--roots, -r         Print the coordinates of the function intersections\n"
                   "\t--iterations, -i    Print the number of iterations needed to find the intersection\n"
                   "\t--test, -t          Test root and integral functions\n",
                   DEFAULT_EPS, DEFAULT_EPS, DEFAULT_LOWER_BOUND, DEFAULT_HIGHER_BOUND);
            exit(0);
        case 0:
            *min = strtof(optarg, NULL);
            break;
        case 1:
            *max = strtof(optarg, NULL);
            break;
        case 2:
            *eps1 = strtof(optarg, NULL);
            if (*eps1 <= 0)
            {
                printf("--eps1 must be a positive float\n");
                exit(1);
            }
            break;
        case 3:
            *eps2 = strtof(optarg, NULL);
            if (*eps2 <= 0)
            {
                printf("--eps2 must be a positive float\n");
                exit(1);
            }
            break;
        case 'r':
            *print_roots = true;
            break;
        case 'i':
            *print_iter = true;
            break;
        case 't':
            *test = true;
            break;
        }
    }
    return 0;
}

// Функция для тестирования функций root и integral
void test_functions(float min, float max, float eps1, float eps2)
{
    uint32_t iterations;
    float found_root = root(test_f1, test_f2, min, max, eps1, dtest_f1, dtest_f2, &iterations);
    printf("Root of x-1=0:\n");
    printf("  (x,y) = (%f, %f)\n", found_root, test_f1(found_root));
    printf("  Number of iterations: %d\n", iterations);
    float found_integral = integral(test_f1, 1, 5, eps2);
    printf("Integral of x-1 on [1,5] = %f\n", found_integral);
}

int main(int argc, char *argv[])
{
    bool print_roots = false, print_iter = false, test = false;
    float eps1 = DEFAULT_EPS, eps2 = DEFAULT_EPS, min = DEFAULT_LOWER_BOUND, max = DEFAULT_HIGHER_BOUND;
    get_args(argc, argv, &eps1, &eps2, &min, &max, &print_roots, &print_iter, &test);

    if (test)
    {
        test_functions(min, max, eps1, eps2);
    }
    else
    {
        float (*my_functions[3])(float) = {f1, f2, f3};
        float (*dfunctions[3])(float) = {df1, df2, df3};
        float found_roots[3];

        for (uint8_t i = 0; i < 3; i++)
        {
            uint8_t j = (i == 2 ? 0 : i + 1); // поочередно ищем пересечения функций
            uint32_t iterations;
            found_roots[i] = root(my_functions[i], my_functions[j], min, max, eps1, dfunctions[i], dfunctions[j], &iterations);
            if (print_roots || print_iter)
                printf("Root %d:\n", i + 1);
            if (print_roots)
                printf("  (x,y) = (%f, %f)\n", found_roots[i], my_functions[i](found_roots[i]));
            if (print_iter)
                printf("  Number of iterations: %d\n", iterations);
        }

        float area = 0;
        for (uint8_t i = 0; i < 3; i++)
        {
            uint8_t j = (i == 0 ? 2 : i - 1); // found_roots[i] и found_roots[j] - корни, принадлежащие функции my_functions[i]
            float found_integral = integral(my_functions[i], found_roots[i], found_roots[j], eps2);
            uint8_t other_idx = i == 2 ? 0 : i + 1;
            // Если интеграл обхатывает 2 крайнее точки, то его вычитываем из area
            if (found_roots[i] < found_roots[other_idx] && found_roots[other_idx] < found_roots[j] || found_roots[j] < found_roots[other_idx] && found_roots[other_idx] < found_roots[i])
            {
                area -= found_integral;
            }
            else
            {
                area += found_integral;
            }
        }
        if (area < 0)
        {
            area = -area;
        }
        printf("Area: %f\n", area);
    }
    return 0;
}
