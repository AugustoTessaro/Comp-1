#include <stdio.h>
#include <math.h>

// Função para calcular se a polícia alcançou o ladrão
void calcular_alcance_policia(int distancia, int vl, int vp) {
    float p;
    // Calcular tempo necessário para o ladrão chegar à fronteira
    float tempo_ladrao = 12.0 / vl;
    
    // Calcular tempo necessário para a polícia chegar ao ponto inicial do ladrão
    p = sqrt(pow(distancia, 2) + pow(12, 2));

    float tempo_policia = p/vp;
    
    // Verificar se a polícia alcança o ladrão
    if (tempo_policia <= tempo_ladrao) {
        printf("A policia alcancou, tempo polica %f, tempo ladrao %f" , tempo_policia, tempo_ladrao);
    } else {
        printf("A policia nao alcancou, tempo polica %f, tempo ladrao %f" , tempo_policia, tempo_ladrao);
    }
}

int main() {
    int d, vl, vp;
    
    
    // Entrada de dados
    printf("Digite a distancia, a velocidade do ladrao e a velocidade da policia: ");
    scanf("%d %d %d", &d, &vl, &vp);
    
    
    // Chamada do procedimento e impressão do resultado
    calcular_alcance_policia(d, vl, vp);
    
    return 0;
}