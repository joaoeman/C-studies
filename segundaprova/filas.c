#include <stdio.h>
#define max 20
#include <stdlib.h>

typedef struct{
    int n;
    int inicio;
    int fim;
    int val[max];
}filaseq;

void crialista(filaseq *f){
    f->n = f->inicio = 0;
    f->fim = -1;
}

int ehvazia(filaseq f){
    return(f.n == 0);
}

int tam(filaseq f){
    return (f.n);
}

void ins(filaseq *f, int valor){
    if(f->n < max){
        f->fim = (f->fim+1)%max;
        f->val[f->fim] = valor;
        f->n++;
    }
    else
        exit(1);
}

int cons(filaseq f){
    if(f.n>0){
        return f.val[f.inicio];
    }
    else
        exit(2);
}

void ret(filaseq *f){
    if(!ehvazia(*f)){
        f->inicio = (f->inicio+1)%max;
        f->n--;
    }
    else 
        exit(3);
}

int consret(filaseq *f){
    int aux;
    if(f->n>0){
        aux = f->val[f->inicio];
        f->inicio = (f->inicio+1)%max;
        f->n--;
        return aux;
    }
    else
        exit(4);
}

void gerafila(filaseq *f,int m, int n){
    if(m>n)
        exit(5);
    if(m == n){
        crialista(f);
        ins(f, m);
    }
    else {
        gerafila(f,m,n-1);
        ins(f,n);
    }
}