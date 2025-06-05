#include <stdio.h>

void imprimir(int array[]);
int main (){

    int array[] = {4, 18, 19, 20, 32, 45};
    imprimir(array);


    return 0;
}

void imprimir(int array[]){

    for (int i = 0; i < 6; i++)
    {
        int* ponteiro = array;
        ponteiro = ponteiro+i;
        printf("%d ", *ponteiro);
    }
    


}