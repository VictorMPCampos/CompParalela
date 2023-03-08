#include <stdio.h>

int main(){
    struct pessoa
    {
        char* nome;
        int idade;
        int peso;
        float altura;
    };
    struct pessoa p1 = {"joao", 25, 70, 1.80};
    struct pessoa p2 = {"jose", 35, 85, 1.83};
    struct pessoa p3 = {"alberto", 27, 78, 1.78};
    struct pessoa vet[3];
    vet[0] = p1;
    vet[1] = p2;
    vet[2] = p3;
    for (int i = 0; i<3;i++)
        printf("pessoa: %s | idade: %d | peso: %d | altura: %f\n", vet[i].nome, vet[i].idade, vet[i].peso, vet[i].altura);
}
