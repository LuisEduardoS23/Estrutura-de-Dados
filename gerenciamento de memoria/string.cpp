#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char nome_temp [100];
    int num_caracteres;
    char *nome;

    printf("Digite seu nome:   ");
    scanf("%[^\n]s", &nome_temp);

    num_caracteres = strlen(nome_temp);
    num_caracteres -= 1;

    nome = (char*) malloc(num_caracteres * sizeof(char));

    strcpy(nome, nome_temp);

    free (nome_temp);

    printf("Seu nome:   %s\n", nome);

    free (nome);

    
    return 0;
}