#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

//create a list of numbers
typedef struct list
{
    int number;
    struct list *next;
}
list;

//destroy function prototype
void destroy(list *first);

int main(void)
{
    //create a null list
    list *first = NULL;

    //add a number to list
    list *n = malloc(sizeof(list));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;

    //update list to pint to new list
    first = n;

    //add number to list;
    n = malloc(sizeof(list));
    if (n == NULL)
    {
        free(first);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    first->next = n;

    //add number to list;
    n = malloc(sizeof(list));
    if (n == NULL)
    {
        free(first->next);
        free(first);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    first->next->next = n;

    //add number to list;
    n = malloc(sizeof(list));
    if (n == NULL)
    {
        free(first->next->next);
        free(first->next);
        free(first);
        return 1;
    }
    n->number = 4;
    n->next = NULL;
    first->next->next->next = n;

    //add number to list;
    n = malloc(sizeof(list));
    if (n == NULL)
    {
        free(first->next->next->next);
        free(first->next->next);
        free(first->next);
        free(first);
        return 1;
    }
    n->number = 5;
    n->next = NULL;
    first->next->next->next->next = n;

    //free list
    destroy(first);
}

//destroy function
void destroy(list *first)
{
    //copy the ponter to the first element in the list
    list *tmp = first;

    //base case
    if (tmp == NULL)
    {
        return;
    }
    //recursion case
    else
    {
        destroy(tmp->next);
        free(tmp);
    }
}