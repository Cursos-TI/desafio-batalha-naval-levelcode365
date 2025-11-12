#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
// Autor : Nicolas Felipe
// Data : 12/11/2025
int main() {
    // ========================
    // Nível Novato - Posicionamento dos Navios
    // ========================

    // Criação do tabuleiro 10x10 (valores 0 representam água)
    int tabuleiro[10][10] = {0};

    // Valor que representa o navio
    const int NAVIO = 3;
    const int TAM_NAVIO = 3;

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linhaH = 2; // linha do navio horizontal
    int colunaH = 4; // coluna inicial do navio horizontal

    int linhaV = 5; // linha inicial do navio vertical
    int colunaV = 7; // coluna do navio vertical

    // Verificação simples de limite (para não ultrapassar o tabuleiro)
    if (colunaH + TAM_NAVIO > 10 || linhaV + TAM_NAVIO > 10) {
        printf("Erro: as coordenadas dos navios ultrapassam os limites do tabuleiro.\n");
        return 1;
    }

    // Posiciona o navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // Verifica se o navio vertical se sobrepõe a outro
    int sobreposicao = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: os navios estao sobrepostos!\n");
        return 1;
    }

    // Posiciona o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // Exibe as coordenadas ocupadas pelos navios
    printf("\nCoordenadas do navio horizontal (linha %d):\n", linhaH);
    for (int i = 0; i < TAM_NAVIO; i++) {
        printf("(%d, %d)\n", linhaH, colunaH + i);
    }

    printf("\nCoordenadas do navio vertical (coluna %d):\n", colunaV);
    for (int i = 0; i < TAM_NAVIO; i++) {
        printf("(%d, %d)\n", linhaV + i, colunaV);
    }

    // Exibe o tabuleiro completo
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}
