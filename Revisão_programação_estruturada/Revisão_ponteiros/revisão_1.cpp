#include <stdio.h>

int main (){

    int razao, PA[10], *ptrTermos;



    printf("PROGRESSAO ARITMETICA\n\n");
    printf("Digite o primeiro termo da PA:  ");
    scanf("%d", &PA[0]);

    printf("\nDigite a razao da PA:  ");
    scanf("%d", &razao);

    ptrTermos = PA;
    PA[1] = 1;

    while (* ptrTermos != PA[9])
    {
        *(ptrTermos +1) = *ptrTermos + razao;
        ptrTermos++;
    }

    printf("|");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d |", PA[i]);
    }
    
    
    




    return 0;
}