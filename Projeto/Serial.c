#include <stdio.h>
#include <gmp.h>

void binary_splitting_e(int a, int b, mpf_t P, mpf_t Q) {
    if (b - a == 1) {
        mpf_set_ui(P, 1);
        if (a == 0)
            mpf_set_ui(Q, 1);
        else
            mpf_set_ui(Q, a); 
    }
    else {
        int m = (a + b) / 2;

        mpf_t P0, Q0, P1, Q1;
        mpf_init(P0);
        mpf_init(Q0);
        mpf_init(P1);
        mpf_init(Q1);

        binary_splitting_e(a, m, P0, Q0);
        binary_splitting_e(m, b, P1, Q1);

        // P = P0*Q1 + P1
        mpf_mul(P, P0, Q1);
        mpf_add(P, P, P1);

        // Q = Q0*Q1
        mpf_mul(Q, Q0, Q1);

        mpf_clear(P0);
        mpf_clear(Q0);
        mpf_clear(P1);
        mpf_clear(Q1);
    }
}

int main() {
    int n = 100000;
    mpf_set_default_prec(1000000);

    mpf_t P, Q, e;
    mpf_init(P);
    mpf_init(Q);
    mpf_init(e);

    binary_splitting_e(0, n, P, Q);

    mpf_div(e, P, Q);

    gmp_printf("e = %.10000Ff\n", e);

    mpf_clear(P);
    mpf_clear(Q);
    mpf_clear(e);

    return 0;
}
