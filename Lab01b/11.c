#include <stdio.h>

void multiMat(int mat[2][3]){
    for (int i = 0; i<3; i++)
		mat[1][i] = mat[0][i]*mat[1][i];
}

void somaMat(int mat[2][3]){
    for (int i = 0; i<3; i++)
		mat[1][i] = mat[0][i]+mat[1][i];
}

void printaMatriz(int mat[2][3]){
    for(int i = 0; i <2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
	int mat[2][3] = {{1,2,3}, {4,5,6}};
    int mat2[2][3] = {{1,2,3}, {4,5,6}};
    printf("Matriz original:\n");
    printaMatriz(mat);
    printf("Matriz multiplicada:\n");
    multiMat(mat);
    printaMatriz(mat);
    printf("Matriz somada:\n");
    somaMat(mat2);
    printaMatriz(mat2);
}
