#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef NODO * list;

//void inicia(list *p){
//	*p = NULL;
//}

void cria(list *p,int n){
    int i;
    list v,last;
    for(i=1;i<=n;i++){
        v = (list)malloc(sizeof(NODO));
        v->inf = i;
        if(i==1){
            v->next = v;
            *p = v;
        }
        else{
            last->next = v;
        }
        last = v;
    }
    last->next = *p;
    *p = last;
}
void ret(list *p){
    list aux = *p, aux2 = (*p)->next;
    aux->next = aux2->next;
    free(aux2);
    
}

int retcomplete(list *p,int n,int k){
    int l,resp;
    list aux =*p;
    while(n>1){
        l = k;
        ret(&aux);
        for(;l>1;l--,aux = aux->next);
        n--;
    }
    resp = aux->inf;
    free(aux);
    return resp;
}

int main(){
    list p;
    int n,i,k;
	scanf("%d", &n);
	while(n != 0){
		i=0;
    	do{
    		i++;
//    		inicia(&p);
        	cria(&p,n);
        	k = retcomplete(&p,n,i);        
    	}while(k != 13);
    	printf("%d\n", i);
    scanf("%d", &n);
	}
}
