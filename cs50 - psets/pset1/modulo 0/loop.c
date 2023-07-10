#include <stdio.h>
#include <cs50.h>


void miau(void)
{
    printf("miau.\n");
}

int main(void)
{
     for(int i = 0; i < 3; i++)
     {
         miau();
	 }
}