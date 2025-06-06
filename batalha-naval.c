#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0}; // inicializa com 0 (água)

    // Vetores representando as partes dos navios (apenas para controle, valor 3)
    int navio_horizontal[TAM_NAVIO] = {3, 3, 3};
    int navio_vertical[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Validação de limites (não precisa validar sobreposição agora porque os navios estão longe)
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
        // Valida sobreposição (opcional aqui, mas bom colocar)
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
