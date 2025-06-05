#include <math.h>
#include <stdio.h>
#include <time.h>

#include <random>

void inicia_vetor(int *vetor, int n) {
  srand(clock());
  for (int i = 0; i < n; i++) {
    vetor[i] = (abs(rand()) % 100);
  }
}

void imprimir(int *vetor, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d -> ", vetor[i]);
  }
  printf("FIM\n");
}

void troca(int *vetor, int i, int j) {
  int aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

void sort(int *vetor, int n) {
}

int main(int argc, char const *argv[]) {
  int n = 0;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  int vetor[n];

  inicia_vetor(vetor, n);

  imprimir(vetor, n);

  sort(vetor, n);

  imprimir(vetor, n);
  return 0;
}
