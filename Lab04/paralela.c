#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int A[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
int x[3] = {2,3,4};
int y[3];

void *multi(void *arg) {
    long inicio = (long) arg;
    for (int i=inicio; i<inicio+2; i++) {
        y[i] = 0;
        for (int j=0; j<3; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    return NULL;
}

int main() {
    printf("vetor original:\n");
    for (int i=0; i<3; i++)
        printf("[%d] ", x[i]);
    
    printf("\nmatriz original:\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++)
            printf("[%d]", A[i][j]);
        printf("\n");
    }

    pthread_t thread1, thread2;
    long inicio1 = 0;
    long inicio2 = 2;

    pthread_create(&thread1, NULL, multi, (void *) inicio1);
    pthread_create(&thread2, NULL, multi, (void *) inicio2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nvetor final:\n");
    for (int i=0; i<3; i++)
        printf("[%d] ", y[i]);
    printf("\n");

    return 0;
}
