#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct {
  int n;
  int vet[max];
} lista;

void cria(lista *p) { p->n = 0; }

void vazio(lista *p) {
  if (p->n == 0)
    printf("eh vazio\n");
  else
    printf("nao eh vazio\n");
}

int tam(lista *p) { return p->n; }

void ins(lista *p, int pos, int valor) {
  int i;

  if (pos < 1 || pos > p->n + 1 || p->n == max) {
    printf("posicao nao valida\n");
    exit(1);
  }

  else {
    if (pos == p->n + 1)
      p->vet[pos - 1] = valor;
    else
      for (i = p->n; i >= pos; i--)
        p->vet[i] = p->vet[i - 1];
    p->vet[pos - 1] = valor;
    p->n++;
  }
}

int recup(lista *p, int pos) {
  if (pos < 1 || pos > p->n || pos == max) {
    printf("posicao nao valida\n");
    exit(2);
  }
  return p->vet[pos - 1];
}

void ret(lista *p, int pos) {
  int i;

  if (pos < 1 || pos > p->n || p->n == max) {
    printf("posicao nao valida\n");
    exit(3);
  } else {
    for (i = pos; i < p->n - 1; i++)
      p->vet[pos - 1] = p->vet[pos];
  }
  p->n--;
}

int pertence(lista *p, int valor) {
  int i, k = 0;
  for (i = 0; i < p->n; i++) {
    if (p->vet[i] == valor)
      i++;
  }
  return k;
}

int ord(lista *p) {
  int i, k = 1;
  for (i = 0; i < p->n - 1; i++) {
    if (p->vet[i] > p->vet[i + 1])
      k--;
  }
  return k;
}
void gera(lista *p, int i, int f) {
  if (i <= f) {
    p->n++;
    p->vet[p->n - 1] = i;
    i++;
    return gera(p, i + 1, f);
  }
}
