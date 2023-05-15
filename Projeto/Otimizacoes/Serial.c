#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int precisao = 1000000;
int n = 100000;
mpf_t e;

void taylor() {
    mpf_t termo;
    mpf_init2(termo, precisao);

    mpf_set_ui(termo, 1);
    for (int i = 1; i <= n; i++) {
        mpf_div_ui(termo, termo, i); 
        mpf_add(e, e, termo);
    }

    mpf_clear(termo);
}

int main(int argc, char *argv[]) {
    mpf_init2(e, precisao);
    mpf_set_ui(e, 1);

    taylor(e);
    gmp_printf("Valor de e encontrado = %.9999Ff\n", e);

    mpf_clear(e);
    return 0;
}
