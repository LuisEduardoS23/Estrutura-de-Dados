#include <stdio.h>

int main (){
    int tamanho_array;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho_array);

    int array_inteiros [tamanho_array];

    //RECOLHE OS NUMEROS DO ARRAY
    for (int i = 0; i < tamanho_array; i++)
    {
        printf("Digite o %d valor do array:  ", i+1);
        scanf("%d", &array_inteiros[i]);

    }

    //MOSTRAR ARRAY ANTES: 
    printf("ARRAY ANTES: \n");
    for (int k = 0; k < tamanho_array; k++)
    {
        printf("%d ", array_inteiros[k]);
    }
    
    //MODIFICA OS NUMEROS DO ARRAY

    for ( int j = 0; j < tamanho_array; j++)
    {
        int* ponteiro_inteiros = &array_inteiros[j];
        *ponteiro_inteiros += 1;
    }

    //IMPRIME O ARRAY MODIFICADO
    printf("\nARRAY DEPOIS: \n");
    for (int l = 0; l < tamanho_array; l++)
    {
        printf("%d ", array_inteiros[l]);
    }
    

    
    return 0;

}