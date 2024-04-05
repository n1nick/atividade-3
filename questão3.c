#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de busca binária
int busca_binaria(int vetor[], int inicio, int fim, int alvo) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Se o elemento está presente no meio
        if (vetor[meio] == alvo)
            return meio;

        // Se o elemento é maior, descarte a metade esquerda
        if (vetor[meio] < alvo)
            inicio = meio + 1;
        // Se o elemento é menor, descarte a metade direita
        else
            fim = meio - 1;
    }

    // Se o elemento não está presente no vetor
    return -1;
}

// Função para imprimir um vetor
void imprimir_vetor(int tamanho, int vetor[]) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    srand(time(NULL));

    int tamanho = 100;
    int vetor[tamanho];

    // Preenche o vetor com números aleatórios ordenados
    vetor[0] = rand() % 10; // Primeiro elemento aleatório
    for (int i = 1; i < tamanho; i++) {
        vetor[i] = vetor[i - 1] + rand() % 10 + 1; // Incrementa aleatoriamente
    }

    // Imprime o vetor original
    printf("Vetor ordenado:\n");
    imprimir_vetor(tamanho, vetor);

    // Aplica a busca binária 10 vezes
    for (int i = 0; i < 10; i++) {
        int alvo = vetor[rand() % tamanho]; // Escolhe um elemento aleatório do vetor
        int resultado = busca_binaria(vetor, 0, tamanho - 1, alvo);
        printf("\nBusca binária pelo elemento %d: ", alvo);
        if (resultado != -1) {
            printf("Encontrado na posição %d\n", resultado);
        } else {
            printf("Não encontrado\n");
        }
    }

    return 0;
}
