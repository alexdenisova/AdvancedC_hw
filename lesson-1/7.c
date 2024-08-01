#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t num;
    scanf("%u", &num);

    printf("%u\n", (~(num >> 24) << 24) | ((num << 8) >> 8));

    return 0;
}
