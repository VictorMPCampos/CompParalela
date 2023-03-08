#include <stdio.h>

int main(){
	int max = 9;
	int min = 1;
	while (max >=  min){
		for (int i=min; i<=max;i++)
			printf("%d ", i);
		printf("\n");
		min++;
		max--;
	}
}
