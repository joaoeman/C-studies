#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef NODO* pilhaenc;

void create(pilhaenc *p){
    *p = NULL;
}

int isempty(pilhaenc p){
    return (p==NULL);
}

void push(pilhaenc *p,int valor){
    pilhaenc v = (pilhaenc)malloc(sizeof(NODO));
    if(!v)
        exit(0);
    v->inf = valor;
    v->next = *p;
    *p = v;
}

int top(pilhaenc p){
    if(isempty(p))
        exit(1);
    else
        return(p->inf);
}

void pop(pilhaenc *p){
    if(isempty(*p))
        exit(2);
    pilhaenc aux = *p;
    (*p) = (*p)->next;

    free(aux);
}

int topop(pilhaenc *p){
    if(isempty(*p))
        exit(1);

    pilhaenc aux = *p;
    int i;
    i = aux->inf;
    (*p) = (*p)->next;
    free(aux);
    return i;
}

void destroi(pilhaenc *p){
    while(*p){
        pilhaenc aux = *p;
        *p = (*p)->next;
        free(aux);
    }
}