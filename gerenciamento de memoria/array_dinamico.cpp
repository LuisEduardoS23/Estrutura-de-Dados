#include <stdio.h>
#include <stdlib.h>

int main (){

    int n, *array;

    printf("Qual o tamanho do array?   ");
    scanf("%d", &n);

    array = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("\nDigite o num %d do array:  ", i+1);
        scanf("%d", &array[i]);
    }
    printf("\nARRAY: \n");
    for (int j = 0; j < n; j++)
    {
        printf("%d, ", array[j]);
    }
    
    
    

    return 0;
}