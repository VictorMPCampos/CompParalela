#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int precisao = 100000;

void taylor(long long n, mpf_t e) {
    long long i;
    mpf_t fat;
    mpf_init2(fat, precisao);
    mpf_t termo;
    mpf_init2(termo, precisao);

    mpf_set_ui(fat, 1);
    for (i = 0; i <= n; i++) {
        mpf_ui_div(termo, 1, fat);
        mpf_add(e, e, termo);
        mpf_mul_ui(fat, fat, i + 1);
    }

    mpf_clear(fat);
    mpf_clear(termo);
}

int main(int argc, char *argv[]) {
    long long n = 10000;
    mpf_t e;
    mpf_init2(e, precisao);

    taylor(n, e);
    gmp_printf("Valor de e encontrado = %.9999Ff\n", e);

    mpf_clear(e);
    return 0;
}
