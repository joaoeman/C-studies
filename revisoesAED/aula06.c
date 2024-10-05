#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next;
} NODO;

typedef NODO *listaennc;

void cria(listaennc *p) {
  *p = (NODO *)calloc(sizeof(NODO), 1);
  if (!p)
    exit(1);
  (*p)->inf = 0;
  (*p)->next = NULL;
}

int vazio(listaennc p) { return (p->inf == 0); }

int tam(listaennc p) { return (p->inf); }

void ins(listaennc p, int valor, int pos) {
  if (pos < 1 || pos > p->inf + 1)
    exit(1);
  listaennc v, aux;

  v = (NODO *)malloc(sizeof(NODO));
  v->inf = valor;

  for (aux = p; pos > 1; aux = aux->next, pos--)
    ;
  v->next = aux->next;
  aux->next = v;
}

int recup(listaennc p, int pos) {
  listaennc aux;
  if (pos < 1 || pos > p->inf)
    exit(1);
  for (aux = p; pos > 0; aux = aux->next, pos--)
    ;
  return (aux->inf);
}

void ret(listaennc p, int pos) {
  if (pos < 1 || pos > p->inf)
    exit(1);
  listaennc aux1, aux2;

  for (aux1 = p; pos > 1; aux1 = aux1->next, pos--)
    ;
  aux2 = aux1->next;
  aux1->next = aux2->next;
  free(aux2);
}
void destruir(listaennc p) {
  listaennc aux;
  while (p) {
    aux = p;
    p = p->next;
    free(aux);
  }
} 