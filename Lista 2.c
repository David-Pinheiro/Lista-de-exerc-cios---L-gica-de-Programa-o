#define exercicio1
#include <stdio.h>
#include <math.h>
#include<locale.h>

#ifdef exercicio1

int main()
{

    setlocale(LC_ALL, "");

    float a, b, c, delta, x1, x2;

    printf("1. Receba tres numeros que garantam a existencia de uma equacao do 2 grau. Se houver raizes reais exiba-as, caso contrario informe ao usuario \n\n");

    printf("f(x) = ax² + bx + c\n\n");
    printf("a = "); scanf("%f", &a);

    while(a==0)
    {
        printf("Em uma equacao do segundo grau, o coeficiente 'a' nao pode ser igual a 0. Digite novamente: \n");
        printf("a = "); scanf("%f", &a);
    }

    printf("b = "); scanf("%f", &b);
    printf("c = "); scanf("%f", &c);

    system("cls");
    printf("\nf(x) = %8.2fx² + %8.2fx + %8.2f\n", a, b, c);

    delta = (b*b) - 4 * a * c;

    if(delta < 0)
    {
        printf("\nDELTA = %8.2f\nNão possui raízes reais\n\n", delta);
    }
    else
    {
        if(delta == 0)
        {
            x1 = -b / (2 * a);
            printf("\nDELTA = %8.2f \nx'   = %8.2f\n\n", delta, x1);
        }
        else
        {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            printf("\nDELTA = %8.2f \nx'   = %8.2f\nx''  = %8.2f\n\n", delta, x1, x2);
        }
    }

    return 0;
}

#endif // exercicio1

#ifdef exercicio2

int main()
{

    float nivel, qaulas, salario;

    printf("2. A FATEC RUBENS LARA faz o pagamento de seus professores por hora/aula. Faça um algoritmo que calcule e exiba o salario de um professor. Sabe-se que o valor da hora/aula segue a tabela abaixo: Professor Nível 1 R$55,00 por hora/aula Professor Nível 2 R$67,00 por hora/aula Professor Nível 3 R$78,00 por hora/aula. \n\n");

    printf("Insira o nivel do(a) professor(a) [niveis de 1 a 3]: \n");
    scanf("%g", &nivel);

    while(nivel<1 || nivel>3)
    {
        printf("Valor invalido. Os niveis variam de '1' a '3', insira novamente: \n");
        scanf("%g", &nivel);
    }

    printf("Insira a quantidade de hora/aula: \n");
    scanf("%g", &qaulas);

    while(qaulas<=0)
    {
        printf("A quantidade de hora/aula nao pode ser igual ou inferior a '0'. Insira novamente: \n");
        scanf("%g", &qaulas);
    }

    if(nivel==1)
    {
        salario= 55*qaulas;
    }
    else if(nivel==2)
    {
        salario= 67*qaulas;
    }
    else
    {
        salario= 78*qaulas;
    }

    printf("\nProfessor(a) nivel: %g \nQuantidade de hora/aula: %g \nValor do salario: %g", nivel, qaulas, salario);

    return 0;
}

#endif // exercicio2

#ifdef exercicio3

int main()
{
   float num1, num2;

printf("\n 3. Escrever um algoritmo que receba dois números e informe ao usuario se eles sao iguais ou se sao distintos. Se forem distintos informe qual e o maior \n\n");

printf("Digite o primeiro numero: \n");
scanf("%g", &num1);

printf("Digite o segundo valor \n");
scanf("%g", &num2);

if(num1==num2)
{printf("Os numeros sao iguais \n");}

else
{
printf("Os numeros sao distintos \n");

if(num1>num2)
{printf("Este e o numero maior: %g \n", num1);}
else
{printf("Este e o numero maior: %g \n", num2);}
}

    return 0;
}
#endif // exercico3

#ifdef exercicio4

int main()
{
float num1, num2, num3;

printf("4. Escrever um algoritmo que leia tres números quaisquer e informe qual e o maior e se eles forem todos igual informe ao usuario e solicite novos dados \n\n");

printf("Digite tres numeros quaisquer: \n");
scanf("%g %g %g", &num1, &num2, &num3);

while(num1 == num2 == num3)
{
printf("os numeros nao podem ser todos iguais. Insira novos dados: \n");
scanf("%g %g %g", &num1, &num2, &num3);
}

if(num1==num2)
{
    if(num1>num3)
    {
        printf("O primeiro e segundo numeros sao iguais (%g) e ambos sao maiores que o terceiro (%g)\n", num1, num3);
    }
    else
    {
        printf("O primeiro e segundo numeros sao iguais (%g) e ambos sao menores que o terceiro (%g)\n", num1, num3);
    }
}

if(num1==num3)
{
    if(num1>num2)
    {
        printf("O primeiro e terceiro numeros sao iguais (%g) e ambos sao maiores que o segundo (%g)\n", num1, num2);
    }
    else
    {
        printf("O primeiro e terceiro numeros sao iguais (%g) e ambos sao menores que o segundo (%g)\n",num1, num2);
    }
}

if(num1>num2 && num1>num3)
{printf("Este e o maior numero: %g\n", num1);}

else if (num2>num1 && num2>num3)
{printf("Este e o maior numero: %g\n", num2);}

else if (num3>num1 && num3>num2)
{printf("Este e o numero maior: %g \n", num3);}

return 0;
}

#endif // exercico4

#ifdef exercicio5

int main()
{
    int num, restdiv;

    printf("5. Faça um algoritmo para receber um numero qualquer e informar na tela se e par ou impar.");

    printf("Digite um numero qualquer: \n");
    scanf("%i", &num);

    restdiv= num%2;

    if(restdiv==0)
    {
        printf("O numero digitado (%i) e par \n", num);
    }
    else
    {
        printf("O numero ditigado (%i) e impar \n", num);
    }

    return 0;
}

#endif // exercico5

#ifdef exercicio61

int main()
{


    printf("6. Receba tres numeros que representam os lados de um triangulo e garantam a existencia de um triangulo. Informe ao usuario se o triangulo e isoscele, equilatero ou escaleno.

    return 0;
}

#endif // exercicio61

#ifdef exercicio71

int main()
{

    float horast, salmin, salbrut, salario;

    printf("Insira o valor do salario minimo: \n");
    scanf("%g", &salmin);

    while(salmin<=0)
    {
        printf("O valor do salario minimo nao pode ser igual ou inferior a 'o'. Insira novamente: \n");
        scanf("%g", &salmin);
    }

    printf("Insira a quantidade de horas trabalhadas: \n");
    scanf("%g", &horast);

    while(horast<=0)
    {
        printf("A quantidade de horas trabalhadas nao pode ser igual ou inferior a '0'. Insira novamente: \n");
        scanf("%g", &horast);
    }

    salbrut= horast*(salmin/2);
    salario= salbrut-(salbrut*0.03);

    printf("\nSalario minimo: %g \nHoras trabalhadas: %g \nSalario bruto: %g \nSalario liquido: %g \n", salmin, horast, salbrut, salario);

    return 0;
}

#endif // exercicio71

#ifdef exercicio6

int main()
{
    float degrau, altura, x;

    printf("6. Cada degrau de uma escada tem X de altura. Faca um programa que receba essa altura e a altura que o usuario deseja subindo a escada. Calcule e mostre quantos degraus o usuário devera subir para atingir seu objetivo, sem se preocupar com a altura do usuario \n\n");

    printf("Insira a altura do degrau da escada [em cm]: \n");
    scanf("%g", &degrau);

    while(degrau<0)
    {
        printf("A altura nao pode ser igual ou inferior a '0'. Insira novamente a altura do degrau: \n");
        scanf("%g", &degrau);
    }

    printf("Insira a altura que deseja subir [em metros]: \n");
    scanf("%g", &altura);

    while(degrau<0)
    {
        printf("A altura nao pode ser igual ou inferior a '0'. Insira novamente a altura do degrau: \n");
        scanf("%g", &altura);
    }

    x= altura/(degrau/100);

    printf("Para alcancar a altura desejada, sera necessario subir %g degraus", x);

    return 0;
}

#endif // exercicio6

#ifdef exercicio7

int main()
{
   float sexo, altura, x;

   printf("7. Faca um programa que receba a altura e o sexo de uma pessoa e que calcule e mostre o seu peso ideal. \n\n");

   printf("Informe o sexo ['1' para feminino e '2' para masculino]: \n");
   scanf("%g", &sexo);

   while(sexo<1 || sexo>2)
   {
       printf("Valor incorreto. Informe o sexo ['1' para feminino e '2' para masculino: \n");
       scanf("%g", &sexo);
   }

   printf("Informe a altura [em metros]: \n");
   scanf("%g", &altura);

   while(altura<=0)
   {
       printf("A altura nao pode ser igual ou inferior a '0', informe novamente: \n");
       scanf("%g", &altura);
   }

   if(sexo==1)
   {
       x= (62.1*altura)-44.7;
   }
   else
   {
       x= (72*altura)-58;
   }

   printf("\nConsiderando os dados informados, o peso ideal e: %g \n", x);

   return 0;
}

#endif // exercicio7

#ifdef exercicio8

main()
{
float peso, altura, imc;

printf("\n 8. O IMC – Indice de Massa Corporal e um criterio da Organizacao Mundial de Saude para dar uma indicacao sobre a condicao de peso de uma pessoa adulta. A formula e IMC = peso / (altura)2. Elabore um algoritmo que leia o peso e a altura de um adulto e mostre sua condicao \n\n");

printf("Digite o peso: \n");
scanf("%g", &peso);
while(peso<=0)
{
    printf("Valor invalido. Digite um valor superior a 0 \n");
    scanf("%g", &peso);
}

printf("Digite a altura: \n");
scanf("%g", &altura);
    while(altura<=0)
{
    printf("Valor invalido. Digite um valor superior a 0 \n");
    scanf("%g", &altura);
}

altura= pow(altura, 2);

imc= peso/altura;

printf("Valor do IMC: %g \n", imc);

if(imc<17)
{
    printf("Condicao: Muito abaixo do peso");
}
else if(imc>=17 && imc<=18.49)
{
    printf("Condicao: Abaixo do peso");
}
else if(imc>=18.50 && imc<=24.99)
{
    printf("Condicao: Peso normal");
}
else if(imc>=25 && imc<=29.99)
{
    printf("Condicao: Acima do peso");
}
else if(imc>=30 && imc<=34.99)
{
    printf("Condicao: Obesidade I");
}
else if(imc>=35 && imc<=39.99)
{
    printf("Condicao: Obsesidade II - severa");
}
else
{
    printf("Condicao: Obesidade III - morbida");
}

}
#endif // exercicio8

#ifdef exercicio9

int main()
{
    float altura, peso;

    printf("9. Faca um programa que receba a altura e o peso de uma pessoa. De acordo com a tabela a seguir e mostre qual a classificacao dessa pessoa \n");

    printf("Informe o peso: \n");
    scanf("%g", &peso);

    while(peso<=0)
    {
        printf("O peso nao pode ser menor ou igual a '0', informe novamente: \n");
        scanf("%g", &peso);
    }

    printf("Informe a altura: \n");
    scanf("%g", &altura);

    while(altura<=0)
    {
        printf("A altura nao pode ser menor ou igual a '0', informe novamente: \n");
        scanf("%g", &altura);
    }

    if(altura<1.20)
    {
        if(peso<60)
        {
            printf("Peso informado: %g \nAltura informada: %g \nClassificacao correspondente: A\n", peso, altura);
        }
        else if(peso<90);
        {
            printf("Peso informado: %g \nAltura informada: %g \nClassificacao correspondente: D\n", peso, altura);
        }
        if(peso>90)
        {
            printf("Peso informado: %g \nAltura informada: %g \nClassificacao correspondente: G\n", peso, altura);
        }
    }
    else if(altura<1.70)
    {
        if(peso<60)
        {
            printf("Peso informado: %g \nAltura informada: %g \nClassificacao correspondente: B\n", peso, altura);
        }
        else if(peso<90);
        {
            printf("Peso informado: %g \nAltura informada: %g \nClassificacao correspondente: E\n", peso, altura);
        }
        if(peso>90)
        {
            printf("Peso informado: %g \nAltura informada: %g \nClassificacao correspondente: H\n", peso, altura);
        }
    }
    if(altura>1.70)
    {
        if(peso<60)
        {
            printf("Peso informado: %g \nAltura informada: %g \nClassificacao correspondente: C\n", peso, altura);
        }
        else if(peso<90);
        {
            printf("Peso informado: %g \nAltura informada: %g \nClassificacao correspondente: F\n", peso, altura);
        }
        if(peso>90)
        {
            printf("Peso informado: %g \nAltura informada: %g \nClassificacao correspondente: I\n", peso, altura);
        }
    }

    return 0;
}

#endif // exercicio9

#ifdef exercicio10

int main()
{
    int idade, sexo, salario;

    printf("10. Faca um algoritmo que receba o a idade, o sexo (1 para masculino e 2 para feminino) e salario fixo de um funcionario. Mostre o sexo, a idade e o salario obtido apos o acrescimo do abono \n\n");

    printf("Informe o sexo ['1' para masculino e '2' para feminino]: \n");
    scanf("%d", &sexo);

    while(sexo<1 || sexo>3)
    {
        printf("Valor invalido. Informe '1' para masculino e '2' para feminino: \n");
        scanf("%d", &sexo);
    }

    printf("Informe a idade: \n");
    scanf("%d", &idade);

    while(idade<=0)
    {
        printf("A idade nao pode ser igual ou inferior a '0', informe novamente: \n");
        scanf("%d", &idade);
    }

    printf("Informe o salario: \n");
    scanf("%d", &salario);

    while(salario<=0)
    {
        printf("O salario nao pode ser igual ou inferior a '0', informe novamente: \n");
        scanf("%d", &salario);
    }

    if(sexo==1 && idade<=30)
    {
        salario= salario+200;
    }
    else if(sexo==1 && idade>30)
    {
        salario= salario+120;
    }

    if(sexo==2 && idade<=30)
    {
        salario= salario+220;
    }
    else if(sexo==2 && idade>30)
    {
        salario= salario+130;
    }

    printf("\Sexo informado: %d \nIdade informada: %d \nSalario com acrescimo de abono: %d", sexo, idade, salario);

    return 0;
}

#endif // exercicio10

#ifdef exercicioswitch

int main(void) {

    char escolha;

    do {
         printf(" 0 - Sair do menu\n 1 - Exercicio 1\n 2 - Exercicio 2\n 3 - Exercicio 3\n 4 - Exercicio 4\n 5 - Exercicio 5\n 6 - Exercicio 6.1\n 7 - Exercicio 7.1\n 8 - Exercicio 6.2\n 9 - Exercicio 7.2\n 10 - Exercicio 8\n 11 - Exercicio 9\n 12 - Exercicio 10\n");

         scanf(" %c", &escolha);

         switch(escolha)
         {

            case '0': //sair


                break;


            case '1':

            printf("Escolheu primeira opcao\n");

                break;


            case '2':

                printf("Escolheu opção telefone\n");

                break;


            case '3':

                printf("Escolheu opção telefone\n");

                break;


            case '4':

                printf("Escolheu opção telefone\n");

                break;


            case '5':

                printf("Escolheu opção telefone\n");

                break;


            case '6':

                printf("Escolheu opção telefone\n");

                break;


            case '7':

                printf("Escolheu opção telefone\n");

                break;


            case '8':

                printf("Escolheu opção telefone\n");

                break;


            case '9':

                printf("Escolheu opção telefone\n");

                break;


            case '10':

                printf("Escolheu opção telefone\n");

                break;


            case '11':

                printf("Escolheu opção telefone\n");

                break;


            case '12':

                printf("Escolheu opção telefone\n");

                break;


               default:
                   printf("Escolheu uma opção inválida\n");
                   break;
         }
    } while (escolha != '0');

    return 0;
}

#endif // exercicioswitch

