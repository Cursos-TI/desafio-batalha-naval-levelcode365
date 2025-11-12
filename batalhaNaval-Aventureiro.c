#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Aventureiro - Tabuleiro Completo e Navios Diagonais
// Objetivo: posicionar 4 navios (2 normais e 2 diagonais) em um tabuleiro 10x10.

#define TAM 10  // Define constante em tempo de compilação (corrige erro de inicialização)

int main() {
    // ========================
    // CONFIGURAÇÕES INICIAIS
    // ========================
    const int NAVIO = 3;       // Valor que representa uma parte de navio
    const int TAM_NAVIO = 3;   // Cada navio ocupa 3 posições

    int tabuleiro[TAM][TAM] = {0}; // Inicializa o tabuleiro com 0 (água)

    // ========================
    // POSICIONAMENTO DOS NAVIOS
    // ========================

    // --- Navio 1: Horizontal ---
    int linhaH = 2;
    int colunaH = 4;

    // --- Navio 2: Vertical ---
    int linhaV = 5;
    int colunaV = 1;

    // --- Navio 3: Diagonal Principal (↘) ---
    int linhaD1 = 0;
    int colunaD1 = 0;

    // --- Navio 4: Diagonal Secundária (↙) ---
    int linhaD2 = 0;
    int colunaD2 = 9;

    // ========================
    // VALIDAÇÕES SIMPLES
    // ========================
    if (colunaH + TAM_NAVIO > TAM || linhaV + TAM_NAVIO > TAM ||
        linhaD1 + TAM_NAVIO > TAM || colunaD1 + TAM_NAVIO > TAM ||
        linhaD2 + TAM_NAVIO > TAM || colunaD2 - TAM_NAVIO < -1) {
        printf("Erro: algum navio ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // ========================
    // POSICIONAMENTO NO TABULEIRO
    // ========================
    int sobreposicao = 0;

    // Navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] == NAVIO) sobreposicao = 1;
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // Navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] == NAVIO) sobreposicao = 1;
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // Navio diagonal principal (↘)
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] == NAVIO) sobreposicao = 1;
        tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
    }

    // Navio diagonal secundária (↙)
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaD2 + i][colunaD2 - i] == NAVIO) sobreposicao = 1;
        tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
    }

    if (sobreposicao) {
        printf("\nAviso: houve sobreposição de navios (simplificação permitida no nível intermediário).\n");
    }

    // ========================
    // EXIBIÇÃO DAS COORDENADAS
    // ========================
    printf("\n=== Coordenadas dos Navios ===\n");
    printf("Horizontal: ");
    for (int i = 0; i < TAM_NAVIO; i++) printf("(%d, %d) ", linhaH, colunaH + i);

    printf("\nVertical: ");
    for (int i = 0; i < TAM_NAVIO; i++) printf("(%d, %d) ", linhaV + i, colunaV);

    printf("\nDiagonal ↘: ");
    for (int i = 0; i < TAM_NAVIO; i++) printf("(%d, %d) ", linhaD1 + i, colunaD1 + i);

    printf("\nDiagonal ↙: ");
    for (int i = 0; i < TAM_NAVIO; i++) printf("(%d, %d) ", linhaD2 + i, colunaD2 - i);

    // ========================
    // EXIBIÇÃO DO TABULEIRO
    // ========================
    printf("\n\n===== TABULEIRO COMPLETO =====\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}
