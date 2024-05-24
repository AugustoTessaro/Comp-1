#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char S[100]; 

 
    printf("Digite um texto: ");
    fgets(S, sizeof(S), stdin);

    char *endptr;
    double resultado = 0.0;

    char *ptr = S;
    while (isspace((unsigned char)*ptr)) {
        ptr++;
    }

    if (*ptr == '+' || *ptr == '-' || isdigit((unsigned char)*ptr)) {
        resultado = strtod(ptr, &endptr);

        if (endptr == ptr) {
            resultado = 0.0;
        }
    }

    printf("resultado %.10g\n", resultado);

    return 0;
}