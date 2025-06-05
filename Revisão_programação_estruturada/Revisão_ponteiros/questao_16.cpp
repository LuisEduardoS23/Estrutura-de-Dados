#include <stdio.h>

void calc_esfera(float, float*, float*);



int main (){
    float raio, area, volume;


    printf("Digite o valor do raio da esfera:   ");
    scanf("%f", &raio);

    calc_esfera(raio, &area, &volume);
    printf("\nA area superficial da esfera e: %.2f\n", area);
    printf("O volume da esfera e: %.2f\n", volume);

    return 0;
}

void calc_esfera(float raio, float* area, float* volume){

    *area = 4 * 3.14 * (raio * raio);
    *volume = 4/3 * 3.14 * (raio * raio *raio);
    

}