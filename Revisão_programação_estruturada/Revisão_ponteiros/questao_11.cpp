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
        if (array_inteiros[i] % 2 == 0)
        {
            printf("%p    ", &array_inteiros[i]);
        }
        else
        {
            printf("Numero primo    ");
        }
        
        
    }
    
    

    return 0;
}