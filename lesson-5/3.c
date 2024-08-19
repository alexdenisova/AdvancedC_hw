#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

const uint16_t MAX_ARRAY_LENGTH = 1000;

int main(void)
{
  int numbers[MAX_ARRAY_LENGTH];
  uint16_t array_len = 0;

  char c;
  while ((c = getchar()) != '.')
  {
    if ('0' <= c && c <= '9')
    {
      uint16_t num = c - '0';
      while ((c = getchar()) != ' ')
      {
        num = num * 10 + c - '0';
      }
      numbers[array_len++] = num;
    }
    else
    {
      int result;
      switch (c)
      {
      case '+':
        result = numbers[array_len - 2] + numbers[array_len - 1];
        break;
      case '-':
        result = numbers[array_len - 2] - numbers[array_len - 1];
        break;
      case '*':
        result = numbers[array_len - 2] * numbers[array_len - 1];
        break;
      case '/':
        result = numbers[array_len - 2] / numbers[array_len - 1];
        break;
      case ' ':
        continue;
      default:
        break;
      }
      numbers[array_len - 2] = result;
      array_len--;
    }
  }
  printf("%d\n", numbers[0]);
  return 0;
}
