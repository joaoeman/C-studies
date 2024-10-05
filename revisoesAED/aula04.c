#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *next;
} NODO;
typedef NODO *listaenc;

void cria(listaenc *p) { *p = NULL; }

void vazia(listaenc p) {
  if (p == NULL)
    printf("eh vazia\n");
  else
    printf("nao eh vazia\n");
}
int tam(listaenc p) {
  int i;
  for (i = 0; p != NULL; i++)
    p = p->next;
  return (i);
}
void ins(listaenc *p, int pos, int valor) {
  NODO *l;
  int i = tam(*p);

  if (pos > i + 1 || pos < 1) {
    printf("posicao invalida\n");
    exit(1);
  }
  l = (NODO *)malloc(sizeof(NODO));
  if (!l) {
    printf("sem espaco\n");
    exit(2);
  }
  if (pos == 1) {
    l->next = *p;
    *p = l;
  } else {
    listaenc aux;

    for (aux = *p; pos > 2; aux = aux->next, pos--)
      ;
    l->next = aux->next;
    aux->next = l;
  }
}