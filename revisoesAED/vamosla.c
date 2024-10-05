#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef NODO * list;

void cria(list *p,int n){
    list v, last;
    int i = 1;
	*p = NULL;
    v = (list)malloc(sizeof(NODO));
    v->next = v;
    v->inf = i;
    i++;
    *p = v;
    last = v;
//    printf("%d\n", last->inf);
    while(i<=n){
        v = (list)malloc(sizeof(NODO));
        v->inf = i;
        i++;
        v->next = last->next;
        last->next = v;
        last = v;
//        printf("%d\n", last->inf);
    }
    *p = last;
}

void remov(list *aux){
    list aux2 = (*aux)->next;
    (*aux)->next = aux2->next;
    free(aux2);
}

int removecomplete(list *p,int n){
    list aux  = *p;
    int l;
    for(;n>1;n--, aux = aux->next);
    l = aux->next->inf;
//    printf("%d\n", l);
    remov(&aux);
    *p = aux;
    return l;
}
void destroi(list *p){
    list aux = (*p)->next;
    while(aux != *p){
        list aux2 = aux;
        aux = aux->next;
        free(aux2);
    }
    free(aux);
}

int main(){
    list p;
    int n,i,k=0,ret;

    scanf("%d", &n);
    cria(&p,n*2);
    i = 1;
    while(1){
        ret = removecomplete(&p,i);
        if(ret > n){
            k++;
            if(k == n)
            	break;
        }
        else{
            destroi(&p);
            cria(&p,n*2);
            i++;
            k=0;
        }
    }
    printf("%d\n", i);
}
