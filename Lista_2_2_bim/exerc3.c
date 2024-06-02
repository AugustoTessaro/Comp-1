#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERMS 5
#define MAX_POLYNOMIALS 900
#define FILENAME "polynomials.txt"

void get_polynomials();
void calculate_derivatives();
void write_derivative(FILE *output, int coeficiente, int expoente);
void parse_polynomial(char *linha, int *coeficientes, int *expoentes, int *num_terms);

int main() {
    get_polynomials();
    calculate_derivatives();
    return 0;
}

void get_polynomials() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int P;
        printf("Digite o numero de termos do polinomio (1-5, ou 0 para encerrar): ");
        scanf("%d", &P);

        if (P == 0) break;

        if (P < 1 || P > MAX_TERMS) {
            printf("Numero de termos invalido! Deve ser entre 1 e 5.\n");
            continue;
        }

        fprintf(file, "%d\n", P);

        printf("Digite o polinomio (ex de polinomio de 2 termos: 6x4 + 31x2): ");
        char polynomial[256];
        getchar(); // Limpar o buffer do \n anterior
        fgets(polynomial, sizeof(polynomial), stdin);
        fprintf(file, "%s", polynomial);
    }

    fclose(file);
}

void parse_polynomial(char *linha, int *coeficientes, int *expoentes, int *num_terms) {
    char *token = strtok(linha, " +\n");
    int index = 0;

    while (token != NULL && index < MAX_TERMS) {
        sscanf(token, "%dx%d", &coeficientes[index], &expoentes[index]);
        index++;
        token = strtok(NULL, " +\n");
    }

    *num_terms = index;
}

void calculate_derivatives() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        int P;
        sscanf(linha, "%d", &P);
        if (P == 0) break;

        fgets(linha, sizeof(linha), file);

        int coeficientes[MAX_TERMS];
        int expoentes[MAX_TERMS];
        int num_terms = 0;

        parse_polynomial(linha, coeficientes, expoentes, &num_terms);

        for (int i = 0; i < num_terms; i++) {
            int new_coeficiente = coeficientes[i] * expoentes[i];
            int new_expoente = expoentes[i] - 1;

            if (i > 0) printf(" + ");
            printf("%dx%d", new_coeficiente, new_expoente);
        }
        printf("\n");
    }

    fclose(file);

  
    file = fopen(FILENAME, "w");
    if (file != NULL) {
        fclose(file);
    }
}