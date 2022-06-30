#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //array que contém os valores dos pontos que cada letra do alfabeto vale(em ordem alfabética).
    int pontos[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    
    //string que irá armazenar a(s) palavra(s) do jogador 1.
    string player1 = get_string("Player 1: ");
    
    //variável que irá armazenar a quantidade de pontos que o jogador 1 fizer.
    int points1 = 0;
   
    //string que irá armazenar a(s) palavra(s) do jogador 2.
    string player2 = get_string("Player 2: ");
    
    //variável que irá armazenar a quantidade de pontos que o jogador 2 fizer.
    int points2 = 0;
    
    //função que irá contar os pontos do jogador 1.
    for (int i = 0; i < strlen(player1); i++)
    {
        //se o caractere for maiúsculo,
        if (isupper(player1[i]))
        {
            //encontra-se a sua posição no alfabeto, e
            int p = (int) player1[i] - 65;
            
            //adiciona-se a quantidade de pontos correspondente.
            points1 += pontos[p];
        }
        
        //se o caractere for minúsculo,
        if (islower(player1[i]))
        {
            //encontra-se a sua posição no alfabeto, e
            int p = (int) player1[i] - 97;
            
            //adiciona-se a quantidade de pontos correspondente.
            points1 += pontos[p];
        }
    }
    
    //função que irá contar a quantidade de pontos do jogador 2
    for (int i = 0; i < strlen(player2); i++)
    {
        //se o caractere for maiúsculo,
        if (isupper(player2[i]))
        {
            //encontra-se a sua posição no alfabeto, e
            int p = (int) player2[i] - 65;
            
            //adiciona-se a quantidade de pontos correspondente.
            points2 += pontos[p];
        }
        
        //se o caractere for minúsculo,
        if (islower(player2[i]))
        {
            //encontra-se a sua posição no alfabeto, e
            int p = (int) player2[i] - 97;
            
            //adiciona-se a quantidade de pontos correspondente.
            points2 += pontos[p];
        }
    }
    
    //se a quantidade de pontos do jogador 1 for maior que a do jogador 2,
    if (points1 > points2)
    {
        //imprime-se "Player 1 wins!".
        printf("Player 1 wins!\n");
    }
    
    //se a quantidade de pontos do jogador 2 for maior que a do jogador 1,
    if (points1 < points2)
    {
        //imprime-se "Player 2 wins!".
        printf("Player 2 wins!\n");
    }
    
    //se a quantidade de pontos dos dois jogadores forem iguais,
    if (points1 == points2)
    {
        //imprime-se "Tie!".
        printf("Tie!\n");
    }
}
