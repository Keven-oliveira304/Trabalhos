#include <stdio.h>

int main() {
    // Movimento da Torre: 5 casas para a direita (usando for)
    printf("Movimento da Torre:\n");
    for (int i = 0; i < 5; i++) {
        printf("Direita\n");
    }

    // Movimento do Bispo: 5 casas na diagonal para cima e à direita (usando while)
    printf("\nMovimento do Bispo:\n");
    int j = 0;
    while (j < 5) {
        printf("Cima Direita\n");
        j++;
    }

    // Movimento da Rainha: 8 casas para a esquerda (usando do-while)
    printf("\nMovimento da Rainha:\n");
    int k = 0;
    do {
        printf("Esquerda\n");
        k++;
    } while (k < 8);

    // Movimento do Cavalo: 2 casas para baixo e 1 para a esquerda (usando loops aninhados)
    printf("\nMovimento do Cavalo:\n");
    
    // Loop para movimentar 2 casas para baixo
    for (int m = 0; m < 2; m++) {
        printf("Baixo\n");
    }
    
    // Loop para movimentar 1 casa para a esquerda
    int n = 0;
    while (n < 1) {
        printf("Esquerda\n");
        n++;
    }
    
    return 0;
}

