#include <stdio.h>
#include <cs50.h>
#include <string.h>

//declaration of binary search function
bool binary_search(int x, int y[13]);

int main(void)
{
    //number
    int number = get_int("Number: ");

    //sorted list of numbers
    int list[13] = {0, 2, 3, 4, 9, 12, 22, 34, 40, 44, 65, 77, 87};

    //check wether the number is in the list
    if (binary_search(number, list) == true)
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found.\n");
    }
}

//binary search function
bool binary_search(int x, int y[13])
{
    //initialize the start and the end of the original array of numbers
    int start = 0;
    int end = 12;

    //repeat until the array is of size 0
    while (start <= end)
    {
        //find the middle of the array
        int middle = (start + end) / 2;

        //if the number is in the middle, return true
        if (x == y[middle])
        {
            return true;
        }
        //otherwise, if the number is less than the number in the middle
        else if (x < y[middle])
        {
            //change the end point to be just to the left of the middle point
            end = middle - 1;
        }
        //otherwise, if the number is greater than the number in the middle
        else if (x > y[middle])
        {
            //change the start point to be just to the right of the middle point
            start = middle + 1;
        }
    }

    //if the number is not in the array, return false
    return false;
}