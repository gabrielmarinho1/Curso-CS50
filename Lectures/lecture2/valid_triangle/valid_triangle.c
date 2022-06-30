#include <stdio.h>
#include <cs50.h>

//function declaration
bool valid_triangle(int x, int y, int z);

int main(void)
{
    //get the 3 sides of the triangle
    int a = get_int("1st side: ");
    int b = get_int("2nd side: ");
    int c = get_int("3rd side: ");

    //check wether the function valided the triangle or not
    if (valid_triangle(a, b, c) == true)
    {
        printf("This is a valid triangle!\n");
    }
    else
    {
        printf("This is not a valid triangle.\n");
    }
}

bool valid_triangle(int x, int y, int z)
{
    //check if all the sides are positive
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }

    //check if the sum of any two sides is greater than the third
    if (x + y > z && x + z > y && y + z > x)
    {
        return true;
    }
    else
    {
        return false;
    }
}