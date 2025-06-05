#include <stdio.h>

int main (){

    int num_alunos;
    printf ("QUANTOS ALUNOS TEM A TURMA?    ");
    scanf("%d", &num_alunos);

    float notas[num_alunos];
    float media_turma = 0;
    for (int i = 0; i < num_alunos; i++)
    {
        printf("\nDIGITE AS NOTAS DO ALUNO_%d:  ", i+1);
        scanf("%f", &notas[i]);
        media_turma += notas[i];
    }
    
    media_turma /= num_alunos;
    printf("A MEDIA DA TURMA E: %.2f", media_turma);
    

    return 0;
}