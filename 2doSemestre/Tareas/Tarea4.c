/*
 autor: Vicente Gonzalez
 Fecha:02/09/2025
 Tema:Repaso vectores/matrices
*/

#include <stdio.h>
#include <string.h>
#define p 5

void Buscar(char [p][p], char[]);
void Rfila(char[p][p], char []);
void Rcol(char[p][p], char []);
void Rdiag(char[p][p], char []);
void palabras(char[p][p]);

int main() {
    int i, j;
    char sopa[p][p] ={{'C', 'R', 'O', 'N', 'O'},
                      {'A', 'A', 'S', 'O', 'L'},
                      {'S', 'T', 'L', 'T', 'A'},
                      {'A', 'O', 'L', 'A', 'R'},
                      {'S', 'S', 'E', 'R', 'S'}};

    palabras(sopa);    
    return 0;
}

void palabras(char sopa[p][p]){
    int i = 0;
    char *palabra[] = {"CASA","RATOS","CALAS","LOSA","RATON","SOLO","SALA"};
    for (i = 0; i < 7; i++){
        Buscar(sopa, palabra[i]);
    }
}

void Buscar(char sopa[p][p], char palabra[]){

    Rfila(sopa, palabra);
    Rcol(sopa, palabra);
    Rdiag(sopa, palabra);

}

void Rfila(char sopa[p][p], char palabra[]){
    int i, j, k, l, c = 0;

    l = strlen(palabra);

    for (i = 0; i < 5; i++){
        for (j = 0; j < (p - l) ; j++){
            for (k = 0; k < l; k++){
                if (sopa[i][j + k] == palabra[k]){
                    c++;
                }
            }
            if (c == l){
                for (k = 0; k < l; k++){
                    printf("%c = (%d,%d) ", sopa[i][j + k], i, j + k);
                }
                printf("| %s\n", palabra);
            }
            c = 0;
        }
    }

    for (i = 0; i < 5; i++){
        for (j = p - 1; j >= l - 1 ; j--){
            for (k = 0; k < l; k++){
                if (sopa[i][j - k] == palabra[k]){
                    c++;
                }
            }
            if (c == l){
                for (k = 0; k < l; k++){
                    printf("%c = (%d,%d) ", sopa[i][j - k], i, j - k);
                }
                printf("| %s\n", palabra);
            }
            c = 0;
        }
    }
}

void Rcol(char sopa[p][p], char palabra[]){
    int i, j, k, l, c = 0;

    l = strlen(palabra);

    for (i = 0; i < 5; i++){
        for (j = 0; j <= (p - l); j++){
            for (k = 0; k < l; k++){
                if (sopa[j + k][i] == palabra[k]){
                    c++;
                }
            }
            if (c == l){
                for (k = 0; k < l; k++){
                    printf("%c = (%d,%d) ", sopa[j + k][i], j + k, i);
                }
                printf("| %s\n", palabra);
            }
            c = 0;
        }
    }

    for (i = 0; i < 5; i++){
        for (j = p - 1; j >= l - 1 ; j--){
            for (k = 0; k < l; k++){
                if (sopa[j - k][i] == palabra[k]){
                    c++;
                }
            }
            if (c == l){
                for (k = 0; k < l; k++){
                    printf("%c = (%d,%d) ", sopa[j - k][i], j - k, i);
                }
                printf("| %s\n", palabra);
            }
            c = 0;
        }
    }
}

void Rdiag(char sopa[p][p], char palabra[]){
    int i, j, k, l, c = 0;

    l = strlen(palabra);

    for (i = 0; i <= (p - l); i++){
        for (j = 0 ; j <= (p - l)  ; j++){
            for (k = 0; k < l; k++){
                if (sopa[i + k][j + k]== palabra[k]){
                    c++;
                }
            }
            if (c == l){
                for (k = 0; k < l; k++){
                    printf("%c = (%d,%d) ", sopa[i + k][j + k], i + k, j + k);
                }
                printf("| %s\n", palabra);
            }
            c = 0;
        }
    }

    for (i = (p - 1); i >= l; i--){
        for(j=(p - 1); j >= l; j--){
            for(k = 0; k < l; k++){
                if (sopa[i - k][j - k] == palabra[k]){
                    c++;
                }
            }
            if (c == l){
                for (k = 0; k < l; k++){
                    printf("%c = (%d,%d) ", sopa[i - k][j - k],i - k,j - k);
                }
                printf("| %s\n", palabra);
            }
            c = 0;
        }
    }

    for (i = 0; i <= p - l; i++){
        for (j = p - 1; j >= l - 1 ; j--){
            for (k = 0; k < l; k++){
                if (sopa[i + k][j - k] == palabra[k]){
                    c++;
                }
            }
            if (c == l){
                for (k = 0; k < l; k++){
                    printf("%c = (%d,%d) ", sopa[i + k][j - k], i + k, j - k);
                }
                printf("|%s\n", palabra);
            }
            c= 0;
        }
    }
    
    for (i = p - 1; i >= l - 1 ; i--){
        for (j = 0; j <= p - l; j++){
            for (k = 0; k < l; k++){
                if (sopa[i - k][j + k] == palabra[k]){
                    c++;
                }
            }
            if (c == l){
                for (k = 0; k < l; k++){
                    printf("%c = (%d,%d) ", sopa[i - k][j + k], i - k, j + k);
                }
                printf("| %s\n", palabra);
            }
            c = 0;
        }
    }

}