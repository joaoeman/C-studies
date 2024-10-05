#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef NODO * listacir;

void cria(listacir *p,int n){
    listacir last,v;
    int i = 1;

    *p=NULL;
    v = (listacir)malloc(sizeof(NODO));
    v->inf = i;
    i++;
    v->next = v;
    *p = v;
    last = v;
//    printf("%d\n", last->inf);

    while(i<=n){
        v = (listacir)malloc(sizeof(NODO));
        v->inf = i;
        i++;
        v->next = last->next;
        last->next = v;
        last=v;
//        printf("%d\n", last->inf);
    }
    *p = last;
}

void remov(listacir *aux){
    listacir aux2 = (*aux)->next;
    (*aux)->next = aux2->next;
    free(aux);
}

int removecomplete(listacir *p,int pass,int n){
    listacir aux = *p;
    int retorno;
    
    while(n>1){
        int l = pass;
        remov(&aux);
        for(;l>1;l--,aux = aux->next); 
        n--;
    }
    
    retorno = aux->inf;
    free(aux);
    return retorno;
}
int main(){
    listacir p;
    int n,k,i=0;
    
    scanf("%d", &n);
    
    while(1){
    	i=0;
        do{
            i++;
            cria(&p,n);
            k = removecomplete(&p,i,n);
        }while(k != 13);
        printf("%d\n", i);
       scanf("%d", &n); 
       if(!n)
       	break;
    } 
    
}
