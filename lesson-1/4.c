#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t num;
    scanf("%u", &num);

    uint8_t k;
    scanf("%hhu", &k);

    uint32_t mask = (1 << k) - 1;

    printf("%u\n", num & mask);

    return 0;
}
