#include <stdio.h>

int main(){
	int mat[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int menor = 100;
	int menorL;
	for (int i = 0; i<3; i++){
		for (int j=0; j<3; j++){
			if (mat[i][j] < menor){
				menor = mat[i][j];
				menorL = i;
			}
		}
	}
	printf("O menor numero eh %d e esta na linha %d\n", menor, menorL);
}
