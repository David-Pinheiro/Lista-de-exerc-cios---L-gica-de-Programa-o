#include "stdio.h"
#include "locale.h"

#define ex5

#ifdef ex1

/*
1 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
    que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
    mostrado na funcao main().
    Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.
*/

int soma_fatorial(int numero);
int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");

    int numero, resultado, opcao;

    do
    {

        printf("\nDigite um número qualquer: ");
        scanf("%d", &numero);

        resultado= soma_fatorial(numero);

        printf("\n O número digitado é %d, a soma dos algarimos do fatorial é %d", numero, resultado);

        opcao= reiniciar(reiniciar);

    }
    while(opcao==1);

}

int soma_fatorial(int numero)
{
    int fatorial=1, acumulador=0, cont;

    for(cont=1; cont<=numero; cont++)
    {
        fatorial= fatorial*cont;
    }

    for(;;)
    {
        acumulador+=(fatorial%10);
        fatorial=fatorial/10;

        if(fatorial<=0)
        {
            break;
        }
    }

    return acumulador;
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar(1 para sim/2 para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex1

#ifdef ex2

/*
2 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
    funçoes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.
*/

int verificar_sinal(int numero);
int operacao_positivos (int numero1, int numero2);
int operacao_negativos(int numero1, int numero2);
int operacao_neg_pos(int numero1, int numero2);
int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");

    int numero1, numero2, sinal1, sinal2, resultado, opcao;

    do
    {

        printf("\nDigite o primeiro número: ");
        scanf("%d", &numero1);

        sinal1= verificar_sinal(numero1);

        printf("\nDigite o segundo número: ");
        scanf("%d", &numero2);

        sinal2= verificar_sinal(numero2);

        if(sinal1 == 1 && sinal2 == 1)
        {
            resultado= operacao_positivos(numero1, numero2);
        }
        if(sinal1 == 0 && sinal2 == 0)
        {
            resultado= operacao_negativos(numero1, numero2);
        }
        if(sinal1 == 1 && sinal2 == 0 || sinal1 == 0 && sinal2 == 1)
        {
            resultado= operacao_neg_pos(numero1, numero2);
        }

        printf("\nResultado: %d", resultado);

        opcao= reiniciar(reiniciar);

    }
    while(opcao==1);

}

int verificar_sinal(int numero)
{
    if(numero>0)
    {
        return 1;
    }

    if(numero<0)
    {
        return 0;
    }

    if(numero==0)
    {
        return -1;
    }
}

int operacao_positivos(int numero1, int numero2)
{
    int resultado=0, cont;

    if(numero1 > numero2)
    {
        numero2++;

        for(cont=numero2; cont<numero1; cont++)
        {
            resultado+=cont;
        }

        return resultado;
    }

    else
    {
        numero1++;

        for(cont=numero1; cont<numero2; cont++)
        {
            resultado+=cont;
        }

        return resultado;

    }
}

int operacao_negativos(int numero1, int numero2)
{
    int resultado=1, cont;

    if(numero1 > numero2)
    {
        for(cont=numero2+1; cont<numero1; cont++)
        {
            resultado*=cont;
        }

        return resultado;
    }

    else
    {


        for(cont=numero1+1; cont<numero2; cont++)
        {
            resultado*=cont;
        }

        return resultado;

    }
}

operacao_neg_pos(int numero1, int numero2)
{
    int resultado;

    resultado = numero1 / numero2;

    return resultado;
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar(1 para sim/2 para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex2

#ifdef ex3

/*
3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima os 4 resultados no video na funcao main().
*/


float soma (float valor1, float valor2);
float subtracao (float valor1, float valor2);
float divisao (float valor1, float valor2);
float multiplicacao (float valor1, float valor2);
int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");
    int opcao;
    float valor1, valor2;

    do
    {

        printf("\nDigite dois valores inteiros: \n\tValor 1: ");
        scanf("%f", &valor1);
        printf("\n\tValor 2: ");
        scanf("%f", &valor2);

        printf("\nForam digitados os valores %g e %g, estes são os resultados \n\tSoma: %g \n\tSubtração: %g \n\tDivisão: %g \n\tMultiplicação: %g\n", valor1, valor2, soma(valor1, valor2), subtracao(valor1, valor2), divisao(valor1, valor2), multiplicacao(valor1, valor2));

        opcao= reiniciar(reiniciar);

    }
    while(opcao==1);
}

float soma (float valor1, float valor2)
{
    return valor1+valor2;
}

float subtracao (float valor1, float valor2)
{
    return valor1-valor2;
}

float divisao (float valor1, float valor2)
{
    if(valor1 == 0 || valor2 == 0)
    {
        return 0;
    }
    else
    {
        return valor1/valor2;
    }
}

float multiplicacao (float valor1, float valor2)
{
    return valor1*valor2;
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar(1 para sim/2 para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex3

#ifdef ex4

/*
4 - Reescreva o programa do exercicio anterior para receber via teclado n
    valores. Os n valores nao sao definidos previamente.
*/

float soma (float valor1, float valor2);
float sub (float valor1, float valor2);
float mult (float valor1, float valor2);
float div (float valor1, float valor2);

int main()
{
    setlocale(LC_ALL, "");
    int dec;
    float valor1, valor2, adc, rem, vez, divi;

    printf("\nDigite os valores:\n");
    printf("Valor 1: ");
    scanf("%f",&valor1);
    adc = rem = vez = divi = valor1;

    printf("Valor 2: ");
    scanf("%f",&valor2);

    do
    {
        adc = soma(adc, valor2);
        rem = sub(rem, valor2);
        vez = mult(vez, valor2);
        divi = div(divi, valor2);

        printf("\nAs operações:\nSoma: %g\nSubtração: %g\nMultiplicação: %g\nDivisão: %g\n", adc, rem, vez, divi);
        printf("\nDeseja continuar?(Digite 0 para finalizar ou qualquer outro numero para uma nova operação) \nResposta: ");
        scanf("%f",&valor2);
    }
    while(valor2 != 0);
}

float soma(float valor1, float valor2)
{
    return valor1+valor2;
}

float sub(float valor1, float valor2)
{
    return valor1-valor2;
}

float mult(float n1, float n2)
{
    return n1*n2;
}

float div(float n1, float n2)
{
    if(n1 == 0 || n2 == 0)
    {
        return 0;
    }
    else
    {
        return n1/n2;
    }
}

#endif // ex4

#ifdef ex5

/*
5 - Escreva um programa que receba n valores inteiros via teclado na funcao main().
    Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
    As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser
    mostrado na funcao main().
*/

float adicao(float n1, float n2);
float subtracao(float n1, float n2);
float multiplicacao(float n1, float n2);
float divisao(float n1, float n2);

int main()
{
    setlocale(LC_ALL, "");
    char ope;
    float adc=0, n1, n2, result=0;

        printf("----------------------------------------------------------------------\n");
        printf("\nDigite + para adição;");
        printf("\nDigite - para subtração;");
        printf("\nDigite * para multiplicação;");
        printf("\nDigite / para divisão.");
        printf("\nDigite = para sair.");
        printf("\n----------------------------------------------------------------------\n\n");
        printf("Digite a opção desejada: ");
        scanf("%c",&ope);

    if(ope != '=')
    {
        printf("Digite dois numeros:");
        printf("\nNumero 1: ");
        scanf("%f",&n1);
        printf("Numero 2: ");
        scanf("%f",&n2);

        switch(ope)
        {
        case '+':
            adc = adicao(n1, n2);
            break;
        case'-':
            adc = subtracao(n1, n2);
            break;
        case '*':
            adc = multiplicacao(n1, n2);
            break;
        case '/':
            adc = divisao(n1, n2);
            break;
        }
        result+=adc;
    }

    if(ope != '=')
    {
        do
        {
                printf("----------------------------------------------------------------------\n");
                printf("\nDigite + para adição;");
                printf("\nDigite = para subtração;");
                printf("\nDigite * para multiplicação;");
                printf("\nDigite / para divisão.");
                printf("\n----------------------------------------------------------------------\n\n");
                printf("Digite a operação que deseja fazer(digite \"0\" para sair): ");
                scanf("%c",&ope);

            if(ope != '=')
            {
                printf("Digite o numero: ");
                scanf("%f",&n1);

                switch(ope)
                {
                case '+':
                    adc = adicao(result, n1);
                    break;
                case '-':
                    adc = subtracao(result, n1);
                    break;
                case '*':
                    adc = multiplicacao(result, n1);
                    break;
                case '/':
                    adc = divisao(result, n1);
                    break;
                }
                result = adc;
            }
        }
        while(ope != '=');
    }
    if(result == 0)
    {
        printf("Não houveram operações aritiméticas.");
    }
    else
    {
        printf("O resultado das operações foi: %g", result);
    }
}

float adicao(float n1, float n2)
{
    return n1+n2;
}

float subtracao(float n1, float n2)
{
    return n1-n2;
}

float multiplicacao(float n1, float n2)
{
    return n1*n2;
}

float divisao(float n1, float n2)
{
    if(n1 == 0 || n2 == 0)
    {
        return 0;
    }
    else
    {
        return n1/n2;
    }
}
#endif // ex5
