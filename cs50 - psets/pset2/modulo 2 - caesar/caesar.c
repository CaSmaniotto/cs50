#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Verifica o numero de argumentos
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Verifica se o argumento é formado somento por números
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    //Pede o texto a ser cifrado
    string s = get_string("plaintext: ");
    printf("ciphertext: ");

    //Converte argv de string para int
    int key = atoi(argv[1]);


    //Inicio do loop
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //Verifica se é alfabético
        if (isalpha(s[i]))
        {
            //variavel cifra recebe o valor do char + valor da chave
            int cifra = s[i] + key;

            //Vefica se o valor é minusculo
            if (islower(s[i]))
            {
                //Se o valor for maior que 'z'. volta ao inicio.
                while (cifra > 'z')
                {
                    cifra -= 26;
                }
            }
            else
            {
                //Faz a mesma coisa, porém pra letra maiuscula
                while (cifra > 'Z')
                {
                    cifra -=26;
                }
            }
            
            //Imprime o texto cifrado
            printf("%c", cifra);
        }
        else
        {
            //Caso não seja alfabético, imprime o valor sem alteração
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
