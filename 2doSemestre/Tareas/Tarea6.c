#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10

void mostrarArray(int [],int *, int);
void moverAdelante(int **);
void moveratrasTres(int **);
void sumarprimeroUltimo(int **, int);
void mostrarDirecciones(int [],int *, int);

int main() {
 int arr[ARRAY_SIZE] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
 int *ptr = arr; /* Puntero al inicio del array */

 printf(" ARITMETICA DE PUNTEROS\n");
 printf("=============================================\n");

 /* Mostrar array inicial */
 printf("\nEstado inicial:\n");
 mostrarArray(arr, ptr, ARRAY_SIZE);
 moverAdelante(&ptr);
 moveratrasTres(&ptr);
 sumarprimeroUltimo(&ptr, ARRAY_SIZE);
 mostrarDirecciones(arr,ptr, ARRAY_SIZE);
 return 0;
}

void mostrarArray(int arr[],int *ptr, int Length){
    int i = 0;

    for(i = 0; i < Length; i++){
        printf("%d  ", arr[i]);
    }
}
void moverAdelante(int **ptr){
    *ptr = *ptr + 5;
    printf("\n%d", **ptr);


}
void moveratrasTres(int **ptr){
    *ptr = *ptr - 3;
    printf("\n%d", **ptr);
}
void sumarprimeroUltimo(int **ptr,int Length){
    int a,b;
    
    *ptr = *ptr - 2;
    a = **ptr;
    *ptr = *ptr + 9 ;
    b = **ptr;

    printf("\n%d", a + b );
}
void mostrarDirecciones(int arr[],int *ptr, int Length){
    int i = 0;
    ptr = arr;

    for(i = 0; i < Length; i++){
        printf("\n%p",*(ptr + i));
    }

}
