#include<stdio.h>
#include<locale.h>

main()
{

setlocale(LC_ALL, "");

int escolha;

do
{

printf("\n\nMENU: \n0 - Sair; \n1 - Exerc�cio 1; \n2 - Exerc�cio 2; \n3 - Exerc�cio 3; \n4 - Exerc�cio 4. \n\n Escolha uma op��o: \n");
scanf("%i", &escolha);


switch(escolha)
{
case 0:
    {
    exit(0);
    }
case 1:

    {
    printf("1. Exiba os n�meros de 1 at� 50 na tela. Use apenas o la�o while.\n");

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
        printf("2.	Exiba todos os n�meros pares entre 1 e 100. Use apenas o la�o do while.\n");

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
        printf("3. Calcule e exiba a m�dia dos n�meros m�ltiplos de 5 entre os n�meros 1 e 200. Use apenas o la�o while.\n\n");

        int num=5, cont=1, media;

        while(num<200)
        {
            num += 5;
            cont++;
        }

        media=num/cont;

        printf("N�meros m�ltiplos de 5 encontrados no intervalo: %i \nEst� � a m�dia dos n�meros: %i\n", cont, media);
    }
    break;

case 4:
    {
        printf("4. Calcule e exiba o resultado da multiplica��o apenas dos n�meros pares e m�ltiplos de 5 entre os n�meros -200 e 200. Use apenas o la�o do while.\n");

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
            printf("\nOp��o inv�lida. Selecione uma op��o de 0 a 4\n");
            break;

}
}
while(escolha != 0);
}
