#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //declaration an array of size 15;
    int list[15];

    //populate array with 15 pseudorandom numbers
    for (int i = 0; i < 15; i++)
    {
        list[i] = rand()%15;
    }

    //print the unsorted list
    printf("Unsorted list: ");
    for (int i = 0; i < 15; i++)
    {
        printf("%i ", list[i]);
    }
    printf("\n");

    //set the swap count to a non-zero value
    int count = -1;

    //repeat until none swaps are done
    while (count != 0)
    {
        //reset swap count so 0
        count = 0;

        //look at each number in the list
        for (int i = 0, s = 0; i < 15; i++)
        {
            //get the ith number to check if it's the smallest
            s = list[i];

            //compare it to every other number on the list
            for (int j = i + 1, temp; j < 15; j++)
            {
                //if the other number is less than the ith number, swap them
                if (list[j] < s)
                {
                    temp = s;
                    s = list[j];
                    list[j] = temp;
                    list[i] = s;

                    //count 1 swap
                    count++;
                }
            }
        }
    }

    //print out the sorted list
    printf("New sorted list: ");
    for (int i = 0; i < 15; i++)
    {
        printf("%i ", list[i]);
    }
    printf("\n");
}