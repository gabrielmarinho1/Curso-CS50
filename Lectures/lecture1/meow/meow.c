#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int m = get_int("Meows: ");

    for (int i = 0; i < m; i++)
    {
        printf("Meow!\n");
    }
}