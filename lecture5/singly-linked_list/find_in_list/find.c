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

bool find(list *first, int value);

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

    //get value you're searching for
    int value = get_int("Number: ");

    //check wether the number is in the list
    if (find(first, value) == true)
    {
        printf("Find!\n");
    }
    else
    {
        printf("Not find.\n");
    }

    //print list
    printf("List: ");
    for (list *tmp = first; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->next != NULL)
        {
            printf("%i, ", tmp->number);
        }
        else
        {
            printf("%i.", tmp->number);
        }
    }
    printf("\n");

    //free list
    while (first != NULL)
    {
        list *tmp = first->next;
        free(first);
        first = tmp;
    }
}

//find function
bool find(list *first, int value)
{
    //loop through each node in the list and check if the number is in there
    for (list *tmp = first; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->number == value)
        {
            return true;
        }
    }

    //if it's not, return false
    return false;
}