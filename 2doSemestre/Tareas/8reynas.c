#include <stdio.h>

#define N 8 /*Tamaño del tablero*/

void printboard(int [][N]);
int recursiva(int , int );
void solveQueens(int [][N]);
int board[N][N]= {{0}};


int main(){
    
    printboard(board);

    return 0;
}

void printboard(int board[N][N]){
    int i,j;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if (board[i][j] == 1){
                printf("Q");
            }else{
                printf(".");
            }

        }
        printf("\n");
    }
    printf("\n");
}

void solveQueens(int board[N][N]){
    int i = 0, j = 0;
    
    recursiva(i,j);

}

int recursiva(int x, int y) {
    int i,j;
    if (x < 0 || x >= N || y < 0 || y >= N)// Verifica límites
        return 0;

    if(x == 0){
        for(i = x; i < N; i++){
            if (board[i][j] != 1){
                return 1;
            }
        }
    }
    
    if (x > 0){

    }
}