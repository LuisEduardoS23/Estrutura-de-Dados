#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void coletar_nome (char**);

int main (){
    
    char *nome;

    coletar_nome(&nome);

    printf("%s\n", nome);

    free(nome);

    return 0;
}

void coletar_nome (char **nome){

    char nome_temporario [100];
    printf("Digite o seu nome completo: ");
    scanf("%[^\n]s", &nome_temporario);

    int num_caracteres = strlen(nome_temporario);

    *nome = (char*) malloc(num_caracteres * sizeof(char));

    strcpy(*nome, nome_temporario);
}