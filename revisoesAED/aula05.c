#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next;
} NODO;
typedef NODO *listaenc;

void cria(listaenc *p) { p = NULL; }

void vazio(listaenc p) {
  if (p == NULL)
    printf("eh vazio\n");
  else
    printf("nao eh vazio\n");
}

int tam(listaenc p) {
  int i;
  for (i = 0; p != NULL; i++)
    p = p->next;
  return (i);
}

void ins(listaenc *p, int pos, int valor) {
  NODO *v;
  int i = tam(*p);
  if (pos > i + 1 || pos < 1)
    exit(1);

  v = (NODO *)malloc(sizeof(NODO));
  if (!v)
    exit(2);
  if (pos == 1) {
    v->next = *p;
    *p = v;
  } else {
    listaenc aux;
    for (aux = *p; pos < 2; aux = aux->next, pos--)
      ;
    v->next = aux->next;
    aux->next = v;
  }
}

int recup(listaenc p, int pos) {
  int i = tam(p), j;
  if (pos < 1 || pos > i)
    exit(1);
  for (i = 0; i <= pos; i++, p = p->next)
    ;
  j = p->inf;
  return (j);
}
void ret(listaenc *p, int pos) {
  NODO *v;
  int i = tam(*p), j;
  listaenc aux1, aux2;

  if (pos < 1 || pos > i)
    exit(1);
  else if (pos == 1 && i > 1) {
    v = *p;
    *p = v->next;
    free(v);
    ;
    *p = v;
  } else {
    for (aux1 = *p; pos > 2; pos--, aux1 = aux1->next)
      ;
    for (aux2 = *p; pos > 0; pos--, aux2 = aux2->next)
      ;
    aux1->next = aux2;
  }
}