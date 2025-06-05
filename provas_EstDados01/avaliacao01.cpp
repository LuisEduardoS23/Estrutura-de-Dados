#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car{
    char nome[30];
    int ano;
    double precoCompra;
    double precoVenda;
} Carro;

typedef struct elem{
    Carro *carro;
    struct elem *prox;
    struct elem *ant;
} Elemento;

typedef struct listaVenda{
    Elemento *comeco;
    Elemento *final;
    int tamanho;
} ListaVenda;


typedef struct listaVendidos{
    Elemento *comeco;
    Elemento *final;
    int tamanho;
} ListaVendidos;


void cadastrarEntrada(ListaVenda *listaVenda){

    //COLHENDO INFORMAÇÕES DO CARRO
    Carro *car = (Carro*) malloc(sizeof(Carro));

    if (car == NULL)
    {
        printf("\nERRO DURANTE ALOCACAO DE MEMORIA\n");
        return;
    }
    getchar();
    printf("\nDigite o nome do novo carro:    ");
    scanf("%[^\n]s", car->nome);

    printf("\nDigite o ano de fabricacao do novo carro:   ");
    scanf("%d", &car->ano);

    printf("\nDigite o preco de compra do novo carro:     ");
    scanf("%lf", &car->precoCompra);

    car->precoVenda = (car->precoCompra * 1.2);


    //INSERINDO DENTRO DE ELEMENTO
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->ant = NULL;
    novo->prox = NULL;
    novo->carro = car;


    //INSERINDO NA LISTA

    //se for o primeiro elemento da lista
    if(listaVenda->tamanho == 0){
        listaVenda->comeco = novo;
        listaVenda->final = novo;
        listaVenda->tamanho++;
    }

    //inserindo ordenado

    else{
        Elemento *aux = listaVenda->comeco;
        while (aux != NULL)
        {

            if(strcmp(novo->carro->nome, aux->carro->nome) <= 0){

            //se aux for o primeiro da lista
            if(aux == listaVenda->comeco){
                novo->prox = aux;
                aux->ant = novo;
                listaVenda->comeco = novo;
                listaVenda->tamanho++;
                break;
            }

            //se aux estiver no meio da lista
            else if(aux->ant != NULL && aux->prox != NULL){
                aux->ant->prox = novo;
                novo->ant = aux->ant;
                aux->ant = novo;
                novo->prox = aux;
                listaVenda->tamanho++;
                break;
            }

            //se aux estiver no final da lista
            else if(aux == listaVenda->final){
                novo->ant = aux;
                aux->prox = novo;
                listaVenda->final = novo;
                listaVenda->tamanho++;
                break;
            }   
        }

        else{
            aux = aux->prox;
        }
        }

        if(aux->prox == NULL){
            aux->prox = novo;
            novo->ant = aux;
            listaVenda->final = novo;
            listaVenda->tamanho++;
        }
    }

    printf("\ncomeco da lista:    %s", listaVenda->comeco->carro->nome);
    printf("\nfinal da lista:   %s", listaVenda->final->carro->nome);
    printf("Tamanho da lista:   %d", listaVenda->tamanho);

    printf("\nCARRO CADASTRADO COM SUCESSO!\n");
}


void buscarCarro(ListaVenda *listaVenda){

    int opcaoBusca;

        printf("\n1 - Buscar pelo ano de fabricacao;");
        printf("\n2 - Buscar por faixa de preco;");
        printf("\n3 - Mostrar todos disponiveis para venda;");
        printf("\n0 - Sair.");
        printf("\nEscolha uma opcao acima:    ");
        scanf("%d", &opcaoBusca);

        switch (opcaoBusca)
        {
        case 1:{
            int ano;
            printf("\n\nDigite o ano de fabricacao que deseja buscar:   ");
            scanf("%d", &ano);

            Elemento *aux = listaVenda->comeco;
            printf("\nCarros de %d disponiveis para venda:\n", ano);
            bool encontrado = false;
            while (aux != NULL)
            {
                if (aux->carro->ano == ano)
                {
                    encontrado = true;
                    printf("Nome: %s, Ano de fabricacao: %d, Preco: %.2lf\n", aux->carro->nome, aux->carro->ano, aux->carro->precoVenda);
                    aux = aux->prox;
                }
                else{
                    aux = aux->prox;
                }
            }

            if(!encontrado){
                printf("Nenhum carro desse ano encontrado!\n");
            }

            break;
            
        } 
        case 2:{

            double preco;
            printf("Digite o valor max que deseja buscar:   ");
            scanf("%lf", &preco);

            Elemento *aux = listaVenda->comeco;
            bool encontrado = false;

            while (aux != NULL)
            {

                if(aux->carro->precoVenda <= preco){
                encontrado = true;
                printf("Nome: %s, Ano de fabricacao: %d, Preco: %.2lf\n", aux->carro->nome, aux->carro->ano, aux->carro->precoVenda);
                aux = aux->prox;
                }

                else{
                    aux = aux->prox;
                }
            }

            if(!encontrado){
                printf("\nNenhum carro com esse preco encontrado!\n");
            }
            break;
        }
        case 3:{

            Elemento *aux = listaVenda->comeco;

            if(listaVenda->tamanho == 0){
                printf("Lista vazia!");
                return;
            }

            while (aux != NULL){
                printf("Nome: %s, Ano de fabricacao: %d, Preco: %.2lf\n", aux->carro->nome, aux->carro->ano, aux->carro->precoVenda);
                aux = aux->prox;
            }
            break;
        }
        case 0:{
            return;
            break;
        }
        default:
            printf("\nOpcao Invalida!");
            break;
        }

}



int main (){

    ListaVenda listaVenda = {NULL, NULL, 0};
    ListaVendidos listaVendidos = {NULL, NULL, 0};


    int option;
    do{
        printf("\n1 - Cadastrar entrada de um carro;");
        printf("\n2 - Buscar carros a venda;");
        printf("\nEscolha uma opcao acima:    ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            cadastrarEntrada(&listaVenda);
            break;

        case 2:
            buscarCarro(&listaVenda);
            break;
        
        default:
            break;
        }

    } while (option != 0);
    




    return 0;
}