#include <stdio.h>
#include <stdlib.h>

typedef struct k{
    int inf;
    struct k *nex;
}key;

typedef struct chave{
    int end;
    struct chave *next;
    key *nex; 
}NODO;

typedef NODO * list;

void cria(list *p,int n){
    int i = 0;
    list v,last;

    v = (list)calloc(sizeof(NODO),1);
    v->end = i;
//    printf("%d\n", i);
    i++;
    last = v;
    *p = v;
    
    while(i<n){
        v = (list)calloc(sizeof(NODO),1);
        v->end = i;
//        printf("%d\n", i);
        i++;
        last->next = v;
        last = v;
        
    }
}

void insere(list *p,int pos,int vet){
    list aux = *p;
    key *v,*aux2;
    int i;
    
    for(;pos>0;aux = aux->next,pos--);
    aux2 = aux->nex;
    if(aux2){
    	while(aux2->nex){
        	aux2 = aux2->nex;
    	}
		v = (key*)calloc(sizeof(key),1);
    	aux2->nex = v;	
	}
	else{
    	v = (key*)calloc(sizeof(key),1);
    	aux->nex = v;
	}
	v->inf = vet;
//	printf("%d\n", vet);
}

void imprime(list p,int n){
    list aux = p;
    key *l;
    for(;aux;aux = aux->next){
        printf("%d ->", aux->end);
        for(l = aux->nex;l;l = l->nex){
            printf(" %d", l->inf);
            if(l->nex)
                printf("-> ");
        }
        printf(" \\\n");
    }
}
void destroi(list *p){
    while (*p) {
    list aux = *p;
    *p = (*p)->next;

    // destruir lista de chaves
    key *chaveAux = aux->nex;
    while (chaveAux) {
      key *temp = chaveAux;
      chaveAux = chaveAux->nex;
      free(temp);
    }
    free(aux);
  }
}

int main(){
    int quant,n,pos,*vet,i=0,l;
    list p;
    scanf("%d", &quant);
    while(quant > 0){
        scanf("%d %d", &n,&pos);
        vet = (int *)malloc(sizeof(int)*n);

        for(i = 0;i<pos;i++)
            scanf("%d", &vet[i]);

        cria(&p,n);
        for(i=0;i<pos;i++){
            l = vet[i]%n;
            insere(&p, l,vet[i]);
        }
        imprime(p,n);
        destroi(&p);
        free(vet);
        quant--;
    }
}
