#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    char matricula[10];
    float nota = 0; 
} aluno;

typedef struct elem{
    aluno *aluno = NULL;
    struct elem *prox = NULL;
} elemento;

typedef struct{
    elemento *inicio = NULL;
    elemento *fim = NULL;
    int tamanho = 0;
} lista;

void inserir_inicio(lista *l, aluno *a){


    elemento *novo = new elemento;
    novo->aluno = a;


    //INSERINDO EM UMA LISTA VAZIA
        if(l->tamanho == 0){
            l->inicio = novo;
            l->fim = novo;
            l->tamanho++;
        } 

    //INSERINDO NO INICIO DE UMA LISTA QUE NÃO ESTA VAZIA    
        else{
            novo->prox = l->inicio;
            l->inicio = novo;
            l->tamanho++;
        }
}


void inserir_fim(lista *l, aluno *a){


        elemento *novo = new elemento;
        novo->aluno = a;


    //INSERINDO EM UMA LISTA VAZIA
        if(l->tamanho == 0){
            l->inicio = novo;
            l->fim = novo;
            l->tamanho++;
        } 

    //INSERINDO NO FINAL DE UMA LISTA QUE NÃO ESTA VAZIA    
        else{
            l->fim->prox = novo;
            l->fim = novo;
            l->tamanho++;
        }
}

void imprimir(lista *l){
    elemento *aux = l->inicio;
    printf("Lista com %d alunos;\n", l->tamanho);
    while (aux != NULL)
    {
        printf("%s -> ", aux->aluno->nome);
        aux = aux->prox;
    }
    printf("NULL\n");
    

}


void trocar(){
    
}


int main (){
    aluno a1;
    strcpy(a1.nome, "Joao");

    aluno a2;
    strcpy(a2.nome, "Andre");

    lista lista_alunos;

    imprimir(&lista_alunos);

    inserir_fim(&lista_alunos, &a1);

    imprimir(&lista_alunos);

    inserir_fim(&lista_alunos, &a2);

    imprimir(&lista_alunos);

    inserir_inicio(&lista_alunos, &a1);

    imprimir(&lista_alunos);

    


    return 0;
}