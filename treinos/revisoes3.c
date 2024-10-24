#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info,altd,alte;
    struct nodo *father,*left,*right;
}NODO;


typedef struct node{
    NODO* inf;
    struct node *next;
}NODE;
typedef NODE * pilha;
typedef NODO* tree;

void cria_pilha(pilha *p){
    *p = NULL;
}

int ehvazia(pilha p){
    return p == NULL;
}

void push(pilha *p, tree t){
    pilha v = (pilha)malloc(sizeof(NODE));
    v->inf = t;
    v->next = *p;
    *p = v;
}

tree cons_pop(pilha *p){
    if(!ehvazia(*p)){
        pilha aux = *p;
        tree arvore = aux->inf;
        (*p) = (*p)->next;
        free(aux);
        return arvore;
    }
    else{
        return NULL;
    }
}
void maketree(tree *t, int valor){
    *t = (tree)malloc(sizeof(NODO));
    (*t)->father = (*t)->left = (*t)->right = NULL;
    (*t)->info = valor;
}

void setleft(tree t, int valor){
    if(t){
        t->left = (tree)malloc(sizeof(NODO));
        t->left->info = valor;
        t->left->left = t->left->right = NULL;
        t->left->father = t;
    }
    else return;
}

void setright(tree t, int valor){
    if(t){
        t->right = (tree)malloc(sizeof(NODO));
        t->right->info = valor;
        t->right->left = t->right->right = NULL;
        t->right->father = t;
    }
    else return;
}
void ins(tree *t,int valor){
    if(!(*t))
        maketree(t, valor);
    else{
        tree aux = *t;
        do{
            if(valor < aux->info){
                if(aux->left)
                    aux = aux->left;
                else{
                    setleft(aux, valor);
                    break;
                }
            }
            else{
                if(aux->right)
                    aux = aux->right;
                else{
                    setright(aux, valor);
                    break;
                }
            }
        }while(1);
    }
}

void percurso(tree t){
    pilha p;
    cria_pilha(&p);
    if(t == NULL)
        return;
    else{
        push(&p, t);
    }
    while(!ehvazia(p)){
        tree aux;
        aux = cons_pop(&p);
        if(aux->right)
            push(&p, aux->right);
        if(aux->left)
            push(&p, aux->left);
        printf("%d ", p->inf->info);
    }
}
void percursoin(tree t) {
    pilha p;
    cria_pilha(&p);
    tree aux = t;

    if (t == NULL)
        return;

    while (!ehvazia(p) || aux != NULL) {
        while (aux) {
            push(&p, aux);
            aux = aux->left;
        }
        aux = cons_pop(&p);
        printf("%d ", aux->info);

        aux = aux->right;
    }
}

int main(){
    int valor,n;
    tree t = NULL;

    scanf("%d", &n);
    while(n>0){
        scanf("%d", &valor);
        ins(&t, valor);
        n--;
    }
    percursoin(t);
}
