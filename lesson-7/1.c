#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

const uint8_t MAX_WORD_LENGTH = 20;

typedef struct list
{
  char word[20];
  struct list *next;
} list;

void scan_list(list **head)
{
  list *next = *head;
  while (1)
  {
    char c;
    uint8_t idx = 0;
    list *new = calloc(1, sizeof(list));
    while ((c = getchar()) != ' ' && c != '.')
    {
      new->word[idx++] = c;
    }
    next->next = new;
    next = new;
    if (c == '.')
      break;
  }
}

void add_to_list(list **head, list *new)
{
  list *next = *head;
  while (next->next)
  {
    next = next->next;
  }
  next->next = new;
}

int main(void)
{
  list *head = NULL;
  head = calloc(1, sizeof(list));

  scan_list(&head);

  // list *new = calloc(1, sizeof(list));
  // strcpy(new->word, "hello");
  // add_to_list(&head, new);

  list *next = head;
  while (next)
  {
    printf("%s ", next->word);
    next = next->next;
  }

  return 0;
}
