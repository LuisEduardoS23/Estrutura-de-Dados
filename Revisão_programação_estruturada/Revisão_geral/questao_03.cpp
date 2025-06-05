#include <stdio.h>

int main (){

    int num;
    float num2;
    char letra;

    printf("Digite um numero inteiro:  \n");
    scanf("%d", &num);
    printf("Digite um numero flutuante:  \n");
    scanf("%f", &num2);
    getchar();
    printf("Digite uma letra:  \n");
    scanf("%c", &letra);

    int* ponteiro_inteiro = &num;
    float* ponteiro_float = &num2;
    char* ponteiro_char = &letra;

    printf("DADOS ANTES:    %d  %f  %c\n", num, num2, letra);
    
    *ponteiro_inteiro *= 3;
    *ponteiro_float += 5.5;
    *ponteiro_char = 'j';

    printf("DADOS DEPOIS:    %d  %f  %c\n", num, num2, letra);

    return 0;
}