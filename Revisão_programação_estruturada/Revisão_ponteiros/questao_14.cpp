#include <stdio.h>

void preencher_vetor(int[], int*);

int main (){
    int array[5];
    int num;
    printf("Digite um inteiro:   ");
    scanf("%d", &num);

    preencher_vetor(array, &num);


    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }
    


    return 0;
}

void preencher_vetor(int array[], int* num){

    for (int i = 0; i < 5; i++)
    {
        int* ptr = array;
        ptr= ptr + i;
        *ptr = *num;

    }
    
   
    



}