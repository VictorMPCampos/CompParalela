#include <stdio.h>

int main(){
	char* nome1 = "Alberto";
	char* nome2 = "Roberto";
	if (*nome1 < *nome2)
		printf("%s, %s\n", nome1, nome2);
	else
		printf("%s, %s\n", nome2, nome1);
}
