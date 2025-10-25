#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int filas;
    int columnas;
    int filas1;
    int columnas1;
    


}valores;

FILE *abrirarch(void);
void Leervalores(FILE *, valores *);
void Leermatriz(FILE *, valores ,int [][1000],int [][1000]);



int main(){
    valores V;
    
    FILE *archivo = abrirarch();

    Leervalores(archivo, &V);
    
    int Matriz1[V.filas][V.columnas], Matriz2[V.filas1][V.columnas1];
    
    Leermatriz(archivo, V , Matriz1,Matriz2);
    
    fclose(archivo);
    
    return 0;
}

FILE *abrirarch(void){
    FILE *archivo = fopen("matrizz.txt", "r");

    if(archivo == NULL){
        printf("Error: no se pudo abrir el archivo\n");
    }     
    

    return archivo;
}

void Leervalores(FILE *archivo,valores *V){
    int i = 0;
    char temp[1024];
    fscanf(archivo,"%d %d",&V->filas,&V->columnas);

    for(i = 0; i < V->filas + 1; i++){
        fgets(temp, 1024, archivo);
    }
    fscanf(archivo,"%d %d",&V->filas1,&V->columnas1);

    printf("%d, %d\n",V->filas,V->columnas);
    printf("%d, %d\n",V->filas1,V->columnas1);
}

void Leermatriz(FILE *archivo,valores V, int Matriz1[V.filas][V.columnas], int Matriz2[V.filas1][V.columnas1]){
    int i,j;
    char temp[1024];
    fscanf(archivo,"%d",temp);
    fscanf(archivo,"%d",temp);
    for (i = 0; i < V.filas; i++){
        for(j = 0; j < V.columnas; j++){
            fscanf(archivo,"%d",&Matriz1[i][j]);
        
        }
        
    }
    for (i = 0; i < V.filas; i++){
        for(j = 0; j< V.columnas; j++){
            printf("%3d", Matriz1[i][j]);
                      
        }
        printf("\n");
    }
}