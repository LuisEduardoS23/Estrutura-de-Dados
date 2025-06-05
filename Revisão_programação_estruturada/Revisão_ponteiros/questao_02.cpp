#include <stdio.h>

int main (){

    int num1, num2;

    int* maior;

    if (&num1 > &num2 ){
        maior = &num1;
    }

    else if (&num1 < &num2){
        maior = &num2;
    }

    printf("O endereco de num1 e: %p\n", &num1);
    printf("O endereco de num2 e: %p\n", &num2);

    printf("O maior endereco e: %p\n", maior);

    return 0;
}