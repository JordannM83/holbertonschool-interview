#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to the list's head pointer
 * @number: value to insert
 *
 * Return: address of the new node, or NULL on failure
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t **link;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);

	link = head;
	while (*link != NULL && (*link)->n < number)
		link = &(*link)->next;

	new_node->n = number;
	new_node->next = *link;
	*link = new_node;

	return (new_node);
}
