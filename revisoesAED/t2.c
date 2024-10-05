#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next;
} NODO;
typedef NODO *listaenc;

void cria(listaenc *p) { *p = NULL; }
int vazio(listaenc p) { return (p == NULL); }
int tam(listaenc p) {
  int cont;
  for (cont = 0; p != NULL; cont++, p = p->next)
    ;
  return cont;
}

void ins(listaenc *p, int pos, int valor) {
  listaenc v, aux;
  if (pos < 1 || pos > tam(*p) + 1)
    exit(1);
  v = (NODO *)malloc(sizeof(NODO));
  if (!v)
    exit(2);
  v->inf = valor;
  if (pos == 1) {
    aux = *p;
    v->next = aux;
    *p = v;
  } else {
    for (aux = *p; pos > 2; pos--, aux = aux->next)
      ;
    v->next = aux->next;
    aux->next = v;
  }
}

void insr(listaenc *p, int pos, int valor) {
  listaenc v;
  if (pos < 1 || pos > tam(*p) + 1)
    exit(1);
  v = (NODO *)malloc(sizeof(NODO));
  if (!v)
    exit(2);
  v->inf = valor;
}