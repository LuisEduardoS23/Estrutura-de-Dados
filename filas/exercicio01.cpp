#include <stdio.h>
#include <stdlib.h>

typedef struct cliente{
    char nome[100];
    int idade;
}Cliente;

typedef struct no{
    Cliente cliente;
    struct no *prox;
}No;

typedef struct{
    No *comeco = NULL;
    No *final = NULL;
    int tamanho = 0;
}Fila;

// FUNÇÕES GENÉRICAS DA ESTRUTURA

void inserir(Fila *fila, Cliente novoCliente){

    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL){
        printf("\nErro de alocação de Memoria!!!!\n");
        return;
    }

    novoNo->cliente = novoCliente;
    novoNo->prox = NULL;

    if(fila->tamanho == 0){
        fila->comeco = novoNo;
        fila->final = novoNo;
    }
    else{
        fila->final->prox = novoNo;
        fila->final = novoNo;
    }
    fila->tamanho += 1;
}

void remover(Fila *fila){

    if(fila->tamanho == 0){
        printf("\nA fila esta vazia!\n");
        return;
    }

    No *aux = fila->comeco;
    fila->comeco = fila->comeco->prox;
    fila->tamanho -= 1;

    aux->prox = NULL;

    free(aux);
}

void imprimir(Fila *fila){

    if (fila->tamanho == 0){
        printf("\nFILA VAZIA...\n");
        return;
    }

    No *aux = fila->comeco;
    int numeracao = 1;
    printf("\n    FILA:\n\n");
    while (aux != NULL){
        printf("%d - Cliente: %s, idade: %d anos.\n",numeracao, aux->cliente.nome, aux->cliente.idade);
        numeracao += 1;
        aux = aux->prox;
    }

}

void liberarMemoria(Fila *fila){
    No *atual = fila->comeco;
    No *prox = NULL;

    while (atual != 0){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    fila->comeco = NULL;
    fila->final = NULL;
    fila->tamanho = 0;
}



//FUNÇÕES ESPECÍFICAS DO SISTEMA

Cliente criarCliente(){
    Cliente cliente;

        getchar();
    printf("\nInsira o nome do cliente:   ");
    scanf("%[^\n]s", &cliente.nome);


    printf("\nInsira a idade do cliente:   ");
    scanf("%d", &cliente.idade);

    return cliente;
}

void chamarProximo(Fila *fila){

    if(fila->tamanho == 0){
        printf("\nA fila esta vazia!\n");
        return;
    }

    printf("\nO PROXIMO DA FILA E:\n");
    printf("Sr./(Sra.) %s - %d anos.\n", fila->comeco->cliente.nome, fila->comeco->cliente.idade);

    remover(&*fila);

}

int main (){
    Fila fila = {};
    int option;
    do{
        printf("\n\n=-=-=- SISTEMA DE SIMULACAO DE FILA =-=-=-\n");
        printf("1 - CADASTRAR NOVO CLIENTE NA FILA;\n");
        printf("2 - CHAMAR O PROXIMO NA FILA;\n");
        printf("3 - VISUALIZAR FILA INTEIRA;\n");
        printf("0 - FINALIZAR PROGRAMA;\n");
        printf("ESCOLHA UMA OPCAO ACIMA:    ");
        scanf("%d", &option);

        switch (option){

        case 1:
            inserir(&fila, criarCliente());
            break;
        
        case 2:
            chamarProximo(&fila);
            break;

        case 3:
            imprimir(&fila);
            break;

        case 0:
            liberarMemoria(&fila);
            printf("\nEncerrando...");
            break;
        
        default:
            printf("\nOPCAO INVALIDA!!!\n");
            break;
        }
    } while (option != 0);
    
}