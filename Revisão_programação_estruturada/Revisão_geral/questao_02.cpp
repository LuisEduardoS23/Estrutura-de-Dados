#include <stdio.h>

int main (){
    double ultima_nota, menor_nota = 10, maior_nota = 0;

    for (int i = 0; i < 10; i++)
    {
        
        printf("Digite a nota do %d aluno:  ", i+1);
        scanf("%lf", &ultima_nota);
        printf("\n");

        if (ultima_nota > maior_nota)
        {
            maior_nota = ultima_nota;
        }
        else if (ultima_nota < menor_nota){
            menor_nota = ultima_nota;
        }
    }
    printf("MAIOR NOTA: %.2lf\n", maior_nota);
    printf("MENOR NOTA: %.2lf\n", menor_nota);
    
   

    return 0;
}