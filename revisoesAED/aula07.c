#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next;
} NODO;

typedef NODO *listacircular;

void cria(listacircular *p) { *p = NULL; }

int vazio(listacircular p) { return (!p); }

int tam(listacircular p) {
  int cont;
  if (!p) {
    return 0;
  } else {
    listacircular aux = p->next;
    for (cont = 0; aux != p; aux = aux->next, cont++)
      ;
    return cont;
  }
}
void ins(listacircular *p, int valor, int pos) {
  listacircular v, aux = *p;

  if (pos < 1 || pos > tam(*p) + 1)
    exit(1);
  v = (NODO *)malloc(sizeof(NODO));
  if (!v)
    exit(2);
  v->inf = valor;
  if (*p == NULL) {
    v->next = v;
    *p = v;
  } else {
    if (pos == tam(*p) + 1)
      *p = v;
    else
      for (; pos > 1; aux = aux->next)
        ;
    v->next = aux->next;
    aux->next = v;
  }
}

int recup(listacircular p, int pos) {

  listacircular aux = p;
  if (pos < 1 || pos > tam(p))
    exit(1);
  for (; pos > 0; pos--, aux = aux->next)
    ;
  return aux->inf;
}

void ret(listacircular *p, int pos) {
  listacircular aux = *p, aux2;
  if (pos < 1 || pos > tam(*p))
    exit(1);
  if (tam(*p) == 1) {
    free(aux);
    *p = NULL;
  } else {
    for (; pos > 1; pos--, aux = aux->next)
      ;
    aux2 = aux->next;
    aux->next = aux2->next;
    if (pos == tam(*p))
      *p = aux;
    free(aux2);
  }
}

void destruir(listacircular p) {
  listacircular aux;
  while (p) {
    aux = p;
    p = p->next;
    free(aux);
  }
}
