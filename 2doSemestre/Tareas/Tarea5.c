#include <stdio.h>
#define F 100
#define C 100
void verificar_archivo(char *);
void contar_lineas(char *);
void contar_palabras(char *);
void guardar_matriz(char *, char [][C]);


int main(){
    char m[F][C]= {{'\0'}}
    char *Nombre_archivo = "matriz.txt";

    verificar_archivo(Nombre_archivo);
    contar_lineas(Nombre_archivo);
    guardar_matriz(Nombre_archivo, m);


}

void verificar_archivo(char *Nombre_archivo){
    char c;
    FILE *archivo = fopen(Nombre_archivo, "r");

    if(archivo == NULL){
        printf("Archivo vacio");
        return;
    }else{
        printf("Leido exitosamente\n");
    }
    
    while((c = fgetc(archivo))!= EOF){
        putchar(c);
    }

    fclose(archivo);
}

void contar_lineas(char *Nombre_archivo){
    FILE *archivo = fopen(Nombre_archivo, "r");
    int lineas = 1;
    int palabras = 1;
    int c;
    c = fgetc(archivo);

    while (c != EOF){
        if(c == ' ' || c == '\n'){
            palabras++;
        }
        
        if(c == '\n'){
            lineas++;
        }
        c = fgetc(archivo);
    }
    printf("\npalabras: %d, Lineas:%d", palabras, lineas);

    fclose(archivo);
}

void guardar_matriz(char *Nombre_archivo, char m[][C]){
    int i = 0, j = 0;
    char c;

    FILE *archivo = fopen(Nombre_archivo, "r");

    c = fgetc(archivo);

    while (c != EOF){
        while(c != '\n'){
            
            m[i][j] = c;
            
            c = fgetc(archivo);
            j++;
        }        
        c = fgetc(archivo);
        i++;
    }


    

}