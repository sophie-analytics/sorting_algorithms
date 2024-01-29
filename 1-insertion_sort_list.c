#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - function that sort using insertion sort method
 * @list: The linked list it takes
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *current_node, *node, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
    
    current_node = (*list)->next; 
    while(current_node != NULL)
    {
        node = current_node;
        prev_node = node->prev;
        while(prev_node != NULL && node->n < prev_node->n)
        {
            prev_node->next = node->next;
            if (node->next != NULL)
                node->next->prev = prev_node;
            node->prev = prev_node->prev;
            node->next = prev_node;
            if (prev_node->prev != NULL)
                prev_node->prev->next = node;
            else
                *list = node;
            prev_node->prev = node;
            prev_node = node->prev;
            if (node->prev == NULL)
                break;
            print_list(*list);
        }
        current_node = current_node->next;
    }
}
