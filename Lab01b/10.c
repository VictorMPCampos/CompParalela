#include <stdio.h>

void multiMat(int mat[3][3], int multi){
    for (int i = 0; i<3; i++)
		mat[0][i] = mat[0][i]*multi;
    for(int j=0;j<3;j++)
		mat[j][0] = mat[j][0]*multi;
}

int main(){
	int mat[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int mult = 3;
    printf("Linha original:\n");
    for (int i = 0; i<3; i++)
	    printf("%d ", mat[0][i]);
    printf("\nColuna original:\n");
    for(int j=0;j<3;j++)
	    printf("%d ", mat[j][0]);
    multiMat(mat, mult);
    printf("\nLinha multiplicada:\n");
    for (int i = 0; i<3; i++)
	    printf("%d ", mat[0][i]);
    printf("\nColuna multiplicada:\n");
    for(int j=0;j<3;j++)
	    printf("%d ", mat[j][0]);
}
