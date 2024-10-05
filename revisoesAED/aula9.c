#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next;
  struct nodo *previous;
} NODO;

typedef NODO *listacircupenc;

void cria(listacircupenc *p) {
  *p = (NODO *)malloc(sizeof(NODO));
  if (!(*p))
    exit(1);
  (*p)->inf = 0;
  (*p)->previous = (*p)->next = *p;
}

int vazio(listacircupenc p) { return (!(p->inf)); }

int tam(listacircupenc p) { return p->inf; }

void ins(listacircupenc p, int pos, int valor) {
  listacircupenc aux, v;
  if (pos < 1 || pos > p->inf + 1)
    exit(2);
  v = (NODO *)malloc(sizeof(NODO));
  if (!v)
    exit(3);
  v->inf = valor;
  for (aux = p; pos > 1; aux = aux->next, pos--)
    ;
  v->next = aux->next;
  v->previous = aux;
  aux->next = v;
  v->next->previous = v;
  p->inf++;
}

int recup(listacircupenc p, int pos) {
  if (pos < 1 || pos > p->inf)
    exit(4);
  for (; pos > 0; pos--, p = p->next)
    ;
  return (p->inf);
}
void ret(listacircupenc p, int pos) {
  listacircupenc aux;
  if (pos < 1 || pos > p->inf)
    exit(5);
  for (aux = p; pos > 0; aux = aux->next)
    ;
  aux->next->previous = aux->previous;
  aux->previous->next = aux->next;
  free(aux);
  p->inf--;
}
void destruir(listacircupenc p) {
  while (p) {
    listacircupenc aux;
    aux = p;
    p = p->next;
    free(aux);
  }
}

void inverter(listacircupenc p) {
  listacircupenc aux = p, aux2, temp;
  p = p->next;
  temp = aux->next;
  aux->next = aux->previous;
  aux->previous = temp;
  while (p != aux) {
    temp = p->next;
    p->next = p->previous;
    p->previous = temp;
    p = p->previous;
  }
}