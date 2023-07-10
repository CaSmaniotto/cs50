#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    //pergunta o tamanho da altura
    do
    {
    height = get_int("Height: \n");
    }

     // o valor deve estar entre 1 e 8 apenas
    while
    ((height < 1) || (height > 8));

    // loop para criar a altura da linha
    for (int row = 0; row < height; row++)
    {
        // loop para criar a largura da piramide
        for (int column = 0; column < height ; column++)
        {
            // if row plus column is greater than or equal than height -1 space print the hashes
            if (row + column >= height - 1)

                printf("#");

            // adding spaces
            else
            {
            printf(" ");
            }

            }
        printf("\n");
    }
}