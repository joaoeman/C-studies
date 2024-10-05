#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct {
  int n;
  int v[max];
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

  if (pos < 1 || pos > tam(p) + 1 || pos == max)
    exit(1);
  if (pos == tam(p) + 1)
    p->v[pos - 1] = valor;
  else {
    int i;
    for (i = tam(p) - 1; i > pos - 1; i--)
      p->v[i + 1] = p->v[i];
    p->v[pos - 1] = valor;
  }
  p->n++;
}
int recup(lista *p, int pos) {
  if (pos < 1 || pos > p->n)
    exit(1);
  return p->v[pos - 1];
}
void ret(lista *p, int pos) {
  if (pos < 1 || pos > p->n)
    exit(1);
  if (pos < p->n) {
    int i;
    for (i = pos - 1; i < p->n - 1; i++)
      p->v[i] = p->v[i + 1];
  }
  p->n--;
}