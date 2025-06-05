#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
} No;

typedef struct lista{
    struct no *comeco;
} Lista;

void inicializar_lista(Lista **cabeca){
    if (*cabeca == NULL){
        *cabeca = (Lista *) malloc(sizeof(Lista));
        (*cabeca)->comeco = NULL;
    }
    

}

void inserir_comeco(Lista **cabeca){
    No *novo = (No*) malloc(sizeof(No));
    if(novo != NULL){
        novo->prox = (*cabeca)->comeco;
        (*cabeca)->comeco = novo;

        printf("Digite o dado:  ");
        scanf("%d",&novo->dado);

    } else{
        printf("Erro ao alocar memoria!");
    }

}

void imprimirLista(Lista ** cabeca){
    No *aux = (*cabeca)->comeco;
    printf("Lista: |");
    while (aux != NULL)
    {
        printf(" %d |", aux->dado);
        aux = aux->prox;
    }
    
}

int contagemElementos(Lista **cabeca){
    int contador = 0;
    No *aux = (*cabeca)->comeco;
    while (aux != NULL)
    {
        contador++;
        aux = aux->prox;
    }
    return contador;
}

void limparMemoria(Lista ** cabeca){
    No *atual = (*cabeca)->comeco;
    No *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    (*cabeca)->comeco = NULL;
    free(*cabeca);
    *cabeca = NULL;
    
}

bool listaVazia(Lista ** cabeca){
    if((*cabeca)->comeco == NULL){
        return true;
    } else{
        return false;
    }
}




int main(){
    Lista *cabeca = NULL;

    /* inicializar_lista(&cabeca);
    inserir_comeco(&cabeca);
    inserir_comeco(&cabeca);
    inserir_comeco(&cabeca);
    inserir_comeco(&cabeca);
    imprimirLista(&cabeca);*/
    printf("\nNum de elementos: %d", contagemElementos(&cabeca));
    if(listaVazia(&cabeca)){
        printf("\nLista vazia\n");
    } else{
        printf("\nLista contem elementos\n");
    }
    limparMemoria(&cabeca);



}