#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num,altd,alte;
    struct nodo *right,*left;
}NODO;

typedef NODO* tree_avl;

void rotacao_direita(tree_avl *t){

    tree_avl aux1,aux2;
    aux1 = (*t)->left;
    aux2 = aux1->right;
    (*t)->left = aux2;
    aux1->right = *t;
    if((*t)->left == NULL)
        (*t)->alte = 0;

    else 
        if((*t)->left->alte > (*t)->left->altd)
            (*t)->alte = (*t)->left->alte+1;
        else
            (*t)->alte = (*t)->left->altd+1;
    if(aux1->right->alte > aux1->right->altd)
        aux1->altd = aux1->right->alte+1;
    else
        aux1->altd = aux1->right->altd+1;
    *t = aux1;
}

void rotacao_esquerda(tree_avl *t){
    tree_avl aux1,aux2;
    aux1 = (*t)->right;
    aux2 = aux1->left;
    (*t)->right = aux2;
    aux1->left = *t;
    if((*t)->right == NULL)
        (*t)->altd = 0;
    else{ 
        if((*t)->right->alte > (*t)->right->altd)
            (*t)->altd = (*t)->left->alte+1;
        else   
            (*t)->altd = (*t)->right->altd+1;
    }
    if((*t)->left->altd>(*t)->left->alte)
        (*t)->alte = (*t)->right->altd+1;
    else
        (*t)->alte = (*t)->right->alte+1;
    *t = aux1;
}

void balanceamento(tree_avl *t){
    int pai,filho;
    pai = (*t)->altd - (*t)->alte;
    if(pai == 2){
        filho = (*t)->right->altd - (*t)->right->alte;
        if(filho < 0)
            rotacao_direita(&((*t)->right));
        rotacao_esquerda(t);
    }
    else{
        if(pai == -2){
            filho = (*t)->left->altd - (*t)->left->alte;
            if(filho >= 0)
                rotacao_esquerda(&((*t)->left));
            rotacao_direita(t);
        }
    }
}