#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int inf[200];
    struct nodo *next; 
}NODO;

typedef NODO * list;

void cria(list *p, int n){
    list v,last;
    int i = 0;

    v = (list)calloc(sizeof(NODO),1);
    v->inf[0] = 0;
    i++;
    *p = v;
    last = v;
    // printf("%d\n", last->inf[0]);
    while(i<n){
        v = (list)calloc(sizeof(NODO),1);
        v->inf[0] = 0;
        i++;
        last->next = v;
        last = v;
        // printf("%d\n", last->inf[0]);
    }
}

void insere(list *p,int pos,int vet){
    list aux = *p;
    int i=pos,j=0;

    for(;i>0;i--,aux = aux->next);
    while(1){
        if(aux->inf[j] != 0)
            j++;
        else{
            aux->inf[j] = vet;
            if(j<199)
            	aux->inf[j+1] = 0;
//            printf("%d\n", aux->inf[j]);
            break;
        }
    }
}

void imprime(list p,int n){
    list aux = p;
    int l=0,k=0,i=0;
    for(;n>0;n--, aux = aux->next,i++){
    	printf("%d -> ",i);
        while(aux->inf[k] != 0){
            printf("%d ", aux->inf[k]);
            k++;
            if(k>0)
                printf("-> ");
        }
		printf("\\\n");
        k=0;
    }
}

void destroi(list *p){
    list aux = *p;
    while(*p){
        aux = *p;
        (*p) = (*p)->next;
        free(aux);
    }
}

int main(){
    int quant,n,pos, *vet,i=0,l;
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
//            insere(&p,l,vet[i]);
        }
//        imprime(p,n);
        destroi(&p);
        free(vet);
        quant --;
    }
}
