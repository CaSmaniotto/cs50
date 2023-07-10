#include <stdio.h>

#include <cs50.h>



int main(void)





{

    printf(" DESCOBRINDO A BANDEIRA DO CARTÃO DE CRÉDITO v.0 \n Programador: Caléb Rangel Porto \n\n");



    // Pedir o número do cartão

    long a = get_long("Digite o número do seu cartão: \n\n");



    // Separando dígito por dígito

    long c01 = (a % 10);

    long c02 = (a % 100);

    long c03 = (a % 1000);

    long c04 = (a % 10000);

    long c05 = (a % 100000);

    long c06 = (a % 1000000);

    long c07 = (a % 10000000);

    long c08 = (a % 100000000);

    long c09 = (a % 1000000000);

    long c10 = (a % 10000000000);

    long c11 = (a % 100000000000);

    long c12 = (a % 1000000000000);

    long c13 = (a % 10000000000000);

    long c14 = (a % 100000000000000);

    long c15 = (a % 1000000000000000);

    long c16 = (a % 10000000000000000);



    // Excluindo os zeros para sobrar somente os dígitos

    int b01 = c01;

    int b02 = (c02 - c01) / 10;

    int b03 = (c03 - c02) / 100;

    int b04 = (c04 - c03) / 1000;

    int b05 = (c05 - c04) / 10000;

    int b06 = (c06 - c05) / 100000;

    int b07 = (c07 - c06) / 1000000;

    int b08 = (c08 - c07) / 10000000;

    int b09 = (c09 - c08) / 100000000;

    int b10 = (c10 - c09) / 1000000000;

    int b11 = (c11 - c10) / 10000000000;

    int b12 = (c12 - c11) / 100000000000;

    int b13 = (c13 - c12) / 1000000000000;

    int b14 = (c14 - c13) / 10000000000000;

    int b15 = (c15 - c14) / 100000000000000;

    int b16 = (c16 - c15) / 1000000000000000;
// Formando o algoritmo de Luhn

    // Multiplicando cada segundo dígito por 2 começando pelo penúltimo e separando e somando os dígitos

    int b0201 = ((b02 * 2) % 10); int b0202 = ((b02 * 2) - b0201) / 10; int b0203 = b0201 + b0202;

    int b0401 = ((b04 * 2) % 10); int b0402 = ((b04 * 2) - b0401) / 10; int b0403 = b0401 + b0402;

    int b0601 = ((b06 * 2) % 10); int b0602 = ((b06 * 2) - b0601) / 10; int b0603 = b0601 + b0602;

    int b0801 = ((b08 * 2) % 10); int b0802 = ((b08 * 2) - b0801) / 10; int b0803 = b0801 + b0802;

    int b1001 = ((b10 * 2) % 10); int b1002 = ((b10 * 2) - b1001) / 10; int b1003 = b1001 + b1002;

    int b1201 = ((b12 * 2) % 10); int b1202 = ((b12 * 2) - b1201) / 10; int b1203 = b1201 + b1202;

    int b1401 = ((b14 * 2) % 10); int b1402 = ((b14 * 2) - b1401) / 10; int b1403 = b1401 + b1402;

    int b1601 = ((b16 * 2) % 10); int b1602 = ((b16 * 2) - b1601) / 10; int b1603 = b1601 + b1602;



    // Somando os dígitos restantes

    int l1 = (b01 + b03 + b05 + b07 + b09 + b11 + b13 + b15);



    // Somando tudo para calcular o algoritmo

    int luhn = b0203 + b0403 + b0603 + b0803 + b1003 + b1203 + b1403 + b1603 + l1;





    // Condições para descobrir a bandeira do cartão, caso o número não seja inválido
if (luhn % 10 != 0)

    {

        printf("INVALID\n");

    }

    else

    {

        if ((a - (a % 10000000000000000)) > 0 || (a - (a % 10000000000000000)) < 0)

        {

            printf("INVALID\n");

        }

        else

        {

            if ((b13 + b14 + b15 + b16) == 0)

            {

                printf("INVALID\n");

            }

            else

            {

                if (((b14 + b15 + b16) == 0) && b13 == 4)

                {

                    printf("VISA\n");

                }

                else

                {

                    if (b16 == 4)

                    {

                        printf("VISA\n");

                    }

                    else

                    {

                        if (b16 == 0 && (((b15 * 10) + b14) == 37 || ((b15 * 10) + b14) == 34))

                        {

                            printf("AMEX\n");

                        }

                        else

                        {

                            if ((b16 == 5) && ((b15 == 1) || (b15 == 2) || (b15 == 3) || (b15 == 4) | (b15 == 5)))

                            {

                                printf("MASTERCARD\n");

                            }

                            else

                            {

                                printf("INVALID\n");

                            }

                        }

                    }

                }

            }

        }

    }

}