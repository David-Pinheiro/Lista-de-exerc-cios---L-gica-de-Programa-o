#include "stdio.h"
#include "locale.h"
#include "stdlib.h"

#define ex3

/*
1 - Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
    Receba via teclado diversos caracteres (um por vezes) e escreva-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes).
*/

#ifdef ex1

int reiniciar(int opcao);

int main()
{
    setlocale(LC_ALL, "");
    char a;
    int cont, contc, opcao;

    do
    {
    contc=0;
    FILE *consultar;
    consultar = fopen("arq.txt", "w");

    printf("\nEscreva a quantidade de caracteres que quiser para serem escritos no arquivo .txt (0 finaliza a entrada de dados):\n");

    do
    {
        scanf("%c", &a);

        if(a=='0')
        {
            break;
        }
        contc++;
        putc(a, consultar);

    }
    while (a!='0');

    fclose(consultar);

    consultar = fopen("arq.txt","r");

    printf("\nEstes foram os caracteres digitados:\n");

    for(cont=0; cont<contc; cont++)
    {
       putchar(getc(consultar));
    }

    fclose(consultar);

    opcao= reiniciar(opcao);
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
2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
    1 - inserir contato
    2 - listar todos os contatos
    3 - pesquisar um contato pelo nome
    4 - listar os contatos cujo nome inicia com uma letra digitada
    5 - imprimir os aniversariantes do mês.
    6 - altera contato
    7 - exclui contato
    8 - saida
*/

#ifdef ex2

struct contatos{
    char nome[30];
    char telefone[12];
    char data[6];
};

void insC(struct contatos *pc){
    FILE *file;
    file = fopen("contatos.txt", "w");
    int cont;

    for(cont=0;cont<4;cont++){
        printf("Digite as informações do contato:\n");
        printf("Nome: ");
        fflush(stdin);
        gets(pc[cont].nome);
        fflush(stdin);
        printf("Telefone: ");
        gets(pc[cont].telefone);
        fflush(stdin);
        printf("Data de aniversário: ");
        gets(pc[cont].data);
        fflush(stdin);
        printf("\n");
        fwrite((pc+cont), sizeof(*pc), 1, file);
    }


    system("pause");
    system("cls");
    fclose(file);
}

void listC(struct contatos *pc){
    FILE *file;
    file = fopen("contatos.txt", "r");
    int cont, d;

    printf("Informações de todos os contatos:\n\n");
    for(cont=0;cont<4;cont++){
        fread((pc+cont), sizeof(*pc), 1, file);
            if(pc[cont].nome[0] == '*'){}
            else{
                printf("Contato %d:\n", cont+1);
                printf("---------------------\n");
                printf("Nome: %s\n", pc[cont].nome);
                printf("Telefone: %s\n", pc[cont].telefone);
                printf("Data de aniversário: %s\n\n",pc[cont].data);
            }
    }

    system("pause");
    system("cls");
    fclose(file);
}

void pesqN(struct contatos *pc){
    FILE *file;
    file = fopen("contatos.txt", "r");
    int cont=0, cont2=0, tent=0;
    char conts[30];

    printf("Digite o nome do contato: ");
    getchar();
    gets(conts);

    for(cont=0;cont<4;cont++){
        fread((pc+cont), sizeof(*pc), 1, file);
        for(cont2=0;conts[cont2] != '\0';cont2++){
            if(conts[cont2] != pc[cont].nome[cont2]){break;}
        }
        if(conts[cont2] == '\0' && pc[cont].nome[cont2] == '\0'){
            tent++;
            printf("Dados do contato %d:\n", cont+1);
            printf("--------------------\n");
            printf("Nome: %s\n", pc[cont].nome);
            printf("Telefone: %s\n", pc[cont].telefone);
            printf("Data de aniversário: %s\n\n",pc[cont].data);
        }
    }
    if(tent == 0){printf("Pessoa não encontrada.\n");}

    system("pause");
    system("cls");
    fclose(file);
}

void listL(struct contatos *pc){
    FILE *file;
    file = fopen("contatos.txt", "r");
    int cont, cont2, tent=0;
    char letra;

    fflush(stdin);
    printf("Digite a primeira letra do contato: ");
    letra = getchar();

    for(cont=0;cont<4;cont++){
        if(letra == pc[cont].nome[0]){
            if(pc[cont].nome[0] == '*'){}
            else{
                tent++;
                printf("Dados do contato %d:\n", cont+1);
                printf("--------------------\n");
                printf("Nome: %s\n", pc[cont].nome);
                printf("Telefone: %s\n", pc[cont].telefone);
                printf("Data de aniversário: %s\n\n",pc[cont].data);
            }
        }
    }
    if(tent == 0){printf("Pessoa não encontrada.\n");}

    system("pause");
    system("cls");
    fclose(file);
}

void impD(struct contatos *pc){
    FILE *file;
    file = fopen("contatos.txt", "r");
    int cont;

    for(cont=0;cont<4;cont++){
        if(pc[cont].nome[0] == '*'){}
        else{
            printf("Aniversário do contato %d:\n", cont+1);
            printf("--------------------\n");
            printf("Nome: %s\n", pc[cont].nome);
            printf("Data de aniversário: %s\n\n",pc[cont].data);
        }
    }

    system("pause");
    system("cls");
    fclose(file);
}

void altC(struct contatos *pc, int j){
    FILE *file;
    file = fopen("contatos.txt", "r+");

    int cont, cont2, tent=0;
    char contato[30];

    printf("Digite o nome do contato: ");
    fflush(stdin);
    gets(contato);

    if(j==2){
        for(cont=0;cont<4;cont++){
        for(cont2=0;contato[cont2] != '\0';cont2++){
            if(contato[cont2] != pc[cont].nome[cont2]){break;}
        }
        if(contato[cont2] == '\0' && pc[cont].nome[cont2] == '\0'){
            tent++;
            printf("Contato encontrado!\n\n");
            printf("CONTATO EXCLUIÍDO...\n\n");
            pc[cont].nome[0] = '*';
            fwrite((pc+cont), sizeof(*pc), 1, file);
            }
        }
    if(tent == 0){printf("Pessoa não encontrada.\n");}
    }
    else{
        for(cont=0;cont<4;cont++){
            for(cont2=0;contato[cont2] != '\0';cont2++){
                if(contato[cont2] != pc[cont].nome[cont2]){break;}
            }
            if(contato[cont2] == '\0' && pc[cont].nome[cont2] == '\0'){
                tent++;
                printf("Contato encontrado!\n\n");
                printf("Digite as informações do novo contato:\n");
                printf("Nome: ");
                fflush(stdin);
                gets(pc[cont].nome);
                fflush(stdin);
                printf("Telefone: ");
                gets(pc[cont].telefone);
                fflush(stdin);
                printf("Data de aniversário: ");
                gets(pc[cont].data);
                fflush(stdin);
                fwrite((pc+cont), sizeof(*pc), 1, file);
                }
            }
        if(tent == 0){printf("Pessoa não encontrada.\n");}
    }

    system("pause");
    system("cls");
    fclose(file);
}

void excC(struct contatos *pc){
    FILE *file;
    file = fopen("contatos.txt", "r+");
    int i=2;

    altC(pc, i);

    fclose(file);
}

int main(){
    setlocale(LC_ALL, "");
    struct contatos agenda[4];
    struct contatos *pc;
    pc = agenda;
    int esc, j=1, *ep;
    ep = &esc;

    do{
        do{
            printf("-----------------------------------------\n");
            printf("1 - inserir contato\n");
            printf("2 - listar todos os contatos\n");
            printf("3 - pesquisar um contato pelo nome\n");
            printf("4 - listar os contatos cujo nome inicia com uma letra digitada\n");
            printf("5 - imprimir os aniversariantes do mês.\n");
            printf("6 - altera contato\n");
            printf("7 - exclui contato\n");
            printf("8 - sair\n");
            printf("Qual ação deseja realizar?\n");
            printf("R: ");
            scanf("%d", &(*ep));
            }while(*ep < 1 || *ep > 8);
            system("cls");

            switch(*ep){
                case 1:
                    insC(pc);
                    break;
                case 2:
                    listC(pc);
                    break;
                case 3:
                    pesqN(pc);
                    break;
                case 4:
                    listL(pc);
                    break;
                case 5:
                    impD(pc);
                    break;
                case 6:
                    altC(pc, j);
                    break;
                case 7:
                    excC(pc);
                    break;
                case 8:
                    printf("\nVocê escolheu sair.\n");
                    exit(0);
                    break;
            }
    }while((*ep) != 8);
}

#endif // ex2

#ifdef ex3

/*
3 - escreva um programa para o controle de mercadorias em uma dispensa
doméstica. Para cada produto será armazenado um código numérico, nome
do produto e a quantidade atual numa estrutura de dados. A unica estrutura
de dados deve ser declarada como variavel LOCAL na função main().
Escreva os itens das mercadorias direto no arquivo. (utilize a função fseek
quando necessario). NÃO pode usar vetor de estruturas. Utilize ponteiros.
O programa deve ter as seguintes opções: (cada opção do menu é uma função)
    1 - incluir produtos
    2 - listar todos os produtos
    3 - pesquisar uma mercadoria pela descrição
    4 - listar os produtos não disponiveis
    5 - alterar a quantidade atual
    6 - alterar produtos
    7 - excluir produtos
    8 - saida
*/

struct produtos{
    int cnum_p;
    char nome_p[30];
    int quant_p;
};

void incP(struct produtos *lp){
    FILE *file;
    file = fopen("produtos.txt", "a");

    printf("Digite o código, nome e quantidade do produto:\n");
    printf("Código do produto: ");
    scanf("%d",&lp->cnum_p);
    printf("Nome do produto: ");
    fflush(stdin);
    gets(lp->nome_p);
    fflush(stdin);
    printf("Quatidade: ");
    scanf("%d",&lp->quant_p);

    fwrite(lp, sizeof(*lp), 1, file);

    system("pause");
    system("cls");
    fclose(file);
}

void listP(struct produtos *lp, int *j){
    FILE *file;
    file = fopen("produtos.txt", "r");
    int tent=0, k, *tp, *kp;
    kp = &k;
    tp = &tent;

    if((*j) == 1){
        for(;;){
            (*kp) = fread(lp, sizeof(*lp), 1, file);
            if((*kp) == 0){break;}
            else{
                if(lp->nome_p[0] == '*'){}
                else{
                    (*tp)++;
                    printf("Código do produto: %d\n", lp->cnum_p);
                    printf("Nome do produto: %s\n", lp->nome_p);
                    printf("quantidade: %d\n\n", lp->quant_p);
                }
            }
        }if((*tp)==0){printf("\nNão há produtos a serem mostrados.\n");}
        system("pause");
        system("cls");
    }else{
        for(;;){
            (*kp) = fread(lp, sizeof(*lp), 1, file);
            if((*kp) == 0){break;}
                if(lp->quant_p == 0){
                    if(lp->nome_p[0] == '*'){}
                    else{
                        (*tp)++;
                        printf("Código do produto: %d\n", lp->cnum_p);
                        printf("Nome do produto: %s\n", lp->nome_p);
                        printf("quantidade: %d\n\n", lp->quant_p);
                    }
                }
            }if((*tp)==0){printf("\nNão há produtos a serem mostrados.\n");}
        }

    fclose(file);
}

void pesqP(struct produtos *lp, int *i){
    FILE *file;
    file = fopen("produtos.txt", "r+");

    char produto[30];
    int d, c=0, cont, tent=0, *dp, *cp, *contp, *tp;
    dp = &d;
    cp = &c;
    contp = &cont;
    tp = &tent;

    printf("Escreva o nome do produto: ");
    fflush(stdin);
    gets(produto);

    if((*i) == 1){
        for(;;){
            (*dp) = fread(lp, sizeof(*lp), 1, file);
            if((*dp) == 0){break;}
            for(*contp=0; produto[*contp] != '\0' ; (*contp)++){
                if(produto[*contp] != lp->nome_p[*contp]){break;}
                }
                    if(lp->nome_p[*contp] == '\0' && produto[*contp] == '\0'){
                        if(lp->nome_p[0] == '*'){break;}
                            else{
                            (*tp)++;
                            printf("\nProduto encontrado--------------------------------------\n");
                            printf("Código do produto: %d\n", lp->cnum_p);
                            printf("Nome do produto: %s\n", lp->nome_p);
                            printf("quantidade: %d\n\n", lp->quant_p);
                            break;
                            }
                    }
            }
            if((*tp) == 0){printf("Produto não encontrado.\n");}
            system("pause");
            system("cls");

    }else if((*i) == 2){
        for(;;){
            (*dp) = fread(lp, sizeof(*lp), 1, file);
            if((*dp) == 0){break;}
            for(*contp=0; produto[*contp] != '\0' ; (*contp)++){
                if(produto[*contp] != lp->nome_p[*contp]){
                        (*cp)++;
                        break;
                    }
                }
                    if(lp->nome_p[*contp] == '\0' && produto[*contp] == '\0'){
                        if(lp->nome_p[0] == '*'){break;}
                        else{
                            (*tp)++;
                            int h = (*cp)*sizeof(*lp);
                            printf("\nProduto encontrado--------------------------------------\n");
                            printf("Quantidade atual: %d\n",lp->quant_p);
                            printf("Escreva a nova quantidade do produto: ");
                            scanf("%d",&lp->quant_p);
                            fseek(file, h, 0);
                            fwrite(lp, sizeof(*lp), 1, file);
                            break;
                            }
                    }
            }
            if((*tp) == 0){printf("Produto não encontrado.\n");}
    }else if((*i) == 3){
        for(;;){
            (*dp) = fread(lp, sizeof(*lp), 1, file);
            if((*dp) == 0){break;}
            for(*contp=0; produto[*contp] != '\0' ; (*contp)++){
                if(produto[*contp] != lp->nome_p[*contp]){
                        (*cp)++;
                        break;
                    }
                }
                    if(lp->nome_p[*contp] == '\0' && produto[*contp] == '\0'){
                        if(lp->nome_p[0] == '*'){break;}
                        else{
                            (*tp)++;
                            int h = (*cp)*sizeof(*lp);
                            printf("\nProduto encontrado--------------------------------------\n");
                            printf("Digite o código, nome e quantidade do produto:\n");
                            printf("Código do produto: ");
                            scanf("%d",&lp->cnum_p);
                            printf("Nome do produto: ");
                            fflush(stdin);
                            gets(lp->nome_p);
                            fflush(stdin);
                            printf("Quatidade: ");
                            scanf("%d",&lp->quant_p);
                            fseek(file, h, 0);
                            fwrite(lp, sizeof(*lp), 1, file);
                            break;
                            }
                    }
            }
            if((*tp) == 0){printf("Produto não encontrado.\n");}
    }else{
        for(;;){
            (*dp) = fread(lp, sizeof(*lp), 1, file);
            if((*dp) == 0){break;}
            for(*contp=0; produto[*contp] != '\0' ; (*contp)++){
                if(produto[*contp] != lp->nome_p[*contp]){
                        (*cp)++;
                        break;
                    }
                }
                    if(lp->nome_p[*contp] == '\0' && produto[*contp] == '\0'){
                        if(lp->nome_p[0] == '*'){break;}
                        else{
                            (*tp)++;
                            int h = (*cp)*sizeof(*lp);
                            printf("\nProduto encontrado--------------------------------------\n");
                            printf("\nProduto excluido!\n\n");
                            lp->nome_p[0] = '*';
                            fseek(file, h, 0);
                            fwrite(lp, sizeof(*lp), 1, file);
                            break;
                            }
                    }
            }
            if((*tp) == 0){printf("Produto não encontrado.\n");}
    }

    fclose(file);
}

void listUP(struct produtos *lp){
    FILE *file;
    file = fopen("produtos.txt", "r");
    int a = 2, *ap;
    ap = &a;

    listP(lp, ap);

    system("pause");
    system("cls");
    fclose(file);
}

void altQP(struct produtos *lp){
    FILE *file;
    file = fopen("produtos.txt", "r+");
    int b = 2, *bp;
    bp = &b;

    pesqP(lp, bp);

    system("pause");
    system("cls");
    fclose(file);
}

void altP(struct produtos *lp){
    FILE *file;
    file = fopen("produtos.txt", "r+");
    int e = 3, *ep;
    ep = &e;

    pesqP(lp, ep);

    system("pause");
    system("cls");
    fclose(file);
}

void excP(struct produtos *lp){
    FILE *file;
    file = fopen("produtos.txt", "r+");
    int f = 4, *fp;
    fp = &f;

    pesqP(lp, fp);

    system("pause");
    system("cls");
    fclose(file);
}

int main(){
    setlocale(LC_ALL, "");
    FILE *file;
    struct produtos lista;
    struct produtos *lp;
    lp = &lista;
    int esc, j = 1, *ep, *jp;
    ep = &esc;
    jp = &j;

    do{
        do{
            printf("-----------------------------------------\n");
            printf("1 - incluir produtos\n");
            printf("2 - listar todos os produtos\n");
            printf("3 - pesquisar produto pela descrição\n");
            printf("4 - listar produtos não disponíveis\n");
            printf("5 - alterar a quantidade atual\n");
            printf("6 - alterar produtos\n");
            printf("7 - excluir produtos\n");
            printf("8 - sair\n");
            printf("Qual ação deseja realizar?\n");
            printf("R: ");
            scanf("%d", &(*ep));
            }while(*ep < 1 || *ep > 8);
            system("cls");

            switch(*ep){
                case 1:
                    incP(lp);
                    break;
                case 2:
                    listP(lp, jp);
                    break;
                case 3:
                    pesqP(lp, jp);
                    break;
                case 4:
                    listUP(lp);
                    break;
                case 5:
                    altQP(lp);
                    break;
                case 6:
                    altP(lp);
                    break;
                case 7:
                    excP(lp);
                    break;
                case 8:
                    printf("Você escolheu sair.\n");
                    exit(0);
                    break;
            }
        }while((*ep) != 8);
}

#endif // ex3

#ifdef ex4

/*
4 - Escreva um programa para controle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, email e celular numa estrutura de dados.
    A unica estrutura de dados e' uma variavel LOCAL na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
    passar parametros para as funcoes.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida
*/

struct registros{
    char nome[30];
    char email[50];
    char celular[12];
};

void incR(struct registros *pc){
    FILE *file;
    file = fopen("registros.txt", "a");

    printf("Digite o nome, E-mail e celular:\n");
    printf("Nome: ");
    fflush(stdin);
    gets(pc->nome);
    fflush(stdin);
    printf("E-mail: ");
    gets(pc->email);
    fflush(stdin);
    printf("Celular: ");
    gets(pc->celular);
    fflush(stdin);

    fwrite(pc, sizeof(*pc), 1, file);

    system("pause");
    system("cls");
    fclose(file);
}

void listR(struct registros *pc){
    FILE *file;
    file = fopen("registros.txt", "r");
    int d, tent=0;

    printf("Clientes cadastrados:\n\n");
    for(;;){
        d = fread(pc, sizeof(*pc), 1, file);
            if(d == 0){break;}
                if(pc->nome[0] == '*'){}
                    else{
                        tent++;
                        printf("Nome: %s\n", pc->nome);
                        printf("E-mail: %s\n", pc->email);
                        printf("Celular: %s\n", pc->celular);
                        printf("-----------------------\n\n");
                    }
            }if(tent==0){printf("\nNão há clientes cadastrados.\n");}

    system("pause");
    system("cls");
    fclose(file);
}

void pesqR(struct registros *pc, int i){
    FILE *file;
    file = fopen("registros.txt", "r+");
    int d, cont, cp=0, tent=0;
    char name[30];

    printf("Digite o nome a ser comparado: ");
    fflush(stdin);
    gets(name);

    if(i == 1){
        for(;;){
                d = fread(pc, sizeof(*pc), 1, file);
                if(d == 0){break;}
                for(cont=0; name[cont] != '\0' ; cont++){
                    if(name[cont] != pc->nome[cont]){break;}
                    }
                        if(pc->nome[cont] == '\0' && name[cont] == '\0'){
                            if(pc->nome[0] == '*'){break;}
                            else{
                                tent++;
                                printf("\nCadastro encontrado--------------------------------------\n");
                                printf("Nome: %s\n", pc->nome);
                                printf("E-mail: %s\n", pc->email);
                                printf("Celular: %s\n", pc->celular);
                                printf("-----------------------\n\n");
                                break;
                                }
                        }
                }
                if(tent == 0){printf("Cadastro não encontrado.\n");}
        }else if(i == 2){
            for(;;){
                d = fread(pc, sizeof(*pc), 1, file);
                if(d == 0){break;}
                for(cont=0; name[cont] != '\0' ; cont++){
                    if(name[cont] != pc->nome[cont]){
                            cp++;
                            break;
                        }
                    }
                        if(pc->nome[cont] == '\0' && name[cont] == '\0'){
                            if(pc->nome[0] == '*'){break;}
                            else{
                                tent++;
                                printf("\nCadastro encontrado--------------------------------------\n");
                                printf("Digite o nome, E-mail e celular:\n");
                                printf("Nome: ");
                                fflush(stdin);
                                gets(pc->nome);
                                fflush(stdin);
                                printf("E-mail: ");
                                gets(pc->email);
                                fflush(stdin);
                                printf("Celular: ");
                                gets(pc->celular);
                                fflush(stdin);
                                fseek(file, cp*sizeof(*pc),0);
                                fwrite(pc, sizeof(*pc), 1, file);
                                break;
                                }
                        }
                }
                if(tent == 0){printf("Cadastro não encontrado.\n");}
        }else{
            for(;;){
                d = fread(pc, sizeof(*pc), 1, file);
                if(d == 0){break;}
                for(cont=0; name[cont] != '\0' ; cont++){
                    if(name[cont] != pc->nome[cont]){
                            cp++;
                            break;
                        }
                    }
                        if(pc->nome[cont] == '\0' && name[cont] == '\0'){
                            if(pc->nome[0] == '*'){break;}
                            else{
                                tent++;
                                printf("\nCadastro encontrado--------------------------------------\n");
                                printf("Cadastro Excluido!\n\n");
                                pc->nome[0] = '*';
                                fseek(file, cp*sizeof(*pc),0);
                                fwrite(pc, sizeof(*pc), 1, file);
                                break;
                                }
                        }
                }
                if(tent == 0){printf("Cadastro não encontrado.\n");}
        }

    system("pause");
    system("cls");
    fclose(file);
}

void altR(struct registros *pc){
    FILE *file;
    file = fopen("registros.txt", "r+");
    int a=2;

    pesqR(pc, a);
    fclose(file);
}

void excR(struct registros *pc){
    FILE *file;
    file = fopen("registros.txt", "r+");
    int b = 3;

    pesqR(pc, b);
    fclose(file);
}

int main(){
    setlocale(LC_ALL, "");
    struct registros lista;
    struct registros *pc;
    pc = &lista;
    int esc, j=1;

    do{
        do{
            printf("-----------------------------------------\n");
            printf("1 - inclui registros\n");
            printf("2 - listar todos os registros\n");
            printf("3 - pesquisar registro pelo nome\n");
            printf("4 - altera registro\n");
            printf("5 - exclui registro\n");
            printf("6 - saida\n");
            printf("Qual ação deseja realizar?\n");
            printf("R: ");
            scanf("%d", &esc);
            }while(esc < 1 || esc > 8);
            system("cls");

            switch(esc){
                case 1:
                    incR(pc);
                    break;
                case 2:
                    listR(pc);
                    break;
                case 3:
                    pesqR(pc, j);
                    break;
                case 4:
                    altR(pc);
                    break;
                case 5:
                    excR(pc);
                    break;
                case 6:
                    printf("Você escolheu sair.\n");
                    exit(0);
                    break;
            }
        }while(esc != 6);
}

#endif // ex4
