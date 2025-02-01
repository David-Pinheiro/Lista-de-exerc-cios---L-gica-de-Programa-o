#include<stdio.h>
#include<locale.h>
#include<math.h>

main()
{
    setlocale(LC_ALL, "");

    int escolha;

    do
    {
        printf("MENU: \n0 - Sair; \n1 - Exercício 1; \n2 - Exercício 2; \n3 - Exercício 3; \n4 - Exercício 4. \n\nEscolha uma opção: ");
        scanf("%i", escolha);

        switch(escolha)
        {
        case 0:
        {
            exit (0);
        }

        case 1 :
        {
            printf("LISTA 4 - 1) Gere e exiba cada uma das sequências abaixo com uma quantidade k de termos determinados pelo usuario. \na) 3, 6, 9, 12, 15,... \n\n");
            int Quant,numero=0,contador=0;

            do
            {
                printf("Digite a quantidade de termos desejada\n");
                scanf("%i",&Quant);
                if(Quant<=0)
                {
                    printf("Quantidade Inválida\n");
                }
            }
            while(Quant<=0);

            do
            {
                numero=numero+3; /*  ou numero+=3; */
                contador=contador+1;/* ou contador++ ou contador+=1;*/
                if(contador!=Quant)
                {
                    printf("%d ,",numero);
                }
                else
                    printf("\be %d.",numero);
            }
            while(contador!=Quant);

        }

        break;

        case 2:
        {
            printf("LISTA 4 - 1) Gere e exiba cada uma das sequencias abaixo com uma quantidade k de termos determinados pelo usuario. \nb) 1/4, 1/8, 1/12, 1/16, 1/20,...\n\n");

            int Quant,numero=0,contador=0;

            do
            {
                printf("Digite a quantidade de termos desejada\n");
                scanf("%i",&Quant);
                if(Quant<=0)
                {
                    printf("Quantidade Inválida\n");
                }
            }
            while(Quant<=0);
            do
            {
                numero=numero+4; /*  ou numero+=3; */
                contador=contador+1;/* ou contador++ ou contador+=1;*/
                if(contador!=Quant)
                {
                    printf("1/%d ,",numero);
                }
                else
                    printf("\be 1/%d.",numero);
            }
            while(contador!=Quant);
        }

        break;

        case 3:
        {
            printf("LISTA 4 - 2)	Gere e exiba cada uma das sequências abaixo com uma quantidade k de termos determinados pelo usuário. \na)	2/5, 4/10, 6/15, 8/20, 10/25, 12/30,...");

            int Quant,numero1=0, numero2=0,contador=0;

            do
            {
                printf("Digite a quantidade de termos desejada\n");
                scanf("%i",&Quant);
                if(Quant<=0)
                {
                    printf("Quantidade Inválida\n");
                }
            }
            while(Quant<=0);
            do
            {
                numero1=numero1+2;
                numero2=numero2+5;
                contador=contador+1;
                if(contador!=Quant)
                {
                    printf("%i/%i ,",numero1, numero2);
                }
                else
                    printf("\be %i/%i.",numero1, numero2);
            }
            while(contador!=Quant);

        }

        break;

        case 4:
        {
            printf("LISTA 4 - 2) Gere e exiba cada uma das sequências abaixo com uma quantidade k de termos determinados pelo usuario. \nb)	4/8, 1, 36/24, 2, 100/40, 144/48, ...");

            int Quant,numero1=0, numero2=0, potencia, contador=0;

            do
            {
                printf("\n\nDigite a quantidade de termos desejada: ");
                scanf("%i",&Quant);
                if(Quant<=0)
                {
                    printf("Quantidade Inválida\n");
                }
            }
            while(Quant <= 0);

            if(Quant == 1)
                printf("4/8.");
            else do
                {
                    numero1=numero1+2;
                    potencia=pow(numero1, 2);
                    numero2=numero2+8;
                    contador=contador+1;
                    if((potencia % numero2) == 0 && contador!=Quant)
                    {
                        printf("%i, ", potencia / numero2);
                    }
                    else if(potencia % numero2 == 0 && contador==Quant)
                    {
                        printf("\b\b e %i.", potencia / numero2);
                    }

                    else if(contador!=Quant)
                    {
                        printf("%i/%i, ",potencia, numero2);
                    }
                    else
                        printf("\b\b e %i/%i.",potencia, numero2);

                }
                while(contador!=Quant);
        }

        default:

            printf("\nOpção inválida. Selecione uma opção de 0 a 4\n");

            break;

        }
    }
    while(escolha != 0);
}
