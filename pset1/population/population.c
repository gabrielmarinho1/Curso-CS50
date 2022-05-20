#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Declaração das variáveis, respectivamente: da quantidade inicial de lhamas, da quantidade final de lhamas e a quantidade de anos necessários.
    int lhamas;
    int lhamasFinal;
    int anos;

    //Função que irá repetir a requisição da quantidade inicial de lhamas enquanto o valor inserido for menor que 9.
    do
    {
        lhamas = get_int("Quantidade inicial de Lhamas: ");
    }
    while (lhamas < 9);

    //Função que irá repetir a requisição da quantidade final de lhamas enquanto o valor inserido for menor que a quantidade inicial.
    do
    {
        lhamasFinal = get_int("Quantidade final de Lhamas: ");
    }
    while (lhamasFinal < lhamas);
    
    if (lhamasFinal == lhamas)
    {
        printf("Years: 0\n");
        return 0;
    }

    //Aqui, o número de lhamas ganha um terço e perde um quarto até que alcance no número final. A cada loop, um ano é acrescentado.
    for (anos = 0; lhamas < lhamasFinal; anos++)
    {
        lhamas = lhamas + (lhamas / 3) - (lhamas / 4);
    }

    //se o número de anos for igual a 1, imprime-se "... ano"
    if (anos == 1)
    {
        printf("Years: " "%d\n", anos);
    }
    //se o número de anos for diferente de 1 (consequentemente maior, já que a população de lhamas apenas cresce), imprime-se "... anos"
    else
    {
        printf("Years: " "%d\n", anos);
    }

}
