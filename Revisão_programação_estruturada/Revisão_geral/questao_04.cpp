#include <stdio.h>

void receber_num(double* valor_a, double* valor_b);
void dobro_num (double* dobro_a, double* dobro_b);
void imprimir_num (double num_a, double num_b);

int main (){
    double num_a, num_b;
    int option;
    do{    
    receber_num(&num_a, &num_b);
    dobro_num(&num_a, &num_b);
    imprimir_num(num_a, num_b);
    

    
    printf("DIGITE 0 PARA ENCERRAR O PROGRAMA OU 1 PARA CONTINUAR...\n");
    scanf("%d", &option);
    }
    while (option > 0);
    
    return 0;
}

void receber_num( double* valor_a, double* valor_b){

    printf("DIGITE UM NUMERO A:  ");
    scanf("%lf", valor_a);

    printf("\nDIGITE UM NUMERO B:  \n");
    scanf("%lf", valor_b);

}

void dobro_num (double* dobro_a, double* dobro_b){

    *dobro_a *= 2;
    *dobro_b *= 2;
}

void imprimir_num (double num_a, double num_b){

    printf("O dobro de A e: %.3lf\n", num_a);
    printf("O dobro de B e: %.3lf\n", num_b);

}