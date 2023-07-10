#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long cartao = get_long("Insira o número do cartão: \n");

 // separando digitos
    long l1 = (cartao % 10);
    long l2 = (cartao % 100);
    long l3 = (cartao % 1000);
    long l4 = (cartao % 10000);
    long l5 = (cartao % 100000);
    long l6 = (cartao % 1000000);
    long l7 = (cartao % 10000000);
    long l8 = (cartao % 100000000);
    long l9 = (cartao % 1000000000);
    long l10 = (cartao % 10000000000);
    long l11 = (cartao % 100000000000);
    long l12 = (cartao % 1000000000000);
    long l13 = (cartao % 10000000000000);
    long l14 = (cartao % 100000000000000);
    long l15 = (cartao % 1000000000000000);
    long l16 = (cartao % 10000000000000000);

 // tirando o zero, deixando apenas o digito
    int i1 = l1;
    int i2 = (l2 - l1)/10;
    int i3 = (l3 - l2)/100;
    int i4 = (l4 - l3)/1000;
    int i5 = (l5 - l4)/10000;
    int i6 = (l6 - l5)/100000;
    int i7 = (l7 - l6)/1000000;
    int i8 = (l8 - l7)/10000000;
    int i9 = (l9 - l8)/100000000;
    int i10 = (l10 - l9)/1000000000;
    int i11 = (l11 - l10)/10000000000;
    int i12 = (l12 - l11)/100000000000;
    int i13 = (l13 - l12)/1000000000000;
    int i14 = (l14 - l13)/10000000000000;
    int i15 = (l15 - l14)/100000000000000;
    int i16 = (l16 - l15)/1000000000000000;

 //algoritmo de luhn

    int v1 = ((i2 * 2)%10); int c1 = ((i2 * 2) - v1) / 10; int a1 = c1 + v1;
    int v2 = ((i4 * 2)%10); int c2 = ((i4 * 2) - v2) / 10; int a2 = c2 + v2;
    int v3 = ((i6 * 2)%10); int c3 = ((i6 * 2) - v3) / 10; int a3 = c3 + v3;
    int v4 = ((i8 * 2)%10); int c4 = ((i8 * 2) - v4) / 10; int a4 = c4 + v4;
    int v5 = ((i10 * 2)%10); int c5 = ((i10 * 2) - v5) / 10; int a5 = c5 + v5;
    int v6 = ((i12 * 2)%10); int c6 = ((i12 * 2) - v6) / 10; int a6 = c6 + v6;
    int v7 = ((i14 * 2)%10); int c7 = ((i14 * 2) - v7) / 10; int a7 = c7 + v7;
    int v8 = ((i16 * 2)%10); int c8 = ((i16 * 2) - v8) / 10; int a8 = c8 + v8;


    int s1 = a1 + a2 + a3 + a4 + a5 + a6 +a7 + a8; //soma dos numeros acima
    int s2 = s1 + i1 + i3 + i5 + i7 + i9 + i11 + i13 + i15; //soma o restante ao resultado

    if (s2 % 10 != 0) //checa se o cartao é valido e qual é a bandeira
    {
        printf("INVALID\n");

    }
    else if ((i16 == 5 && i15 == 1) || i15 == 2 || i15 == 3 || i15 == 4 || i15 == 5)

                        {
                            printf("MASTERCARD\n");
                        }

    else if ((i16 == 0) && (((i15 * 10) + i14) == 37 || ((i15 * 10) + i14) == 34))

                        {

                            printf("AMEX\n");

                        }

                        else if

                            (i16 == 4)

                            {
                                printf("VISA\n");
                            }

                            else if ((i16 + i15 + i14 == 0) && (i13 == 4))

                            {
                                printf("VISA\n");
                            }

                            else
                            {
                                printf("INVALID\n");
                            }

    }