/*
    Franco Gajardo 
    Fecha: 02-09-25
    Tema: Matriz
*/ 

#define P 5
 
#include <stdio.h> 
#include <string.h> 
void recorrer_fila(char[P][P], char[]);
void recorrer_columna(char[P][P], char[]);
void recorrer_diagonal(char[P][P], char[]);
void inicializar(char[P][P]);
void palabras(char[P][P]);
void buscar_palabra(char[P][P], char[]);


int main(){
    char sopa[P][P];
    inicializar(sopa);
    palabras(sopa);
    return 0;
}


void inicializar(char sopa[P][P]){
    char copia [P][P] = {
        {'C', 'R', 'O', 'N', 'O'},
        {'A', 'A', 'S', 'O', 'L'},
        {'S', 'T', 'L', 'T', 'A'},
        {'A', 'O', 'L', 'A', 'R'},
        {'S', 'S', 'E', 'R', 'S'}
    };
    int i = 0, j = 0;
    for (i = 0; i < P; i++){
        for (j = 0; j < P; j++){
            sopa[i][j] = copia[i][j];
        }
    }
}

void palabras(char sopa[P][P]){
    int i = 0;
    char *palabra[] = {"CASA","RATOS","CALAS","LOSA","RATON","SOLO","SALA"};
    for (i = 0; i < 7; i++){
        buscar_palabra(sopa, palabra[i]);
    }

}

void buscar_palabra(char sopa[P][P], char palabra[]){
    recorrer_fila(sopa, palabra);
    recorrer_columna(sopa, palabra);
    recorrer_diagonal(sopa, palabra);
}

void recorrer_fila(char m[P][P], char palabra[]){
    int i, j, largo = strlen(palabra), k = 0, l = 0;
    for (i = 0; i < 5; i++){
        for (j = 0; j < (P - largo) ; j++){
            for (k = 0; k < largo; k++){
                if (m[i][j + k] == palabra[k]){
                    l++;
                }
            }
            if (l == largo){
                for (k = 0; k < largo; k++){
                    printf("%c = (%d,%d) ", m[i][j + k], i, j + k);
                }
                printf(" La palabra es: %s\n", palabra);
            }
            l = 0;
        }
    }

    for (i = 0; i < 5; i++){
        for (j = P - 1; j >= largo - 1 ; j--){
            for (k = 0; k < largo; k++){
                if (m[i][j - k] == palabra[k]){
                    l++;
                }
            }
            if (l == largo){
                for (k = 0; k < largo; k++){
                    printf("%c = (%d,%d) ", m[i][j - k], i, j - k);
                }
                printf(" La palabra es: %s\n", palabra);
            }
            l = 0;
        }
    }
}

void recorrer_columna(char m[P][P], char palabra[]){
    int i, j, largo = strlen(palabra), k = 0, l = 0;
    for (i = 0 ; i < 5; i++){
        for (j = 0; j <= (P - largo) ; j++){
            for (k = 0; k < largo; k++){
                if (m[j + k][i] == palabra[k]){
                    l++;
                }
            }
            if (l == largo){
                for (k = 0; k < largo; k++){
                    printf("%c = (%d,%d) ", m[j + k][i], j + k, i);
                }
                printf(" La palabra es: %s\n", palabra);
            }
            l = 0;
        }
    }
    for (i = 0 ; i < 5; i++){
        for (j = P - 1; j >= largo - 1 ; j--){
            for (k = 0; k < largo; k++){
                if (m[j - k][i] == palabra[k]){
                    l++;
                }
            }
            if (l == largo){
                for (k = 0; k < largo; k++){
                    printf("%c = (%d,%d) ", m[j - k][i], j - k, i);
                }
                printf(" La palabra es: %s\n", palabra);
            }
            l = 0;
        }
    }        
}

void recorrer_diagonal(char m[P][P], char palabra[]){
    int i, j, largo = strlen(palabra), k = 0, l = 0;
    for (i = 0; i <= P - largo; i++){
        for (j = 0; j <= P - largo ; j++){
            for (k = 0; k < largo; k++){
                if (m[i + k][j + k] == palabra[k]){
                    l++;
                }
            }
            if (l == largo){
                for (k = 0; k < largo; k++){
                    printf("%c = (%d,%d) ", m[i + k][j + k], i + k, j + k);
                }
                printf(" La palabra es: %s\n", palabra);
            }
            l = 0;
        }
    }

    for (i = P - 1 ; i >= largo - 1 ; i--){
        for (j = P - 1; j >= largo - 1 ; j--){
            for (k = 0; k < largo; k++){
                if (m[i - k][j - k] == palabra[k]){
                    l++;
                }
            }
            if (l == largo){
                for (k = 0; k < largo; k++){
                    printf("%c = (%d,%d) ", m[i - k][j - k], i - k, j - k);
                }
                printf(" La palabra es: %s\n", palabra);
            }
            l = 0;
        }
    }

    for (i = 0; i <= P - largo; i++){
        for (j = P - 1; j >= largo - 1 ; j--){
            for (k = 0; k < largo; k++){
                if (m[i + k][j - k] == palabra[k]){
                    l++;
                }
            }
            if (l == largo){
                for (k = 0; k < largo; k++){
                    printf("%c = (%d,%d) ", m[i + k][j - k], i + k, j - k);
                }
                printf(" La palabra es: %s\n", palabra);
            }
            l = 0;
        }
    }

    for (i = P - 1; i >= largo - 1 ; i--){
        for (j = 0; j <= P - largo; j++){
            for (k = 0; k < largo; k++){
                if (m[i - k][j + k] == palabra[k]){
                    l++;
                }
            }
            if (l == largo){
                for (k = 0; k < largo; k++){
                    printf("%c = (%d,%d) ", m[i - k][j + k], i - k, j + k);
                }
                printf(" La palabra es: %s\n", palabra);
            }
            l = 0;
        }
    }
}