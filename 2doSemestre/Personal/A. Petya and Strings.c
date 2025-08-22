#include <stdio.h>
#include <string.h>

void obtenerstrings(char *, char *);
void compararstrings(char *, char *);

int main(){
    char string1[100];
    char string2[100];
    obtenerstrings(string1, string2);
    compararstrings(string1, string2);
}

void obtenerstrings(char *string1, char *string2){
    int i = 0, c;

    while ((c = getchar())!='\n'){
        string1[i] = c;
        i++;
    }
    string1[i] = '\0';
    
    i = 0;
    
    while ((c = getchar())!='\n'){
        string2[i] = c;
        i++;
    }
    string2[i] = '\0';

}

void compararstrings(char *string1, char *string2){
    strlwr(string1);
    strlwr(string2);
    if (strcmp(string1,string2) == 0) {
        printf("0"); 
    }
    if(strcmp(string1, string2) < 0) {
        printf("-1");
    }
    if(strcmp(string1, string2) > 0) {
        printf("1");
    }


}