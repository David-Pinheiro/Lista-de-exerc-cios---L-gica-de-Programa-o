#include<stdio.h>
#include<locale.h>

main()
{

setlocale(LC_ALL, "");

int escolha;

do
{

printf("\n\nMENU: \n0 - Sair; \n1 - Exercício 1; \n2 - Exercício 2; \n3 - Exercício 3; \n4 - Exercício 4. \n\n Escolha uma opção: \n");
scanf("%i", &escolha);


switch(escolha)
{
case 0:
    {
    exit(0);
    }
case 1:

    {
    printf("1. Exiba os números de 1 até 50 na tela. Use apenas o laço while.\n");

    int num=1;

    while(num<50)
    {
        printf("%i, ", num);
        num++;
    }
    if(num==50)
    {
        printf("\b e %i.", num);
    }
    }
    break;

case 2:
    {
        printf("2.	Exiba todos os números pares entre 1 e 100. Use apenas o laço do while.\n");

        int num=2;

        do
        {
            printf("%i ,", num);
            num += 2;
        }
        while(num<100);

        if(num==100)
        {
           printf("\b e %i", num);
        }
    }

    break;

case 3:
    {
        printf("3. Calcule e exiba a média dos números múltiplos de 5 entre os números 1 e 200. Use apenas o laço while.\n\n");

        int num=5, cont=1, media;

        while(num<200)
        {
            num += 5;
            cont++;
        }

        media=num/cont;

        printf("Números múltiplos de 5 encontrados no intervalo: %i \nEstá é a média dos números: %i\n", cont, media);
    }
    break;

case 4:
    {
        printf("4. Calcule e exiba o resultado da multiplicação apenas dos números pares e múltiplos de 5 entre os números -200 e 200. Use apenas o laço do while.\n");

        int num=-200;
        long long int multi=1;

        while(num<200)
        {
            printf("%i * %i, ", multi, num);
            multi=multi*num;
            num += 10;
        }
    }

    default:
            printf("\nOpção inválida. Selecione uma opção de 0 a 4\n");
            break;

}
}
while(escolha != 0);
}
