#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
    struct nodo *previous; 
}NODO;

typedef NODO * listacirdupencnc;

void cria(listacirdupencnc *p){
    *p = (NODO *)malloc(sizeof(NODO));
    if(!p)
        exit(1);
    (*p)->next = *p;
    (*p)->previous = *p;
    *p = NULL;
}
int vazio(listacirdupencnc p){
    return(p->inf == 0);
}

int tam(listacirdupencnc p){
    return(p->inf);
}

void ins(listacirdupencnc p,int pos, int valor){
    listacirdupencnc aux,v;
    if(pos < 1 || pos > p->inf + 1)
        exit(2);

    v = (NODO *)malloc(sizeof(NODO));
    if(!v)
        exit(3);
    v->inf = valor;

    if(pos <= p->inf/2){
        for(aux = p;pos > 1; pos--, aux = aux->next);
        v->next = aux->next;
        aux->next = v;
        v->previous = aux;
        v->next->previous = v;
    }
    else {
        for(aux = p; pos <= p->inf;pos++,aux = aux->previous);
        v->previous = aux->previous;
        v->next = aux;
        aux->previous = v;
        v->previous->next = v;
    }
    p->inf ++;
}

int recup(listacirdupencnc p,int pos){
    listacirdupencnc aux;
    if(pos < 1 || pos > p->inf)
        exit(4);
    if(pos <= p->inf/2){
        for(aux = p;pos > 0; pos--, aux = aux->next);
    }
    else{
        for(aux = p; pos <= p->inf;pos++,aux = aux->previous);        
    }
    return(aux->inf);
}
void ret(listacirdupencnc p,int pos){
    listacirdupencnc aux,v;

    if(pos < 1 || pos > p->inf)
        exit(5);
    if(pos <= p->inf/2){
        for(aux = p;pos > 0; pos--, aux = aux->next);
    }
    else {
        for(aux = p; pos <= p->inf;pos++,aux = aux->previous);
    }
    aux->next->previous = aux->previous;
    aux->previous->next= aux->next;
    free(aux);    
}