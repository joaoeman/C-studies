#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef NODO * list;

void cria(list *p,int n){
    int i=1;
    list aux,aux2,v;

    *p = (NODO*)malloc(sizeof(NODO));
    (*p)->next = *p;
    (*p)->inf = i;
    i++;
    list last = *p;
//    printf("%d\n", (*p)->inf);

    while(i<=n){
        int l;

        v = (NODO*)malloc(sizeof(NODO));
        v->inf = i;
		
        v->next = last->next;
        last->next = v;
        last = v;
        i++;
//        printf("%d\n", v->inf);
    }
}

int remov(list *p,int m){
    list aux = *p,aux2,aux3;
    int l;
    while(aux->next != aux){
        l = m;
    
        for(aux3 =aux;l>2;l--,aux3 = aux3->next);
        aux2 = aux3->next;
        aux3->next = aux3->next->next;
        aux = aux3->next;
        free(aux2);
    }
    l = aux->inf;
	free(aux);
    return l;
}

int main(){
    list p;
    int n,m,i,l=1;
    scanf("%d", &i);
	while(l<=i){
		scanf("%d %d", &n,&m);
		cria(&p,n);
		printf("Case %d: %d\n",l, remov(&p,m));
		l++;
	}
}
