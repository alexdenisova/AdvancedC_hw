#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

const uint16_t MAX_NUM_LENGTH = 1000;

uint32_t number_of_combinations(uint8_t array[], uint64_t array_len)
{
  bool found[1000];
  for (uint16_t i = 0; i < 1000; i++)
  {
    found[i] = false;
  }
  for (uint64_t i = 0; i < array_len - 2; i++)
  {
    for (uint64_t j = i + 1; j < array_len - 1; j++)
    {
      for (uint64_t k = j + 1; k < array_len; k++)
      {
        found[array[i] * 100 + array[j] * 10 + array[k]] = true;
      }
    }
  }
  uint32_t count = 0;
  for (uint16_t i = 0; i < 1000; i++)
  {
    if (found[i])
    {
      count++;
    }
  }
  return count;
}

int main(void)
{
  uint8_t array[MAX_NUM_LENGTH];
  uint64_t array_len = 0;

  char c = 0;
  while ((c = getchar()) != '\n')
  {
    array[array_len++] = c - '0';
  }

  printf("%u\n", number_of_combinations(array, array_len));
  return 0;
}
