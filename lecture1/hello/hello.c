#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get name
    string name = get_string("Name: ");
    //print Hello, "name"!
    printf("Hello, %s!\n", name);
}