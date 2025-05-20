#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int agua[10][10];

    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            agua[i][j] = 0;
        }
    }

    
    for (int i = 0; i < 3; i++) {
        agua[4][1 + i] = 3;
    }

    
    for (int i = 0; i < 3; i++) {
        agua[7 + i][8] = 3;
    }

    
    printf("  ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", letras[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
        for (int j = 0; j < 10; j++) {
            printf("%d ", agua[i][j]);
        }
        printf("\n");
    }
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    #include <stdio.h>

#define LetrasLinhas 10
#define AguaLinha 10
#define AguaColuna 10

    char letras[LetrasLinhas] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int agua[AguaLinha][AguaColuna];

    
    for (int i = 0; i < AguaLinha; i++) {
        for (int j = 0; j < AguaColuna; j++) {
            agua[i][j] = 0;
        }
    }

    
    for (int i = 0; i < 3; i++) {
        agua[4][1 + i] = 3;
    }

    
    for (int i = 0; i < 3; i++) {
        agua[7 + i][8] = 3;
    }
    
    for (int i = 0; i < 3; i++)
    {
        agua[i][4-i] = 3;
    }

    for (int i = 0; i < 3; i++)
    {
        agua[8-i][4-i] = 3;
    }
    
    printf("  ");
    for (int i = 0; i < LetrasLinhas; i++) {
        printf("%c ", letras[i]);
    }
    printf("\n");

    for (int i = 0; i < AguaLinha; i++) {
        printf("%d ", i);
        for (int j = 0; j < AguaColuna; j++) {
            printf("%d ", agua[i][j]);
        }
        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
