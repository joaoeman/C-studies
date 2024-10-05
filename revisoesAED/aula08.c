#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *previous;
  struct nodo *next;
} NODO;

typedef NODO *listadupenc;

void cria(listadupenc *p) { *p = NULL; }
int vazio(listadupenc p) { return (!p); }
int tam(listadupenc p) {
  int count;

  for (count = 0; p; count++, p = p->next)
    ;
  return (count);
}

void ins(listadupenc *p, int pos, int valor) {
  listadupenc v;
  if (pos < 1 || pos > tam(*p) + 1)
    exit(1);
  v = (NODO *)calloc(sizeof(NODO), 1);
  if (!v)
    exit(2);
  v->inf = valor;
  if (pos == 1) {
    listadupenc aux = *p;
    v->next = aux;
    v->previous = NULL;
    *p = v;
    if (aux)
      aux->previous = v;
  } else {
    listadupenc aux;
    for (aux = *p; pos > 2; pos--, aux = aux->next)
      ;
    v->next = aux->next;
    v->previous = aux;
    aux->next = v;
    if (v->next)
      v->next->previous = v;
  }
}
int recup(listadupenc p, int pos) {
  if (pos < 1 || pos > tam(p))
    exit(3);
  for (; pos > 1; pos--, p = p->next)
    ;
  return (p->inf);
}

void ret(listadupenc *p, int pos) {
  if (pos < 1 || pos > tam(*p))
    exit(4);
  if (pos == 1) {
    listadupenc aux = *p;
    *p = aux->next;
    if (aux->next)
      aux->next->previous = NULL;
    free(aux);
  } else {
    listadupenc aux;
    for (aux = *p; pos > 1; pos--, aux = aux->next)
      ;
    aux->previous->next = aux->next;
    if (aux->next)
      aux->next->previous = aux->previous;
    free(aux);
  }
}
void destruir(listadupenc p) {
  while (p) {
    listadupenc aux;
    aux = p;
    p = p->next;
    free(aux);
  }
}

void inverter(listadupenc *p) {
  listadupenc aux1, aux2, aux4, aux3, temp;
  int t, j = 0;

  if (tam(*p) == 0 || tam(*p) == 1)
    exit(5);
  for (t = tam(*p), aux3 = *p, aux4 = *p; t > 1; t--, aux3 = aux1->next)
    ;
  t = tam(*p);
  while (t > j) {
    aux2 = aux3;
    aux1 = aux1;
    aux2->next->previous = aux1;
    aux1->previous->next = aux2;
    temp = aux2->next; // trocando o antecessor e proximo dos dois a partir daq
    aux2->next = aux1->next;
    aux1->next = temp;
    temp = aux2->previous;
    aux2->previous = aux1->previous;
    aux1->previous = temp;
    if (j != 0)
      aux2->previous->next = aux1;
    if (t != tam(*p))
      aux1->next->previous = aux2;
    j++;
    t--;
    aux3 = aux3->previous;
    aux4 = aux4->next;
  }
}
