#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para calcular o determinante de uma matriz 3x3
float calcularDeterminante(float matriz[3][3]) {
    return ((matriz[0][2] * matriz[1][0] * matriz[2][1]) + (matriz[0][1] * matriz[1][2] * matriz[2][0]) + (matriz[0][0] * matriz[1][1] * matriz[2][2]))
    - ((matriz[0][1] * matriz[1][0] * matriz[2][2]) + (matriz[0][0] * matriz[1][2] * matriz[2][1]) + (matriz[0][2] * matriz[1][1] * matriz[2][0]));
}

int main() {
    float matriz[3][3];

    printf("Digite as coordenadas dos vértices do triângulo:\n");

    for (int i = 0; i < 3; i++) {
        printf("Vértice %d (x%d y%d): ", i+1, i+1, i+1);
        scanf("%f %f", &matriz[i][0], &matriz[i][1]);
        matriz[i][2] = 1; 
    }

    float determinante = calcularDeterminante(matriz);

    float area = fabs(determinante) / 2.0;

    // Imprimindo a área do triângulo
    printf("A área do triângulo é: %.2f\n", area);

    return 0;
}