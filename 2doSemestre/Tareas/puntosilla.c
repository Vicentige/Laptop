#include <stdio.h>
#define N 5

void leerArchivo(int [][N]);
void mostrarM(int [][N]);
void buscarpunto(int [][N]);
int esMinimoFila(int [][N], int , int );
int esMaximoColumna(int [][N], int , int );

int main(){
    int M[N][N];
    leerArchivo(M);
    mostrarM(M);
    buscarpunto(M);
}

void leerArchivo(int M[N][N]){
    int i, j;
    FILE *archivo = fopen("matriz5x5.txt","r");

    if(archivo == NULL){
        printf("Archivo vacio");
        return;
    }else{
        printf("Leido exitosamente\n");
    }
    
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            fscanf(archivo, "%d", &M[i][j]);
            
        }
    }

    fclose(archivo);
}

void mostrarM(int M[N][N]){
    int i, j;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%3.2d", M[i][j]);
            
        }
        printf("\n");
    }
    printf("\n");
}

void buscarpunto(int M[N][N]) {
    int encontrado = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (esMinimoFila(M, i, j) && esMaximoColumna(M, i, j)) {
                printf("Punto silla encontrado en posicion (%d, %d) con valor %d\n", i, j, M[i][j]);
                encontrado = 1;
            }
        }
    }

    if (!encontrado){
        printf("No se encontraron puntos silla en la matriz.\n");
    }
}

int esMinimoFila(int M[N][N], int fila, int col) {
    for (int j = 0; j < N; j++) {
        if (M[fila][j] < M[fila][col]){
            return 0; // hay un valor menor, no es mínimo
        }
    }
    return 1;
}

int esMaximoColumna(int M[N][N], int fila, int col) {
    for (int i = 0; i < N; i++) {
        if (M[i][col] > M[fila][col]){
            return 0; // hay un valor mayor, no es máximo
        }
    }
    return 1;
}