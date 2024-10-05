#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
    struct nodo *previous;
}NODO;

typedef NODO * listadupenccir;

void popula(listadupenccir *p,int n){
    int i = 1;
    *p = (NODO*)malloc(sizeof(NODO));
    (*p)->next = *p;
    (*p)->previous = *p;
    (*p)->inf = i;
    i++;
    printf("%d\n", (*p)->inf);
    while(i<=n){
        int l;
        listadupenccir v,aux;
        v = (NODO*)malloc(sizeof(NODO));
        v->inf = i;
        l = i;

        for(aux = *p;l>2;l--,aux = aux->next);
        v->next = aux->next;
        aux->next = v;
        v->previous = aux;
        v->next->previous = v;

        printf("%d\n", v->inf);
        i++;
        }
}

void remov(listadupenccir *p,int k,int m,int n){
    while(n>0){
        int l = k, f = m,jhom = n;
        listadupenccir aux,aux2,aux3,aux4,aux5;

        for(aux = *p; l>1;l--, aux =aux->next);
        aux2 = aux;
        for(aux=(*p)->previous; m>1;m--,aux = aux->previous);
        aux3 = aux;
        if(n == jhom){
            if(aux2 != aux3){
                printf("%d %d, ", aux2->inf,aux3->inf);
                n -=2;
            
                aux2->next->previous = aux2->previous;
                aux2->previous->next = aux2->previous;
                aux3->next->previous = aux3->previous;
                aux3->previous->next = aux3->previous;

                aux5 = aux2->next;
                aux4 = aux3->previous;
                free(aux2);
                free(aux3);
            }
            else{
                printf("%d, ",aux3->inf);
                n--;
            
                aux3->next->previous = aux3->previous;
                aux3->previous->next = aux3->previous;
            
                aux4 = aux3->previous;
                while(n>0){
                    
                }
                free(aux3);
            }
    }
    }
}
int main(){
    listadupenccir p;
    int n,k,m;
    
    scanf("%d %d %d", &n, &k, &m);

    popula(&p,n);
    remov(&p,k,m,n);
}

