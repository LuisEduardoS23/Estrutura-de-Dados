#include <stdio.h>

void inverte_valores(int* ponteiro_A, int* ponteiro_B);

int main (){

    int num_A;
    int num_B;

    printf("Digite o valor de A:  \n");
    scanf("%d", &num_A);

    printf("Digite o valor de B:  \n");
    scanf("%d", &num_B);

    printf("ANTES DA FUNCAO       A: %d     B: %d\n", num_A, num_B);

    inverte_valores(&num_A, &num_B);

    printf("DEPOIS DA FUNCAO       A: %d     B: %d\n", num_A, num_B);

    return 0;
}

void inverte_valores(int* ponteiro_A, int* ponteiro_B){
    int temporario = *ponteiro_B;
    *ponteiro_B = *ponteiro_A;
    *ponteiro_A = temporario;

}
