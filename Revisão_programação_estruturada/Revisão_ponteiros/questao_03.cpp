#include <stdio.h>

int main (){

    int int_1;
    int int_2;

    printf("Digite um numero inteiro:   ");
    scanf ("%d", &int_1);

    printf("\nDigite um segundo numero inteiro:   ");
    scanf("%d", &int_2);


    printf("\n  O endereco do primeiro e: %p\n  O endereco da segunda e:  %p\n'", &int_1, &int_2);

    if (&int_1 > &int_2)
    {
        printf("O conteudo da de maior endereco e:  %p", int_1);
    }
    else if (&int_2 > &int_1){
        printf("O conteudo da de maior endereco e:  %p", int_2);
    }
    


    return 0;
}