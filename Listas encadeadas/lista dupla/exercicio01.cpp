#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char nome[25];
    char matricula[20]; 
    int idade;
    double notas[3];
    double media;
} Aluno;

typedef struct no{
    Aluno *aluno;
    struct no *prox;
    struct no *anterior;
} No;

typedef struct lista{
    No *comeco;
} Lista;


void cadastrarAluno(Lista ** lista){
    if (*lista == NULL)
    {
        *lista = (Lista*) malloc(sizeof(Lista));
        (*lista)->comeco = NULL;
    }


    No *novo = (No*) malloc(sizeof(No));
    novo->aluno = (Aluno*) malloc (sizeof(Aluno));

    getchar();
    printf("\nDigite o nome do aluno:   ");
    scanf("%[^\n]s", novo->aluno->nome);
    getchar();

    printf("\nDigite a matricula do aluno:(LETRAS MAIUSCULAS)    ");
    scanf("%[^\n]s", novo->aluno->matricula);
    getchar();


    printf("\nDigite a idade do aluno:  ");
    scanf("%d", &novo->aluno->idade);


    printf("\nDigite o valor da primeira nota do aluno:     ");
    scanf("%lf", &novo->aluno->notas[0]);

    printf("\nDigite o valor da segunda nota do aluno:     ");
    scanf("%lf", &novo->aluno->notas[1]);

    printf("\nDigite o valor da terceira nota do aluno:     ");
    scanf("%lf", &novo->aluno->notas[2]);

    double media = 0;
        for (int i = 0; i < 3; i++)
        {
            media += novo->aluno->notas[i];
        }

    media = media / 3;

    novo->aluno->media = media;
        
    //INSERINDO EM ORDEM ALFABETICA SE A LISTA NAO TIVER VAZIA
    if ((*lista)->comeco != NULL)
    {
        No *aux = (*lista)->comeco;
        while (aux != NULL)
        {
            if (strcmp(novo->aluno->nome, aux->aluno->nome) <= 0)
            {
                //SE FOR O PRIMEIRO
                if(aux == (*lista)->comeco){
                    novo->prox = (*lista)->comeco;
                    (*lista)->comeco = novo;
                    novo->anterior = NULL;
                    break;
                }

                //SE FOR NO MEIO
                else{
                    novo->prox = aux;
                    novo->anterior = aux->anterior;
                    aux->anterior->prox = novo;
                    aux->anterior = novo;
                    break;
                }

            } 
            //SE FOR NO FINAL
            else if (aux->prox == NULL){
                novo->prox = aux->prox;
                novo->anterior = aux;
                aux->prox = novo;
                break;
            }

            else{
                aux = aux->prox;
            }
            
        }
        
    }

    else if((*lista)->comeco == NULL){
        novo->prox = (*lista)->comeco;
        novo->anterior = NULL;
        (*lista)->comeco = novo;
    }
    
 
}

void imprimirAlunos(Lista ** lista){
    if((*lista)->comeco == NULL){
        printf("Nenhum aluno cadastrado!");
    } else{

        No *aux = (*lista)->comeco;
        printf("\n\n             ALUNOS MATRICULADOS\n");
        printf("=============================================\n");
        while (aux != NULL){
            

            printf("Nome: %s\n", aux->aluno->nome);
            printf("Idade: %d\n", aux->aluno->idade);
            printf("Matricula: %s\n", aux->aluno->matricula);
            printf("Nota 1: %.2lf\n", aux->aluno->notas[0]);
            printf("Nota 2: %.2lf\n", aux->aluno->notas[1]);
            printf("Nota 3: %.2lf\n", aux->aluno->notas[2]);
            printf("Media: %.2lf\n",aux->aluno->media);
            printf("=============================================\n");
            aux = aux->prox;
        }
    }
}

void removerAluno(Lista ** lista){
    char matriculaBuscada[20];
    getchar();
    printf("Digite a matricula do aluno que deseja remover: (LETRAS MAIUSCULAS)    ");
    scanf("%[^\n]s", &matriculaBuscada);

    No *buscador = (No*) malloc(sizeof(No));
    buscador = (*lista)->comeco;
    bool encontrado = false;
    while (buscador != NULL)
    {
        if (strcmp(buscador->aluno->matricula, matriculaBuscada) == 0)
        {
            int confirmacao;
            encontrado = true;
            printf("O aluno que deseja remover e: %s   -   %s\n", buscador->aluno->nome, buscador->aluno->matricula);
            printf("1 - Confirmar;\n");
            printf("2 - Cancelar;\n");
            printf("Confirme se deseja remover o aluno acima:   ");
            scanf("%d", &confirmacao);


            switch (confirmacao)
            {
            case 1:

                //se no meio
                if (buscador->anterior != NULL && buscador->prox != NULL)
                {

                
                buscador->anterior->prox = buscador->prox;
                buscador->prox->anterior = buscador->anterior;
                buscador->anterior = NULL;
                buscador->prox = NULL;
                free(buscador->aluno);
                free(buscador);
                buscador = NULL;
                printf("\nAluno removido com sucesso!\n");
                break;
                }
                //SE NO COMECO E CHEIA
                else if(buscador->anterior == NULL && buscador->prox != NULL){
                    buscador->prox->anterior = NULL;
                    (*lista)->comeco = buscador->prox;
                    buscador->prox = NULL;
                    free(buscador->aluno);
                    free(buscador);
                    buscador = NULL;
                    printf("\nAluno removido com sucesso!\n");

          
                }

                //SE NO COMECO E COM 1 ELEMENTO
                else if (buscador->anterior == NULL && buscador->prox == NULL){
                    free(buscador->aluno);
                    free(buscador);
                    (*lista)->comeco = NULL;
                    buscador = NULL;
                    printf("\nAluno removido com sucesso!\n");

                }

                //se no final
                else if (buscador->prox == NULL){
                    buscador->anterior->prox = NULL;
                    buscador->anterior = NULL;
                    free(buscador->aluno);
                    free(buscador);
                    buscador = NULL;
                    printf("\nAluno removido com sucesso!\n");

                }
                else{
                    printf("\nLista vazia!\n");
                }

                break;

            case 2:
            printf("\n\n*Operacao cancelada*\n\n");
                break;
                
            default:
            printf("\n\n*ERRO OPCAO INVALIDA!!!*\n\n");
            break;

            }
            break;
        }
        else
        {
            buscador = buscador->prox;
        }
        
        
    }

    if (!encontrado)
    {
        printf("\nAluno nao encontrado no sistema!\n");
    }
}


void desalocarMemoria(Lista **lista){
    No* atual = (*lista)->comeco;
    No* proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->prox;
        free(atual->aluno);
        free(atual);
        atual = proximo;
    }
    
}



int main(){
    Lista *lista = NULL;
    int option;
    do{
        printf("\n\n1 - CADASTRAR ALUNO;\n");
        printf("2 - IMPRIMIR ALUNOS;\n");
        printf("3 - REMOVER ALUNO;\n");
        printf("0 - SAIR;\n");
        printf("Digite uma opcao acima:     ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            cadastrarAluno(&lista);
            break;

        case 2:
            imprimirAlunos(&lista);
            break;

        case 3:
            removerAluno(&lista);
            break;

        case 0:
            desalocarMemoria(&lista);
            free(lista);
            printf("Saindo...");
            break;

        default:
            printf("*Opcao Invalida*");
            break;
        }

    } while(option != 0);
        


    return 0;
}