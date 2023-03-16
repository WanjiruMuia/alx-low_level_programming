#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"

typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

/**
 * print_dlistint - prints all the elements of a doubly linked list
 * @h: pointer to the head of the list
 * Return: the number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;
    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
        count++;
    }
    return (count);
}

