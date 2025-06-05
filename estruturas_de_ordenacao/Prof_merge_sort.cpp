#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int start, int meio, int end) {
  int i = start, j = meio + 1, k = 0;
  int temp[end - start + 1];

  while (i <= meio && j <= end) {
    if (vetor[i] <= vetor[j]) {
      temp[k++] = vetor[i++];
    } else {
      temp[k++] = vetor[j++];
    }
  }

  while (i <= meio) temp[k++] = vetor[i++];
  while (j <= end) temp[k++] = vetor[j++];

  for (i = start, k = 0; i <= end; i++, k++) {
    vetor[i] = temp[k];
  }
}

void divide(int *vetor, int start, int end) {
  if (start >= end) {
    // printf("Caso base 1 elemento: %d\n", vetor[start]);
    return;
  }

  int meio = (start + end) / 2;
  divide(vetor, start, meio);
  divide(vetor, meio + 1, end);
  merge(vetor, start, meio, end);
}

int main() {
  int vetor[] = {8, 7, 3, 9, 2, 5, 6, 1, 4, 10};
  int tamanho = sizeof(vetor) / sizeof(vetor[0]);

  divide(vetor, 0, tamanho - 1);

  for (int i = 0; i < tamanho; i++) {
    printf(" -> %d", vetor[i]);
  }
  printf("\n");

  return 0;
}
