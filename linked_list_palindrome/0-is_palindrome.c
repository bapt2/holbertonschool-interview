#include "lists.h"

int is_palindrome(listint_t **head)
{
    listint_t *copy = NULL;
    listint_t *current = *head;
    if (head == NULL)
    {
        return (1);
    }

    while (current)
    {
        add_nodeint_end(&copy, current->n);
        current = current->next;
    }
    listint_t *prev = NULL;
    listint_t *next = NULL;
    current = copy;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    copy = prev;

    current = *head;
    while(current && copy)
    {
        if (current->n != copy->n)
        {
            return(0);
        }
        current = current->next;
        copy = copy->next;
    }
    return (1);
}