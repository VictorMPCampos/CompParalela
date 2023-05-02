#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>

int precisao = 1000000;

void taylor(long long n, mpf_t e, int thread_count) {
    #pragma omp parallel num_threads(thread_count)
    {
        int my_rank = omp_get_thread_num();
        int thread_count = omp_get_num_threads();
        long long i;

        mpf_t local_e;
        mpf_init2(local_e, precisao);
        mpf_t fat;
        mpf_init2(fat, precisao);
        mpf_t termo;
        mpf_init2(termo, precisao);

        mpf_set_ui(fat, 1);
        for (i = 0; i <= n; i++) {
            if (i % thread_count == my_rank) {
                mpf_ui_div(termo, 1, fat);
                mpf_add(local_e, local_e, termo);
            }
            mpf_mul_ui(fat, fat, i + 1);
        }

        #pragma omp critical
        mpf_add(e, e, local_e);

        mpf_clear(local_e);
        mpf_clear(fat);
        mpf_clear(termo);
    }
}

int main(int argc, char *argv[]) {
    long long n = 100000;
    mpf_t e;
    mpf_init2(e, precisao);
    int thread_count = strtol(argv[1], NULL, 10);

    taylor(n, e, thread_count);
    gmp_printf("Valor de e encontrado = %.1000000Ff\n", e);

    mpf_clear(e);
    return 0;
}
