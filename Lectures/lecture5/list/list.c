#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //get a 12 bytes(3 ints) chuck of memory from heap
    int *list = malloc(sizeof(int) * 3);

    //if there ain't no memory available, return 1
    if (list == NULL)
    {
        return 1;
    }

    //put the values on the list
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    //resize list to be of size 4(16 bytes)
    int* tmp = realloc(list, sizeof(int) * 4);
    ////if i can't get another chunck of memory from heap, free list and return 1
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    //passes the value of 4 to tmp[3]
    tmp[3] = 4;

    //update the address of tmp to list
    list = tmp;

    //print list
     for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    //free the memory that list had(16 bytes)
    free(list);

    return 0;
}