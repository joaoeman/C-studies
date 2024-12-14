#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *left;
    struct nodo *right;
    struct nodo *father;
}NODO;

typedef NODO * tree;

typedef struct node{
    tree inf;
    struct node *next;
}NODE;

typedef struct{
    NODE *inicio;
    NODE *fim;
}descritor;

typedef descritor* fila;

void criafila(fila *f){
    *f = (fila)malloc(sizeof(descritor));
    (*f)->inicio = (*f)->fim = NULL;
}

void insfila(fila f, tree t){
    NODE *v = (NODE *)malloc(sizeof(NODE));
    v->inf = t;
    v->next = NULL;

    if(f->inicio == NULL){
        f->inicio = f->fim = v;
    }else {
        f->fim->next = v;
        f->fim = v;
    }
}

void retfila(fila f){
    if(f->inicio == NULL)
        exit(2);

    NODE *aux = f->inicio;
    f->inicio = f->inicio->next;
    free(aux);

    if(!(f->inicio))
        f->fim = NULL;
}

tree consfila(fila f){
    return f->inicio->inf;
}
tree direita(fila f){
    return f->inicio->inf->right;
}

tree esquerda(fila f){
    return f->inicio->inf->left;
}

void maketree(tree *t,int valor){
    *t = (tree)malloc(sizeof(NODO));
    (*t)->left = (*t)->right = (*t)->father = NULL;
    (*t)->info = valor;
}

void setleft(tree t,int valor){
    if(!t)
        exit(0);
    t->left = malloc(sizeof(NODO));
    t->left->left = t->left->right = NULL;
    t->left->father = t;
    t->left->info = valor;
}

void setright(tree t,int valor){
    if(!t)
        exit(1);
    t->right = malloc(sizeof(NODO));
    t->right->left = t->right->right = NULL;
    t->right->father = t;
    t->right->info = valor;
}

int info(tree t){
    return t->info;
}

tree left(tree t){
    return t->left;
}

tree right(tree t){
    return t->right;
}

tree father(tree t){
    return t->father;
}

tree brother(tree t){
    if(t->father){
        if(t->father->left == t)
            return t->father->right;
        else
            return t->father->left;
    }
    else return NULL;
}

int isleft(tree t){
    if(t->father){
        if(t->father->left == t)   
            return 1;
        else
            return 0;
    }
    else 
        return 0;
}

int isright(tree t){
    if(t->father){
        return (!(isleft(t)));
    }
    else 
        return 0;
    
}

void percursolargura(tree t){
    fila f;
    criafila(&f);
    if(t)
        insfila(f,t);

    while(!f){
        printf("%d ", info(consfila(f)));
        if(esquerda(f))
            insfila(f,esquerda(f));
        if(direita(f))
            insfila(f, direita(f));
        retfila(f);
    }
}
void percursopreordem(tree t){
    printf("%d ", info(t));
    percursopreordem(t->left);
    percursopreordem(t->right);
}
void percursoinordem(tree t){
    percursoinordem(t->left);
    printf("%d ", info(t));
    percursoinordem(t->right);
}
void percursoposordem(tree t){
    percursoposordem(t->left);
    percursoposordem(t->right);
    printf("%d ", info(t));
}

void instree(tree *t, int valor){
    tree aux = *t;
    if(!(*t))
        exit(2);
    while(1){
        if(aux->info > valor){
            if(aux->left)
                aux = aux->left;
            else{
                setleft(aux,valor);
                break;
            }
        }
        else {
            if(aux->right)
                aux = aux->right;
            else{
                setright(aux,valor);
                break;
            }
        }
    }
}

void fusionremove(tree *t){
   if(*t){
        tree aux = *t;
        if(!(*t)->right){
            if((*t)->left){
                (*t)->left->father = (*t)->father;
                *t = (*t)->left;
            }
        }else if((*t)->left == NULL){
            (*t)->right->father = (*t)->father;
            *t = (*t)->right;
        }else{
            aux = (*t)->left;
            while(aux->right)
                aux = aux->right;
            aux->right = (*t)->right;
            aux->right->father = aux;
            aux = *t;
            *t = (*t)->left;
        }
        free(aux);
   }
}

void copyremove(tree *t){
    tree aux = *t;
    if(!(*t)){
        if(!(*t)->right){
            if((*t)->left){
                (*t)->left->father = (*t)->father;
                *t = (*t)->left;
            }
        }else if((*t)->left == NULL){
            (*t)->right->father = (*t)->father;
            *t = (*t)->right;
        }
        else{
            aux = (*t)->right;
            while(aux->left)
                aux = aux->left;
            (*t)->info = aux->info;
            if(aux->father == *t){
                aux->father->right = aux->right;
                if(aux->father->right)
                    aux->father->right->father = aux->right;
            }
            else{
                aux->father->left = aux->right;
                if(aux->father->left)
                    aux->father->left->father = aux->father;
            }
        }
        free(aux);
        
    }
}
