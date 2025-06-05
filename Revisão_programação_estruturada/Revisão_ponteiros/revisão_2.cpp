#include <stdio.h>

int main (){

    char nome[] = "Luis Eduardo";
    char *ptrNome = nome;

    while (*ptrNome != nome[12])
    {
        printf("%c", *ptrNome);
        ptrNome++;
    }
    


    return 0;
}