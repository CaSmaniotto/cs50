#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("X: \n");

    int y = get_int("Y: \n");



    if (x < y)
    {
        printf("X é menor que Y");
    }
    else if (x > y)
    {
        printf("X é maior que Y");
    }
    else
    {
        printf("X e Y são iguais\n");
    }

}