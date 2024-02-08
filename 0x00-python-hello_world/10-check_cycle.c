#include "lists.h"

/**
 * check_cycle - checks the linked_list if it contains a cycle or not
 * @list: linked list were we check
 * Return: 1 if succes, 0 if it fail
 */

int check_cycle(listint_t *list)
{

    listint_t *a = list;
    listint_t *b = list;

    if (!list)
        return 0;

    while (a && b && b->next)
    {
        a = a->next;
        b = b->next->next;
        if (a == b)
            return 1;
    }
    return 0;
}