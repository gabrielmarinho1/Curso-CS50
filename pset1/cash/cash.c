#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // variáveis que representam, respectivamente: o troco  inserido, a quatidade de moedas utilizadas, a moeda de 1 centavo,
    //a moeda de 5 centavos, a moeda de 10 centavos e a moeda de 25 centavos

    float reais;
    int moedas;
    int penny = 1;
    int nickel = 5;
    int dime = 10;
    int quarter = 25;

    //função que irá repetir a requisição do troco enquanto o valor inserido não corresponder a um número maior que 0.

    do
    {
        reais = get_float("Quanto de troco? ");
    }
    while (reais < 0);

    //função para converter o valor do troco de reais para centavos

    int centavos = round(reais * 100);

    //funções que irão contar quantas moedas são necessárias para dar o troco

    //moedas de 25 centavos

    for (moedas = 0; centavos - quarter >= 0; moedas++)
    {
        centavos = centavos - quarter;
    }

    //moedas de 10 centavos

    for (; centavos - dime >= 0; moedas++)
    {
        centavos = centavos - dime;
    }

    //moedas de 5 centavos

    for (; centavos - nickel >= 0; moedas++)
    {
        centavos = centavos - nickel;
    }

    //moedas de 1 centavo

    for (; centavos - penny >= 0; moedas++)
    {
        centavos = centavos - penny;
    }

    //função que imprime a quantidade de moedas necessárias

    printf("%i moedas\n", moedas);

    //teste github

}
