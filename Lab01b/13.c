#include <stdio.h>
#include <string.h>

void removeChar(char str[], int pos) {
    int len = strlen(str);
    if (pos >= 0 && pos < len) {
        for (int i = pos; i < len - 1; i++) {
            str[i] = str[i + 1];
        }
        str[len - 1] = '\0';
    }
}


int main(){
    char Str[100] = "String exemplo";
    int pos = 3;
    printf("String original: %s\n", Str);
    removeChar(Str, pos);
    printf("String nova: %s\n", Str);
}
