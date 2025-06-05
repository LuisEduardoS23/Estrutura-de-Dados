#include <stdio.h>
#include <string.h>


char nomes [][20] ={"Luis", "Yan", "Yasmin", "Larissa", "Matheus"};

int main (){

    //bubble sort

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (strcmp(nomes[j], nomes[j+1]) > 0){
                char temp[20];
                strcpy(temp, nomes[j]);
                strcpy(nomes[j], nomes[j+1]);
                strcpy(nomes[j+1], temp);

            }
            

        }
        
    }

    for (int i = 0; i < 5; i++)
    {
        printf("    %s  ", nomes[i]);
    }

    return 0;
}