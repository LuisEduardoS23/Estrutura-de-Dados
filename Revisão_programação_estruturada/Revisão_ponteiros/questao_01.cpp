#include <stdio.h>

int main (){

    int num_inteiro = 5;
    float num_real = 3.45;
    char letra = 'L';

    int* ponteiro_inteiro = &num_inteiro;
    float* ponteiro_real = &num_real;
    char* ponteiro_char = &letra;

    printf("DADOS ANTES: \n");
    printf("INTEIRO: %d     REAL:   %f     CHAR:    %c\n",num_inteiro, num_real, letra);

    *ponteiro_inteiro *= 10;
    *ponteiro_real = 9.999;
    *ponteiro_char = 'J';
    printf("DADOS DEPOIS: \n");
    printf("INTEIRO: %d     REAL:   %f     CHAR:    %c\n",num_inteiro, num_real, letra);

    return 0;
}