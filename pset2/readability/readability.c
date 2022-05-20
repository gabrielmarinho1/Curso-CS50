#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //variáveis dos números de palavras(que já começa com no mínimo 1), sentenças e letras do texto
    int palavras = 1, sentenças = 0, letras = 0;
    
    //função para pegar o texto que o usuário quer testar
    string texto = get_string("Texto: ");
    
    //variável que contém o tamanho do texto
    int n = strlen(texto);
    
    //função para contar a quantidade de letras do texto
    for (int i = 0; i < n; i++)
    {
        //se o caractere for uma letra minúscula de a a z ou maiúscula de A a Z, acrescenta-se 1 letra
        if (isalpha(texto[i]))
        {
            letras++;
        }
    }
    
    //função para contar a quantidade de palavras do texto
    for (int i = 0; i < n; i++)
    {
        //a cada espaço em branco, uma palavra é adicionada
        if (isspace(texto[i]))
        {
            palavras++;
        }
    }
    
    //função para contar a quantidade de sentenças do texto
    for (int i = 0; i < n; i++)
    {
        //se o caractere for um "!", uma sentença é adicionada;
        if (texto[i] == '!')
        {
            sentenças++;
        }
        
        //se o caractere for um ".", uma sentença também é adicionada;
        else if (texto[i] == '.')
        {
            sentenças++;
        }
        
        //se o caractere for um "?", uma sentença também é adicionada.
        else if (texto[i] == '?')
        {
            sentenças++;
        }
    }
    
    //média de letras por 100 palavras
    float l = (float) letras / (float) palavras * 100;
    
    //média de sentenças por 100 palavras
    float s = (float) sentenças / (float) palavras * 100;
    
    //fórmula do índice Coleman-Liau (com o resultado arredondado para o inteiro mais próximo)
    float indice = (int) round(0.0588 * l - 0.296 * s - 15.8);
    
    //se o índice for menor que 1, imprime-se "Before Grade 1"
    if (indice < 1)
    {
        printf("Before Grade 1\n");
    }
    
    //se o índice for igual a 2, imprime-se "Grade 2"
    else if (indice == 2)
    {
        printf("Grade 2\n");
    }
    
    //se o índice for igual a 3, imprime-se "Grade 3"
    else if (indice == 3)
    {
        printf("Grade 3\n");
    }
    
    //se o índice for igual a 4, imprime-se "Grade 4"
    else if (indice == 4)
    {
        printf("Grade 4\n");
    }
    
    //se o índice for igual a 5, imprime-se "Grade 5"
    else if (indice == 5)
    {
        printf("Grade 5\n");
    }
    
    //se o índice for igual a 6, imprime-se "Grade 6"
    else if (indice == 6)
    {
        printf("Grade 6\n");
    }
    
    //se o índice for igual a 7, imprime-se "Grade 7"
    else if (indice == 7)
    {
        printf("Grade 7\n");
    }
    
    //se o índice for igual a 8, imprime-se "Grade 8"
    else if (indice == 8)
    {
        printf("Grade 8\n");
    }
    
    //se o índice for igual a 9, imprime-se "Grade 9"
    else if (indice == 9)
    {
        printf("Grade 9\n");
    }
    
    //se o índice for igual a 10, imprime-se "Grade 10"
    else if (indice == 10)
    {
        printf("Grade 10\n");
    }
    
    //se o índice for igual a 11, imprime-se "Grade 11"
    else if (indice == 11)
    {
        printf("Grade 11\n");
    }
    
    //se o índice for igual a 12, imprime-se "Grade 12"
    else if (indice == 12)
    {
        printf("Grade 12\n");
    }
    
    //se o índice for igual a 13, imprime-se "Grade 13"
    else if (indice == 13)
    {
        printf("Grade 13\n");
    }
    
    //se o índice for igual a 14, imprime-se "Grade 14"
    else if (indice == 14)
    {
        printf("Grade 14\n");
    }
    
    //se o índice for igual a 15, imprime-se "Grade 15"
    else if (indice == 15)
    {
        printf("Grade 15\n");
    }
    
    //se o índice for maior ou igual a 16, imprime-se "Grade 16+"
    else if (indice >= 16)
    {
        printf("Grade 16+\n");
    }
}
