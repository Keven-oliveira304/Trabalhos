#include <stdio.h>

// Definições do tamanho do tabuleiro e do navio
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    // Letras das linhas
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    // Tabuleiro 10x10, inicializado com água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    
    // Posicionando o navio horizontalmente
    int linhaHorizontal = 2, colunaHorizontal = 3;
    if (colunaHorizontal + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
        }
    }
    
    // Posicionando o navio verticalmente
    int linhaVertical = 5, colunaVertical = 6;
    if (linhaVertical + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaVertical + i][colunaVertical] = 3;
        }
    }
    
    // Exibindo cabeçalho das colunas
    printf("   ");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Exibindo o tabuleiro com rótulos de linha
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%c  ", linha[i]);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

