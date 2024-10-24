#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
  char inf;
  struct nodo *left, *right, *father;
} NODO;

typedef NODO *tree;

void maketree(tree *t, char c) {
  *t = (tree)malloc(sizeof(NODO));
  (*t)->father = (*t)->left = (*t)->right = NULL;
  (*t)->inf = c;
}

void setleft(tree t, char c) {
  t->left = (tree)malloc(sizeof(NODO));
  t->left->left = t->left->right = NULL;
  t->left->father = t;
  t->left->inf = c;
}
void setright(tree t, char c) {
  t->right = (tree)malloc(sizeof(NODO));
  t->right->right = t->right->left = NULL;
  t->right->father = t;
  t->right->inf = c;
}

void ins(tree *t, char c) {
    tree aux = *t;
  if (!(*t))
    maketree(t, c);
  else {
    while (1) {
      
      if (c > aux->inf) {
        if (aux->right)
          aux = aux->right;
        else {
          setright(aux, c);
          break;
        }
      }
      else{
        if(aux->left)
            aux = aux->left;
        else{
            setleft(aux, c);
            break;
        }
      }
    }
  }
}
void procura(tree t, char c) {
  if (!t) {
    printf("arvore vazia\n");
    return;
  }

  tree aux = t;
  while (aux) {
    if (c == aux->inf) {
      printf("%c existe\n", c);
      return;
    } else if (c > aux->inf) {
      aux = aux->right;
    } else {
      aux = aux->left;
    }
  }

  printf("%c nao existe\n", c);
}

char info(tree t) { return (t->inf); }

tree left(tree t) { return (t->left); }

tree right(tree t) { return (t->right); }

void preordem(tree t) {
  if (t) {
    printf(" %c", info(t));
    preordem(left(t));
    preordem(right(t));
  }
}
void inordem(tree t) {
  if (t) {
    inordem(left(t));
    printf(" %c", info(t));
    inordem(right(t));
  }
}

void posordem(tree t) {
  if (t) {
    posordem(left(t));
    posordem(right(t));
    printf(" %c", info(t));
  }
}

int main(){
    char leitura,c,str[12];
    tree t=NULL;
    while(1){
        scanf(" %s", str);
        if(!strcmp(str,"I")){
            scanf(" %c", &c);
            ins(&t, c);
            printf("foi\n");
        }
        else if(!strcmp(str,"P")){
            scanf(" %c", &c);
            procura(t, c);
        }
        else if(!strcmp(str,"INFIXA"))
            inordem(t);
        else if(!strcmp(str, "PREFIXA"))
            preordem(t);
        else if(!strcmp(str,"POSFIXA"))
            posordem(t);
    }
}