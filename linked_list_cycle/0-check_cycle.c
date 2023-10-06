#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - function that check if a singly linkded list ha a cycle in it
 * @list: list to check
 * Return : 0 if there is no cycle else 1
 **/
int check_cycle(listint_t *list)
{
    listint_t *slow = list, *fast = list;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}