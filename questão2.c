#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de partição para o Quick Sort
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] < pivo) {
            i++;
            // Troca os elementos
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    // Troca o pivo para a posição correta
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;

    return (i + 1);
}

// Função Quick Sort
void quick_sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pi = particionar(vetor, inicio, fim);

        quick_sort(vetor, inicio, pi - 1);
        quick_sort(vetor, pi + 1, fim);
    }
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

    // Preenche o vetor com números aleatórios
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000; // Números aleatórios de 0 a 999
    }

    // Imprime o vetor original
    printf("Vetor original:\n");
    imprimir_vetor(tamanho, vetor);

    // Quick Sort
    quick_sort(vetor, 0, tamanho - 1);
    printf("\nVetor ordenado pelo Quick Sort:\n");
    imprimir_vetor(tamanho, vetor);

    return 0;
}
