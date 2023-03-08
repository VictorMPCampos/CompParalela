#include <stdio.h>

int main(){
	int mat[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int mult = 3;
	printf("Linha original: %d, %d, %d\n", mat[0][0], mat[0][1], mat[0][2]);
	for (int i = 0; i<3; i++)
		mat[0][i] = mat[0][i]*mult;
	printf("Linha Multiplicada: %d, %d, %d\n", mat[0][0], mat[0][1], mat[0][2]);
	printf("Coluna original: %d, %d, %d\n", mat[0][0], mat[1][0], mat[2][0]);
	for(int j=0;j<3;j++)
		mat[j][0] = mat[j][0]*mult;
	printf("Coluna multiplicada: %d, %d, %d\n", mat[0][0], mat[1][0], mat[2][0]);
}
