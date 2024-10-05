#include <stdio.h>
#include <stdlib.h>
#define tam 31
#include <string.h>

typedef struct nodo{
	int inf;
    char s[tam];
	struct nodo *next;
	struct nodo *prev;
}NODO;

typedef NODO * listacircular;

void cria(listacircular *p){
    *p = NULL;
}

void ins(listacircular *p, char c[31],int n){
    listacircular v = (listacircular)malloc(sizeof(NODO));
    v->inf = n;
    strcpy(v->s,c);
    if(!(*p)){
        v->prev = v->next = v;
    }
    else{
        listacircular aux = *p;
        v->prev = aux->prev;
        v->next = aux;
        aux->prev = v;
        v->prev->next = v;
    }
    *p = v;
}

listacircular remov(listacircular *aux){
    listacircular aux2 = *aux,aux3;
    aux2->next->prev = aux2->prev;
    aux2->prev->next= aux2->next;
    aux3 = aux2->next;
    free(aux2);
    return aux3;
}

int tama(listacircular p){
    if(!p)
        return 0;
    else{
        listacircular aux = p->next;
        int i=1;
        for(;aux != p;i++,aux = aux->next);
        return i;
    }
}
void print(listacircular p){
    listacircular aux = p;
    int i = tama(p);
    
    for(;i>0;i--,aux = aux->next)
        printf(" %s ", aux->s);
    printf("\n");
}
void removecomplete(listacircular *p){
	
    listacircular aux;
    int l=(*p)->next->inf,t = tama(*p);
    char r[31];
    
    if(l%2 == 0)
    	aux = (*p)->next->next;
    else
    	aux = (*p);
    	
    if(t == 1){
        printf("%s\n", (*p)->s);
        free(p);
    }
    else{
   		while(t>1){
       		if(l%2 == 0){
           		for(;l>0;l--,aux = aux->next);
           		l = aux->inf;
           		// printf("%s\n", aux->s);
           		aux = remov(&aux);
       		}
        	else{
           		for(;l>0;l--,aux = aux->prev);
           		l = aux->inf;
           		// printf("%s\n", aux->s);
           		aux = remov(&aux);
          	 	aux = aux->prev;    
       		}
       		t--; 
   		}
   		strcpy(r, aux->s);
   		free(aux);
   		printf("Vencedor(a): %s\n", r);
   }	
}

int main(){
    listacircular p;
    char str[31];
    int e,n,i;
    
    scanf("%d", &n);
    while(n != 0){
        i = 1;
        cria(&p);
        while(i<=n){
            scanf(" %s", str);
            scanf("%d", &e);
            ins(&p, str, e);
            i++;
        }
//        print(p);
        removecomplete(&p);
        scanf("%d", &n);
    }
}
