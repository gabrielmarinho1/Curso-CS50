#include <stdio.h>
#include <cs50.h>

//collatz function prototype
int collatz(int n);

int main(void)
{
    //get integer
    int i = get_int("Number: ");

    //if it's less or equal to 0
    if (i <= 0)
    {
        printf("Enter a positive integer\n");
        return 1;
    }
    else
    {
        printf("Collatz Steps: %i\n", collatz(i));
    }
}

//collatz function
int collatz(int n)
{
    //count steps
    int steps = 0;

    //base case
    //if n = 1, the total steps is 0
    if (n == 1)
    {
        return 0;
    }

    //recursive cases
    //while it doesn't get back to 1
    while (n != 1)
    {
        //if it's even
        if (n % 2 == 0)
        {
            n /= 2;
            //increase steps by 1
            steps++;
        }
        //else it's odd
        else
        {
            n = 3 * n + 1;
            //increase steps by 1
            steps++;
        }
    }
    return steps;
}