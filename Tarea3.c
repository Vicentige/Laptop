#include <stdio.h>
#define MAX 100
int invertir(int);


int main(){
    int i,rut[MAX], rut1;
    printf("Ingrese un RUT su rut: ");
    scanf("%d", &rut1);
    for(i = 0; i < 8; i++){
        scanf("%1d", &rut[i]);
        if (rut[i] < 0 || rut[i] > 9) {
            printf("Error: El RUT debe contener solo dígitos del 0 al 9.\n");
            return 1; // Salir del programa si se ingresa un dígito inválido
        }
    }
    
    




}

int invertir(int rut){
    int invertido = 0, i;
    for (int i = 0; i < 8; i++) {
        rut[i] = rut[i] % 10; // Extraer el dígito menos significativo
        invertido = invertido * 10 + rut[i]; // Construir el número invertido
    }
    return invertido;
}