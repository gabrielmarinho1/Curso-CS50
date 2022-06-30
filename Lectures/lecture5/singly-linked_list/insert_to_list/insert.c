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

//add number function prototype
list *add_number(list *first, int value);

int main(void)
{
    //create a null list
    list *first = NULL;

    //elements
    int size = get_int("How many elements on the list?: ");

    //ask for each element to be added to the list and add it
    do
    {
        int value = get_int("Number: ");
        first = add_number(first, value);
        size--;
    }
    while (size > 0 && first != NULL);

    //print list
    for (list *tmp = first; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    //free list
    while (first != NULL)
    {
        list *tmp = first->next;
        free(first);
        first = tmp;
    }

}

//add_number function
list *add_number(list *first, int value)
{
    //copy the pointer for the first element on the list
    list *last = first;

    //if it's null, the first element will be added
    if (last == NULL)
    {
        list *new = malloc(sizeof(list));
        if (new == NULL)
        {
            return NULL;
        }
        //get the value
        new->number = value;
        //point to the new element
        last = new;

        //return pointer to the new element
        return last;
    }
    //if it's not the first element on the list, add one more
    else
    {
        list *new = malloc(sizeof(list));
        if (new == NULL)
        {
            return NULL;
        }
        //get the value
        new->number = value;
        //point to the last element
        new->next = last;
        //point to the new element
        last = new;
    }

    //return pointer to the new element
    return last;
}