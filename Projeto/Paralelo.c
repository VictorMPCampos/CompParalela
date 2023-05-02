#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>

int precisao = 100000;

void fatP(mpf_t fat, long double x){
    mpf_set_ui(fat, 1);
    for(long double i = 2; i <= x; i++){
        mpf_mul_ui(fat, fat, i);
    }
}

void taylor(long double n, mpf_t e){
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    long double local_n = (n/thread_count) * (my_rank+1);
    long double local_i = local_n * my_rank;

    mpf_t local_e;
    mpf_init2(local_e, precisao);
    mpf_t fat;
    mpf_init2(fat, precisao);
    mpf_t termo;
    mpf_init2(termo, precisao);

    for (local_i; local_i<=local_n;local_i++){
        fatP(fat, local_i);
        mpf_ui_div(termo, 1, fat);
        mpf_add(local_e, local_e, (termo));
    }
    #pragma omp critical
    mpf_add(e, e, local_e);

    mpf_clear(local_e);
    mpf_clear(fat);
    mpf_clear(termo);
}

int main(int argc, char *argv[]){
    long double n = 10000;
    mpf_t e;
    mpf_init2(e, precisao);
    int thread_count = strtol(argv[1], NULL, 10);

    #pragma omp parallel num_threads(thread_count)
    taylor(n, e);
    gmp_printf("Valor de e encontrado = %.9999Ff\n", e);

    mpf_clear(e);
    return 0;
}
