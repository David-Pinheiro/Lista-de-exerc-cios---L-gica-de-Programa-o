#include "stdio.h"
#include "locale.h"

#define ex1

/*
1 - Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas.
*/

#ifdef ex1

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");
    int num1, num2, soma, subtracao, multi, opcao;
    float divisao;

    do
    {
        printf("\nInsira dois valores quaisquer:");
        printf("\nValor 1: ");
        scanf("%d", &num1);
        printf("\nValor 2: ");
        scanf("%d", &num2);

        soma= num1 + num2;
        subtracao= num1 - num2;
        divisao= (float) num1/num2;
        multi= num1*num2;

        printf("\nEstes são os resultados:\n\tSoma: %d\n\tSubtração: %d\n\tDivisão: %g\n\tMultiplicação: %d", soma, subtracao, divisao, multi);

        opcao= reiniciar(reiniciar);
    }
    while(opcao==1);
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar('1' para sim / '2' para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex1

/*
2 - Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.
*/

#ifdef ex2

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");
    int num1, num2, soma, subtracao, multi, opcao;
    float divisao;

    do
    {
        printf("\nInsira dois valores quaisquer:");
        printf("\nValor 1: ");
        scanf("%d", &num1);
        soma= num1;
        subtracao= num1;
        divisao= (float) num1;
        multi= num1;

        printf("\nValor 2: ");
        scanf("%d", &num2);

        soma+= num2;
        subtracao-= num2;
        divisao/= (float) num2;
        multi*= num2;

        printf("\nEstes são os resultados:\n\tSoma: %d \n\tSubtração: %d \n\tDivisão: %g \n\tMultiplicação: %d", soma, subtracao, divisao, multi);

        opcao= reiniciar(reiniciar);
    }
    while(opcao==1);
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar('1' para sim / '2' para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex2

/*
3 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.
*/

#ifdef ex3

int reiniciar(int opcao);

int main()
{
    setlocale(LC_ALL, "");
    int dian, mesn, anon, diaa, mesa, anoa, opcao;
    int cont, anob = 0, dias, mes, anos;
    do
    {
        printf("\nDigite sua data de nascimento:");
        do
        {
            printf("\n\tDia: ");
            scanf("%d", &dian);
        }
        while (dian > 31);
        do
        {
            printf("\n\tMês: ");
            scanf("%d", &mesn);
        }
        while (mesn > 12);
        printf("\n\tAno: ");
        scanf("%d", &anon);

        printf("\nDigite a data atual:");
        do
        {
            printf("\n\tDia: ");
            scanf("%d", &diaa);
        }
        while (diaa > 31);
        do
        {
            printf("\n\tMês: ");
            scanf("%d", &mesa);
        }
        while (mesa > 12);
        printf("\n\tAno: ");
        scanf("%d", &anoa);

        //**********ANOS
        anos = anoa - anon;

        //**********MESES
        if (mesa < mesn || (mesa == mesn && diaa < dian))
        {
            anos--;
            mes = 12 - mesn + mesa;
        }
        else
        {
            mes = mesa - mesn;
        }

        //**********DIAS
        if (diaa < dian)
        {
            mes--;
            if (mesn == 2 && ((anoa % 4 == 0 && anoa % 100 != 0) || (anoa % 400 == 0)))
            {
                dias = 29 - dian + diaa;
            }
            else if (mesn == 2)
            {
                dias = 28 - dian + diaa;
            }
            else if (mesn == 4 || mesn == 6 || mesn == 9 || mesn == 11)
            {
                dias = 30 - dian + diaa;
            }
            else
            {
                dias = 31 - dian + diaa;
            }
        }
        else
        {
            if (mesn == 2 && ((anoa % 4 == 0 && anoa % 100 != 0) || (anoa % 400 == 0)))
            {
                dias = diaa - dian;
            }
            else if (mesn == 2)
            {
                dias = diaa - dian;
            }
            else if (mesn == 4 || mesn == 6 || mesn == 9 || mesn == 11)
            {
                dias = diaa - dian;
            }
            else
            {
                dias = diaa - dian;
            }
        }

        if (dias == 0 && mes == 0)
        {
            printf("Você tem %d anos.\n", anos);
        }
        else if (dias == 0)
        {
            printf("Você tem %d meses e %d anos.\n", mes, anos);
        }
        else if (mes == 0)
        {
            printf("Você tem %d dias e %d anos.\n", dias, anos);
        }
        else
        {
            printf("Você tem %d dias, %d meses e %d anos.\n", dias, mes, anos);
        }

        opcao = reiniciar(opcao);
    }
    while (opcao == 1);

    return 0;
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar ('1' para sim / '2' para não)? \nResposta: ");
    scanf("%d", &opcao);

    while (opcao != 1 && opcao != 2)
    {
        printf("\nOpção inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex3

/*
4 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
    Determine o dia da semana desta data.
*/

#ifdef ex4

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");
    int opcao, dia, mes, ano, semana, k, j;

    do
    {
        printf("\n*******PROGRAMA PARA INFORMAR O DIA DA SEMANA DE UMA DATA*******");
        printf("\nInforme a data desejada:\n\tdia: ");
        scanf("%d", &dia);
        printf("\n\tmês: ");
        scanf("%d", &mes);
        printf("\n\tano: ");
        scanf("%d", &ano);

        if(mes<=2)
        {
            mes+=12;
            ano--;
        }

        semana= (dia+ ((13*(mes+1))/5)+ano+(ano/4)-(ano/100)+(ano/400))%7; // Fórmula de Congruência de Zeller

        printf("\n%d/%d/%d -> ", dia, mes, ano);

        switch(semana)
        {
        case 0:
            printf("Sábado.");
            break;

        case 1:
            printf("Domingo.");
            break;

        case 2:
            printf("Segunda-feira.");
            break;

        case 3:
            printf("Terça-feira.");
            break;

        case 4:
            printf("Quarta-feira.");
            break;

        case 5:
            printf("Quinta-feira.");
            break;

        case 6:
            printf("Sexta-feira.");
            break;

        default:
            printf("\nOpção inválida");
        }

        opcao= reiniciar(reiniciar);
    }
    while(opcao==1);
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar('1' para sim / '2' para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex4

/*
5 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal.
*/

#ifdef ex5

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");
    int num1, num2, opcao;

    do
    {
        printf("\nDigite dos números inteiros quaisquer: ");
        printf("\n\tNúmero 1: ");
        scanf("%d", &num1);
        printf("\n\tNúmero 2: ");
        scanf("%d", &num2);

        printf("---------------------OPERACOES---------------------");
        printf("\n\nAND: Decimal: %3d  \nHexadecimal: 0x%x\n\n", num1&num2, num1&num2);
        printf("OU: Decimal: %3d  \nHexadecimal: 0x%x\n\n", num1|num2, num1|num2);
        printf("OU EXCLUSIVO: Decimal: %3d  \nHexadecimal: 0x%x", num1^num2, num1^num2);

        opcao= reiniciar(reiniciar);
    }
    while(opcao==1);
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar('1' para sim / '2' para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex5
