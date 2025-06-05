#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void){
    int n;

    printf("Qual o tamanho do array?    ");
    scanf("%d", &n);
    printf("\n");

    int array [n];

    srand (time(NULL));

    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 11;
    }

    // MOSTRANDO ARRAY ANTES DA BUBBLE SORT -----> (n^2)
        for (int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);

        }
        printf("\n");   

    // BUBBLE SORT

    int num_repeticoes = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                num_repeticoes += 1;
                
            }else{
                num_repeticoes += 1;
            }
            
        }
        
    }


    // MOSTRANDO ARRAY NA TELA

        for (int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }

        printf("\nNumero de repeticoes: %d", num_repeticoes);
    return 0;
}