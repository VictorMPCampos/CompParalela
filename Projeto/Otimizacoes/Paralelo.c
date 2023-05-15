#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>

int precisao = 1000000;
int n = 100000;
mpf_t e;

void taylor(int thread_count) {
    #pragma omp parallel num_threads(thread_count)
    {
        int thread_count = omp_get_num_threads();
        int my_rank = omp_get_thread_num();

        mpf_t termo;
        mpf_init2(termo, precisao);
        mpf_t local_e;
        mpf_init2(local_e, precisao);

        mpf_set_ui(termo, 1);
        for (int i = 1; i <= n; i++) {
            if (i % thread_count == my_rank){
                mpf_add(local_e, local_e, termo);
            }
            mpf_div_ui(termo, termo, i+1);
        }
        #pragma omp critical
        mpf_add(e, e, local_e);

        mpf_clear(termo);
        mpf_clear(local_e);
    }
}

int main(int argc, char *argv[]) {
    mpf_init2(e, precisao);
    mpf_set_ui(e, 1);

    int thread_count = strtol(argv[1], NULL, 10);

    taylor(thread_count);
    gmp_printf("Valor de e encontrado = %.9999Ff\n", e);

    mpf_clear(e);
    return 0;
}