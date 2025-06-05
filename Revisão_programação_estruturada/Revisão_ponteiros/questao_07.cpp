#include <stdio.h>

void soma (int* ponteiro1, int* ponteiro2);
int main (){
    int num_A, num_B;

    printf("Digite um inteiro: \n");
    scanf("%d", &num_A);
    printf("Digite um segundo inteiro: \n");
    scanf("%d", &num_B);

    printf("A: %d, B: %d\n", num_A, num_B);
    soma(&num_A, &num_B);

    printf("Soma: %d\n", num_A);


    

    return 0;
}

void soma (int* ponteiro1, int* ponteiro2){

    *ponteiro1 = *ponteiro1 + *ponteiro2;
}