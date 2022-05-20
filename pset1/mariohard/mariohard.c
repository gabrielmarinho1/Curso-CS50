#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //variável referente à altura (a) que será inserida pelo usuário.

    int altura;

    // função que irá repetir a requisição da altura enquanto o valor inserido não corresponder a um número inteiro de 1 a 8.

    do
    {
        altura = get_int("Altura da pirâmide: ");
    }

    while (altura < 1 || altura > 8);

    //função que construirá a pirâmide em si, onde v= número de linhas na vertical, h= número de caracteres da horizontal e
    //e= número de espaços em cada linha.

    for (int vertical = 0; vertical < altura; vertical++)
    {
        //função que irá imprimir os espaços em cada linha da pirâmide

        for (int espaços = 0; espaços < altura - vertical - 1; espaços++)
        {
            printf(" ");
        }

        //função que irá imprimir as hashes # em cada linha da pirâmide alinhada à direita

        for (int horizontal = 0; horizontal <=vertical; horizontal++)
        {
        printf("#");
        }

        // função para imprimir os espaços entre as duas pirâmides

        printf("  ");

        //função que irá imprimir as hashes # em cada linha da pirâmide alinhada à esquerda

        for (int horizontal = 0; horizontal <=vertical; horizontal++)
        {
        printf("#");
        }

        //função que irá adicionar uma nova linha a cada loop

        printf("\n");
    }
}
// A primeira coisa feita no código foi definir como pegar o input do usuário para definir a altura da pirâmide,
//sendo que teria que ser um número maior ou igual a 1 e menor ou igual a 8 e, caso não fosse um deles, a requisição "Altura da pirâmide: "
//se repetiria até que um valor permitido fosse inserido.

//Depois de determinada a altura da pirâmide, ela então será contruída com a sequência de loops seguintes. Os espaços vêm antes
//das hashes, então a função que os imprime vem primeiro, mas ainda dentro da função que quebra as linhas na vertical.

//A relação entre espaços e a altura da pirâmide é que o número de espaços = altura - o número da linha na vertical - 1. Então, numa
//pirâmide de altura 3, temos:

//1º loop:  a=8
//          v=0                     |.......#|
//          e= 8-0-1 => 7 espaços

//2º loop:  a=8
//          v=1                     |......##|
//          e= 8-1-1 => 6 espaços

//3º loop:  a=8
//          v=2                     |.....###|
//          e= 8-2-1 => 5 espaços                .

// A segunda pirâmide funciona do mesmo jeito, só que sem os espaços.

//Depois de imprimir os espaços e hashes certos, uma nova linha é criada com o printf("\n"); e o loop se repete até
//que se alcance a altura certa.
