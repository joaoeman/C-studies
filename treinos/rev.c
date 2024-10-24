#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *left, *right;
  int altd, alte;
} NODO;
typedef struct nodo {
  int info;
  struct nodo *father;
  struct nodo *left;
  struct nodo *right;
} NODE;
typedef NODE *tree;
typedef NODO *tree_avl;

void rotacao_direita(tree_avl *t) {
  tree_avl aux1, aux2;
  aux1 = (*t)->left;
  aux2 = aux1->right;
  aux1->right = *t;
  (*t)->left = aux2;

  if ((*t)->left == NULL)
    (*t)->alte = 0;
  else if ((*t)->left->alte > (*t)->left->altd)
    (*t)->alte = (*t)->left->alte + 1;
  else
    (*t)->alte = (*t)->left->altd + 1;

  if (aux1->right->alte > aux1->right->altd)
    aux1->altd = aux1->right->alte + 1;
  else
    aux1->altd = aux1->right->altd + 1;
  *t = aux1;
}

void rotacao_esquerda(tree_avl *t) {
  tree_avl aux1, aux2;
  aux1 = (*t)->right;
  aux2 = aux1->left;
  (*t)->right = aux2;
  aux1->left = *t;

  if ((*t)->right == NULL)
    (*t)->altd = 0;
  else if ((*t)->right->altd > (*t)->right->alte)
    (*t)->altd = (*t)->right->altd + 1;
  else
    (*t)->altd = (*t)->right->alte + 1;

  if (aux1->left->alte > aux1->left->altd)
    aux1->alte = aux1->left->alte + 1;
  else
    aux1->altd = aux1->left->altd + 1;
  *t = aux1;
}
void balanceamento(tree_avl *t) {
  int pai, filho;
  pai = (*t)->altd - (*t)->alte;
  if (pai == 2) {
    filho = (*t)->right->altd - (*t)->right->alte;
    if (filho < 0)
      rotacao_direita(&((*t)->right));
    rotacao_esquerda(t);
  } else if (pai == -2) {
    filho = (*t)->left->altd - (*t)->left->alte;
    if (filho >= 0)
      rotacao_esquerda(&((*t)->left));
    rotacao_direita(t);
  }
}

void fusionremove(tree *t) {
  tree aux = *t;
  if (*t) {
    if (!(*t)->right) {
      if ((*t)->left) {
        (*t)->left->father = (*t)->father;
        *t = (*t)->left;
      }
    } else if ((*t)->left == NULL) {
      (*t)->right->father = (*t)->father;
      *t = (*t)->right;
    } else {
      aux = aux->left;
      while (aux->right)
        aux = aux->right;
      aux->right = (*t)->right;
      if (aux->right)
        aux->right->father = aux;
      aux = *t;
      *t = (*t)->left;
    }
    free(aux);
  }
}

void copyremove(tree *t) {
  tree aux = *t;
  if (*t) {
    if (!(*t)->right) {
      if ((*t)->left) {
        (*t)->left->father = (*t)->father;
        *t = (*t)->left;
      }
    } else if ((*t)->left == NULL) {
      (*t)->right->father = (*t)->father;
      *t = (*t)->right;
    } else {
      aux = aux->right;
      while (aux->left)
        aux = aux->left;
      (*t)->info = aux->info;
      if(aux->father == *t){
        aux->father->right = aux->right;
        if(aux->father->right)
            aux->father->right->father = aux->right;
      }
      else{
        aux->father->left = aux->right;
        if(aux->father->left)
            aux->father->left->father = aux->left;
      }
    }
    free(aux);
  }
}