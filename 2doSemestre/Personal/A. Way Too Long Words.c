#include <stdio.h>
#include <string.h>

void obtenerfrase(char *);
void escribirfrase(char *);

int main(){
    char frase[100];
    obtenerfrase(frase);
    escribirfrase(frase);
    return 0;
}
void obtenerfrase(char *frase){
    int  i = 0, c;
    printf("ingrese una frase o palabra(no mas de 100 caracteres):");
    while ((c = getchar())!='\n'){
        frase[i] = c;
        i++;
    }
    frase[i] = '\0';
}

void escribirfrase(char *frase){
    int longitud, i = 0, largo;

    longitud = strlen(frase);
    if(longitud > 10){
        largo = longitud - 2;
        printf("La palabra resumida es:%c%d%c",frase[0], largo, frase[longitud - 1]);
    }else{
        for(i=0; i < longitud ;i++){
        printf("%c",frase[i]);
        }
    }
}