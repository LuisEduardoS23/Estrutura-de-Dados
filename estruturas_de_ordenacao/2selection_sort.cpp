#include <stdio.h>
#include <stdlib.h>




int main (){

    int vetor[] = {1, 8, 19, 1, 5, 7, 15, 22, 6, 3, 12};
    int tamanho = 11;


    //antes da ordenação
    printf("Vetor antes do selection sort: \n|");

    for (size_t i = 0; i < tamanho; i++)
    {
        printf(" %d |", vetor[i]);
    }

    int num_repeticoes = 0;
    //SELECTION SORT

    for (int i = 0; i < tamanho -1; i++)
    {
        for (int j = i; j < tamanho; j++)
        {
            if (vetor[j] < vetor[i])
            {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                num_repeticoes += 1;
            }else{
                num_repeticoes += 1;
            }
            
        }
        
    }



    //mostrando ordenado
        printf("\nVetor DEPOIS do selection sort: \n|");
     for (size_t i = 0; i < tamanho; i++)
    {
        printf(" %d |", vetor[i]);
    }
    printf("\nNumero de repeticoes: %d", num_repeticoes);
    
    


}