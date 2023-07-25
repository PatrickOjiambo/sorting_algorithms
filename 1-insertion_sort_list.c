#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of 
 * integers in ascending order using the Insertion sort algorithm
 * @list: the list to be sorted.
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *current = (*list)->next;
    while(current != NULL)
    {
        listint_t *key = current;
        listint_t *prev = current->prev;
        while(prev != NULL && prev->n > key->n)
        {
            if(prev->prev != NULL)
            {
                prev->prev->next = key;
            }
            else
            {
                *list = key;
            }
            if(key->next != NULL)
            {
                key->next->prev = prev;
            }
            prev->next = key->next;
            key->prev = prev->prev;
            key->next = prev;
            prev->prev = key;
            prev = key->prev;
            print_list(*list);
        }
        current = current->next;
    }
}
