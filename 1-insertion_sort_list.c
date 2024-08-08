#include "sort.h"
/**
 *insertion_sort_list - sorting a linked list
 *@list: liast to sort
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *tmp;

	 if (!list || !*list || !(*list)->next)
        	return;
	current = *list;
	tmp = current;
	while (current->next)
	{
		while (list && *list->n < current->n)
		{
		
			if()tmp->next = current->next;
			tmp->prev = current->prev;
			current->next = current->next->next;
			current->prev = current->next->prev;
			current->next->prev = tmp->prev;
			current->next->next = tmp->next;
		}
	current = current->next;
	}
}
