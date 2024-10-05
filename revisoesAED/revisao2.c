#include <stdio.h>
#include <stdlib.>

typedef struct nodo {
  int inf;
  struct nodo *next;
} NODO;
typedef NODO *listaenc;

void cria(listaenc *p) { *p = NULL; }

int vazio(listaenc p) {
  if (p == NULL)
    return 0;
  else
    return 1;
}

int tam(listaenc p) {
  int cont;
  for (cont = 0; p != NULL; cont++, p = p->next)
    ;
  return cont;
}
void ins(listaenc *p, int pos, int valor) {
  NODO *v;

  if (pos > tam(*p) + 1 || pos < 1)
    exit(1);
  v = (NODO *)malloc(sizeof(NODO));
  if (pos == 1) {
    v->next = *p;
    *p = v;
  } else {
    listaenc aux;
    for (aux = *p; pos > 2; pos--, aux = aux->next)
      ;
    v->next = aux->next;
    aux->next = v;
  }
}
void ret(listaenc *p, int pos) {
  listaenc aux1, aux2;
  if (pos > tam(*p) || pos < 1)
    exit(1);
  if (pos == 1) {
    aux1 = *p;
    *p = aux1->next;
    free(aux1);
  } else {
    for (aux1 = *p; pos > 2; pos--, aux1 = aux1->next)
      ;
    aux2 = aux1->next;
    aux1->next = aux2->next;
    free(aux2);
  }
}
void detruir(listaenc p) {
  listaenc aux;
  while (p) {
    aux = p;
    p = p->next;
    free(aux);
  }
}
void insr(listaenc *p, int pos, int valor) {
  if (pos < 1 || pos > tam(*p) + 1)
    exit(1);
  if (pos == 1) {
    listaenc v;
    v = (NODO *)malloc(sizeof(NODO));
    v->inf = valor;
    v->next = *p;
    *p = v;
  } else {
    return insr(&((*p))->next, pos - 1, valor);
  }
}
void retr(listaenc *p, int pos) {
  if (pos < 1 || pos > tam(*p)) {
    exit(1);
  }
  if (pos == 1) {
    listaenc v;
    v = *p;
    *p = v->next;
    free(v);
  } else
    return ret(&(*p)->next, pos - 1);
}
void destr(listaenc p) {
  if (p) {
    destr(p->next);
    free(p);
  }
}
int recupr(listaenc p, int pos) {
  if (pos < 1 || pos > tam(p))
    exit(1);
  if (pos == 1)
    return p->inf;
  else
    return recupr(p->next, pos - 1);
}
int pertence(listaenc p, int valor) {
  int i = tam(p), j = 0;
  for (; p; p = p->next) {
    if (p->inf == valor)
      j++;
  }
  return j;
}
int pertencer(listaenc p, int valor) {
  if (p->inf == valor)
    return 1;
  else if (p->next)
    return (p->inf);
  else
    return 0;
}
void gera(listaenc *p, int m, int n) {
  if (m > n)
    exit(5);
  else {
    ins(p, tam(*p) + 1, m);
    return gera(&(*p)->next, m + 1, n);
  }
}