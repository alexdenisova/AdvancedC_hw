#include <stdio.h>
#include <stdint.h>

uint8_t number_bit_length(uint32_t num)
{
    uint8_t len = 0;
    while (num != 0)
    {
        len++;
        num >>= 1;
    }
    return len;
}

int main(void)
{
    uint32_t num;
    scanf("%u", &num);

    uint8_t k;
    scanf("%hhu", &k);

    uint32_t mask = (1 << k) - 1;

    uint32_t max = num & mask;
    uint8_t diff = number_bit_length(num) - number_bit_length(mask);
    for (uint8_t i = 1; i < diff + 1; i++)
    {
        mask <<= 1;
        if (((num & mask) >> i) > max)
        {
            max = (num & mask) >> i;
        }
    }

    printf("%u\n", max);

    return 0;
}
