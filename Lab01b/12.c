#include <stdio.h>

void achaCarac(char* palavra, char carac){
    int cont = 0;
    while (*palavra != '\0'){
        cont++;
        if (*palavra == carac){
            printf("A letra %c esta na posicao %d da palavra.\n", carac, cont);
            break;
        }
        palavra++;
    }
    if (*palavra == '\0')
        printf("Caractere nao encontrado.\n");
}

int main(){
    char* palavra = "palavra";
    char carac = 'l';
    achaCarac(palavra, carac);
}
