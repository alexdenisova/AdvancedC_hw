#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

const uint16_t MAX_STRING_LENGTH = 104;

uint8_t prefix_suffix(char first[], char second[])
{
  uint8_t prefix_len = 0;

  uint8_t first_len = strlen(first);
  uint8_t sec_len = strlen(second);
  uint8_t max_len = first_len > sec_len ? first_len : sec_len;
  for (uint16_t len = 1; len < max_len; len++)
  {
    bool match = true;
    for (uint16_t i = 0; i < len; i++)
    {
      if (first[i] != second[sec_len - len + i])
      {
        match = false;
        break;
      }
    }
    if (match)
      prefix_len = len;
  }
  return prefix_len;
}

int main(void)
{
  char first[MAX_STRING_LENGTH], second[MAX_STRING_LENGTH];
  scanf("%s", first);
  scanf("%s", second);

  printf("%u %u\n", prefix_suffix(first, second), prefix_suffix(second, first));
  return 0;
}
