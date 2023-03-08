#include <stdio.h>

int main(){
	int N1 = 7;
	int N2 = 8;
	int N3 = 6;
	int ME = (N1+N2+N3)/3;
	int MA = (N1 + N2*2 + N3*3 + ME)/7;
	char res;
	if (MA >= 9)
		res = 'A';
	else if (MA >= 7.5)
		res = 'B';
	else if (MA >= 6)
		res = 'C';
	else if (MA >= 4)
		res = 'D';
	else
		res = 'E';
	printf("Resultado = %c\n", res);
}
