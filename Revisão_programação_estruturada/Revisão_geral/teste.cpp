#include <stdio.h>

int main (){

    char nome[50];
    int idade;

    printf("Digite o seu nome:   \n");
    scanf("%[^\n]s", nome);
    
    fflush;
    printf("Digite a sua idade: ");
    scanf("%d", idade);
    printf("Voce tem %d anos", idade);
    printf("Seu nome e:   %s\n", nome);



    return 0;
}