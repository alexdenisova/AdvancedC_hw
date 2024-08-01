#include <stdio.h>
#include <stdint.h>

/// Считает 1*3^0 + 0*3^1 + 1*3^2..., где ...101 - бинарное предствление num
uint32_t from_binary_format(uint32_t num)
{
    uint32_t result = 0;
    uint32_t pow_3 = 1;
    while (num != 0)
    {
        result += (num & 1) * pow_3;
        num >>= 1;
        pow_3 *= 3;
    }
    return result;
}

/// Возвращает -1, если невозможно число представить в формате sum((0||1)*3^n)
int64_t to_binary_format(uint32_t num)
{
    int64_t result = -1;
    for (uint32_t i = 1; from_binary_format(i) <= num; i++)
    {
        if (from_binary_format(i) == num)
        {
            result = i;
        }
    }
    return result;
}

/// Считает количество 1 в бинарном предствлении
uint32_t count_1s(uint32_t num)
{
    uint32_t count = 0;
    while (num > 0)
    {
        count += (num & 1);
        num >>= 1;
    }
    return count;
}

int main(void)
{
    uint32_t weight;
    scanf("%u", &weight);

    uint32_t number_of_weights = 0;
    /// binary_weights - это бинарноге представление количество гирь (1*3^0 + 0*3^1 + 1*3^2...)
    for (uint32_t binary_weights = 0; from_binary_format(binary_weights) < weight; binary_weights++)
    {
        uint32_t additional_weight = from_binary_format(binary_weights);
        uint32_t total_weight = weight + additional_weight;

        int64_t total_weight_binary = to_binary_format(total_weight);
        if (total_weight_binary > 0 && (total_weight_binary & binary_weights) == 0)
        {
            number_of_weights = count_1s(binary_weights) + count_1s(total_weight_binary);
            break;
        }
    }
    if (number_of_weights > 0)
    {
        printf("%u\n", number_of_weights);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
