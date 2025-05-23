#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definições do tamanho do tabuleiro e do navio
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define NUM_NAVIOS 4
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%c  ", linha[i]);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se um navio pode ser posicionado sem sobreposição
int podePosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + (diagonal ? i : (direcao == 1 ? i : 0));
        int y = coluna + (diagonal ? i : (direcao == 0 ? i : 0));
        
        if (x >= TAM_TABULEIRO || y >= TAM_TABULEIRO || tabuleiro[x][y] != 0) {
            return 0; // Posição inválida
        }
    }
    return 1;
}

// Função para posicionar um navio
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int diagonal) {
    int linha, coluna, direcao, posicionado = 0;
    
    while (!posicionado) {
        linha = rand() % (TAM_TABULEIRO - (diagonal ? TAM_NAVIO : 0));
        coluna = rand() % (TAM_TABULEIRO - (diagonal ? TAM_NAVIO : 0));
        direcao = rand() % 2; // 0 para horizontal, 1 para vertical
        
        if (podePosicionar(tabuleiro, linha, coluna, direcao, diagonal)) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                int x = linha + (diagonal ? i : (direcao == 1 ? i : 0));
                int y = coluna + (diagonal ? i : (direcao == 0 ? i : 0));
                tabuleiro[x][y] = 3;
            }
            posicionado = 1;
        }
    }
}

// Função para aplicar habilidades no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemX, int origemY, int tipo) {
    int efeito[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (tipo == 1 && j >= (TAM_HABILIDADE / 2 - i) && j <= (TAM_HABILIDADE / 2 + i)) {
                efeito[i][j] = 1; // Cone
            } else if (tipo == 2 && (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)) {
                efeito[i][j] = 1; // Cruz
            } else if (tipo == 3 && abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2) {
                efeito[i][j] = 1; // Octaedro
            }
        }
    }

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int x = origemX + i - TAM_HABILIDADE / 2;
            int y = origemY + j - TAM_HABILIDADE / 2;
            if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO && efeito[i][j] == 1) {
                tabuleiro[x][y] = 5;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    inicializarTabuleiro(tabuleiro);
    
    // Posicionar dois navios horizontais ou verticais
    for (int i = 0; i < 2; i++) {
        posicionarNavio(tabuleiro, 0);
    }
    
    // Posicionar dois navios diagonais
    for (int i = 0; i < 2; i++) {
        posicionarNavio(tabuleiro, 1);
    }
    
    // Aplicar habilidades
    aplicarHabilidade(tabuleiro, 4, 4, 1); // Cone
    aplicarHabilidade(tabuleiro, 6, 6, 2); // Cruz
    aplicarHabilidade(tabuleiro, 2, 2, 3); // Octaedro
    
    // Exibir o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}

