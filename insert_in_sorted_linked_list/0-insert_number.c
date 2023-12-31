#include "lists.h"
#include <stdlib.h>
/*
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to head of list
 * @number: number to insert
 * Return: the address of the new node, or NULL if it failed
**/

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *current = *head;
    listint_t *new = malloc(sizeof(listint_t));

    if (new == NULL)
    {
        return NULL;
    }

    new->n = number;
    new->next = NULL;
    
    if (*head == NULL || new->n < (*head)->n)
    {
        new->next = *head;
        *head = new;
        return new;
    }
    else
    {
        while (current->next != NULL && number > current->next->n)
        {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
    return new;
}