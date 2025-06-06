#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0}; // inicializa com 0 (água)

    // Vetores representando as partes dos navios (valor 3)
    int navio_horizontal[TAM_NAVIO] = {3, 3, 3};
    int navio_vertical[TAM_NAVIO] = {3, 3, 3};
    int navio_diagonal[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Navio 3: Diagonal principal (linha++, coluna++)
    int linha_d3 = 0, coluna_d3 = 0;

    // Navio 4: Diagonal secundária (linha++, coluna--)
    int linha_d4 = 2, coluna_d4 = 7;

    // Validação de limites
    if (coluna_horizontal + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    if (linha_vertical + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Posiciona navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] == 3) {
            printf("Erro: sobreposição detectada ao posicionar o navio horizontal.\n");
            return 1;
        }
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    // Posiciona navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_vertical + i][coluna_vertical] == 3) {
            printf("Erro: sobreposição detectada ao posicionar o navio vertical.\n");
            return 1;
        }
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }

    // Navio Diagonal Principal
    if (linha_d3 + TAM_NAVIO > TAM_TABULEIRO || coluna_d3 + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio diagonal principal ultrapassa os limites.\n");
        return 1;
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_d3 + i][coluna_d3 + i] == 3) {
            printf("Erro: sobreposição no navio diagonal principal.\n");
            return 1;
        }
        tabuleiro[linha_d3 + i][coluna_d3 + i] = navio_diagonal[i];
    }

    // Navio Diagonal Secundária
    if (linha_d4 + TAM_NAVIO > TAM_TABULEIRO || coluna_d4 - (TAM_NAVIO - 1) < 0) {
        printf("Erro: navio diagonal secundária ultrapassa os limites.\n");
        return 1;
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_d4 + i][coluna_d4 - i] == 3) {
            printf("Erro: sobreposição no navio diagonal secundária.\n");
            return 1;
        }
        tabuleiro[linha_d4 + i][coluna_d4 - i] = navio_diagonal[i];
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
