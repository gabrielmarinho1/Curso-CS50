#include <stdio.h>
#include <cs50.h>

//factorial function prototype
int fact(int f);

int main(void)
{
    //get an integer
    int i = get_int("Factorial of: ");

    //if the input is a negative integer
    if (i < 0)
    {
        printf("Negative integers doesn't have a factorial.\n");
        return 1;
    }
    //0! = 1
    else if (i == 0)
        printf("1\n");
    else
    {
        //print the factorial of i
        printf("%d\n", (fact(i)));
    }

}

//factorial function
int fact(int n)
{
    //base case
    if (n == 1)
        return 1;
    //recursive case
    else
        return n * fact(n - 1);
}