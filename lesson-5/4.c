#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

const uint16_t MAX_ARRAY_LENGTH = 1000;

uint8_t number_of_zeros(uint32_t num)
{
  uint8_t count = 0;
  while (num > 0)
  {
    count += 1 - (num & 1);
    num >>= 1;
  }
  return count;
}

int main(void)
{
  uint32_t n, k;
  scanf("%d %d", &n, &k);

  uint32_t count = 0;
  for (uint32_t i = 0; i < n; i++)
  {
    if (number_of_zeros(i) == k)
    {
      count++;
    }
  }
  printf("%u\n", count);

  return 0;
}
