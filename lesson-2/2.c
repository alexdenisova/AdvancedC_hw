#include <stdio.h>

typedef struct list
{
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

size_t totalMemoryUsage(list *head)
{
    if (head == NULL)
    {
        return 0;
    }
    size_t total_size = 0;
    while (head)
    {
        total_size += head->size;
        head = head->next;
    }
    return total_size;
}

int main(void)
{
    list last = {.address = &last, .size = 3, .next = NULL};
    list second = {.address = &second, .size = 5, .next = &last};
    list first = {.address = &first, .size = 1, .next = &second};

    printf("Total size: %ld\n", totalMemoryUsage(&first));
    return 0;
}
