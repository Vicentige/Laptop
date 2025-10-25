#include <stdio.h>
#include <string.h>
#define Nombre_archivo "nombres.txt"
#define largo 256
#define max_columnas 256
#define max_filas 256

int Matriz(char M[][max_columnas]);
void mostrar_menu();
void ingresar_nombres();
void modificar(char M[][max_columnas]);
void ordenar_alf_nombres(char M[][max_columnas]);
void ordenar_alf_apellidos(char M[][max_columnas]);
void eliminar(char M[][max_columnas]);
void mostrar_listado();
void salir();

int main(){
    int opcion;
    char M[max_filas][max_columnas];
    Matriz(M);

    
    do{
        mostrar_menu();
        printf("seleccione opcion: ");
        scanf("%d", &opcion);
        getchar(); /*limpia el buffer de entrada */
        
        switch(opcion){
            case 1:
                ingresar_nombres();
                break;
            case 2:
                //modificar(M);
                break;
            case 3:
                //ordenar_alf_nombres(M);
                break;
            case 4:
                //ordenar_alf_apellidos(M);
                break;
            case 5:
                //eliminar(M);
                break;
            case 6:
                mostrar_listado();
                break;
            case 7:
                //salir();
                break;
            default:
                printf("opcion invalida\n");
        }
        if (opcion != 7){
            printf("\nPresione enter para continuar");
            getchar();
        }
    }while(opcion != 7);
    return 0;
}

int Matriz(char M[][max_columnas]){
    

    FILE *archivo = fopen(Nombre_archivo, "r");
    
    if(archivo == NULL){
        printf("Error: no se pudo abrir el archivo\n");
    }             // no existe o no se pudo abrir

    int n = 0;
    char buf[max_filas];

    while (n < max_filas && fgets(buf, sizeof buf, archivo)){
        buf[strcspn(buf, "\r\n")] = '\0';

        // saltar líneas vacías o de solo espacios/tabs
        int solo_blancos = 1;
        
        for (int i = 0; buf[i]; ++i){
            if (buf[i] != ' ' && buf[i] != '\t'){
                solo_blancos = 0; break;
            }
        }
        if (solo_blancos) continue;

        // copiar seguro al arreglo destino
        strncpy(M[n], buf, max_filas - 1);
        M[n][max_columnas - 1] = '\0';
        n++;


    }

    fclose(archivo);
    return n;   // cantidad de filas cargadas (>=0). -1 si fallo fopen.

}


void mostrar_menu(){

    printf("\n-------------------------------------------------\n");

    printf("1.- Ingresar nombre y apellido.\n");
    printf("2.- modificar\n");
    printf("3.- ordenar alfabeticamente por nombres\n");
    printf("4.- Ordenar alfabeticamente por apellidos\n");
    printf("5.- Eliminar.\n");
    printf("6.- Mostrar listado.\n");
    printf("7.- Salir / Finalizar.\n");
    printf("-------------------------------------------------\n");
}

void mostrar_listado(){
    int c;
    FILE *archivo = fopen( Nombre_archivo,"r");
    char linea[50];

    
    if(archivo == NULL){
        printf("Error: no se pudo abrir el archivo\n");
    }

    while((c = fgetc(archivo))!= EOF){
        putchar(c);
    }
    fclose(archivo);
}


int es_nombre_valido_basico(char *s){
    char c, *p;
    *p = *s;
    for (p = s; *p; ++p){
        unsigned char c = *p;
        if (c == ' ' || c == '-' || c == '\'') continue;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) continue;
        if (c >= 128) continue; // permite caracteres acentuados en UTF-8
        return 0;               // rechaza dígitos y símbolos
    }
    return 1;
}


void ingresar_nombres(){

    int solo_blancos = 1;
    char temp[largo];

    FILE *archivo = fopen( Nombre_archivo ,"a");
    if(archivo == NULL){
        printf("Error: no se pudo abrir el archivo\n");
    }
    
    printf("Escriba el nombre que desea agregar: ");
    if (!fgets(temp, sizeof temp, stdin)){
        printf("Error leyendo la entrada.\n");
        fclose(archivo);
        return;
    }
    
    temp[strcspn(temp, "\r\n")] = '\0';

    // ¿solo espacios?
    
    for (int i = 0; temp[i]; ++i){
        if (temp[i] != ' ' && temp[i] != '\t'){ solo_blancos = 0; break; }
    }

    if (solo_blancos){
        printf("Entrada vacia. No se guardo.\n");
        fclose(archivo);
        return;
    }

    if (!es_nombre_valido_basico(temp)){
        printf("Entrada invalida: use solo letras, espacios, '-' y apostrofe.\n");
        fclose(archivo);
        return;
    }

    if (fprintf(archivo, "\n%s", temp) < 0){
        printf("Error al escribir en el archivo.\n");
    } else {
        printf("OK: '%s' agregado.\n", temp);
    }
    fclose(archivo);

}