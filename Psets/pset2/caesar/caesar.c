#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//função main onde a linha de comando vai receber ./caesar + a chave, onde: k = quantidade de argumentos e key é a string que vai armazenar esses argumentos em que key[0] = ./caesar e key[1] = chave que será inserida
int main(int k, string key[])
{
    //se o número de argumentos não for 2 ou se a chave for menor ou igual a 0, uma mensagem de erro aparece e o programa retorna erro. 
    //obs: atoi(num_key[1] converte o valor inserido para a chave de string para int)
    if (k != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    //função que checa se os valores inseridos para a chave são apensas números
    for (int r = 0; r < strlen(key[1]); r++)
    {
        //se não forem, o programa imprime a mensagem de erro e encerra
        if (!isdigit(key[1][r]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    //variável que contém a chave inserida que foi convertida de string para int
    int chave = atoi(key[1]);
    
    //requisição do texto a ser criptografado
    string texto = get_string("Insira o texto: ");
    
    printf("ciphertext: ");
   
    //função que irá criptografar o texto inserido:
    for (int i = 0; i <= strlen(texto); i++)
    {
        //se o caractere for uma letra maiúscula;
        if (isupper(texto[i]))
        {
            printf("%c", (texto[i] - 65 + chave) % 26 + 65);
        }
        
        //se o caractere for uma letra minúscula e;
        else if (islower(texto[i]))
        {
            printf("%c", (texto[i] - 97 + chave) % 26 + 97);
        }
        
        //caso não seja uma letra nem maiúscula e nem minúscula, o caractere não é criptografado
        else
        {
            printf("%c", texto[i]);
        }
    }
    
    //uma nova linha é impressa
    printf("\n");
}
