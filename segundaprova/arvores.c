#include <stdio.h>
#include <stdlib.h>
// todos as funcoes envolvendo arvores

typedef struct nodo {
  int info;
  struct nodo *father;
  struct nodo *left;
  struct nodo *right;
} NODO;

typedef struct node {
  NODO *inf;
  struct node *prox;
} fila;

typedef struct {
  fila *inicio;
  fila *fim;
} DESCRITOR;

typedef DESCRITOR *filaenc;
typedef NODO *tree;

void maketree(tree *t, int valor) {
  *t = calloc(sizeof(NODO), 1);
  (*t)->info = valor;
}

void setleft(tree t, int valor) {
  t->left = calloc(sizeof(NODO), 1);
  t->left->info = valor;
}

void setright(tree t, int valor) {
  t->right = calloc(sizeof(NODO), 1);
  t->right->info = valor;
}

int info(tree t) { return (t->info); }

tree left(tree t) { return (t->left); }

tree right(tree t) { return (t->right); }

tree brother(tree t) {
  if (t->father) {
    if (t->father->left == t)
      return t->father->right;
    else
      return t->father->left;
  }
}
tree father(tree t) { return t->father; }

int isleft(tree t) {
  if (t->father) {
    if (t->father->left == t)
      return 1;
    else
      return 0;
  }
}

int isright(tree t) {
  if (t->father) {
    if (t->father->right == t)
      return 1;
    else
      return 0;
  }
}

void cria_fila(filaenc *p) { *p = (filaenc)calloc(sizeof(DESCRITOR), 1); }

void inscfila(pilhaenc p, tree t) {

  fila *aux = (fila *)calloc(sizeof(fila), 1);
  aux->inf = t;
  if (!(p)) {
    (p)->fim = aux;
    (p)->inicio = aux;
  } else {
    p->fim->prox = aux;
    p->fim = aux;
  }
}

void retfila(filaenc p) {
  if (!p) {
    exit(6);
  } else {
    fila *aux = p->inicio;
    p->inicio = p->inicio->prox;
    free(aux);

    if (!(p->inicio))
      p->fim = NULL;
  }
}

tree cons_fila(filaenc p) {
  if (p->inicio) {
    return p->inicio->inf;
  } else {
    return NULL;
  }
}

tree direita(filaenc p) { return p->inicio->inf->right; }

tree esquerda(filaenc p) { return p->inicio->inf->left; }

void percursolargura(tree t) {
  filaenc f;
  cria_fila(&f);
  if (t) {
    inscfila(f, t);
  }
  while (f) {
    printf("%d ", info(cons_fila(f)));
    if (left(cons_fila(f))) {
      inscfila(f, left(cons_fila(f)));
    }
    if (right(cons_fila(f))) {
      inscfila(f, right(cons_fila(f)));
    }
    retfila(f);
  }
}

void preordem(tree t) {
  if (t) {
    printf("%d\n", info(t));
    preordem(left(t));
    preordem(right(t));
  }
}

void inordem(tree t){
    if(t){
        preordem(left(t));
        printf("%d\n", info(t));
        preordem(right(t));
    }
}

void posordem(tree t){
    if(t){
        preordem(left(t));
        preordem(right(t));
        printf("%d\n", info(t));
    }

}

void ins_ele(tree *t, int valor){
    if(!(*t))
        maketree(t,valor);
    else{
        tree father = *t;
        do{
            if(valor<father->info){
                if(father->father)
                    father = father->left;
                else{
                    setleft(father,valor);
                    break;
                }
            }
            else{
                if(father->right)
                    father = father->right;
                else{
                    setright(father,valor);
                    break;
                }
            }
        }while(1);
    }
}

void fusionremove(tree *t){
    tree aux = *t;
    if(!(*t))
        exit(7);

    if(father(*t)){
        if(!(left(*t) && right(*t))){
            free(aux);
        }
        else {
        if((!left(*t) && right(*t)) || (left(*t) && !right(*t))){
            if(left(*t))
                left(*t)->father = (*t)->father;
            else
                right(*t)->father = (*t)->father;
        free(aux);
        }
        else{
            tree aux2 = aux;
            aux = aux->left; 
            aux->father = NULL;

            while(aux->right)
                aux = aux->right;

            aux->right = aux2->right;
            free(aux2);
        }
        }
    }
}

void copyremove(tree *t){
    tree aux = *t;
    if(!(*t))
        exit(7);

    if(father(*t)){
        if(!(left(*t) && right(*t))){
            free(aux);
        }
        else {
        if((!left(*t) && right(*t)) || (left(*t) && !right(*t))){
            if(left(*t))
                left(*t)->father = (*t)->father;
            else
                right(*t)->father = (*t)->father;
        free(aux);
        }
        else{
            tree aux2 = aux;
            aux = aux->right; 
            aux->father = NULL;

            while(aux->left)
                aux = aux->left;
            
            aux->father = aux->father->left = NULL;
            aux->left = aux2->left;
            aux->right = aux2->right;

            free(aux2);
            *t = aux;
        }
        }
    }
}