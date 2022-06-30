#include <stdio.h>
#include <cs50.h>

//declaration of linear search function
bool linear_search(int x, int y[12]);

int main(void)
{
    //number
    int number = get_int("Number: ");

    //list of numbers
    int list[12] = {2, 4, 9, 45, 3, 12, 67, 0, 5, 24, 100, 32};

    //check wether the number is in the list
    if (linear_search(number, list) == true)
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found.\n");
    }
}

//linear search
bool linear_search(int x, int y[12])
{
    //loop through every element of the array looking for the number
    for (int i = 0; i < 12; i++)
    {
        //if the number is found on the array, return true
        if (x == y[i])
        {
            return true;
        }
    }

    //if the number is not in the array, return false
    return false;
}