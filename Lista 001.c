#define exercicio1
#include <stdio.h>
#include <math.h>

/* 1. Ler um número inteiro e exiba o seu sucessor e seu antecessor. */

#ifdef exercicio1

main()
{
    int A, SUCESSOR, ANTECESSOR;

    printf("Digite um numero qualquer:\n");
    scanf("%i", &A);

SUCESSOR=A+1;
ANTECESSOR=A-1;

    printf("Sucessor: %i\n", SUCESSOR);
    printf("Antecessor: %i", ANTECESSOR);

return 0;
}
#endif // exercicio1

/* 2. Receber um valor positivo e exiba esse valor com reajuste de 10%. */

#ifdef exercicio2

main()
{
    float valor, DEZPORC, RESULT;

    printf("Digite um valor positivo:\n");
    scanf("%g", &valor);
    while(valor<0)
    {
       printf("Valor informado negativo. Digite um valor positivo: \n");
       scanf("%g", &valor);
    }

DEZPORC=valor*0.10;
RESULT=valor+DEZPORC;

    printf("Com reajuste de dez por cento, o valor resulta em: %g\n", RESULT);

return 0;
}
#endif // exercicio2

/* 3. Informar um preço de um produto e calcular novo preço com desconto de 9%. */

#ifdef exercicio3

main()
{
float preco, NOVEPORC, RESULT;

    printf("Digite um valor do preco:\n");
    scanf("%g", &preco);

    while(preco<=0)
    {
        printf("Valor informado negativo. Digite um valor positivo: \n");
        scanf("%g", &preco);
    }

NOVEPORC=preco*0.09;
RESULT=preco-NOVEPORC;

    printf("Com o desconto de nove por cento, o valor do preco e: %g\n", RESULT);

return 0;
}
#endif // exercicio3

/* 4. Cálculo de um salário líquido de um professor. Serão fornecidos valor da hora aula, número de aulas dadas e o % de desconto do INSS. */

#ifdef exercicio4

main()
{
    float VH, NA, INSS, DESINSS, RESULT;

    printf("Digite o valor da hora aula:\n");
    scanf("%g", &VH);
    while(VH<=0)
    {
        printf("Valor digitado negativo. Digite um valor positivo: \n");
        scanf("%g", &VH);
    }

    printf("Digite o numero de aulas:\n");
    scanf("%g", &NA);
    while(NA<=0)
    {
        printf("Valor digitado negativo. Digite um valor positivo: \n");
        scanf("%g", &NA);
    }

    printf("Digite a porcentagem de desconto do INSS:\n");
    scanf("%g", &INSS);
    while(INSS<0)
    {
        printf("Valor digitado inferior a 0. Digite a porcentagem de desconto do INSS: \n");
        scanf("%g", &INSS);
    }

DESINSS=(VH*NA)*(INSS/100);
RESULT=(VH*NA)-DESINSS;

    printf("Desconto do INSS: %g\n", DESINSS);
    printf("Valor do salario liquido do(a) professor(a): %g\n", RESULT);

return 0;
}
#endif // exercicio4

/*
5. O custo ao consumidor de um carro novo é a soma do preço da fábrica com o percentual de lucro do distribuidor
e dos impostos aplicados ao preço de fábrica. Faça um programa que receba o preço de fábrica de um veículo, o
percentual de lucro do distribuidor e o percentual de impostos. Calcule e mostre:
a. O valor correspondente ao lucro do distribuidor
b. O valor correspondente aos impostos
c. O preço final do veículo
*/

#ifdef exercicio5

main()
{
float PFAB, PLUC, PIMP, LDIS, IMP, PFIN;

    printf("Digite o valor do preco de fabrica: \n");
    scanf("%g", &PFAB);
    while (PFAB<=0)
    {
        printf("Digite um positivo para o preco de fabrica: \n");
        scanf("%g", &PFAB);
    }

    printf("Digite o percentual de lucro do distribuidor: \n");
    scanf("%g", &PLUC);
    while (PLUC<=0)
    {
        printf("Digite um positivo para o lucro do distribuidor: \n");
        scanf("%g", &PLUC);
    }


    printf("Digite o percentual de impostos: \n");
    scanf("%g", &PIMP);
    while (PIMP<=0)
    {
        printf("Digite um positivo para o percentual de impostos: \n");
        scanf("%g", &PIMP);
    }

LDIS=PFAB*(PLUC/100);
IMP=PFAB*(PIMP/100);
PFIN=PFAB+LDIS+IMP;

    printf("Valor correspondente ao lucro do distribuidor: %g\n", LDIS);
    printf("Valor correspondente aos impostos: %g\n", IMP);
    printf("Preco final do veiculo: %g\n", PFIN);

return 0;
}
#endif // exercicio5

/* 6. Elabore um programa que receba o salário de um funcionário e calcule o reajuste desse salário. Considere
que o funcionário deve receber um reajuste de 15% caso seu salário seja menor que 800 reais. Se o salário for
maior ou igual a 800 e menor ou igual a 1000, seu reajuste será de 10 %; caso seja maior que 1000, o reajuste
deve ser de 5%. Ao final do programa deve apresentar o valor antigo e o novo salário. */

#ifdef exercicio6

main()
{
float SALARIO, QUINZEPORC, DEZPORC, CINCOPORC;

    printf("Digite o valor do salario: \n");
    scanf("%g", &SALARIO);
    while(SALARIO<=0)
    {
        printf("Digite um valor positivo para o salario: \n");
        scanf("%g", &SALARIO);
    }

QUINZEPORC=SALARIO+(SALARIO*0.15);
DEZPORC=SALARIO+(SALARIO*0.10);
CINCOPORC=SALARIO+(SALARIO*0.05);

    printf("Salario antigo: %g\n", SALARIO);

    if(SALARIO<800)
    {
    printf("Percentual de reajuste: quinze por cento\n");
    printf ("Salario novo: %g\n", QUINZEPORC);
    }
    else if(SALARIO<=1000)
    {
    printf("Percentual de reajuste: dez por cento\n");
    printf ("Salario novo: %g\n", DEZPORC);
    }
    else (SALARIO>1000);
    {
    printf("Percentual de reajuste: cinco por cento\n");
    printf ("Salario novo: %g\n", CINCOPORC);
    }
return 0;
}
#endif // exercicio6

/* 7. Leia quatro valores referentes às notas escolares de um aluno e exiba uma mensagem dizendo que
ele foi aprovado se a média for maior ou igual a 6. Caso contrário informe que ele está reprovado. Apresente
junto à mensagem o valor da média obtida pelo aluno independente de ter sido aprovado ou não. As notas deverão
ser maiores ou iguais a zero e menores ou iguais a dez */

#ifdef exercicio7

main()
{
  float nota1, nota2, nota3, nota4, MEDIA;

  printf("As notas nao podem ser menores que zero ou maiores que dez\n");

  printf("Digite a primeira nota do(a) aluno(a): ");
  scanf("%g",&nota1);
  while (nota1 <0 || nota1 > 10)
    {printf("Nota invalida. Insira a primmeira nota, com valor entre 0 e 10: \n");
    scanf("%g", &nota1);}

  printf("Digite a segunda nota do(a) aluno(a): ");
  scanf("%g",&nota2);
  while (nota2 <0 || nota2 > 10)
    {printf("Nota invalida. Insira a segunda nota, com valor entre 0 e 10: \n");
    scanf("%g", &nota2);}

  printf("Digite a terceira nota do(a) aluno(a): ");
  scanf("%g",&nota3);
  while (nota3 <0 || nota3 > 10)
    {printf("Nota invalida. Insira a terceira nota, com valor entre 0 e 10: \n");
    scanf("%g", &nota3);}

  printf("Digite a quarta nota do(a) aluno(a): ");
  scanf("%g",&nota4);
  while (nota4 <0 || nota4 > 10)
    {printf("Nota invalida. Insira a quarta nota, com valor entre 0 e 10: \n");
    scanf("%g", &nota4);}

  MEDIA=(nota1+nota2+nota3+nota4)/4;

  printf("Media do(a) aluno(a) = %g\n", MEDIA);

  if (MEDIA>=6)
  {printf("Aluno(a) aprovado(a)\n");}
  else
  {printf("Aluno(a) reprovado(a)\n");}

return 0;
}
#endif // exercicio7

/* 8.	Receba dois números, o primeiro deve ser maior que 10 e menor que 25, o segundo deve ser
maior ou igual a zero, o terceiro deve ser a soma dos dois primeiros e o quarto é o produto dos
três números anteriores. Calcule e exiba a soma dos quadrados de cada um dos quatro números. Caso
o resultado seja menor que 50000, solicite novos dados. */

#ifdef exercicio8

int main()
{
    int valor1, valor2, valor3, valor4, Q1, Q2, Q3, Q4, QT;

    do{
    printf("Digite o primeiro numero, que deve ser maior que 10 e menor que 25: \n");
    scanf("%i", &valor1);
    while (valor1<10 || valor1>25)
    {printf("Valor invalido. Digite um numero maior que 10 e menor que 25: \n");
    scanf("%i", &valor1);}

    printf("Digite o segundo numero, que deve ser maior que zero: \n");
    scanf("%i", &valor2);
    while (valor2<0)
    {printf("Valor invalido. Digite um numero maior que 0: \n");
    scanf("%i", &valor2);}

    valor3= valor1+valor2;
    printf("Valor do terceiro numero: %i\n", valor3);
    valor4=valor1+valor2+valor3;
    printf("valor do quarto numero: %i\n", valor4);

    Q1=pow(valor1, 2);
    Q2=pow(valor2, 2);
    Q3=pow(valor3, 2);
    Q4=pow(valor4, 2);

    printf("Quadradro do primeiro numero: %i\n", Q1);
    printf("Quadrado do segundo numero: %i\n", Q2);
    printf("Quadrado do terceiro numero: %i\n", Q3);
    printf("Quadrado do quarto numero: %i\n", Q4);

    QT= Q1+Q2+Q3+Q4;

    printf("Resultado da soma dos quadrados: %i\n\n", QT);

    if (QT<5000)
    {
        printf("Valor da soma dos quadrados menor que 5.000, digite novos dados\n\n");
    }
}
    while(QT<5000);

    return 0;
}
#endif // exercico8

/* 9. Leia dois valores a e b e os escreve com a mensagem: "São múltiplos" ou "Não são múltiplos". */

#ifdef exercicio9
main()
{
    int valor1, valor2, restdiv;

    printf("Digite o primmeiro valor: \n");
    scanf("%i", &valor1);
    printf ("Digite o segundo valor: \n");
    scanf("%i", &valor2);

    if (valor1>valor2)
    {
        restdiv=valor1%valor2;
    }
    else if (valor2>valor1)
    {
        restdiv=valor2%valor1;
    }

    if (restdiv==0)
    {
        printf("\nOs valores informados sao multiplos \n");
    }
    else
    {
        printf("\nOs valores informados nao sao multiplos \n");
    }
}

#endif // exercicio9

/* 10. Leia o preço de um produto e inflaciona esse preço em 10% se ele for menor que 100
e em 20% se ele for maior ou igual a 100. */

#ifdef exercicio10
main()
{
  float preco, reajuste;

  printf("Digite o valor do preco: \n");
  scanf("%g", &preco);
  while(preco<=0)
  {
      printf("O preco deve corresponder a um valor positivo: \n");
      scanf("%g", &preco);
  }

  if (preco<100)
    {
    reajuste=preco+(preco*0.10);
    printf("Preco menor que 100, aplicavel reajuste de dez por cento\n");
    printf("Valor reajustado: %g", reajuste);
    }
    else
    {
        reajuste=preco+(preco*0.20);
        printf("Preco maior ou igual a 100, aplicavel reajuste de vinte por cento\n");
        printf("Valor reajustado: %g", reajuste);
    }

    return 0;
}
#endif // exercicio10

/* 11.	Leia dois números inteiros e mostre o maior deles. */

#ifdef exercicio11
main()
{
    int n1, n2, maior;

    printf("Digite o primeiro numero: \n");
    scanf("%i", &n1);
    printf("Digite o segundo numero: \n");
    scanf("%i", &n2);

    if (n1>n2)
   {
    maior= n1;
    printf("Dentre os numeros informados, este e o maior: %i", maior);
    }
    else if (n2>n1)
    {
    maior= n2;
    printf("Dentre os numeros informados, este e o maior: %i", maior);
    }
    else
    {printf("Os numeros sao iguais");}


    return 0;
}

#endif // exercicio11

/* 12.	Leia o número de identificação, as 3 notas obtidas por um aluno nas 3 verificações
e a média dos exercícios que fazem parte da avaliação. Calcular a média de aproveitamento,
usando a fórmula: MA = (Nota1 + Nota2 x 2 + Nota3 x 3 + ME)/7 */

#ifdef exercicio12

int main()
{
    float ident, nota1, nota2, nota3, ME, MA;

    printf("Digite o numero de identificacao do(a) aluno(a): \n");
    scanf("%g", &ident);
    printf("Digite a primeira nota: \n");
    scanf("%f", &nota1);
    while(nota1<0||nota1>10)
    {
        printf("\nInvalido. Digite um valor entre 0 e 10\n");
        scanf("%f", &nota1);
    }
    printf("Digite a segunda nota: \n");
    scanf("%f", &nota2);
    while(nota2<0||nota2>10)
    {
        printf("\nInvalido. Digite um valor entre 0 e 10\n");
        scanf("%f", &nota2);
    }
    printf("Digite a terceira nota: \n");
    scanf("%f", &nota3);
    while(nota3<0||nota3>10)
    {
        printf("\nInvalido. Digite um valor entre 0 e 10\n");
        scanf("%f", &nota3);
    }
    printf("Digite a media de exercicios: \n");
    scanf("%f", &ME);
    while(ME<0||ME>10)
    {
        printf("\nInvalido. Digite um valor entre 0 e 10\n");
        scanf("%f", &ME);
    }

    MA= (nota1+(nota2*2)+(nota3*3)+ME)/7;

    printf("\nNumero do(a) aluno: %g\n", ident);
    printf("Notas do(a) aluno(a): %.2f %.2f %.2f\n", nota1, nota2, nota3);
    printf("Media de exercicios: %.2f\n", ME);
    printf("Media de aproveitamento: %.2f\n", MA);

    if(MA<4)
    {
        printf("Conceito do(a) aluno(a): E\n");
        printf("Aluno(a) Reprovado(a)\n");
    }
    else if (MA<6)
    {
        printf("Conceito do(a) aluno(a): D\n");
        printf("Aluno(a) Reprovado(a)\n");
    }
    else if (MA<7.5)
    {
        printf("Conceito do(a) aluno(a): C\n");
        printf("Aluno(a) Aprovado(a)\n");
    }
    else if (MA<9)
    {
        printf("Conceito do(a) aluno(a): B\n");
        printf("Aluno(a) Aprovado(a)\n");
    }
    else if (MA>9)
    {
        printf("Conceito do(a) aluno(a): A\n");
        printf("Aluno(a) Aprovado(a)\n");
    }

    return 0;
}
#endif // exercicio12
