#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index
 * @head: Double pointer to the head of the doubly linked list
 * @index: Index of the node to delete (starting from 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    tmp = *head;

    /* Case 1: Deleting the head node (index 0) */
    if (index == 0)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(tmp);
        return (1);
    }

    /* Traverse to the node at the specified index */
    while (tmp != NULL && i < index)
    {
        tmp = tmp->next;
        i++;
    }

    /* If index is out of bounds */
    if (tmp == NULL)
        return (-1);

    /* Case 2: Deleting a node in the middle or at the end */
    tmp->prev->next = tmp->next;

    if (tmp->next != NULL)
    {
        tmp->next->prev = tmp->prev;
    }

    free(tmp);
    return (1);
}
