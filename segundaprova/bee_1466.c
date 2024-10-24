#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *father,*left,*right;
}NODO;

typedef struct node{
    NODO *inf;
    struct node *next;
}NODE;

typedef struct{
    NODE *inicio;
    NODE *fim;
}descritor;

typedef NODO * tree;
typedef descritor * fila;

void maketree(tree *t,int valor){
    *t = (tree)malloc(sizeof(NODO));
    (*t)->father = (*t)->left = (*t)->right = NULL;
    (*t)->info = valor;
}

void setleft(tree t, int valor) {
  t->left = (tree)malloc(sizeof(NODO));
  t->left->left = t->left->right = NULL;
  t->left->father = t;
  t->left->info = valor;
}
void setright(tree t, int valor) {
  t->right = (tree)malloc(sizeof(NODO));
  t->right->right = t->right->left = NULL;
  t->right->father = t;
  t->right->info = valor;
}
void ins_tree(tree *t,int valor){
    if(!(*t))
        maketree(t, valor);
    else{
        tree aux = *t;
        while(1){
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
        }
    }
}

void cria_fila(fila *f){
    *f = (fila)malloc(sizeof(NODE));
    (*f)->fim = (*f)->inicio = NULL;
}

void ins_fila(fila f, tree t){
    NODE *v = (NODE *)malloc(sizeof(NODE));
    v->inf = t;
    v->next = NULL;
    if(f->inicio == NULL)
        f->inicio = v;
    else{
        f->fim->next = v;
    }
    f->fim = v;
}

void ret_fila(fila f){
    NODE *aux = f->inicio;
    f->inicio = f->inicio->next;
    if(f->inicio == NULL)
        f->fim = NULL;
    free(aux);
}

tree cons(fila f){
    return f->inicio->inf;
}

tree left(fila f){
    return f->inicio->inf->left;
}

tree right(fila f){
    return f->inicio->inf->right;
}

void percurso_largura(tree t){
    fila f;
    cria_fila(&f);
    ins_fila(f, t);
    while(f->inicio){
        printf("%d ", cons(f)->info);
        if(left(f))
            ins_fila(f, left(f));
        if(right(f))
            ins_fila(f, right(f));
        ret_fila(f);
    }
}

int main(){
    int casos, i = 1,n,valor;
    tree t = NULL;

    scanf("%d", &casos);
    while(i<=casos){
        scanf("%d", &n);
        for(int k = 0; k<n;k++){
            scanf("%d", &valor);
            ins_tree(&t, valor);
        }
        printf("Case %d:\n",i);
        percurso_largura(t);
        printf("\n\n");
        t = NULL;
        i++;
    }
}