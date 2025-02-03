#include "stdio.h"
#include "locale.h"

#define ex1

/*
1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las usando ponteiros e retorne como resultado se
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
    Imprima o resultado na funcao main(). Declare os vetores como variavel global
*/

#ifdef ex1

int reiniciar(int opcao);
int comparativo();

main()
{
    setlocale(LC_ALL, "");

    int comparacao, opcao;
    char primeira [10], segunda [10];
    char *pprimeira, *psegunda;

    pprimeira= primeira;
    psegunda= segunda;

    do
    {
        printf("\nPreencha a primeira string: ");
        gets(primeira);

        printf("\nPreencha a segunda string: ");
        gets(segunda);

        comparacao= comparativo(pprimeira, psegunda);

        if(comparacao==0)
        {
            printf("\n\nAs strings são diferentes.");
        }

        else
        {
            printf("\n\nAs strings são iguais.");
        }

        opcao= reiniciar(opcao);
        getchar();
    }
    while(opcao==1);

}

int comparativo(char *pprimeira, char *psegunda)
{
    int comparacao=1, cont;

    for(cont=0; cont<10; cont++)
    {
        if(pprimeira[cont]!= psegunda[cont])
        {
            comparacao=0;
            break;
        }

        if(pprimeira[cont]== '\0' || psegunda[cont] == '\0')
        {
            break;
        }
    }

    return comparacao;
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
2 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/

#ifdef ex2

int reiniciar(int opcao);
int comparativo();
char vet_letras[]= {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

main()
{
    setlocale(LC_ALL, "");
    int opcao, resposta;
    char letra;
    char *pletra;
    pletra= &letra;

    do
    {
        printf("\nDigite uma letra qualquer: ");
        scanf("%c", &letra);

        resposta= comparativo(pletra);

        if(resposta==1)
        {
            printf("\n\nA letra digitada consta no vetor: b,d,f,h,j,k,m,o,q,s,u,w,y.");
        }

        else
        {
            printf("\n\nA letra digitada não consta no vetor: b,d,f,h,j,k,m,o,q,s,u,w,y.");
        }

        opcao= reiniciar(opcao);
    }
    while(opcao==1);
}

int comparativo(char *pletra)
{
    int cont, resposta=0;

    for(cont=0; cont<10; cont++)
    {
        if(*pletra==vet_letras[cont])
        {
            resposta=1;
            break;
        }
    }

    return resposta;
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
3 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
*/

#ifdef ex3

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");

    int intvar, *pintvar, opcao;
    long int longvar, *plongvar;
    unsigned int unsignedvar, *punsignedvar;
    float floatvar, *pfloatvar;
    double doublevar, *pdoublevar;
    char charvar, *pcharvar;
    unsigned long int unlonint, *punlonint;
    unsigned char uncharvar, *puncharvar;


    pintvar= &intvar;
    plongvar= &longvar;
    punsignedvar= &unsignedvar;
    pfloatvar= &floatvar;
    pdoublevar= &doublevar;
    pcharvar= &charvar;
    punlonint= &unlonint;
    puncharvar= &uncharvar;

    do
    {
    printf("\nPreencha os valores das variáveis:");
    printf("\n\tint: ");
    scanf("%d", pintvar);
    printf("\n\tlong: ");
    scanf("%ld", plongvar);
    printf("\n\tunsigned: ");
    scanf("%u", punsignedvar);
    printf("\n\tfloat: ");
    scanf("%f", pfloatvar);
    printf("\n\tdouble: ");
    scanf("%lf", pdoublevar);
    printf("\n\tunsigned long: ");
    scanf("%u", punlonint);
    getchar();
    printf("\nchar: ");
    scanf("%c", pcharvar);
    getchar();
    printf("\nunsigned char: ");
    scanf("%c", puncharvar);

        printf("\n        10        20        30        40        50        60");
        printf("\n123456789012345678901234567890123456789012345678901234567890");

        printf("\n    %-11d         %-11ld         %-u", *pintvar, *plongvar, *punsignedvar);
        printf("\n              %-8.1e            %-9.1e           %-c", *pfloatvar, *pdoublevar, *pcharvar);
        printf("\n         %-11lu         %c", *punlonint, *puncharvar);

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

#endif // ex3

/*
4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.
*/

#ifdef ex4

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");
    int numero, contsoma, contquant, *pnumero= &numero, *pcontsoma= &contsoma, *pcontquant= &contquant;
    char opcao;

    do
    {
        contsoma=0;
        contquant=0;

        printf("\nDigite valores positivos e, ao final, um valor negativo");

        for(;;)
        {
            printf("\n\tValor %d: ", contquant+1);
            scanf("%d", pnumero);

            if(*pnumero>=0)
            {

                *pcontsoma+= *pnumero;
                *pcontquant+= 1;
            }

            else
            {
                break;
            }
        }

        if(*pcontquant!=0)
        {
            printf("\nForam digitados %d números positivos, a media entre eles é %d", *pcontquant, *pcontsoma / *pcontquant);
        }

        else
        {
            printf("\nNao foram digitados números positivos\n");
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
5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep
*/

#ifdef ex5

struct cadastro
{
    char nome[30];
    char end[50];
    char cidade[15];
    char estado[20];
    char cep[12];
};

struct cadastro set[4];

void cads(struct cadastro *pset)
{
    int cont;
    setlocale(LC_ALL, "");

    for(cont=0; cont<4; cont++)
    {
        printf("Escreva os dados da pessoa %d:\n", cont+1);
        fflush(stdin);
        printf("Nome: ");
        gets(pset[cont].nome);
        fflush(stdin);
        printf("Endereço: ");
        gets(pset[cont].end);
        fflush(stdin);
        printf("Cidade: ");
        gets(pset[cont].cidade);
        fflush(stdin);
        printf("Estado: ");
        gets(pset[cont].estado);
        fflush(stdin);
        printf("CEP: ");
        gets(pset[cont].cep);
        system("cls");
    }
}

void imp(int *pdados, struct cadastro *pset)
{
    setlocale(LC_ALL, "");
    int cont;

    if(*pdados == 0)
    {
        printf("\nNão há dados.\n\n");
    }
    else
    {
        for(cont=0; cont<4; cont++)
        {
            printf("\n\nDados da pessoa %d:\n-------------------------------------\n", cont+1);
            printf("Nome: %s\n", pset[cont].nome);
            printf("Endereço: %s\n", pset[cont].end);
            printf("Cidade: %s\n", pset[cont].cidade);
            printf("Estado: %s\n", pset[cont].estado);
            printf("CEP: %s\n", pset[cont].cep);
        }
    }
    system("pause");
    system("cls");
}

int main()
{
    setlocale(LC_ALL, "");

    int esc, dados=0;
    int *pdados;
    pdados= &dados;
    struct cadastro *pset;
    pset= &set[0]; // ou pset= set;

    do
    {
        do
        {
            printf("--------------------------\n");
            printf("1 - receber todos os dados\n");
            printf("2 - mostrar todos os dados\n");
            printf("3 - sair\n");
            printf("Qual ação deseja realizar?\n");
            printf("R: ");
            scanf("%d", &esc);
        }
        while(esc < 1 || esc > 3);
        system("cls");

        switch(esc)
        {
        case 1:
            cads(pset);
            dados++;
            break;
        case 2:
            imp(pdados, pset);
            break;
        case 3:
            exit(0);
            break;
        }
    }
    while(esc != 3);
}

#endif // ex5

/*
6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano
*/

#ifdef ex6

struct data{
    int dian, mesn, anon, diaa, mesa, anoa;
    int dias, mes, anos;
    int diatotal;
};

struct data gend;

int reiniciar(int opcao);

int main(){
    setlocale(LC_ALL, "");
        struct data *pc;
        pc = &gend;
        int va, *vp, opcao;
        vp = &va;

        do
        {

            printf("\nDigite a primeira data:");
        do{
            printf("\n\tDia: ");
            scanf("%d", &(*pc).dian);
        }while ((*pc).dian > 31);
        do{
            printf("\n\tMês: ");
            scanf("%d", &(*pc).mesn);
        }while ((*pc).mesn > 12);
        printf("\n\tAno: ");
        scanf("%d", &(*pc).anon);

            printf("\nDigite a segunda data:");
        do{
            printf("\n\tDia: ");
            scanf("%d", &(*pc).diaa);
        }while ((*pc).diaa > 31);
        do
        {
            printf("\n\tMês: ");
            scanf("%d", &(*pc).mesa);
        } while ((*pc).mesa > 12);
        printf("\n\tAno: ");
        scanf("%d", &(*pc).anoa);

        //**********ANOS
        if((*pc).anoa > (*pc).anon){(*pc).anos = (*pc).anoa - (*pc).anon;}
        else if((*pc).anoa == (*pc).anon){(*pc).anos = 0;}
        else{(*pc).anos = (*pc).anon - (*pc).anoa;}

        //**********MESES

        if((*pc).mesn > (*pc).mesa){
            (*vp) = (*pc).mesn;
            (*pc).mesn = (*pc).mesa;
            (*pc).mesa = (*vp);
        }

        if ((*pc).mesa < (*pc).mesn || ((*pc).mesa == (*pc).mesn && (*pc).diaa < (*pc).dian)){
            (*pc).anos--;
            (*pc).mes = 12 - (*pc).mesn + (*pc).mesa;
        }else{(*pc).mes = (*pc).mesa - (*pc).mesn;}

        //**********DIAS

        if ((*pc).diaa < (*pc).dian){
            (*pc).mes--;
            if ((*pc).mesn == 2 && (((*pc).anoa % 4 == 0 && (*pc).anoa % 100 != 0) || ((*pc).anoa % 400 == 0))){(*pc).dias = 29 - (*pc).dian + (*pc).diaa;}
            else if ((*pc).mesn == 2){(*pc).dias = 28 - (*pc).dian + (*pc).diaa;}
            else if ((*pc).mesn == 4 || (*pc).mesn == 6 || (*pc).mesn == 9 || (*pc).mesn == 11){(*pc).dias = 30 - (*pc).dian + (*pc).diaa;}
            else{(*pc).dias = 31 - (*pc).dian + (*pc).diaa;}
            }
        else{
            if ((*pc).mesn == 2 && (((*pc).anoa % 4 == 0 && (*pc).anoa % 100 != 0) || ((*pc).anoa % 400 == 0))){(*pc).dias = (*pc).diaa - (*pc).dian;}
            else if ((*pc).mesn == 2){(*pc).dias = (*pc).diaa - (*pc).dian;}
            else if ((*pc).mesn == 4 || (*pc).mesn == 6 || (*pc).mesn == 9 || (*pc).mesn == 11){(*pc).dias = (*pc).diaa - (*pc).dian;}
            else{(*pc).dias = (*pc).diaa - (*pc).dian;}
        }

        diast(pc);

        printf("O número de dias entre as datas é: %d", (*pc).diatotal);

        opcao= reiniciar(opcao);
    }
    while(opcao==1);

    return 0;
}

void diast(struct data *pc){
    int cont, *cp;
    int anob=0, *ab;
    cp = &cont;
    ab = &anob;

    for((*cp)=0;(*cp)<=(*pc).anos;(*cp)++){
        if((*cp) % 4 == 0){(*ab)++;}
    }
    (*pc).diatotal = (((*pc).anos * 365) + (*ab)) + (*pc).dias + ((*pc).mes * 30);

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

#endif // ex6
