#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t num;
    scanf("%u", &num);

    uint32_t k;
    scanf("%u", &k);

    printf("%u\n", num >> k | num << (32 - k));

    return 0;
}
