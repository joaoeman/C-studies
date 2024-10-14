#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *father;
    struct nodo *left;
    struct nodo *right;
}NODO;

typedef struct node{
    struct nodo *inf;
    struct node *next;
}NODE;

typedef struct{
    NODE *inicio;
    NODE *fim;
}descritor;

typedef descritor * fila;
typedef NODO * tree;

void cria(fila *f){
    *f = (fila)calloc(sizeof(descritor),1);
}

void ins(fila f,tree t){
    NODE *v = (NODE *)calloc(sizeof(NODE),1);
    v->inf = t;

    if(f->inicio == NULL){
        f->inicio = f->fim = v;
    }
    else{
        f->fim->next = v;
        f->fim = v;
    }
}

void ret(fila f){
    if(f->inicio == NULL){
        exit(5);
    }
    else{
        NODE * aux = f->inicio;
        f->inicio = f->inicio->next;
        free(aux);
        if(f->inicio == NULL)
            f->fim = NULL;
    }
}

tree cons_fila(fila f){
    if(f->inicio == NULL)
        return NULL;
    else{
        return f->inicio->inf;
    }
}

tree direita(fila f){
    return f->inicio->inf->right;
}

tree esquerda(fila f){
    return f->inicio->inf->left;
}


void maketree(tree *t,int valor){
    *t = (tree)calloc(sizeof(NODO),1);
    (*t)->info = valor;
}

void setleft(tree t,int valor){
    t->left = (tree)calloc(sizeof(NODO),1);
    t->left->father = t;
    t->info = valor;
}

void setright(tree t,int valor){
    t->right = (tree)calloc(sizeof(NODO),1);
    t->right->father = t;
    t->info = valor;
}

int info(tree t){
    if(!t)
        exit(0);
    else
        return t->info;
}

tree left(tree t){
    if(!t)
        return NULL;
    else
        return t->left;
}

tree right(tree t){
    if(!t)
        return NULL;
    else
        return t->right;
}

tree brother(tree t){
    if(t->father){
        if(t->father->left == t)
            return t->father->right;
        else
            return t->father->left;
    }
    else {
        return NULL;
    }
}

int isleft(tree t){
    if(t->father){
        if(t->father->left == t)
            return 1;
        else
            return 0;
    }
    else {
        return 0;
    }
}

int isright(tree t){
    if(t->father){
        if(t->father->left == t)
            return 0;
        else
            return 1;
    }
    else {
        return 0;
    }
}

void percursolargura(tree t){
    fila f;
    if(!f)
        cria(&f);
    if(f)
        ins(f,t);
    while(f){
        printf("%d", info(cons_fila(f)));
        if(esquerda(f))
            ins(f,left(cons_fila(f)));
        if(direita(f))
            ins(f, right(cons_fila(f)));
        ret(f);
    }
}

void preordem(tree t){
    printf("%d\n", t->info);
    preordem(left(t));
    preordem(right(t));
}

void inordem(tree t){
    preordem(left(t));
    printf("%d\n", t->info);
    preordem(right(t));
}
void posordem(tree t){
    preordem(left(t));
    preordem(right(t));
    printf("%d\n", t->info);
}