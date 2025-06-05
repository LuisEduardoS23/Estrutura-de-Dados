#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void contador (int[], int, int*, int*);

int main (){
    srand (time(NULL));
    int n, maior_num, num_repeticoes;

    printf("Digite o numero de elementos do array:  ");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");

    contador(array, n, &maior_num, &num_repeticoes);
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    

    printf("\nMaior num:  %d        Vezes que repetiu:  %d\n", maior_num, num_repeticoes);

    return 0;
}

void contador (int array[], int n, int* maior_num, int* num_repeticoes){

    for (int k = 0; k <= n; k++)
    {
      
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0 ; j--)
        {
            if (array[i] <= array[j])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;

                
            }
            
        }
        
    }
}
    *maior_num = array[n-1];
    *num_repeticoes = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (array[i] == *maior_num)
        {
            *num_repeticoes +=1;
        }
        
    }
    
    

}