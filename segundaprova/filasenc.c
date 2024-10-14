#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef struct{
    NODO *fim;
    NODO *inicio;
}descritor;

typedef descritor * filaenc;

void cria(filaenc *f){
    *f = (filaenc)calloc(sizeof(descritor),1);
}

int ehvazia(filaenc f){
    return (f->inicio == NULL);
}

void ins(filaenc f,int valor){
    NODO *v = (NODO *)calloc(sizeof(NODO),1);
    v->inf = valor;

    if(ehvazia(f)){
        f->fim = f->inicio = v;
    }
    else{
        f->fim->next = v;
        f->fim = v;
    }
}

int cons(filaenc f){
    return(f->inicio->inf);
}

void ret(filaenc f){
    NODO *aux = f->inicio;
    f->inicio = aux->next;
    if(!(f->inicio))
        f->fim = NULL;
    free(aux);

}