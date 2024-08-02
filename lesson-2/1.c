#include <stdio.h>

typedef struct list
{
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

void *findMaxBlock(list *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    list *largest = head;
    head = head->next;
    while (head)
    {
        if (head->size > largest->size)
        {
            largest = head;
        }
        head = head->next;
    }
    return largest->address;
}

int main(void)
{
    list last = {.address = &last, .size = 3, .next = NULL};
    list second = {.address = &second, .size = 5, .next = &last};
    list first = {.address = &first, .size = 1, .next = &second};

    list *max = findMaxBlock(&first);
    printf("Max list: address=%p, size=%ld\n", max->address, max->size);
    return 0;
}
