#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef NODO * list;

void cria(list *p,int n){
	if(n<=0)
		return;
    int i=1;
    list v;
    v = (NODO *)malloc(sizeof(NODO));
    if(!v)
        exit(1);
    v->inf = i;
    v->next = v;
    *p = v;
    i++;
    // printf("%d\n", v->inf);
    list last = v;
    for (i = 2; i <= n; i++) {
        list v2 = (NODO *)malloc(sizeof(NODO));
        if (!v2)
            exit(2);
        v2->inf = i;
        v2->next = *p;  // Novo nó aponta para o início da lista
        last->next = v2; // Último nó aponta para o novo nó
        last = v2; // Atualiza o último nó
    }
}


int remov(list *p,int m){
    list aux=*p,aux2,aux3;
    int l;
    while(aux->next != aux){
        l = m;
        for(aux2 = aux; l>2;l--,aux2 = aux2->next);
        aux3 = aux2->next;
        aux2->next = aux3->next;
        aux = aux2->next;
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
    
