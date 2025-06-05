#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct {
    char nome[30];
    char cpf[12];
    char sexo;
    Data nascimento;
    Pessoa *prox;
} Pessoa;


void cadastrarCliente(Pessoa **cabeca){

    Pessoa *novo = (Pessoa*) malloc(sizeof(Pessoa));

    printf("\nDigite o nome do cliente: ");
    scanf("%[^\n]s", &novo->nome);

    printf("\nDigite o CPF do cliente: ");
    scanf("%[^\n]s", &novo->cpf);

    printf("\nDigite o sexo do cliente (F ou M): ");
    scanf("%[^\n]s", &novo->sexo);

    printf("\nDigite o dia de nascimento: ");
    scanf("%d", &novo->nascimento.dia);

    printf("\nDigite o mes de nascimento: ");
    scanf("%d", &novo->nascimento.mes);

    printf("\nDigite o ano de nascimento: ");
    scanf("%d", &novo->nascimento.ano);

    novo->prox = NULL;
    *cabeca = novo;


}


int main (){

    Pessoa *cabeca = NULL;
    int option;

    do{
        printf("1 - Cadastrar cliente;\n");
        printf("Escolha uma opcao acima:    ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            cadastrarCliente(&cabeca);
            break;
        case 0:{
            Pessoa *atual = cabeca;
            Pessoa *prox = NULL;

            while (atual != NULL)
            {
                prox = atual->prox;
                free(atual);
                atual = prox;
            }
            
        }
        
        default:
            break;
        }




    }
    while (option != 0);
    


    return 0;
}