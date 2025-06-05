#include <stdio.h>


int verificar_string (char* ponteiro1,char *ponteiro2);
int main (){

    char string1[] = "Luis";
    char string2[] = "Ola eu sou o Luis Eduardo";

    verificar_string(string1, string2);

    return;
}

int verificar_string (char* ptr_string1,char *ptr_string2){

    for (char* ptr1 = ptr_string1; *ptr1 != '\0'; *ptr1++)
    {
        if (*ptr1 == *ptr_string2)
        {
            
        }
        
    }
    


}