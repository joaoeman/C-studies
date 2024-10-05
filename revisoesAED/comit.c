#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef NODO * list;

void cria(list *p,int n){
	if(n<= 0)
		return;
		
    int i=1;
    list v;
    
    v = (NODO *)malloc(sizeof(NODO));
    if(!v)
        exit(1);
        
    v->inf = 1;
    v->next = v;
    *p = v;
//    printf("%d\n", v->inf);
    while(i<n){
        int k =i;
        list aux,v2;
        v2 = (NODO *)malloc(sizeof(NODO));
        if(!v2)
            exit(2);
        v2->inf = i;
        for(aux = *p;k>1; aux = aux->next,k--);
        v2->next = aux->next;
        aux->next = v2;
        i++;
//        printf("%d\n", v2->inf);
    }
}

int remov(list *p,int m){
    list aux=*p,aux2,aux3;
    int l;
    while(aux->next != aux){
        l = m;
        for(aux2 = aux; l>1;l--,aux2 = aux2->next);
        aux3 = aux2->next;
        aux2->next = aux3->next;
        aux = aux2;
        free(aux3);
    }
    l = aux->inf;
    free(aux);
    return l;
    
}

int main(){
    list p;
    int n,m,i;
    scanf("%d", &i);
    while(i>0){
        scanf("%d %d", &n,&m);
        cria(&p,n);
        printf("Case %d: %d\n",i,remov(&p,m));    
        i--;
    }
    
}
