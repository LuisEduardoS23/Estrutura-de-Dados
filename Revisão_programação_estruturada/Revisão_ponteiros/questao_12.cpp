#include <stdio.h>

int organizador (int*, int*, int*);

int main (){

    int num1, num2, num3;

    printf("Digite o primeiro valor:    ");
    scanf("%d", &num1);

    printf("\nDigite o segundo valor:    ");
    scanf("%d", &num2);

    printf("\nDigite o terceiro valor:    ");
    scanf("%d", &num3);

    switch (organizador(&num1, &num2, &num3))
    {
    case 1:
        printf("\nOs 3 valores sao iguais.\n");
        break;

    case 0:
        printf("A sequencia organizada de menor para o maior e:  %d    %d    %d", num1, num2, num3);
    
    default:
        break;
    }

    return 0;
}

int organizador (int* ponteiro_1, int* ponteiro_2, int* ponteiro_3){

    if (*ponteiro_1 == *ponteiro_2 && *ponteiro_1 == *ponteiro_3)
    {
        return 1;
    }

    else{

        int inteiros[3];

        inteiros[0] = *ponteiro_1;
        inteiros[1] = *ponteiro_2;
        inteiros[2] = *ponteiro_3;

        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < 2; i++) { 
                if (inteiros[i] > inteiros[i + 1]) {
                    int temporario = inteiros[i];
                    inteiros[i] = inteiros[i + 1];
                    inteiros[i + 1] = temporario;
                }
            }
        }
            

        *ponteiro_1 = inteiros[0];
        *ponteiro_2 = inteiros[1];
        *ponteiro_3 = inteiros[2];

        return 0;
    }
    

}