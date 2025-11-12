//Autor: Nicolas Felipe
//Data: 12/11/2025
//Descrição: Implementação das habilidades "cone", "cruz" e "octaedro" em um tabuleiro de batalha naval.

#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB 10    // tamanho do tabuleiro (10x10)
#define HSIZE 5       // tamanho das matrizes de habilidade (usar ímpar para centrar facilmente)

enum SkillType { SKILL_CONE, SKILL_CROSS, SKILL_OCTAHEDRON };

/*
 * Gera uma matriz de habilidade de tamanho HSIZE x HSIZE preenchida com 0/1
 * usando condicionais e loops aninhados (conforme requisito).
 * - cone: topo na linha 0, expandindo para baixo (cone apontando para baixo)
 * - cross: cruz com origem no centro (linha e coluna do centro)
 * - octahedron: "losango" (abs(dr)+abs(dc) <= radius)
 *
 * O chamador deve fornecer um array skill[HSIZE][HSIZE].
 */
void gerar_matriz_habilidade(int skill[HSIZE][HSIZE], enum SkillType tipo) {
    int center = HSIZE / 2; // índice do centro, ex: para HSIZE=5 -> center=2

    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            skill[r][c] = 0; // inicializa
            if (tipo == SKILL_CONE) {
                // cone apontando para baixo: linha 0 = ponta
                // incluímos (r,c) se abs(c-center) <= r   (expande conforme r aumenta)
                if (abs(c - center) <= r) {
                    skill[r][c] = 1;
                }
            } else if (tipo == SKILL_CROSS) {
                // cruz: linha central e coluna central
                if (r == center || c == center) {
                    skill[r][c] = 1;
                }
            } else if (tipo == SKILL_OCTAHEDRON) {
                // octaedro (vista frontal) ~ losango: abs(dr)+abs(dc) <= radius
                int dr = abs(r - center);
                int dc = abs(c - center);
                if (dr + dc <= center) {
                    skill[r][c] = 1;
                }
            }
        }
    }
}

/*
 * Sobrepõe a matriz de habilidade skill[HSIZE][HSIZE] no tabuleiro board[TAM_TAB][TAM_TAB],
 * centrando a habilidade em (orig_r, orig_c) no tabuleiro.
 * Marca as posições afetadas com o valor 5 (substitui qualquer conteúdo anterior).
 * Faz checagem de limites para não acessar fora do tabuleiro.
 */
void aplicar_habilidade(int board[TAM_TAB][TAM_TAB], int skill[HSIZE][HSIZE], int orig_r, int orig_c) {
    int center = HSIZE / 2;

    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            if (skill[r][c] == 1) {
                int board_r = orig_r - center + r;
                int board_c = orig_c - center + c;
                // checar limites
                if (board_r >= 0 && board_r < TAM_TAB && board_c >= 0 && board_c < TAM_TAB) {
                    board[board_r][board_c] = 5; // marca área afetada com 5
                }
            }
        }
    }
}

/* Função que imprime o tabuleiro: 0 = água, 3 = navio, 5 = área de habilidade */
void imprimir_tabuleiro(int board[TAM_TAB][TAM_TAB]) {
    printf("Tabuleiro (0=agua, 3=navio, 5=area-habilidade):\n\n");
    for (int r = 0; r < TAM_TAB; r++) {
        for (int c = 0; c < TAM_TAB; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Exemplo simples de posicionamento de alguns navios (apenas para visualização) */
void posicionar_navios_exemplo(int board[TAM_TAB][TAM_TAB]) {
    // limpa
    for (int r = 0; r < TAM_TAB; r++)
        for (int c = 0; c < TAM_TAB; c++)
            board[r][c] = 0;

    // coloca alguns "navios" (valor 3) - posições fixas de exemplo
    board[2][2] = 3;
    board[2][3] = 3;
    board[2][4] = 3;

    board[5][7] = 3;
    board[6][7] = 3;

    board[8][1] = 3;
    board[8][2] = 3;
    board[8][3] = 3;
}

/* Função de demonstração: cria habilidades, define centros e aplica no tabuleiro. */
int main(void) {
    int board[TAM_TAB][TAM_TAB];
    int skill_cone[HSIZE][HSIZE];
    int skill_cross[HSIZE][HSIZE];
    int skill_octa[HSIZE][HSIZE];

    // 1) posicionar navios de exemplo
    posicionar_navios_exemplo(board);

    // 2) gerar matrizes de habilidade dinamicamente (com loops + condicionais)
    gerar_matriz_habilidade(skill_cone, SKILL_CONE);
    gerar_matriz_habilidade(skill_cross, SKILL_CROSS);
    gerar_matriz_habilidade(skill_octa, SKILL_OCTAHEDRON);

    // 3) definir pontos de origem no tabuleiro (linha, coluna) - definidos diretamente no código
    // Observação: índices base 0 (0..9)
    int orig_cone_r = 1, orig_cone_c = 2;   // exemplo: cone centralizado em (1,2)
    int orig_cross_r = 5, orig_cross_c = 5; // cruz centralizada em (5,5)
    int orig_octa_r = 8, orig_octa_c = 2;   // octaedro centralizado em (8,2)

    // 4) aplicar habilidades ao tabuleiro
    aplicar_habilidade(board, skill_cone, orig_cone_r, orig_cone_c);
    aplicar_habilidade(board, skill_cross, orig_cross_r, orig_cross_c);
    aplicar_habilidade(board, skill_octa, orig_octa_r, orig_octa_c);

    // 5) imprimir matrizes de habilidade (opcional) e o tabuleiro final
    printf("Matriz - Cone (1=afetado):\n");
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) printf("%d ", skill_cone[r][c]);
        printf("\n");
    }
    printf("\n");

    printf("Matriz - Cruz (1=afetado):\n");
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) printf("%d ", skill_cross[r][c]);
        printf("\n");
    }
    printf("\n");

    printf("Matriz - Octaedro (1=afetado):\n");
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) printf("%d ", skill_octa[r][c]);
        printf("\n");
    }
    printf("\n");

    // imprimir tabuleiro final
    imprimir_tabuleiro(board);

    return 0;
}
