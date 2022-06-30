#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long num_cartao;
    long number;
    int soma = 0;
    int dobro;
    int dobro2;
    int num_digitos;
    bool validade;
    bool tipo;

    //função que irá repetir a requisição do número do cartão enquanto o valor inserido tiver menos de 13 dígitos, 14 dígitos ou mais de 16 dígitos

    do
    {
        num_cartao = get_long("Insira o número do cartão: ");
        number = num_cartao;

        //função que irá checar quantos dígitos tem o valor inserido no número do cartão

        for (num_digitos = 0; number != 0; num_digitos++)
        {
            number /= 10;
        }

        //função que irá imprimir "INVÁLIDO" e encerra caso o número do cartão inserido não tiver uma quantidade de dígitos aceita

        if (num_digitos < 13 || num_digitos > 16 || num_digitos == 14)
        {
            printf("INVALID\n");
            return 0;
        }
        
    }
    while (num_digitos < 13 || num_digitos > 16 || num_digitos == 14);

    //aqui, o número do cartão é copiado para as variáveis number2, number3 e number4
    long number2 = num_cartao;
    long number3 = num_cartao;
    long number4 = num_cartao;
    
    //esta função irá realizar a primeira parte do Algoritmo de Luhn
    while (number2 >= 1)
    {
        //elimina o último dígito do número
        number2 /= 10;
        
        //coleta o dobro do penúltimo dígito do número e armazena-o na variável "dobro"
        dobro = 2 * (number2 % 10);
        
        // elimina o dígito que foi coletado anteriormente
        number2 /= 10;
        
        //nesta função, se o dobro do dígito coletado for maior ou igual a 10, os dígitos desse número serão somados
        //e só então, o resultado dessa soma será acrescentado à variável "soma"
        if (dobro >= 10)
        {
            dobro2 = dobro % 10;
            dobro2 += ((dobro / 10) % 10);
            soma += dobro2;
        }
        
        //caso o dobro do dígito coletado for menor que 10, esse será adicionado diretamente à variável "soma"
        else
        {
            soma += dobro;
        }

    }
    
    //aqui será realizada a segunda parte do Algoritmo de Luhn
    while (number3 >= 1)
    {
        //o último dígito é adicionado à variável "soma"
        soma += number3 % 10;
        
        //o dígito coletado e o dígito imediatamente à sua esquerda são eliminados
        number3 /= 100;
    }
    
    //aqui, se a soma final do Algoritmo de Luhn terminar com 0, então o número do cartão será válido
    if (soma % 10 == 0)
    {
        validade = true;
    }
    
    //se não, será inválido
    else
    {
        validade = false;
    }
    
    //aqui, se o número do cartao tiver 13 dígitos e começar com 4, imprimirá "VISA"
    if (validade == true && num_digitos == 13)
    {
        number4 /= 1000000000000;
        number4 = number4 % 10;
        if (number4 == 4)
        {
            printf("VISA\n");
            tipo = true;
        }
        
        //se não, o cartão não é VISA
        else
        {
            tipo = false;
        }
    }
    
    //aqui, se o cartão tiver 15 dígitos e começar com 34 ou 37, imprimirá "AMERICAN EXPRESS"
    if (validade == true && num_digitos == 15)
    {
        number4 /= 10000000000000;
        number4 = number4 % 100;
        if (number4 == 34 || number4 == 37)
        {
            printf("AMEX\n");
            
            tipo = true;
        }
        
        //se não, o cartão não é AMERICAN EXPRESS
        else
        {
            tipo = false;
        }
    }
    
    //aqui, se o cartão tiver 16 dígitos e :
    if (validade == true && num_digitos == 16)
    {
        number4 /= 100000000000000;
        number4 = number4 % 100;
        
        //começar com 51, 52 ,53, 54 ou 55, imprimirá "MASTERCARD"
        if (number4 == 51 || number4 == 52 || number4 == 53 || number4 == 54 || number4 == 55)
        {
            printf("MASTERCARD\n");
            tipo = true;
        }
        
        //caso não for MASTERCARD, mas...
        else
        {
            number4 /= 10;
            number4 = number4 % 10;
            
            //começar com 4, imprimirá "VISA"
            if (number4 == 4)
            {
                printf("VISA\n");
                tipo = true;
            }
            
            //se não, o cartão não é nem MASTERCARD e nem VISA
            else
            {
                tipo = false;
            }
        
        }
    }
    
    //se o cartão não for AMERICAN EXPRESS, MASTERCARD ou VISA, imprimirá "INVÁLIDO" e encerra
    if (tipo == false)
    {
        printf("INVALID\n");
        return 0;
    }

}
