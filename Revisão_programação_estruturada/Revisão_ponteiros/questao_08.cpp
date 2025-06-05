#include <stdio.h>

int main (){

    int array[10];

    for (int i = 0; i < 10; i++)
    {
        printf("array[%d] = %p\n", i, &array[i]);
    }
    

    return 0;
}