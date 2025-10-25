#include <stdio.h>
#include <string.h>

#define p 300

void Leer_texto(char [p]);


int main(){
    char texto[p];
    int i = 0;

    Leer_texto(texto);

    
    return 0;
}

void Leer_texto(char T[p]){
    int i = 0;
    

    printf("ingrese el texto: ");
    
    while (i < 300){
        scanf("%c",T[i]);
        if (T[i] == '\n'){
            i = 305;
        }
        i++;

    }
    
    for(i = 0; i < 300; i++){
        printf("%c",T[i]);
        if (T[i] == '\n'){
            i = 305;
        }
        

    }

}