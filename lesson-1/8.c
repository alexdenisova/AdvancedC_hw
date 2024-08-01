#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t num;
    scanf("%u", &num);

    uint32_t unique_number;
    scanf("%u", &unique_number);
    for (uint32_t i = 1; i < num; i++)
    {
        uint32_t next;
        scanf("%u", &next);

        unique_number = unique_number ^ next;
    }
    printf("%u\n", unique_number);
    return 0;
}
