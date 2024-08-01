#include <stdio.h>
#include <stdint.h>

int extractExp(float num)
{
    int exp = 0;
    if (num >= 2.0)
    {
        while (num >= 2)
        {
            num = num / 2;
            exp++;
        }
    }
    else if (num < 1)
    {
        while (num < 1.0)
        {
            num = num * 2;
            exp--;
        }
    }
    return 127 + exp;
}

int main(void)
{
    float num;
    scanf("%f", &num);
    printf("%d\n", extractExp(num));
    return 0;
}
