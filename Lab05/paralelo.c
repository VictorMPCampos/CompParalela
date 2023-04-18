#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

double f(double x){
        return exp(x);
}

void trap(double a, double b, int n, double *global){
        double local_a, local_b;
        int local_n;
        int my_rank = omp_get_thread_num();
        int thread_count = omp_get_num_threads();

        double h = (b-a)/n;
        local_n = n/thread_count;
        local_a = a + my_rank * local_n * h;
        local_b = local_a + local_n * h;
        double approx = (f(local_a) + f(local_b))/2.0;
        double x;
        for (int i = 1; i <= local_n; i++){
                x = local_a + i*h;
                approx += f(x);
        }
        approx = h*approx;
        #pragma omp critical
        *global += approx;
}

int main(int argc, char *argv[]){
        double global = 0.0;
        double a = 3.5;
        double b = 5.5;
        int n = 100000000;
        int thread_count;
        thread_count = strtol(argv[1], NULL, 10);
        #pragma omp parallel num_threads(thread_count)
        trap(a, b, n, &global);
        printf("Com n = %d trapezios, a estimativa do integral de %f ate %f é %f\n", n, a, b, global);
        return 0;
}
