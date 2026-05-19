#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index index of a
 * dlistint_t linked list.
 * @head: double pointer to the head of the list
 * @index: index of the node to delete
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

    /* Case 2: Index out of range (node doesn't exist) */
    if (tmp == NULL)
        return (-1);

    /* Case 3: Deleting a middle or tail node */
    /* Break the connection from the previous node pointing forward */
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;

    /* Break the connection from the next node pointing backward */
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;

    free(tmp);
    return (1);
}
