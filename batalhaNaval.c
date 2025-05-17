#include <stdio.h>
#define TAM 10
#define NAVIO_TAM 3
#define NAVIO_VALOR 3

// Função para verificar se o navio cabe e não se sobrepõe
int pode_posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int horizontal) {
    if (horizontal) {
        if (coluna + NAVIO_TAM > TAM) return 0; // Fora do limite
        for (int i = 0; i < NAVIO_TAM; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0; // Sobreposição
        }
    } else {
        if (linha + NAVIO_TAM > TAM) return 0;
        for (int i = 0; i < NAVIO_TAM; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio
void posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int horizontal) {
    if (horizontal) {
        for (int i = 0; i < NAVIO_TAM; i++) {
            tabuleiro[linha][coluna + i] = NAVIO_VALOR;
        }
    } else {
        for (int i = 0; i < NAVIO_TAM; i++) {
            tabuleiro[linha + i][coluna] = NAVIO_VALOR;
        }
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   ");
    for (char c = 'A'; c < 'A' + TAM; c++) {
        printf(" %c", c);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        if (i < 9) printf(" %d ", i + 1);
        else printf("%d ", i + 1);

        for (int j = 0; j < TAM; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa com água (0)

    // Coordenadas iniciais dos navios (linha, coluna)
    int linha_navio1 = 2, coluna_navio1 = 3; // horizontal
    int linha_navio2 = 5, coluna_navio2 = 6; // vertical

    // Verificações e posicionamentos
    if (pode_posicionar_navio(tabuleiro, linha_navio1, coluna_navio1, 1)) {
        posicionar_navio(tabuleiro, linha_navio1, coluna_navio1, 1);
    } else {
        printf("Erro: navio horizontal não pode ser posicionado.\n");
    }

    if (pode_posicionar_navio(tabuleiro, linha_navio2, coluna_navio2, 0)) {
        posicionar_navio(tabuleiro, linha_navio2, coluna_navio2, 0);
    } else {
        printf("Erro: navio vertical não pode ser posicionado.\n");
    }

    // Exibir o tabuleiro final
    printf("\nTABULEIRO DE BATALHA NAVAL:\n\n");
    exibir_tabuleiro(tabuleiro);

    return 0;
}