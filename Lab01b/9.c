#include <stdio.h>
#include <stdlib.h>

void modulo(int mat[3][3]){
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            mat[i][j] = abs(mat[i][j]);
        }
    }
}

void printaMatriz(int mat[3][3]){
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int mat[3][3] = {{-1,-2,-3}, {-4,-5,-6}, {-7,-8,-9}};
    printf("Matriz orginal:\n");
    printaMatriz(mat);
    modulo(mat);
    printf("Matriz em mdoulo:\n");
    printaMatriz(mat);
}
