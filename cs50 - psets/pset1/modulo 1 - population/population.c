submit50 cs50/problems/2021/x/substitution#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int pop_i;
    int pop_f;
    int y = 0;

    //pede o valor inicial da populacao. valor q n pode ser menor que 9
    do
    {
        pop_i = get_int("Start size: \n");
    }
    while (pop_i < 9);

    //pede o valor final da populacao
    do
    {
        pop_f = get_int("End size: \n");
    }
    while (pop_f < pop_i);

    //faz o calculo de quantos anos serão necessários para pop. inicial seja = a pop.final
    //usado round para arredondar o valor para o mais próximo
    //pop_i = pop_i + (pop_i / 3) - (pop_i / 4); regra dada pelo exercicio para se fazer o calculo
    while (pop_i < pop_f)
    {
        pop_i = round(pop_i + (pop_i / 3) - (pop_i / 4));
        y++;
    }

    printf("Years: %i\n", y);


}