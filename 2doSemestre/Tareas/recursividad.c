/*Vicente Gonzalez*/

#include <stdio.h>
#define FILAS 10
#define COLUMNAS 10

void mostrarLaberinto();
int recursiva(int, int);
void Buscar_A(int *, int *);


char laberinto[FILAS][COLUMNAS] = {{' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' '},
                                   {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' '},
                                   {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' '},
                                   {'A', '#', '#', ' ', '#', '#', '#', ' ', '#', ' '},
                                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
                                   {'#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' '},
                                   {' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' '},
                                   {' ', '#', '#', '#', '#', ' ', '#', '#', '#', ' '},
                                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
                                   {'#', '#', '#', '#', '#', '#', '#', '#', '#', 'B'}};

int main(){
    int x = 3, y = 0;
    printf("---laberinto a resolver---\n");
    mostrarLaberinto();
    Buscar_A(&x,&y);
    
    recursiva(x,y);
    printf("---Laberinto resuelto---\n");
    mostrarLaberinto();
    return 0;
}

void Buscar_A(int *x, int *y){
    int i, j;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            if(laberinto[i][j]== 'A'){
                *x = i;
                *y = j;
            }
        }   
    }
}

int recursiva(int x, int y) {
    
    if (x < 0 || x >= FILAS || y < 0 || y >= COLUMNAS)// Verifica límites
        return 0;
    
    if (laberinto[x][y] == '#' || laberinto[x][y] == '.')// Si es pared o ya visitado, retorna 0
        return 0;
    
    if (laberinto[x][y] == 'B')// Si es meta, retorna 1
        return 1;
    
    if (laberinto[x][y] != 'A')// Marca el camino
        laberinto[x][y] = '.';
    
    if (recursiva(x+1, y) || recursiva(x-1, y) || recursiva(x, y+1) || recursiva(x, y-1)){// Intenta moverse en las 4 direcciones
        return 1;
    }
    if (laberinto[x][y] != 'A')// Si no hay camino, desmarca (backtracking)
        laberinto[x][y] = ' ';
    return 0;
}


void mostrarLaberinto(){
    int i, j;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("%c ", laberinto[i][j]);
        }   
        printf("\n");
    }
    printf("\n\n");
}
