#include <stdio.h>

int main() {
    // --- 1. Definição de Variáveis e Constantes ---
    // Define o tamanho do tabuleiro (10x10) e do navio (3 partes)
    const int TAM_TABULEIRO = 10;
    const int TAM_NAVIO = 3;
    
    // Valores para representar água (0) e navio (3)
    const int AGUA = 0;
    const int PARTE_NAVIO = 3;

    // Matriz que representa o tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Vetor representando a estrutura do navio (preenchido com 3)
    // Conforme solicitado: usamos este vetor para "copiar" o valor para o tabuleiro
    int navio[3] = {PARTE_NAVIO, PARTE_NAVIO, PARTE_NAVIO};

    // --- 2. Inicialização do Tabuleiro ---
    // Preenche todo o tabuleiro com ÁGUA (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // --- 3. Posicionamento do Navio Horizontal ---
    // Coordenadas fixas para o navio horizontal (Linha 2, Coluna 2)
    int hLinha = 2;
    int hColuna = 2;

    // Validação: Verifica se o navio cabe dentro do limite horizontal
    if (hColuna + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Copia o valor do vetor 'navio' para a matriz 'tabuleiro'
            // A linha é fixa, a coluna avança (hColuna + i)
            tabuleiro[hLinha][hColuna + i] = navio[i];
        }
        printf("Navio Horizontal posicionado com sucesso!\n");
    } else {
        printf("Erro: Navio Horizontal fora dos limites.\n");
    }

    // --- 4. Posicionamento do Navio Vertical ---
    // Coordenadas fixas para o navio vertical (Linha 5, Coluna 6)
    int vLinha = 5;
    int vColuna = 6;

    // Validação 1: Verifica limites verticais
    if (vLinha + TAM_NAVIO <= TAM_TABULEIRO) {
        
        // Validação 2: Verifica sobreposição (simples)
        // Checa se as posições alvo já estão ocupadas (diferente de 0)
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[vLinha + i][vColuna] != AGUA) {
                sobreposicao = 1;
                break; // Se achou uma parte ocupada, para a verificação
            }
        }

        if (sobreposicao == 0) {
            // Se não houver sobreposição, posiciona o navio
            for (int i = 0; i < TAM_NAVIO; i++) {
                // A coluna é fixa, a linha avança (vLinha + i)
                tabuleiro[vLinha + i][vColuna] = navio[i];
            }
            printf("Navio Vertical posicionado com sucesso!\n");
        } else {
            printf("Erro: Sobreposicao detectada ao posicionar navio vertical.\n");
        }
        
    } else {
        printf("Erro: Navio Vertical fora dos limites.\n");
    }

    // --- 5. Exibição do Tabuleiro ---
    printf("\n--- TABULEIRO BATALHA NAVAL ---\n");
    // Cabeçalho das colunas para facilitar leitura
    printf("  0 1 2 3 4 5 6 7 8 9\n"); 
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d ", i); // Imprime o número da linha
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            // Imprime o valor da célula seguido de um espaço
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Quebra de linha ao final de cada linha da matriz
    }

    return 0;
}