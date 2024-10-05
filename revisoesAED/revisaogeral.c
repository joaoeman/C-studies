#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef NODO * listacir;

void ins(listacir *p,int n){
    listacir v,last;
    int i=1;
    *p = NULL;
    v = (listacir)malloc(sizeof(NODO));
    v->inf = i;
    v->next = v;
    *p = v;
    i++;
    last = v;
     printf("%d\n", last->inf);
    while(i<=n){
        v = (listacir)malloc(sizeof(NODO));
        v->inf = i;
        i++;
        v->next = last->next;
        last->next = v;
        last = v;
        printf("%d\n", last->inf);
    }
    *p = last;

}

void remov(listacir *aux){
    listacir aux2 = (*aux)->next;
    (*aux)->next = aux2->next;
    free(aux2); 
}

int removecomplete(listacir *p,int pos,int n){
    int i;
    if(pos < 1)
        exit(0);
    listacir aux = *p;
    while(n>1){
        int l = pos;
        for(;l>1;l--, aux = aux->next);
        remov(&aux);
        n--;
    }
    i = aux->inf;
    free(aux);
    return i;
}
int main(){
    listacir p;
    ins(&p,1234);
    printf("%d\n",removecomplete(&p,233,1234));

}



