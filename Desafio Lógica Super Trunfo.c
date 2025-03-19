#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
typedef struct {
    char nome[30];
    int populacao;       // Em milhões
    int area;           // Em mil km²
    int pib;            // Em trilhões de dólares
    int densidade;      // Habitantes por km²
} Carta;

// Função para exibir os atributos disponíveis
void mostrarOpcoes() {
    printf("1 - População (milhões)\n");
    printf("2 - Área (mil km²)\n");
    printf("3 - PIB (trilhões de dólares)\n");
    printf("4 - Densidade Demográfica (habitantes por km²)\n");
}

// Função para obter o valor do atributo escolhido
int obterAtributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return -1;
    }
}

// Função para determinar o vencedor da rodada
void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    int valor0 = obterAtributo(c1, atributo1);
    int valor1 = obterAtributo(c2, atributo1);
    int valor2 = obterAtributo(c1, atributo2);
    int valor3 = obterAtributo(c2, atributo2);

    // Comparação dos atributos individuais
    int pontos1 = 0, pontos2 = 0;

    if (atributo1 == 4) // Densidade Demográfica (quanto menor, melhor)
        (valor0 < valor1) ? pontos1++ : (valor2 > valor3) ? pontos2++ : 0;
    else
        (valor0 > valor1) ? pontos1++ : (valor2 < valor3) ? pontos2++ : 0;

    if (atributo2 == 4) // Densidade Demográfica (quanto menor, melhor)
        (valor0 < valor1) ? pontos1++ : (valor2 > valor3) ? pontos2++ : 0;
    else
        (valor0 > valor1) ? pontos1++ : (valor2 < valor3) ? pontos2++ : 0;

    // Soma total dos atributos
    int soma1 = valor0 + valor2;
    int soma2 = valor1 + valor3;

    // Exibição do resultado
    printf("\n------------------ RESULTADO ------------------\n");
    printf("%s vs %s\n", c1.nome, c2.nome);
    printf("Atributos comparados:\n");
    printf("- %d: %d vs %d\n", atributo1, valor0, valor1);
    printf("- %d: %d vs %d\n", atributo2, valor2, valor3);
    printf("Soma dos atributos: %d vs %d\n", soma1, soma2);

    // Determinação do vencedor
    if (soma1 > soma2)
        printf("🏆 %s venceu!\n", c1.nome);
    else if (soma2 > soma1)
        printf("🏆 %s venceu!\n", c2.nome);
    else
        printf("⚖️ Empate!\n");
}

// Função para obter a escolha do jogador, garantindo que não escolha o mesmo atributo duas vezes
int escolherAtributo(int escolhido) {
    int opcao;
    do {
        printf("Escolha um atributo (diferente do anterior %d): ", escolhido);
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 4 || opcao == escolhido)
            printf("❌ Escolha inválida! Tente novamente.\n");
    } while (opcao < 1 || opcao > 4 || opcao == escolhido);
    return opcao;
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 225, 8510, 1.8, 25};
    Carta carta2 = {"Russia", 200, 7500, 4.0, 50};

    int atributo1, atributo2;

    printf("🎴 SUPER TRUNFO - COMPARAÇÃO DE PAÍSES 🎴\n");
    
    // Escolha dos atributos
    mostrarOpcoes();
    printf("Escolha o primeiro atributo para comparação:\n");
    atributo1 = escolherAtributo(0);
    mostrarOpcoes();
    atributo2 = escolherAtributo(atributo1);

    // Comparação das cartas
    compararCartas(carta1, carta2, atributo1, atributo2);

    return 0;
}
