#include <stdio.h>
#include <stdlib.h>


#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5

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
    // Construção das Matrizes de Habilidade 

    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Construir Cone (ponta no topo, expandindo para baixo)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= (TAM_HABILIDADE / 2) - i && j <= (TAM_HABILIDADE / 2) + i && i <= TAM_HABILIDADE / 2) {
                cone[i][j] = 1;
            }
        }
    }

    // Construir Cruz
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                cruz[i][j] = 1;
            }
        }
    }

    // Construir Octaedro (forma de losango)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2) {
                octaedro[i][j] = 1;
            }
        }
    }

// Definir pontos de origem (exemplo: você pode mudar)
    int origem_cone_linha = 1, origem_cone_coluna = 1;
    int origem_cruz_linha = 5, origem_cruz_coluna = 5;
    int origem_octaedro_linha = 7, origem_octaedro_coluna = 3;

    // Sobrepor habilidades no tabuleiro

int offset = TAM_HABILIDADE / 2; // deslocamento do centro da matriz de habilidade

// Função de sobreposição reutilizável:

void sobreporHabilidade(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {

            // Posição correspondente no tabuleiro
            int tab_linha = origem_linha - offset + i;
            int tab_coluna = origem_coluna - offset + j;

            // Verificar se está dentro dos limites do tabuleiro
            if (tab_linha >= 0 && tab_linha < TAM_TABULEIRO &&
                tab_coluna >= 0 && tab_coluna < TAM_TABULEIRO) {

                // Se a célula da habilidade for 1 e o tabuleiro tiver água (0), marca como 5
                if (habilidade[i][j] == 1 && tabuleiro[tab_linha][tab_coluna] == 0) {
                    tabuleiro[tab_linha][tab_coluna] = 5;
                }
            }
        }
    }
}

// Chamar a função para cada habilidade
sobreporHabilidade(cone, origem_cone_linha, origem_cone_coluna);
sobreporHabilidade(cruz, origem_cruz_linha, origem_cruz_coluna);
sobreporHabilidade(octaedro, origem_octaedro_linha, origem_octaedro_coluna);


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
