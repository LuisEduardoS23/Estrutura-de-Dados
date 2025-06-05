#include <stdio.h>

int soma_do_dobro (int* ponteiro1, int* ponteiro2);
int main (){
    int num1, num2;

    printf("Digite um inteiro: \n");
    scanf("%d", &num1);
    printf("Digite um segundo inteiro: \n");
    scanf("%d", &num2);

    printf("ANTES DE DOBRAR    INTEIRO_1:  %d    INTEIRO_2:  %d\n", num1, num2);

    printf("A soma do dobro e: %d", soma_do_dobro(&num1, &num2));
    

    return 0;
}

int soma_do_dobro (int* ponteiro1, int* ponteiro2){

    *ponteiro1 *= 2;
    *ponteiro2 *= 2;

    return (*ponteiro1 + *ponteiro2);


}