#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int inf;
	struct nodo *next;
	struct nodo *prev;
}NODO;

typedef NODO * listacircular;

void cria(listacircular *p, int n){
    int i =1;
    listacircular v, last;
	*p = NULL;
    v = (listacircular)malloc(sizeof(NODO));
    v->inf = i;
    i++;
    v->next = v->prev = v;
    *p = v;
    last = v;
    printf("%d\n", last->inf);

    while(i<=n){
        v = (listacircular)malloc(sizeof(NODO));
        v->inf = i;
        i++;
        v->next = last->next;
        last->next = v;
        v->prev = last;
        last = v;
        printf("%d\n", last->inf);
    }
    (*p)->prev = last;
    *p = last;
}

listacircular remov(listacircular *p){
    listacircular aux = *p,aux2;
    aux->next->prev= aux->prev;
    aux->prev->next= aux->next;
    aux2 = aux->next;
    free(aux);
    return aux2;
}

void removecomplete(listacircular *p,int k,int m,int n){
    listacircular auxhor = (*p)->next,auxanti = *p;
    while(n>0){

        int hor = k,anti = m;
        for(;hor>1;hor--, auxhor = auxhor->next);
        for(;anti>1;anti--,auxanti = auxanti->prev);

        if(auxanti != auxhor){
            n-=2;
            printf("%3d %3d, ", auxhor->inf, auxanti->inf);
            auxanti = remov(&auxanti);
            auxhor = remov(&auxhor);
        }
        else {
            n--;
            printf("%d, ", auxanti->inf);
            auxanti = auxhor = remov(&auxanti);
        }
        auxanti = auxanti->prev;
    }
}
int main(){
    listacircular p;
    int n,k,m;
    scanf("%d %d %d", &n,&k,&m);
    cria(&p,n);
    removecomplete(&p,k,m,n);
}
