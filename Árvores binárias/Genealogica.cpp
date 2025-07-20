#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT 9

typedef struct {
  char nome[30];
  int idade;
} Pessoa;

typedef struct node {
  Pessoa *pessoa;
  struct node *filhos[QNT];

} No;

No *criar_no() {
  Pessoa *p = new Pessoa;
  No *node = new No;

  printf("Digite o nome: ");
  scanf(" %s", p->nome);
  printf("Digite a idade: ");
  scanf("%d", &p->idade);

  node->pessoa = p;
  for (int i = 0; i < QNT; i++) {
    node->filhos[i] = NULL;
  }

  return node;
}

void inserir_no(No *pai, No *novo) {
  for (int i = 0; i < QNT; i++) {
    if (pai->filhos[i] == NULL) {
      pai->filhos[i] = novo;
      return;
    }
  }

  printf("Não inseriu. Excesso de filhos.\n");
}

No *busca_nome(No *node, char *nome) {
  if (node == NULL) return NULL;

  if (strcmp(node->pessoa->nome, nome) == 0) {
    return node;
  }

  No *res = NULL;
  for (int i = 0; i < QNT; i++) {
    res = busca_nome(node->filhos[i], nome);
    if (res != NULL) {
      return res;
    }
  }

  return NULL;
}

void imprimir(No *node, int tab = 0) {
  if (node == NULL) return;

  for (int i = 0; i < tab; i++) {
    printf("\t");
  }

  printf("%s - %d\n", node->pessoa->nome, node->pessoa->idade);
  for (int i = 0; i < QNT; i++) {
    imprimir(node->filhos[i], tab + 1);
  }
}

void inserir_pai(No **node) {
  if (*node == NULL) {
    *node = criar_no();
    return;
  }

  char nome_pai[30];
  printf("Digite o nome do nó pai: ");
  scanf(" %s", nome_pai);

  No *pai = busca_nome(*node, nome_pai);
  if (pai == NULL) {
    printf("Nó não encontrado\n");
    return;
  }

  No *filho = criar_no();
  inserir_no(pai, filho);
}

void buscar_pai(No *root) {
  char nome[30];
  printf("Digite o nome da pessoa: ");
  scanf(" %s", nome);
  No *no = busca_nome(root, nome);
  if (no == NULL) {
    printf("Pessoa não encontrada\n");
    return;
  }
  printf("%s - %d\n", no->pessoa->nome, no->pessoa->idade);
}

void menu() {
  printf("MENU\n");
  printf("1-Inserir\n");
  printf("2-Buscar\n");
  printf("3-Imprimir Árvore\n");
  printf("0-Sair\n");
}

int main(int argc, char const *argv[]) {
  No *root = NULL;

  int opc = 1;
  while (opc != 0) {
    menu();
    scanf("%d", &opc);
    switch (opc) {
      case 1:
        inserir_pai(&root);
        break;
      case 2:
        buscar_pai(root);
        break;
      case 3:
        imprimir(root);
        break;
      default:
        printf("Opção inválida\n");
        break;
    }
  }

  return 0;
}
