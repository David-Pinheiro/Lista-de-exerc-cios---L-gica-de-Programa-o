#include<stdio.h>
#include<locale.h>
#include<math.h>

#define exercicio1

#ifdef exercicio1

/*
1.	Receba doze números positivos e armazene no vetor A.
Após a alimentação de todos os números mostre apenas os números maiores que 121 que estão armazenados no vetor.
*/

int A[12];

int receber_valores();

main()
{
    int sup121;

    setlocale(LC_ALL, "");

    sup121= receber_valores();

    if(sup121==0)
    {
        printf("\nNão foram digitados números maiores que 121.");
    }

    else
    {
        superior_121(sup121);
    }

    return 0;
}

int receber_valores()
{
    int cont, sup121=0;

    printf("\nInforme os valores que serão armazenados no vetor: ");

    for(cont=0; cont<12; cont++)
    {
        do
        {
            printf("\n\tValor %d: ", cont+1);
            scanf("%d", &A[cont]);

            if(A[cont]<=0)
            {
                printf("\nInforme um número positivo.");
            }

        }
        while(A[cont]<=0);

        if(A[cont]>121)
        {
            sup121++;
        }
    }

    return sup121;
}

void superior_121(int x)
{
    int cont, cont121=1;

    printf("\nHá %d número(s) superior(es) a 121 armazenado(s) no vetor: ", x);

    for(cont=0; cont<12; cont++)
    {
        if(A[cont]>121)
        {

            if(x==1)
            {
                printf("%d.", A[cont]);
            }

            else if(cont121!=x)
            {
                printf("%d, ", A[cont]);
                cont121++;
            }

            else
            {
                printf("\b\b e %d.", A[cont]);
            }
        }
    }
}

#endif // exercicio1

#ifdef exercicio2

/*
2.	Leia oito elementos e armazene-os no vetor A.
Construa o vetor B de mesma dimensão com os elementos do vetor A multiplicados por 3.
Apresente o conteúdo dos dois vetores.
*/

int A[8];
int B[8];

int Termos();

main()
{
    setlocale(LC_ALL,"");

    int termos=Termos();

    cadastro_A(termos);
    cadastro_B(termos);
    exibir_valores(termos);

    return 0;
}

int Termos(int x)
{
    do
    {
        printf("\nInforme a quantidade de termos que integrarão os vetores: ");
        scanf("%d", &x);

        if(x<=0 || x>8)
        {
            printf("\n\tInsira um valor superior a 0 e inferior a 9.");
        }

    }
    while(x<=0 || x>8);

    return x;
}

void cadastro_A(int x)
{
    int cont;

    printf("\nInforme os valores que serão armazenados no vetor A: ");

    for(cont=0; cont<x; cont++)
    {
        printf("\n\tValor %d: ", cont+1);
        scanf("%d", &A[cont]);
    }
}

void cadastro_B(int x)
{
    int cont, contA=0;

    for(cont=0; cont<x; cont++)
    {
        B[cont]= A[contA]*3;
        contA++;
    }
}

void exibir_valores(int x)
{
    int contA, contB=0, contx=(x-1);

    printf("\n\nOs valores do vetor B correspondem aos valores armazenados no vetor A, respectivamente e multiplicados por 3:");

    printf("\nValores do vetor A: \n\t");
    for(contA=0; contA<x; contA++)
    {
        if(contA<contx)
        {
            printf("%d, ", A[contA]);
        }

        else
        {
            printf("\b\b e %d.", A[contA]);
        }
    }

    printf("\n\nValores do vetor B: \n\t");

    for(contB=0; contB<x; contB++)
    {
        if(contB<contx)
        {
            printf("%d, ", B[contB]);
        }

        else
        {
            printf("\b\b e %d.\n\n", B[contB]);
        }
    }
}

#endif // exercicio2

#ifdef exercicio3

/*
3.	Faça um programa que armazene num vetor 6 números negativos.
Calcule a soma dos seus quadrados; se a soma for inferior a 1000 solicite novos dados.
Mostre somente a soma que satisfaz a condição.
*/

int A[6];

int Termos();

main()
{
    setlocale(LC_ALL, "");

    int termos= Termos(termos);

    receber_valor(termos);

    return 0;
}

int Termos(int x)
{
    do
    {
        printf("\nInforme a quantidade de termos que serão armazenados: ");
        scanf("%d", &x);

        if(x<=0 || x>6)
        {
            printf("\n\tInsria um valor positivo, inferior a 7.");
        }
    }
    while(x<=0 || x>6);

    return x;

}

void receber_valor(int x)
{
    int cont, contq=0, contall=0;

    printf("\nInsira os valores negativos que serão armazenados no vetor: ");

    do
    {
        for(cont=00; cont<x; cont++)
        {
            do
            {
                printf("\n\tValor %d: ", cont+1);
                scanf("%d", &A[cont]);

                if(A[cont]>=0)
                {
                    printf("\nO valor deve ser negativo.");
                }

            }
            while(A[cont]>=0);

            contq= pow(A[cont], 2);
            contall+=contq;
        }

        if(contall<1000)
        {
            printf("\nA soma dos quadrados dos números inseridos é inferior a 1.000. Insira novos dados.");
        }
    }
    while(contall<1000);

    printf("\n\nEsta é a soma dos quadrados dos números inseridos: %d\n\n", contall);
}

#endif // exercicio3

#ifdef exercicio4

/* Armazene num vetor dez números positivos. Exiba o conteúdo do vetor.
Mostre o maior número, quantas vezes ele foi digitado e em que posições ele apareceu dentro do vetor. */

int A[10];
int maior_numero();
int quantidade_maior();

main()
{
    int maior;

    setlocale(LC_ALL, "");

    receber_valores();
    maior= maior_numero();
    printf("\nDentre os valores inseridos no vetor, o maior deles é %d, que apareceu %d vez(es), na posição: ",maior, quantidade_maior(maior));
    maior_posicoes(maior);


    return 0;
}

void receber_valores()
{
    int cont;

    printf("\nInsira dez números positivos: ");

    for(cont=0; cont<10; cont++)
    {
        do
        {
            printf("\n\tValor %d: ", cont+1);
            scanf("%d", &A[cont]);

            if(A[cont]<=0)
            {
                printf("\nInsira o valor positivo.");
            }
        }
        while(A[cont]<=0);
    }
}

int maior_numero()
{
    int cont, maior=0;

    for(cont=0; cont<10; cont++)
    {
        if(A[cont]>maior)
        {
            maior= A[cont];
        }
    }

    return maior;
}

int quantidade_maior(int x)
{
    int cont, contmaior=0;

    for(cont=0; cont<10; cont++)
    {
        if(A[cont]==x)
        {
            contmaior++;
        }
    }

    return contmaior;
}

void maior_posicoes(int x)
{
    int cont;

    for(cont=0; cont<10; cont++)
    {
        if(A[cont]==x)
        {
            printf("%d ", cont);
        }
    }
}

#endif // exercicio4

#ifdef exercicio5

/*
5.	Armazene no vetor A 10 elementos positivos. Construa o vetor B do mesmo tipo e dimensão.
Cada elemento do vetor B deve ser o valor negativo do elemento correspondente do vetor A.
Desta forma, se em A [1] estiver armazenado o elemento 8 deve estar em B [1] o valor –8,
e assim por diante. Apresentar o conteúdo dos dois vetores */

int A[10], B[10];

int receber_valores();
int mediaA();

main()
{
    setlocale(LC_ALL, "");

    int somaA;

    somaA= receber_valores();
    exibir_valores();
    printf("\n\nEsta é a média dos números do vetor A: %d\n", mediaA(somaA));

    return 0;
}

int receber_valores()
{
    int cont, soma=0;

    printf("\nInsira os valores que serão armazenados no vetor A:");

    for(cont=0; cont<10; cont++)
    {
        do
        {
            printf("\nValor %d: ", cont+1);
            scanf("%d", &A[cont]);

            if(A[cont]<=0)
            {
                printf("\nInsira um valor positivo");
            }
        }
        while(A[cont]<=0);

        soma+=A[cont];
        B[cont]= -A[cont];
    }

    return soma;
}

void exibir_valores()
{
    int cont;

    printf("\nEstes são os valores: \n\tVetor A: ");

    for(cont=0; cont<10; cont++)
    {
        if(cont<9)
        {
            printf("%d, ", A[cont]);
        }

        else
        {
            printf("\b\b e %d.", A[cont]);
        }
    }

    printf("\n\n\tVetor B: ");

    for(cont=0; cont<10; cont++)
    {
        if(cont<9)
        {
            printf("%d, ", B[cont]);
        }

        else
        {
            printf("\b\b e %d.", B[cont]);
        }
    }
}

int mediaA(int soma)
{
    int media;

    media=soma/10;

    return media;
}

#endif // exercicio5


#ifdef exercicio6

/*
6.	Leia o vetor A de uma dimensão máxima de 15 elementos.
O usuário poderá digitar a quantidade desejada desde que o valor seja inferior ou igual a 15.
Construir um vetor B de mesmo tipo, de modo que cada elemento do vetor B seja fatorial do elemento correspondente do vetor A.
Apresentar o conteúdo dos dois vetores.
*/

unsigned int A[15], B[15];
int Termos();

main()
{
    setlocale(LC_ALL, "");

    int termos;

    termos= Termos();
    receber_valoresA(termos);
    calcular_vetorB(termos);
    exibir_valores(termos);

    return 0;
}

int Termos()
{
    int termos;

    do
    {
        printf("\nInsira a quantidade de termos que serão armazenados no vetor: ");
        scanf("%d", &termos);

        if(termos<=0)
        {
            printf("\nInsira um valor positivo, menor do que 15.");
        }
    }
    while(termos<=0 || termos>15);

    return termos;
}

void receber_valoresA(int x)
{
    int cont;

    printf("\nInsira os valores que serão armazenados no vetor A:");

    for(cont=0; cont<x; cont++)
    {
        do
        {
            printf("\n\tValor %d: ", cont+1);
            scanf("%d", &A[cont]);

            if(A[cont]<=0)
            {
                printf("\nInsira um valor positivo.");
            }
        }
        while(A[cont]<=0);
    }
}

void calcular_vetorB(int x)
{
    int cont, cont2, vetorb;

    for(cont=0; cont<x; cont++)
    {
        vetorb=1;

        for(cont2=A[cont]; cont2>0; cont2--)
        {
            vetorb= vetorb*cont2;
        }

        B[cont]=vetorb;
    }
}

void exibir_valores(int x)
{
    int cont, contx;

    contx=x-1;

    printf("\nEstes são os valores dos vetores:\n\tVetor A: ");

    if(x==1)
    {
        printf("%d.", A[0]);
    }

    else
    {

        for(cont=0; cont<x; cont++)
        {
            if(cont!=contx)
            {
                printf("%d, ", A[cont]);
            }

            else
            {
                printf("\b\b e %d.", A[cont]);
            }
        }

    }


    printf("\n\tVetor B: ");

    if(x==1)
    {
        printf("%d.\n\n", B[0]);
    }

    else
    {

        for(cont=0; cont<x; cont++)
        {

            if(cont!=contx)
            {
                printf("%d, ", B[cont]);
            }

            else
            {
                printf("\b\b e %d.\n\n", B[cont]);
            }
        }

    }

}

#endif // exercicio6

#ifdef exercicio7

/*
7.	O usuário poderá digitar a quantidade de números que ele deseja armazenar no vetor A
desde que esse valor seja superior a 4 e inferior ou igual a 20.
Construa o vetor B da mesma dimensão e com os mesmos elementos do vetor A.
Observando que o primeiro elemento de A passa a ser o último de B,
o segundo elemento de A passa a ser o penúltimo de B e a assim por diante.
Exibir o conteúdo dos dois vetores.
*/

int A[50], B[50];
int Termos();

main()
{
    setlocale(LC_ALL, "");

    int termos;

    termos= Termos();
    receber_valores(termos);
    exibir_valores(termos);

    return 0;
}

int Termos()
{
    int termos;

    do
    {
        printf("\nInforme a quantidade de números que serão inseridos no vetor: ");
        scanf("%d", &termos);

        if(termos<5 || termos>20)
        {
            printf("\nInforme um valor superior a 4 e inferior a 21");
        }

    }
    while(termos<5 || termos>20);

    return termos;
}

void receber_valores(int x)
{
    int cont, cont2=x-1;

    printf("\nInforme os valores que serão armazenados no vetor A:");

    for(cont=0; cont<x; cont++)
    {
        printf("\n\tValor %d: ", cont+1);
        scanf("%d", &A[cont]);

        B[cont2]= A[cont];
        cont2--;
    }
}

void exibir_valores(int x)
{
    int cont, contx=x-1;

    printf("\nEstes são os valores dos vetores:\n\tVetor A: ");

    for(cont=0; cont<x; cont++)
    {
        if(cont!=contx)
        {
            printf("%d, ", A[cont]);
        }

        else
        {
            printf("\b\b e %d", A[cont]);
        }
    }

    printf("\n\tVetor B: ");

    for(cont=0; cont<x; cont++)
    {
        if(cont!=contx)
        {
            printf("%d, ", B[cont]);
        }

        else
        {
            printf("\b\b e %d\n\n", B[cont]);
        }
    }
}

#endif // exercicio7

#ifdef exercicio8

/*
8.	Leia três vetores (A, B e C) de uma dimensão com 5 elementos cada. Construa o vetor D, sendo este a junção dos três outros vetores.
Armazene no vetor D o primeiro elemento do vetor A depois do B e do C e assim sucessivamente.  Apresentar o conteúdo de todos os vetores.
Exiba quantas vezes apareceram números negativos no vetor D.
*/

int A[5], B[5], C[5], D[15];

int Termos();

main()
{
    setlocale(LC_ALL, "");

    int termos= Termos();

    receber_valor(termos);
    calculo_vetorD(termos);
    exibir_valor(termos);
    negativos_vetorD(termos);

    return 0;
}

int Termos()
{
    int termos;

    do
    {
        printf("\nInforme a quantidade de termos: ");
        scanf("%d", &termos);

        if(termos<=0 || termos>5)
        {
            printf("\n\tInsira um valor entre 1 e 5.");
        }
    }
    while(termos<=0 || termos>5);

    return termos;
}

void receber_valor(int x)
{
    int cont;

    printf("\nInsira os valores que serão armazenados no vetor A:");

    for(cont=0; cont<x; cont++)
    {
        printf("\n\tValor %d: ", cont+1);
        scanf("%d", &A[cont]);
    }

    printf("\nInsira os valores que serão armazenados no vetor B:");

    for(cont=0; cont<x; cont++)
    {
        printf("\n\tValor %d: ", cont+1);
        scanf("%d", &B[cont]);
    }

    printf("\nInsira os valores que serão armazenados no vetor C:");

    for(cont=0; cont<x; cont++)
    {
        printf("\n\tValor %d: ", cont+1);
        scanf("%d", &C[cont]);
    }
}

void calculo_vetorD(int x)
{
    int cont, contA=0, contB=0, contC=0, contD=(x*3);

    for(cont=0; cont<contD; cont++)
    {
        D[cont]=A[contA];
        contA++;
        D[cont+1]=B[contB];
        contB++;
        D[cont+2]=C[contC];
        contC++;
        cont+=2;
    }
}

void exibir_valor(int x)
{
    int cont, cont2=(x-1);

    printf("\nEstes são os valores dos vetores: \n\tVetor A: ");

    for(cont=0; cont<x; cont++)
    {
        if(cont<cont2)
        {
            printf("%d, ", A[cont]);
        }

        else
        {
            printf("\b\b e %d.", A[cont]);
        }
    }

    printf("\n\tVetor B: ");

    for(cont=0; cont<x; cont++)
    {
        if(cont<cont2)
        {
            printf("%d, ", B[cont]);
        }

        else
        {
            printf("\b\b e %d.", B[cont]);
        }
    }

    printf("\n\tVetor C: ");

    for(cont=0; cont<x; cont++)
    {
        if(cont<cont2)
        {
            printf("%d, ", C[cont]);
        }

        else
        {
            printf("\b\b e %d.", C[cont]);
        }
    }

    printf("\n\tVetor D: ");

    int contD=(x*3);
    int cont2D= (contD-1);

    for(cont=0; cont<contD; cont++)
    {
        if(cont<cont2D)
        {
            printf("%d, ", D[cont]);
        }

        else
        {
            printf("\b\b e %d.", D[cont]);
        }
    }
}

void negativos_vetorD(int x)
{
    int cont, contneg=0, contD=(x*3);

    for(cont=0; cont<contD; cont++)
    {
        if(D[cont]<0)
        {
            contneg++;
        }
    }

    if(contneg==0)
    {
        printf("\n\nNão há números negativos no vetor D.");
    }

    else
    {
        printf("\n\nEsta é a quantidade de números negativos armazenados no vetor D: %d\n\n", contneg);
    }
}

#endif // exercicio8

#ifdef exercicio9

/*
9.	Leia o vetor A tipo vetor com 10 elementos positivos.
Construa o vetor B de mesmo tipo, e cada elemento de B deve ser a metade de cada elemento de A.
Exiba em que Vetor e em que posições apareceram valores superiores a 4.
*/

float A[10], B[10];

int Termos();
float receber_valoresA();
float calculo_valoresB();

main()
{
    int termos= Termos();
    float contA, contB;

    setlocale(LC_ALL, "");

    contA= receber_valoresA(termos);
    contB= calculo_valoresB(termos);

    if(contA==0)
    {
        printf("\nNão há números superiores a 4 armazenados nos vetores.\n\n");
    }

    else
    {
        printf("\nHá %g número(s) superior(es) a 4 armazenado(s) no vetor A, na(s) posição(ões): ", contA);
        verificar_sup4A(termos);

        if(contB==0)
        {
            printf("\nNão há números superiores a 4 armazenados no vetor B.\n\n");
        }

        else
        {
            printf("\nHá %g número(s) superior(es) a 4 armazenado(s) no vetor B, na(s) posição(ões): ", contB);
            verificar_sup4B(termos);
        }

    }

    return 0;

}

int Termos()
{
    int termos;

    do
    {
        printf("\nInsira a quantidade de termos desejados: ");
        scanf("%d", &termos);

        if(termos<=0 || termos>10)
        {
            printf("\n\tInsira um valor entre 1 e 9.");
        }

    }
    while(termos<=0 || termos>10);

    return termos;
}

float receber_valoresA(int x)
{
    int cont;
    float cont4=0;

    printf("\nInforme os valores que serão armazenados no vetor A:");

    for(cont=0; cont<x; cont++)
    {
        do
        {
            printf("\n\tValor %d: ", cont+1);
            scanf("%f", &A[cont]);

            if(A[cont]<=0)
            {
                printf("\nInsira um valor positivo.");
            }

        }
        while(A[cont]<=0);

        if(A[cont]>4)
        {
            cont4++;
        }
    }

    return cont4;
}

float calculo_valoresB(int x)
{
    int cont;
    float cont4=0;

    for(cont=0; cont<x; cont++)
    {
        B[cont]= A[cont]/2;

        if(B[cont]>4)
        {
            cont4++;
        }
    }

    return cont4;
}

void verificar_sup4A(int x)
{
    int cont;

    for(cont=0; cont<x; cont++)
    {
        if(A[cont]>4)
        {
            printf("%d  ", cont);
        }
    }
}

void verificar_sup4B(int x)
{
    int cont;

    for(cont=0; cont<x; cont++)
    {
        if(B[cont]>4)
        {
            printf("%d  ", cont);
        }
    }

    printf("\n\n");
}

#endif // exercicio9

#ifdef exercicio10

/*
10.	Elabore um programa que efetue o cálculo de uma tabuada de um número qualquer
e armazene os resultados no vetor A de uma dimensão para 10 elementos.
O usuário deverá digitar o número e o programa deverá construir e exibir a tabuada correspondente.
*/

int A[10];

main()
{
    setlocale(LC_ALL, "");

    int termo;
    termo= receber_termo();
    obter_tabuada(termo);
    exibir_valores(termo);

    return 0;
}

int receber_termo()
{
    int termo;

    do
    {
        printf("\nInforme o número para o qual deseja obter a tabuada: ");
        scanf("%d", &termo);

        if(termo<=0)
        {
            printf("\nInforme um valor positivo.");
        }

    }
    while(termo<=0);

    return termo;
}

void obter_tabuada(int termo)
{
    int cont;

    for(cont=0; cont<10; cont++)
    {
        A[cont]= termo*(cont+1);
    }
}

void exibir_valores(int termo)
{
    int cont;

    printf("\nEsta é a tabuada do número %d:\n", termo);

    for(cont=0; cont<10; cont++)
    {
        printf("\n\t%d x %d= %d", termo, cont+1, A[cont]);
    }

    printf("\n");
}

#endif // exercicio10

#ifdef exercicio11

/*
11.	Receba a temperatura média de cada mês do ano e armazene essas temperaturas em um vetor;
calcule e mostre a maior, a menor temperatura do ano e a média das temperaturas.
Mostre todas as temperaturas armazenadas.
*/

float A[12];

float maior_temperatura();
float menor_temperatura();
float media_temperaturas();

main()
{
    setlocale(LC_ALL, "");
    receber_temperaturas();
    exibir_temperaturas();
    printf("\n\nEsta é a maior temperatura: %g\nEsta é a menor temperatura: %g\nEsta é a média das temperaturas: %g\n", maior_temperatura(), menor_temperatura(), media_temperaturas());

    return 0;
}

void receber_temperaturas()
{
    int cont;

    printf("\nInforme as temperaturas apuradas: ");

    for(cont=0; cont<12; cont++)
    {
        printf("\n\tMês %d: ", cont+1);
        scanf("%f", &A[cont]);
    }
}

float maior_temperatura()
{
    int cont;
    float maior;

    maior= A[0];

    for(cont=0; cont<12; cont++)
    {
        if(A[cont]>maior)
        {
            maior=A[cont];
        }
    }

    return maior;
}

float menor_temperatura()
{
    int cont;
    float menor;

    menor=A[0];

    for(cont=0; cont<12; cont++)
    {
        if(A[cont]<menor)
        {
            menor= A[cont];
        }
    }

    return menor;
}

float media_temperaturas()
{
    int cont;
    float somatemp=0, media;

    for(cont=0; cont<12; cont++)
    {
        somatemp+=A[cont];
    }

    media=somatemp/12;

    return media;
}

void exibir_temperaturas(float maior, float menor, float media)
{
    int cont;

    printf("\nEstas são as temperaturas aferidas no ano: ");

    for(cont=0; cont<12; cont++)
    {
        printf("\n\tMês %d: %g", cont+1, A[cont]);
    }
}

#endif // exercicio11

#ifdef exercicio12

/*
12.	Receba a nota de dez alunos e armazene essas notas em um vetor. Calcule e mostre:
a)	A média da classe;
b)	A quantidade de alunos aprovados, isto é, com nota >=7;
c)	A quantidade de alunos reprovados, isto é, com nota <7.
*/

float A[10];

float media();
float alunos_aprovados();
float alunos_reprovados();

main()
{
    setlocale(LC_ALL, "");
    receber_valores();
    printf("\nEsta é a média das notas da classe: %g", media());
    printf("\nEsta é a quantidade de alunos aprovados: %g", alunos_aprovados());
    printf("\nEsta é a quantidade de alunos reprovados: %g\n", alunos_reprovados());

    return 0;
}

void receber_valores()
{
    int cont;

    printf("\nInforme as notas dos alunos:");

    for(cont=0; cont<10; cont++)
    {
        do
        {
            printf("\n\tAluno %d: ", cont+1);
            scanf("%f", &A[cont]);

            if(A[cont]<0)
            {
                printf("\nA nota não pode ser representada por um valor negativo, insira novamente.");
            }

        }
        while(A[cont]<0);
    }
}

float media()
{
    int cont;
    float media, somanotas=0;

    for(cont=0; cont<10; cont++)
    {
        somanotas+=A[cont];
    }

    media= somanotas/10;

    return media;
}

float alunos_aprovados()
{
    int cont;
    float aprovados=0;

    for(cont=0; cont<10; cont++)
    {
        if(A[cont]>=7)
        {
            aprovados++;
        }
    }

    return aprovados;
}

float alunos_reprovados()
{
    int cont;
    float reprovados=0;

    for(cont=0; cont<10; cont++)
    {
        if(A[cont]<7)
        {
            reprovados++;
        }
    }

    return reprovados;
}

#endif // exercicio12

#ifdef exercicio13

/*
13.	 Receba o peso e o número de identificação gerado pelo programador contendo no máximo de 15 pessoas.
A quantidade de indivíduos será definida pelo usuário. Armazene esses dados em dois vetores,
o primeiro contendo os pesos e o segundo contendo os números de identificação.
Calcule e mostre:
a)	Quantas pessoas apresentaram peso superior ao menor peso. Armazene os números de identificação das pessoas que satisfazem essa condição.
Mostre o conteúdo desse vetor.
b)	Armazene num outro vetor os pesos superiores a 55 quilos e menores ou igual a 80 quilos das pessoas. Mostre o conteúdo desse vetor.
*/

float peso[15];
int identificacao[15];

int quantidade_pessoas();

main()
{
    int qpessoas;

    setlocale(LC_ALL, "");
    qpessoas= quantidade_pessoas();
    receber_valores(qpessoas);
    superior_menorpeso(qpessoas);
    superior_5580(qpessoas);

    return 0;
}

int quantidade_pessoas()
{
    int x;

    do
    {
        printf("\nInforme a quantidade de  pessoas cujos dados serão armazenados:");
        scanf("%d", &x);

        if(x<=0 || x>15)
        {
            printf("\n\tA quantidade deve ser representada por um valor positivo, inferior a 16.");
        }

    }
    while(x<=0 || x>15);

    return x;
}

void receber_valores(int x)
{
    int cont;

    printf("\nInsira os dados: ");

    for(cont=0; cont<x; cont++)
    {
        do
        {
            printf("\n\tPeso %d: ", cont+1);
            scanf("%f", &peso[cont]);

            if(peso[cont]<=0)
            {
                printf("\nO peso deve ser representado por um valor positivo.");
            }

        }
        while(peso[cont]<=0);

        identificacao[cont]= (cont+1);

    }
}

void superior_menorpeso(int x)
{
    int cont, cont2, supmenor=0, idsupmenor[x];
    float menor;

    menor=peso[0];

    for (cont=0; cont<x; cont++)
    {
        if(peso[cont]<menor)
        {
            menor=peso[cont];
        }
    }

    for(cont=0; cont<x; cont++)
    {
        if(peso[cont]>menor)
        {
            idsupmenor[cont2]= identificacao[cont];
            supmenor++;
            cont2++;
        }
    }

    printf("\Dentro os pesos inseridos, %g é o menor deles. Há %d pesos superiores ao menor peso. Estas são as identificações:", menor, supmenor);

    for(cont=0; cont<supmenor; cont++)
    {
        printf("\n\t Identificação: %d", idsupmenor[cont]);
    }
}

void superior_5580(int x)
{
    int cont, cont2=0;
    float sup5580[x];

    for(cont=0; cont<x; cont++)
    {
        if(peso[cont]>55 && peso[cont]<= 80)
        {
            sup5580[cont2]= peso[cont];
            cont2++;
        }
    }

    printf("\nDentre os pesos inseridos, %d deles são superiores a 55 e inferiores ou iguais a 80, esta é a relação:", cont-1);

    cont=cont-1;

    for(cont2=0; cont2<cont; cont2++)
    {
        printf("\n\tPeso %d: %g", cont2+1, sup5580[cont2]);
    }
}

#endif // exercicio13

#ifdef exercicio14

/*
14. Efetue a leitura de dez elementos para o vetor A. Construa o vetor B, observando a seguinte lei de formação:
se o valor do índice do vetor for par, o valor do elemento deve ser multiplicado pelo valor 5;
sendo o índice ímpar, deverá ser somado ao valor existente o valor 5. Mostre o conteúdo dos dois vetores.
*/

int A[10], B[10];

int Termos();

main()
{
    setlocale(LC_ALL, "");

    int termos= Termos();

    receber_valoresA(termos);
    calculo_valoresB(termos);
    exibir_valores(termos);


    return 0;
}

int Termos()
{
    int x;

    do
    {
        printf("\nInforme a quantidade de termos que serão armazenados: ");
        scanf("%d", &x);

        if(x<=0)
        {
            printf("\n\tInforme um valor positivo.");
        }
    }
    while(x<=0);

    return x;
}

void receber_valoresA(int x)
{
    int cont;

    printf("\nInsira os valores que serão armazenados no vetor A:");

    for(cont=0; cont<x; cont++)
    {
        printf("\n\tValor %d: ", cont+1);
        scanf("%d", &A[cont]);
    }
}

void calculo_valoresB(int x)
{
    int cont;

    for(cont=0; cont<x; cont++)
    {
        if(cont%2==0)
        {
            B[cont]= A[cont]*5;
        }

        else
        {
            B[cont]= A[cont]+5;
        }
    }
}

void exibir_valores(int x)
{
    int cont, cont2=(x-1);

    printf("\nValores do vetor A: ");

    for(cont=0; cont<x; cont++)
    {
        if(cont<cont2)
        {
            printf("%d, ", A[cont]);
        }

        else
        {
            printf("\b\b e %d", A[cont]);
        }
    }

    printf("\nValores do vetor B: ");

    for(cont=0; cont<x; cont++)
    {

        if(cont<cont2)
        {
            printf("%d, ", B[cont]);
        }

        else
        {
            printf("\b\b e %d", B[cont]);
        }
    }
}

#endif // exercicio14

#ifdef exercicio15

/*
15.	Efetue a leitura de dez elementos para o vetor A. No final, apresente a somatória de todos os elementos do vetor A que sejam ímpares.
Armazene no vetor B a posição em que estão armazenados os números ímpares. Mostre o conteúdo dos dois vetores.
*/

int A[10], B[10];

int receber_valoresA();
int soma_impar();

main()
{
    int contimpar;

    setlocale (LC_ALL, "");
    contimpar= receber_valoresA();

    if(contimpar==0)
    {
        exibir_valoresA();
        printf("\nNão foram inseridos números ímpares no vetor A, portanto, não há valores armazenados no vetor B.\n\n");
    }

    else
    {
        printf("\nEsta é a somatória dos números ímpares inseridos no vetor A: %d", soma_impar());
        contimpar= receber_valoresB();
        exibir_valoresA();
        exibir_valoresB(contimpar);
    }



    return 0;
}

int receber_valoresA()
{
    int cont, contimpar;

    printf("\nInforme os valores que serão armazenados no vetor A:");

    for(cont=0; cont<10; cont++)
    {
        printf("\n\tValor %d: ", cont+1);
        scanf("%d", &A[cont]);

        if(A[cont]%2!=0)
        {
            contimpar++;
        }

    }

    return contimpar;
}

int soma_impar()
{
    int cont, somaimpar=0;

    for(cont=0; cont<10; cont++)
    {
        if(A[cont]%2!=0)
        {
            somaimpar+=A[cont];
        }
    }

    return somaimpar;
}

int receber_valoresB()
{
    int cont, cont2=0;

    for(cont=0; cont<10; cont++)
    {
        if(A[cont]%2!=0)
        {
            B[cont2]= cont;
            cont2++;
        }
    }

    return cont2;
}

void exibir_valoresA()
{
    int cont;

    printf("\nEstes são os valores armazenados no vetor A: ");

    for(cont=0; cont<10; cont++)
    {
        if(cont<9)
        {
            printf("%d, ", A[cont]);
        }

        else
        {
            printf("\b\b e %d.", A[cont]);
        }
    }
}

void exibir_valoresB(int x)
{
    int cont, cont2= (x-1);

    printf("\nEstes são os valores do vetor B, que armazena as posições dos números ímpares armazenados no vetor A: ");

    for(cont=0; cont<x; cont++)
    {
        if(cont<cont2)
        {
            printf("%d, ", B[cont]);
        }

        else
        {
            printf("\b\b e %d.", B[cont]);
        }
    }
}

#endif // exercicio15

#ifdef exercicio16

/*
16.	Leia 12 elementos inteiros para o vetor A e construa o vetor B com a mesma dimensão,
observando a seguinte lei de formação: “Todo elemento do vetor A que for ímpar deve ser multiplicado por 2;
caso contrário, o elemento do vetor A deve permanecer constante”. Exiba o conteúdo dos dois vetores.
*/

int A[12], B[12];

int Termos();

main()
{
    setlocale(LC_ALL, "");

    int termos;
    termos= Termos();
    receber_valoresA(termos);
    receber_valoresB(termos);
    exibir_vetorA(termos);
    exibir_vetorB(termos);

    return 0;
}

int Termos()
{

    int cont, x;

    do
    {
        printf("\nInforme quantos elementos serão armazenados: ");
        scanf("%d", &x);

        if(x<=0 || x>12)
        {
            printf("\nInforme um valor superior a 0 e inferior a 13.");
        }
    }
    while(x<=0 || x>12);

    return x;
}

void receber_valoresA(int x)
{
    int cont;

    printf("\nInforme os valores que serão armazenados no vetor A:");

    for(cont=0; cont<x; cont++)
    {
        printf("\n\tValor %d: ", cont+1);
        scanf("%d", &A[cont]);
    }
}

void receber_valoresB(int x)
{
    int cont;

    for(cont=0; cont<x; cont++)
    {
        if(A[cont]%2==1)
        {
            B[cont]= (A[cont]*2);
        }

        else
        {
            B[cont]= A[cont];
        }
    }
}

void exibir_vetorA(int x)
{
    int cont, cont2= (x-1);

    printf("\nEstes são os valores armazenados no vetor A: ");

    for(cont=0; cont<x; cont++)
    {
        if(cont<cont2)
        {
            printf("%d, ", A[cont]);
        }

        else
        {
            printf("\b\b e %d.", A[cont]);
        }
    }
}

void exibir_vetorB(int x)
{
    int cont, cont2= (x-1);

    printf("\nEstes são os valores armazenados no vetor B: ");

    for(cont=0; cont<x; cont++)
    {
        if(cont<cont2)
        {
            printf("%d, ", B[cont]);
        }

        else
        {
            printf("\b\b e %d.", B[cont]);
        }
    }

    printf("\n");
}

#endif // exercicio16

#ifdef exercicio17

/*
17.	Receba o salário e o número de identificação gerado pelo programador contendo no máximo 13 pessoas.
A quantidade de indivíduos será definida pelo usuário. Armazene esses dados em dois vetores,
o primeiro contendo os salários e o segundo contendo os números de identificação. Calcule e mostre:
a)	Armazene em um vetor os números de identificação de todas as pessoas que apresentam a maior salário.
b)	Armazene num outro vetor os números de identificação de todas as pessoas que apresentam a menor salário encontrado.
Mostre o conteúdo de todos os vetores.

*/

float A[13];
int B[13];

int Termos();

main()
{
    setlocale(LC_ALL, "");

    int termos, qmaior;

    termos= Termos();
    receber_valores(termos);
    maior_salario(termos);
    menor_salario(termos);

    return 0;
}

int Termos()
{
    int x;

    do
    {
        printf("\nInforme a quantidade de pessoas cujo salário será armazenado: ");
        scanf("%d", &x);

        if(x<=0 || x>13)
        {
            printf("\n\tInforme um valor superior a 0 e inferior a 13.");
        }

    }
    while(x<=0 || x>13);

    return x;
}

void receber_valores(int x)
{
    int cont;

    printf("\nInforme os salários que serão armazenados: ");

    for(cont=0; cont<x; cont++)
    {
        do
        {
            printf("\n\tSalário %d: ", cont+1);
            scanf("%f", &A[cont]);

            if(A[cont]<=0)
            {
                printf("\nO salário deve corresponder a um valor positivo.");
            }

        }
        while(A[cont]<=0);

        B[cont]= cont+1;
    }
}

void maior_salario(int x)
{
    int cont, cont2=0, contmaior=0, maiores[x];
    float maior=0;

    for(cont=0; cont<x; cont++)
    {
        if(A[cont]>maior)
        {
            maior=A[cont];
            contmaior++;
        }
    }

    for(cont=0; cont<x; cont++)
    {
        if(A[cont]==maior)
        {
            maiores[cont2]=B[cont];
            cont2++;
        }
    }

    printf("\nDentre os salários inseriores, %g é o maior deles. Há %d salário(s) com esse valor, identificação:", maior, cont2);

    for(cont=0; cont<cont2; cont++)
    {
        printf(" %d", maiores[cont]);
    }
}

void menor_salario(int x)
{
    int cont, cont2=0, contmenor=0, menores[x];
    float menor;

    menor=A[0];

    for(cont=0; cont<x; cont++)
    {
        if(A[cont]<menor)
        {
            menor=A[cont];
            contmenor++;
        }
    }

    for(cont=0; cont<x; cont++)
    {
        if(A[cont]==menor)
        {
            menores[cont2]=B[cont];
            cont2++;
        }
    }

    printf("\nDentre os salários inseriores, %g é o menor deles. Há %d salário(s) com esse valor, identificação: ", menor, cont2);

    for(cont=0; cont<cont2; cont++)
    {
        printf("%d ", menores[cont]);
    }
}

#endif // exercicio17

#ifdef exercicio19

/*
19.	Leia dois vetores A e B de uma dimensão com 6 elementos. O vetor A deve aceitar apenas a entrada de valores pares,
enquanto o vetor B deve aceitar apenas a entrada de valores ímpares.
A entrada dos dois vetores deve ser validada pelo programa e não pelo usuário.
Construir o vetor C que deverá ser a junção dos vetores A e B, de modo que seja armazenado um elemento do vetor A e em seguida um elemento do vetor B.
O vetor C contenha 12 elementos. Exiba os conteúdos dos vetores A e B juntos e depois o conteúdo do vetor C.
*/

int A[6], B[6], C[12];

int Termos();

int main()
{
    setlocale(LC_ALL, "");

    int termos= Termos();

    receber_valorA(termos);
    receber_valorB(termos);
    calculo_valorC(termos);
    exibir_valoresAB(termos);
    exibir_valoresC(termos);

    return 0;
}

int Termos()
{
    int x;

    do
    {
        printf("\nInforme a quantidade de termos: ");
        scanf("%d", &x);

        if(x<=0)
        {
            printf("\n\tInforme um valor positivo.");
        }
    }
    while(x<=0);
}

void receber_valorA(int x)
{
    int cont;

    printf("\nInforme os números pares que serão armazenados no vetor A:");

    for(cont=0; cont<x; cont++)
    {
        do
        {
            printf("\nValor %d: ", cont+1);
            scanf("%d", &A[cont]);

            if(A[cont]%2!=0)
            {
                printf("\nInsira o número par");
            }

        }
        while(A[cont]%2!=0);
    }
}

void receber_valorB(int x)
{
    int cont;

    printf("\nInforme os números ímpares que serão armazenados no vetor B:");

    for(cont=0; cont<x; cont++)
    {
        do
        {
            printf("\nValor %d: ", cont+1);
            scanf("%d", &B[cont]);

            if(B[cont]%2==0)
            {
                printf("\nInsira o número ímpar");
            }

        }
        while(B[cont]%2==0);
    }
}

void calculo_valorC(int x)
{
    int cont, contx=0, x2=(x*2);

    for(cont=0; cont<x2; cont+=2)
    {
        C[cont]= A[contx];
        C[cont+1]= B[contx];
        contx++;
    }
}

void exibir_valoresAB(int x)
{
    int cont;

    printf("\nEstes são os valores dos vetores A e B:");

    for(cont=0; cont<x; cont++)
    {
        printf("\n\tValor %d: vetor A: %d / vetor B: %d", cont+1, A[cont], B[cont]);
    }
}

void exibir_valoresC(int x)
{
    int cont, x2=(x*2), cont2=(x2-1);

    printf("\n\nEstes são os valores do vetor C:\n");

    for(cont=0; cont<x2; cont++)
    {
        if(cont<cont2)
        {
            printf("%d, ", C[cont]);
        }

        else
        {
            printf("\b\b e %d.", C[cont]);
        }
    }
}

#endif // exercicio19
