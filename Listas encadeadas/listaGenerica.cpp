#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int dado;
}Elemento;

typedef struct no{
    int index;
    Elemento elemento;
    struct no *prox;
    struct no *anterior;
}No;

typedef struct lista{
    No *comeco;
    No *final;
    int tamanho;
}Lista;

void createList(Lista *lista){
    lista->comeco = NULL;
    lista->final = NULL;
    lista->tamanho = 0;
}

void insertFront(Lista *lista, Elemento newElement){

    No *novo = (No*) malloc(sizeof(No));
    novo->elemento = newElement;
    novo->prox = NULL;
    novo->anterior = NULL;
    novo->index = lista->tamanho;

    if(lista->tamanho == 0){
        lista->comeco = novo;
        lista->final = novo;
    }
    else{
        novo->prox = lista->comeco;
        lista->comeco->anterior = novo;
        lista->comeco = novo;
    }

    lista->tamanho += 1;
}

void insertBack(Lista *lista, Elemento newElement){
    No *novo = (No*) malloc(sizeof(No));
    novo->index = lista->tamanho;
    novo->prox = NULL;
    novo->anterior = NULL;
    novo->elemento = newElement;

    if(lista->tamanho == 0){
        lista->comeco = novo;
        lista->final = novo;
    }
    else{
        novo->anterior = lista->final;
        lista->final->prox = novo;
        lista->final = novo;
    }

    lista->tamanho += 1;
}

void insertAt(Lista *lista,int indexNew, Elemento newElement){
    No *novo = (No*) malloc(sizeof(No));
    novo->index = indexNew;
    novo->prox = NULL;
    novo->anterior = NULL;
    novo->elemento = newElement;

    if(indexNew == 0){
        insertFront(lista, newElement);
        return;
    }
    else if(indexNew == lista->tamanho){
        insertBack(lista, newElement);
        return;
    }
    else if(indexNew < 0 || indexNew > lista->tamanho){
        printf("Error: Index out of bounds.");
        return;
    }

    No *aux = lista->comeco;
    while (aux->prox->index != indexNew)
    {
        aux = aux->prox;
    }

    novo->prox = aux->prox;
    aux->prox->anterior = novo;
    novo->anterior = aux;
    aux->prox = novo;

    aux = novo->prox;

    while (aux != NULL)
    {
        aux->index += 1;
        aux = aux->prox;
    }

    lista->tamanho += 1;

}