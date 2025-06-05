#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *proximo;
    struct no *anterior;
} No;


void inserir_final(No **cabeca){

    No *novo = (No*) malloc(sizeof(No));

    printf("Digite o numero que deseja inserir: ");
    scanf("%d", &novo->dado);

    //CASO SEJA O PRIMEIRO ELEMENTO
    if(*cabeca == NULL){
        novo->proximo = *cabeca;
        novo->anterior = NULL;
        *cabeca = novo;
        return;
    } else{

    //CASO JÁ TENHA ELEMENTOS

    No *ultimo = *cabeca;
    while (ultimo->proximo != NULL)
    {
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = novo;
    novo->anterior = ultimo;
    novo->proximo = NULL;
}

}


void imprimir_lista(No ** cabeca){

    No *leitor = *cabeca;
    printf("Lista: |");
    while (leitor != NULL)
    {
        printf(" %d |", leitor->dado);
        leitor = leitor->proximo;
    }
    
}

void selection_sort(No ** cabeca){

    No *atual = *cabeca;

    while (atual != NULL)
    {
        No *menor = atual;
        No *aux = menor->proximo;

        while (aux != NULL)
        {
            if (aux->dado < menor->dado)
            {
                menor = aux;
            }
            aux = aux->proximo;
            
        }

        if (menor != atual)
        {
            int temp = atual->dado;
            atual->dado = menor->dado;
            menor->dado = temp;
        }

        atual = atual->proximo;
        
    }
    





    


}




int main (){

    No *cabeca = NULL;
    int option;
    do{
        printf("\n1 - Inserir elemento no final;");
        printf("\n2 - Imprimir lista;");
        printf("\n3 - Organizar com SELECTION SORT;");
        printf("\n0 - Sair.");
        printf("\nEscolha uma opcao acima:    ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            inserir_final(&cabeca);
            break;

        case 2:
            imprimir_lista(&cabeca);
            break;
        case 3:
            selection_sort(&cabeca);
            break;

        case 0:{
            No *atual = cabeca;
            No *proximo = NULL;

            while (atual != NULL)
            {
                proximo = atual->proximo;
                free(atual);
                atual = proximo;
            }
            
        }
        
        default:
            break;
        }



    }
    while (option != 0);
    


    return 0;
}