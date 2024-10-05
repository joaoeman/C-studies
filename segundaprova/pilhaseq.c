#include <stdio.h>
#include <stdlib.h>
#define max 20

typedef struct{
    int topo;
    int val[max];
}pilha;

void cria(pilha *p){
    p->topo = -1;
}

int ehvazia(pilha p){
    return (p.topo == -1);
}

void push(pilha *p,int valor){
    if(p->topo == max-1){
        exit(0);
    }
    p->topo = (p->topo+1);
    p->val[p->topo] = valor;
}

int top(pilha p){
    if(ehvazia(p)){
        exit(1);
    }
    return (p.val[p.topo]);
}

void pop(pilha *p){
    if(ehvazia(*p)){
        exit(2);
    }
    p->topo--;
}
int topop(pilha *p){
    if(ehvazia(*p)){
        exit(1);
    }
    int i = p->val[p->topo];
    p->topo--;
    return i;
}

