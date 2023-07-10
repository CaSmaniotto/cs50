#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //Declaração das variaveis
    int word = 1;
    int sentence = 0;
    int letter = 0;

    string s = get_string("Texto: ");

    //Inicio do LOOP
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //Caso o texto na posição s[i] seja um espaço em branco, word++
        if (s[i] == ' ')
        {
            word++;
        }

        //Caso o texto na posição s[i] seja um ponto final, interrogação ou exclamação, sentence++
        else if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentence++;
        }

        //Caso o texto na posição s[i] seja uma letra minuscula entra 'a' e 'z', letter++
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            letter++;
        }

        //Caso o texto na posição s[i] seja uma letra MAISCULA entra 'A' e 'Z', letter++
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            letter++;
        }

    }

    //Calcula a média de letras e sentenças por 100 palavras.
    float l = ((float) letter / word) * 100;
    float st = ((float) sentence / word) * 100;

    //índice Coleman-Liau
    int index = round(((0.0588 * l) - (0.296 * st) - 15.8));

    //Imprime o grau do texto
    //Se index < 1 o grau será "Antes da 1 Série"
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    //Se index >= 16 o grau será "Serie 16+"
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {

    //Se não for nenhum dos anterior a série será o numero de index. "Grade , index"
        printf("Grade %i\n", index);
    }
}