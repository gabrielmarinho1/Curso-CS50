#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//função main onde a linha de comando vai receber ./substitution + a chave, onde: k = quantidade de argumentos e
//key é a string que vai armazenar esses argumentos.
//key[0] = ./substitution e key[1] = chave que será inserida.
int main(int k, string key[])
{
    //se o número de argumentos não for 2,
    if (k != 2)
    {
        //imprime-se a mensagem de erro "Use: ./substitution KEY" e o programa encerra.
        printf("Use: ./substitution KEY\n");
        
        return 1;
    }
    //se a quantidade de caracteres inseridos para a chave não for 26
    else if (strlen(key[1]) != 26)
    {
        //imprime-se a mensagem de erro "A CHAVE DEVE CONTER 26 CARACTERES" e o programa encerra.
        printf("A CHAVE DEVE CONTER 26 CARACTERES\n");
        
        return 1;
    }
    
    //string que receberá a chave inserida para ser utilizada.
    string chave = key[1];
    
    //função que irá validar ou não a chave.
    for (int i = 0; i < strlen(chave); i++)
    {
        //variável que armazenará a quantidade de vezes que uma letra aparece na chave.
        int count = 0;
        
        //se o caractere em questão da chave for uma letra do alfabeto, será executada a +
        if (isalpha(chave[i]))
        {
            //função que irá checar se o caractere em questão aparece mais de uma vez na chave.
            for (int h = 0; h < strlen(chave); h++)
            {
                //se o caractere for igual a outro na chave,
                if (chave[i] == chave[h])
                {
                    //conta-se mais um. 
                    count++;
                }
                
                //Numa chave válida, cada caractere aparece apenas uma vez, então,
                
                //se o caractere for contado mais de uma vez,
                if (count > 1)
                {
                    //imprime-se a mensagem de erro "A CHAVE NÃO DEVE TER CARACTERES REPETIDOS" e o programa encerra.
                    printf("A CHAVE NÃO DEVE TER CARACTERES REPETIDOS\n");
                    
                    return 1;
                }
            }
        }
        
        // caso o caractere não for uma letra do alfabeto,
        else
        {
            //imprime-se a mensagem de erro "A CHAVE DEVE CONTER APENAS LETRAS DO ALFABETO" e o programa encerra
            printf("A CHAVE DEVE CONTER APENAS LETRAS DO ALFABETO\n");
            
            return 1;
        }
    }
    
    //string que vai coletar o texto simples.
    string texto = get_string("Texto Simples: ");
    
    //imprime-se "Texto Cifrado: ".
    printf("ciphertext: ");
    
    //função que irá criptografar o texto simples, um caractere por vez.
    for (int j = 0; j < strlen(texto); j++)
    {
        //se o caractere for uma letra maiúscula,
        if (isupper(texto[j]))
        {
            //determina-se a sua posição no alfabeto e
            int l = (int) texto[j] - 65;
            
            //imprime-se a letra da chave correspondente à sua posição em maiúsculo.
            printf("%c", toupper(chave[l]));
        }
        
        //se for uma letra minúscula,
        else if (islower(texto[j]))
        {
            //determina-se a sua posição no alfabeto e
            int l = (int) texto[j] - 97;
            
            //imprime-se a letra da chave correspondente à sua posição em minúsculo.
            printf("%c", tolower(chave[l]));
        }
        
        //se o caractere for um espaço,
        else if (isspace(texto[j]))
        {
            //imprime-se um espaço.
            printf(" ");
        }
        
        //se o caractere for uma pontuação,
        else if (ispunct(texto[j]))
        {
            //imprime-se o mesmo caractere.
            printf("%c", texto[j]);
        }
        
        //se o caractere for um número,
        else if (isalnum(texto[j]))
        {
            //imprime-se o mesmo caractere.
            printf("%c", texto[j]);
        }
    }
    
    //imprime-se uma nova linha.
    printf("\n");
}
