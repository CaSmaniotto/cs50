#include <stdio.h>
#include <cs50.h>
#include  <math.h>

int main(void)
{
    float troco;
    int counter = 0;
    int m1 = 25;
    int m2 = 10;
    int m3 = 5;
    int m4 = 1;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;

    do
    {
        troco = get_float("Digite o valor do troco em centavos: ");

    } while (troco < 0);

    troco = round(troco * 100);


    do
    {

    if (troco >= m1)
    {
        do
        {
            troco = troco - m1;
            c1++;
        } while (troco >= m1);
    }

    if (troco >= m2)
    {
        do
        {
            troco = troco - m2;
            c2++;
        } while (troco >= m2);
    }

    else if (troco >= m3)
    {
        do
        {
            troco = troco - m3;
            c3++;
        } while (troco >= m3);
    }

    else if(troco >= m4)
    {
        do
        {
            troco = troco - m4;
            c4++;
        } while (troco > 0);
    }
    } while (troco > 0);
    printf("%f\n", troco);

    printf("%i moedas de R$0.25\n",c1);
    printf("%i moedas de R$0.10\n",c2);
    printf("%i moedas de R$0.05\n",c3);
    printf("%i moedas de R$0.01\n",c4);
}