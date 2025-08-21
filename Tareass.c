#include <stdio.h>
void arr(int arreglo[2][3][4]);
void cambi(int arreglo[2][3][4]);
void inv(int arreglo[2][3][4]);
void replace(int arreglo[2][3][4]);
void prim(int arreglo[2][3][4]);

int main(){
    
    int arreglo[2][3][4] ={{{1,2,3},{4,5},{6,7,8,9}},
                           {{10,11},{},{12,13,14}}
    };
    
    //arr(arreglo);
    cambi(arreglo);
    //arr(arreglo);
    inv(arreglo);
    arr(arreglo);
    replace(arreglo);
    arr(arreglo);
    prim(arreglo);
    arr(arreglo);
    return 0;
}

void arr(int arreglo[2][3][4]){
    int i,j,k;
    printf("----------------\n");
    for(i = 0; i < 2; i++){        
        for(j = 0; j < 3; j++){        
            for(k = 0; k < 4; k++){            
            printf("%3d",arreglo[i][j][k]);
            }
            printf("\n");
        }
        printf("----------------\n");
    }
}

void cambi(int arreglo[2][3][4]){
    int j = 15,k;
    
    for(k = 0; k < 4; k++){
        arreglo[1][1][k] = j;
        j++;
    }
        
    

}

void inv(int arreglo[2][3][4]){
    int i,j,k,z,m;

    for(i = 0; i < 2; i++){        
        for(j = 0; j < 3; j++){ 
            for(k = 0; k < 4; k++){
                for(m = 0; m < 4; m++){
                    if(arreglo[i][j][k] > arreglo[i][j][m]){
                        z = arreglo[i][j][k];
                        arreglo[i][j][k] = arreglo[i][j][m];
                        arreglo[i][j][m] = z;
                        
                    }
                }                
            }
        }
    }
}
void replace(int arreglo[2][3][4]){
    int i, j, k;
    for(i = 0; i < 2; i++){        
        for(j = 0; j < 3; j++){ 
            for(k = 0; k < 4; k++){
                if(arreglo[i][j][k] % 2 == 0){
                    arreglo[i][j][k] = 0;
                }
                                
            }
        }
    }
}

void prim(int arreglo[2][3][4]){
    int i, j, k;
    for(i = 0; i < 2; i++){        
        for(j = 0; j < 3; j++){ 
            for(k = 0; k < 4; k++){
                if( arreglo[i][j][k] % 2 != 0 && arreglo[i][j][k] % 3 != 0 && arreglo[i][j][k] % 5 != 0 && arreglo[i][j][k] % 7 != 0    ){
                    arreglo[i][j][k] = 0;
                    
                }
                
            }
        }
    }
}

