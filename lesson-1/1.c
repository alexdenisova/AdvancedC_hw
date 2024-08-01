#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint64_t num;
    scanf("%lu", &num);

    int64_t max;
    scanf("%ld", &max);
    uint64_t count = 1;
    for (uint64_t i = 0; i < num - 1; i++)
    {
        int64_t next;
        scanf("%ld", &next);
        if (next > max)
        {
            max = next;
            count = 1;
        }
        else if (next == max)
        {
            count++;
        }
    }

    printf("%lu\n", count);
    return 0;
}
