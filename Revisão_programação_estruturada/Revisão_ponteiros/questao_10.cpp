#include <stdio.h>

int main (){

    int array_inteiros [5];
    
    for (int i = 0; i < 5; i++)
    {
        printf("Digite o %d valor do array:   ", i+1);
        scanf("%d", &array_inteiros[i]);
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        int* ponteiro_dobro = &array_inteiros[i];
        *ponteiro_dobro *= 2;

        printf("%d  ",  array_inteiros[i]);
    }
    
    

    return 0;
}