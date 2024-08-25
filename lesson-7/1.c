#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
  char word[20];
  struct list *next;
} list;

void add_to_list(list **head, list *new)
{
  list *next = *head;
  while (next->next)
  {
    next = next->next;
  }
  next->next = new;
}

void swap_elements(list **head, list *element_1, list *element_2)
{
  list *tmp = element_1->next;
  element_1->next = element_2->next;
  element_2->next = tmp;
  if (*head == element_1)
  {
    *head = element_2;
  }
  else if (*head == element_2)
  {
    *head = element_1;
  }

  list *next = *head;
  while (next->next)
  {
    if (next->next == element_1)
    {
      next->next = element_2;
    }
    else if (next->next == element_2)
    {
      next->next = element_1;
    }
    next = next->next;
  }
}

void insert_before(list **head, list *before, list *new)
{
  new->next = before;
  if (*head == before)
  {
    *head = new;
  }
  else
  {
    list *previous = *head;
    while (previous->next != before)
    {
      previous = previous->next;
    }
    previous->next = new;
  }
}

void scan_list(list **head)
{
  while (1)
  {
    list *new = calloc(1, sizeof(list));
    char c;
    uint8_t idx = 0;
    while ((c = getchar()) != ' ' && c != '.')
    {
      new->word[idx++] = c;
    }

    if ((*head)->word[0] == '\0')
    {
      *head = new;
    }
    else
    {
      list *next = *head;
      while (next && strcmp(new->word, next->word) > 0)
      {
        next = next->next;
      }
      if (next)
      {
        insert_before(head, next, new);
      }
      else
      {
        add_to_list(head, new);
      }
    }

    if (c == '.')
      break;
  }
}

void print_list(list *head)
{
  list *next = head;
  while (next)
  {
    printf("%s ", next->word);
    next = next->next;
  }
}

void delete_list(list *head)
{
  if (head->next)
  {
    delete_list(head->next);
  }
  free(head);
}

int main(void)
{
  list *head = NULL;
  head = calloc(1, sizeof(list));

  scan_list(&head);

  // list *element_1 = head->next;
  // list *element_2 = head->next->next;
  // swap_elements(&head, element_1, element_2);

  print_list(head);
  delete_list(head);

  return 0;
}
