#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
	int inf;
	char s[500];
	struct nodo *next;
	struct nodo  *prev;
}NODO;

typedef NODO * list;

void inicializa(list *p){
	*p = NULL;
}

void cria(list *p,char c[500],int i){
	
	list v;
	v = (list)malloc(sizeof(NODO));
	
	v->inf = i;
	strcpy(v->s,c);
	
	if(!p){
		v->next= v->prev = v;
	}
	else{
		v->next = *p;
		v->prev = (*p)->prev;
		(*p)->prev = v;
		v->prev->next = v;
	}
	*p = v;
}
 
void rethor(list *p){
	
	list aux = *p, aux2 = (*p)->next;
	aux->next = aux2->next;
	free(aux2);
}

void retant(list *p){
	list aux = *p, aux2 = (*p)->prev;
	aux->prev = aux2->prev;
	free(aux2);
}

void retcomplete(list *p,int n){
	list aux = (*p)->next->next;
	int gira,l = aux->inf;
	
	while(n>1){//enquanto houver mais de uma vai eliminar
		
		gira = l;
		if(gira%2 == 0){
			for(;l>2;l--,aux = aux->next);
			l = aux->next->inf;//atualizando o valor de l antes de liberar
			rethor(&aux);
			n--;
		}
		else{
			for(;l>2;l--,aux = aux->prev);
			l = aux->prev->inf;
			retant(&aux);
			n--;
		}
	}
	printf(" %[^\n]", aux->s); 
}

int main(){
	list p;
	int n, ficha;
	char s[500];
	
	
	scanf("%d", &n);
	inicializa(&p);
	while(n>0){
		scanf(" %s", s);
		scanf("%d", &ficha);
		cria(&p,s,ficha);
		n--;
	}
	retcomplete(&p,n);
}
