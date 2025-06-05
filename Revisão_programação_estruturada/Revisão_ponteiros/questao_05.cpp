#include <stdio.h>

void organizador (int* ponteiro1, int* ponteiro2);
int main (){
    int num1, num2;

    printf("Digite um inteiro: \n");
    scanf("%d", &num1);
    printf("Digite um segundo inteiro: \n");
    scanf("%d", &num2);

    printf("ANTES DE ORGANIZAR    INTEIRO_1:  %d    INTEIRO_2:  %d\n", num1, num2);
    organizador(&num1, &num2);
    printf("DEPOIS DE ORGANIZAR    INTEIRO_1:  %d    INTEIRO_2:  %d\n", num1, num2);

    return 0;
}

void organizador (int* ponteiro1, int* ponteiro2){

    if (*ponteiro1 < *ponteiro2)
    {
        int temporario = *ponteiro1;
        *ponteiro1 = *ponteiro2;
        *ponteiro2 = temporario;
    }
    

}