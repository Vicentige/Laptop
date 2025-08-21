#include <stdio.h>
#include <string.h>

void pedirUsname(char *);
void escribirBoG(char *);

int main(){
    char User[100];

    pedirUsname(User);
    escribirBoG(User);

}
void pedirUsname(char *User){
    int  i = 0, c;
    printf("ingrese su nombre de usuario(no mas de 100 caracteres):");
    while ((c = getchar())!='\n'){
        User[i] = c;
        i++;
    }
    User[i] = '\0';
}

void escribirBoG(char *User){
    int i = 0, j = 0, longitud, c = 0;
    longitud = strlen(User);

    for(i = 0; i < longitud; i++){
        for(j = 0; j < longitud; j++){
            if(User[i] == User[j]){//xiaodao
                User

                
            }

        }
    }

}