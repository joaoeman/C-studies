#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;

typedef NODO * list;

void cria(list *p){
	*p=NULL;
}

void ins(list *p,int valor){
	list v;
    if(!(*p)){
    	*p = (list)malloc(sizeof(NODO));
    	(*p)->next = *p;
	}
	else{
		v = (list)malloc(sizeof(NODO));
		v->next = (*p)->next;
		(*p)->next = v;
		*p = v; 
	}
	(*p)->inf = valor;
	
}

int tam(list p){
	list aux;
	int cont=0;
	if(p){
		for(cont = 1,aux = p->next;aux != p;cont++, aux = aux->next);
	}
		return cont;
}

int remov(list p,int pos){
	int l = pos;
	list aux = p,aux2;
	
	if(tam(p)>1){
		
		for(;l>1;aux = aux->next,l--);
		aux2 = aux->next;
		aux->next = aux->next->next;
		free(aux2);
		remov(aux,pos);
	}
	else
		return (p->inf);
}
    
int main(){
    list p;
    int n,i=2,k=0,i2=0;
    
    scanf("%d", &n);
	while(n>0){
    	do{
			if(n==0)
			break;
    		i2++;
    		cria(&p);
    		for(i=2;i<=n;i++)
    			ins(&p,i);
    		
    		k = remov(p,i2);
		}while(k != 13);
	printf("%d\n", i2);
	scanf("%d", &n);
	}
}
