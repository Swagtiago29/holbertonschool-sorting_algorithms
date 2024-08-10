#include "sort.h"
/**
 *insertion_sort_list - sorting a linked list
 *@list: liast to sort
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	//listint_t *tmp;

	 if (!list || !*list || !(*list)->next)
        	return;
	current = *list;
	while (current->next)
	{
		current = current->next;
		while (current->next->n < current->n)
		{
			printf("xd1");
			tmp = current;
			tmp->next = current->next;
			tmp->prev = current->prev;
			current->prev = current->next->prev;
			current->next = current->next->next;
			current->next->next = tmp->next;
			current->next->prev = tmp->prev;
			print_list(*list);
			}	 
		} 
	}
}
