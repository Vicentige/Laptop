#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define limite 30

void ordenar (char *);
void leertexto (char *);

int main(){
    char alfabeto[] = "FZJYQKOMWUXVCPRSTBHLADGNIE";
    char texto[limite];
    ordenar(alfabeto);
    leertexto(texto);
    return 0;
}

void ordenar (char *alfabeto ){
    int i,j,largo;
    largo = strlen(alfabeto) -1;
    char aux;

    for (i = 0; i <= largo ; i++){
        for (j = 0 ; j <= largo ; j++){
            if (alfabeto[j] > alfabeto [j + 1]){
                aux = alfabeto[j];
                alfabeto[j] = alfabeto[j + 1];
                alfabeto [j + 1] = aux; 
            }
        }
    }
    printf("\nOrdenado alfabeticamente:");
    for (i = 1; i <= largo+1; i++){
        printf("%c", alfabeto[i]);
    }
}

void leertexto(char *texto){
    int c, i= 0;
    
    printf("\nEscriba una oracion(no mas de 30 letras):");
    
    while ((c = getchar())!='\n'){
        texto[i] = c;
        i++;
    }
    texto[i] = '\0';
    ordenar(texto);
}