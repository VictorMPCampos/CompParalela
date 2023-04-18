#include <stdio.h>
#include <math.h>

double f(double x){
	return exp(x);
}

void trap(double a, double b, int n, double *global){
	double h = (b-a)/n;
	double approx = (f(a) + f(b))/2.0;
	double x;
	for (int i=1; i<=n-1; i++){
		x = a + i*h;
		approx += f(x);
	}
	approx = h*approx;
	*global += approx;
}

int main(){
	double global = 0.0;
	double a = 5.5;
	double b = 3.5;
	int n = 1000000;
	trap(a, b, n, &global);
	printf("Com n = %d trapezios, a estimativa do integral de %f ate %f é %f\n", n, a, b, global);
}
