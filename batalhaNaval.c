    #include <stdio.h>

#define TamanhoDoTabuleiro 10 
#define HabilidadesNoTabuleiro 5  
#define LetrasLinhas 10
#define AguaLinha 10
#define AguaColuna 10
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

int aplicarHabilidade(int tabuleiro[TamanhoDoTabuleiro][TamanhoDoTabuleiro], int habilidade[HabilidadesNoTabuleiro][HabilidadesNoTabuleiro], int origemLinha, int origemColuna) {
    for (int i = 0; i < HabilidadesNoTabuleiro; i++) {
        for (int j = 0; j < HabilidadesNoTabuleiro; j++) {
            int linha = origemLinha + i - HabilidadesNoTabuleiro / 2;
            int coluna = origemColuna + j - HabilidadesNoTabuleiro / 2;

            if (linha >= 0 && linha < TamanhoDoTabuleiro && coluna >= 0 && coluna < TamanhoDoTabuleiro) {
                if (habilidade[i][j] == 1) {
                    if (tabuleiro[linha][coluna] == 3) {
                        tabuleiro[linha][coluna] = 5; 
                    } else if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 1; 
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    char letras[TamanhoDoTabuleiro] = {'A','B','C','D','E','F','G','H','I','J'};
    int agua[TamanhoDoTabuleiro][TamanhoDoTabuleiro];

    
    for (int i = 0; i < TamanhoDoTabuleiro; i++)
        for (int j = 0; j < TamanhoDoTabuleiro; j++)
            agua[i][j] = 0;

    
    for (int i = 0; i < 3; i++) agua[4][1 + i] = 3;
    for (int i = 0; i < 3; i++) agua[7 + i][8] = 3;
    for (int i = 0; i < 3; i++) agua[i][4 - i] = 3;
    for (int i = 0; i < 3; i++) agua[8 - i][4 - i] = 3;

    
    int habilidadeCone[HabilidadesNoTabuleiro][HabilidadesNoTabuleiro];
    for (int i = 0; i < HabilidadesNoTabuleiro; i++) {
        for (int j = 0; j < HabilidadesNoTabuleiro; j++) {
            if (j >= (HabilidadesNoTabuleiro - 1) / 2 - i && j <= (HabilidadesNoTabuleiro - 1) / 2 + i)
                habilidadeCone[i][j] = 1;
            else
                habilidadeCone[i][j] = 0;
        }
    }

    
    int habilidadeCruz[HabilidadesNoTabuleiro][HabilidadesNoTabuleiro];
    for (int i = 0; i < HabilidadesNoTabuleiro; i++) {
        for (int j = 0; j < HabilidadesNoTabuleiro; j++) {
            if (i == HabilidadesNoTabuleiro / 2 || j == HabilidadesNoTabuleiro / 2)
                habilidadeCruz[i][j] = 1;
            else
                habilidadeCruz[i][j] = 0;
        }
    }

    
    int habilidadeOctaedro[HabilidadesNoTabuleiro][HabilidadesNoTabuleiro];
    int centro = HabilidadesNoTabuleiro / 2;
    for (int i = 0; i < HabilidadesNoTabuleiro; i++) {
        for (int j = 0; j < HabilidadesNoTabuleiro; j++) {
            int distLinha = (i > centro) ? (i - centro) : (centro - i);
            int distColuna = (j > centro) ? (j - centro) : (centro - j);
            if (distLinha + distColuna <= centro)
                habilidadeOctaedro[i][j] = 1;
            else
                habilidadeOctaedro[i][j] = 0;
        }
    }

    
    aplicarHabilidade(agua, habilidadeCone, 2, 2);
    aplicarHabilidade(agua, habilidadeCruz, 5, 5);
    aplicarHabilidade(agua, habilidadeOctaedro, 7, 2);

    
    printf("  ");
    for (int i = 0; i < TamanhoDoTabuleiro; i++) printf("%c ", letras[i]);
    printf("\n");

    for (int i = 0; i < TamanhoDoTabuleiro; i++) {
        printf("%d ", i);
        for (int j = 0; j < TamanhoDoTabuleiro; j++) {
            printf("%d ", agua[i][j]);
        }
        printf("\n");
    }

    return 0;
}

    return 0;
}
