#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox = NULL;
}No;

typedef struct pilha{
    No *comeco = NULL;
    int tamanho = 0;
}Pilha;

void adicionarElemento(Pilha *p){

    int newDado;
    printf("\nDigite o valor do Dado do novo elemento:  ");
    scanf("%d", &newDado);

    No *novo = new No;
    if (novo == NULL){
        printf("Erro de alocacao de memoria!!!");
        return;
    }

    novo->dado = newDado;

    if (p->tamanho != 0){
        novo->prox = p->comeco;
    }

    p->comeco = novo;
    p->tamanho += 1;

    printf("\n%d adicionado a pilha com sucesso!\n", newDado);
}


void removerElemento(Pilha *p){

    if (p->tamanho == 0)
    {
        printf("\nPilha vazia, impossivel remover!\n");
        return;
    }
    

    No *aux = p->comeco;
    p->comeco = aux->prox;

    int dadoRemovido = aux->dado;

    aux->dado = 0;
    aux->prox = NULL;

    free(aux);
    p->tamanho -= 1;

    printf("\nItem %d removido do topo da pilha com sucesso!\n", dadoRemovido);
}

void imprimirPilha(Pilha *p){
    if (p->tamanho == 0){
        printf("\nPilha vazia...\n");
        return;
    }

    No *aux = p->comeco;
    printf("\nPILHA:\n");
    while (aux != NULL){

        printf("%d\n", aux->dado);
        aux = aux->prox;
    }
    
}

void desalocarMemoria(Pilha *p){
    if (p->tamanho != 0){

        No *atual = p->comeco;
        No *prox = NULL;

        while (atual != NULL)
        {
            prox = atual->prox;
            atual->dado = 0;
            atual->prox = NULL;
            free(atual);
            atual = prox;
        }
        
        printf("\nMemoria desalocada!\n");
    }
    
}

int main (){

    Pilha p;

    int option;
    do{
        printf("\n1 - ADICIONAR ELEMENTO A PILHA\n");
        printf("2 - REMOVER ELEMENTO DA PILHA;\n");
        printf("3 - IMPRIMIR PILHA;\n");
        printf("0 - ENCERRAR PROGRAMA;\n");
        printf("ESCOLHA UMA OPCAO ACIMA:    ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            adicionarElemento(&p);
            break;

        case 2:
            removerElemento(&p);
            break;
        
        case 3:
            imprimirPilha(&p);
            break;

        case 0:
            desalocarMemoria(&p);
            printf("Encerrando....");
            break;

        default:
            printf("\nERRO!!! Opcao Invalida.\n");
            break;

        }

    } while(option != 0);




    return 0;
}