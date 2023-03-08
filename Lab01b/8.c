#include <stdio.h>

void transpor(int mat[3][3], int transp[3][3]){
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            transp[j][i] = mat[i][j];
        }
    }
}

int main(){
    int mat[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    printf("Matriz orginal:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    int transp[3][3];
    transpor(mat, transp);
    printf("Matriz transposta:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", transp[i][j]);
        }
        printf("\n");
    }
}
