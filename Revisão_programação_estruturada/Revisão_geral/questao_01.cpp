#include <stdio.h>
#include <string.h>

int main (){
    char sexo;
    char nome [50];
    printf("Qual o seu sexo? Digite f ou m :");
    scanf("%c", &sexo);
    getchar();

    printf("\nQual o seu nome?\n");
    fgets(nome, 50, stdin);

    int localizacao = strcspn(nome, "\n");

    if (nome[localizacao] == '\n'){
        nome[localizacao] = '\0';
    }

    switch (sexo){

        case 'f':
            printf("Bem vinda %s! E um prazer te ver\n", nome);
            break;
        case 'm':
            printf("Bem vindo %s! E um prazer te ver\n", nome);
            break;
        default:
            printf("CODIGO INVALIDO!!!");
    }
    

    return 0;
}