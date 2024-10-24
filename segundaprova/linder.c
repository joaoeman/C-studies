#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int info;
  struct nodo *father, *left, right;
} NODO;

typedef NODO *tree;

typedef struct node {
  tree inf;
  struct node *next;
} NODE;

typedef struct {
  NODE *inicio, *fim;
} descritor;

typedef descritor *fila;

void cria_fila(fila *f) {
  *f = (fila)malloc(sizeof(descritor));
  (*f)->inicio = (*f)->fim = NULL;
}

void ins_fila(fila f, tree t) {
  NODE *v = (NODE *)malloc(sizeof(NODE));
  v->inf = t;
  v->next = NULL;
  if (!(f)->inicio) {
    (f)->inicio = (f)->fim = v;
  } else {
    (f)->fim->next = v;
    (f)->fim = v;
  }
}

void ret_fila(fila f) {
  if (f) {

    NODE *aux = f->inicio;
    f->inicio = f->inicio->next;
    if (f->inicio == NULL)
      f->fim = NULL;
    free(aux);
  }
}

tree cons_fila(fila f){
    return f->inicio->inf;
}

int info(tree t){
    return t->info;
}

void percurso_largura(tree t){
    fila f;
    cria_fila(&f);
    ins_fila(f,t);
    while(f->inicio){
        printf("%d", info(cons_fila(f)));
        if(cons_fila(f)->left)
            ins_fila(f, cons_fila(f)->left);
        
        if(cons_fila(f)->right)
            ins_fila(f,cons_fila(f)->right);
        ret_fila(f);
    }
}