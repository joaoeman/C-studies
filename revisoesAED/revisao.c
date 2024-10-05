#include <stdio.h>
#define max 100
#include <stdlib.h>

typedef struct {
  int n;
  int val[max];
} lista;

void cria(lista *p) { p->n = 0; }

int vazio(lista *p) {
  if (p->n == 0)
    return 0;
  else
    return 1;
}

int tam(lista *p) { return p->n; }

void ins(lista *p, int pos, int valor) {
  int i;
  if (pos < 1 || pos > tam(p) + 1 || pos == max)
    exit(1);
  if (pos == tam(p) + 1)
    p->val[pos - 1] = valor;
  else {
    for (i = tam(p) - 1; i >= pos - 1; i--)
      p->val[i + 1] = p->val[i];
    p->val[pos - 1] = valor;
  }
  p->n++;
}

int recup(lista *p, int pos) {
  if (pos < 1 || pos > p->n)
    exit(2);
  return p->val[pos - 1];
}

void ret(lista *p, int pos) {
  int i;
  if (pos < 1 || pos > p->n)
    exit(2);
  p->n--;
  for (i = pos - 1; i < p->n; i++)
    p->val[i] = p->val[i + 1];
}

int pertence(lista *p, int valor) {
  int i;
  for (i = 0; i < p->n; i++) {
    if (p->val[i] == valor)
      return 1;
  }
  return 0;
}

int ordem(lista *p) {
  int i;
  for (i = 0; i < p->n - 1; i++) {
    if (p->val[i] > p->val[i + 1]) {
      return 0;
    }
    return 1;
  }
}
void gera(lista *p, int m, int n) {
  if (m > n)
    exit(3);
  else {
    p->n++;
    ins(p, p->n, m);
    gera(p, m + 1, n);
  }
}