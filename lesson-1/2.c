#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint64_t num;
    scanf("%lu ", &num);

    char c;
    while ((c = getchar()) != '.')
    {
        if ('A' <= c && c <= 'Z')
        {
            c = (c - 'A' + num) % 26 + 'A';
        }
        else if ('a' <= c && c <= 'z')
        {
            c = (c - 'a' + num) % 26 + 'a';
        }
        printf("%c", c);
    }
    printf("%c\n", c);

    return 0;
}
