#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    //declaration an array of size 50;
    int list[15];

    //populate array with 15 pseudorandom numbers
    for (int i = 0; i < 15; i++)
    {
        list[i] = rand()%15;
    }

    //count the amount of integers in the array
    int elements = sizeof(list) / sizeof(int);

    //set the counter to a non-zero value
    int counter = -1;

    //repeat until none swaps are done
    while (counter != 0)
    {
        //reset swap counter to 0
        counter = 0;

        //look at each adjecent pair
        for (int i = 0, j = 0; i < elements - 1; i++)
        {
            //if two adjecent elements are not sorted, swap them and count 1 swap
            if (list[i] > list[i + 1])
            {
                j = list[i + 1];

                list[i + 1] = list[i];

                list[i] = j;

                counter++;
            }
        }
    }

    //print out the sorted list
    for (int i = 0; i < elements; i++)
    {
        printf("%i\n", list[i]);
    }
}