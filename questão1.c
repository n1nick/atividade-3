#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um vetor de números aleatórios
void gerar_vetor(int tamanho, int minimo, int maximo, int vetor[]) {
    // Itera sobre o vetor e preenche com números aleatórios dentro do intervalo especificado
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (maximo - minimo + 1) + minimo;
    }
}

// Função para imprimir um vetor
void imprimir_vetor(int tamanho, int vetor[]) {
    // Imprime os elementos do vetor formatados entre colchetes
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) {
            printf(", "); // Adiciona vírgula e espaço entre elementos
        }
    }
    printf("]\n"); // Imprime uma quebra de linha ao final
}

int main() {
    // Inicializa o gerador de números aleatórios com base no tempo atual
    srand(time(NULL));

    int tamanho = 10; // Tamanho do vetor
    int minimo = 1;   // Valor mínimo dos números aleatórios
    int maximo = 100; // Valor máximo dos números aleatórios
    int vetor_aleatorio[tamanho]; // Declaração do vetor

    // Gera um vetor de números aleatórios
    gerar_vetor(tamanho, minimo, maximo, vetor_aleatorio);

    // Imprime o vetor gerado
    printf("Vetor gerado: ");
    imprimir_vetor(tamanho, vetor_aleatorio);

    return 0;
}
