
#include <stdio.h>
#include <stdlib.h>

int A[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
int x[3] = {2,3,4};
int y[3];

void multi(){
    for (int i=0; i<3; i++){
        y[i] = 0;
        for (int j=0; j<3; j++){
            y[i] += A[i][j] * x[j];
        }
    }
}

int main(){
    printf("vetor original:\n");
    for (int i=0; i<3; i++)
        printf("[%d] ", x[i]);
    printf("\nmatriz original:\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++)
            printf("[%d]", A[i][j]);
        printf("\n");
    }
    multi();
    printf("\nvetor final:\n");
    for (int i=0; i<3; i++)
        printf("[%d] ", y[i]);
}
