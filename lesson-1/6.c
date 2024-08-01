#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t num;
    scanf("%u", &num);

    uint8_t count = 0;
    while (num > 0)
    {
        count += (num & 1);
        num >>= 1;
    }

    printf("%u\n", count);

    return 0;
}
