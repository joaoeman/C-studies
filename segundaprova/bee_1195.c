#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int inf;
  struct nodo *father, *left, *right;
} NODO;

typedef NODO *tree;

void maketree(tree *t, int valor) {
  *t = (tree)malloc(sizeof(NODO));
  (*t)->father = (*t)->left = (*t)->right = NULL;
  (*t)->inf = valor;
}

void setleft(tree t, int valor) {
  t->left = (tree)malloc(sizeof(NODO));
  t->left->inf = valor;
  t->left->right = t->left->left = NULL;
  t->left->father = t;
}

void setright(tree t, int valor) {
  t->right = (tree)malloc(sizeof(NODO));
  t->right->inf = valor;
  t->right->right = t->right->left = NULL;
  t->right->father = t;
}

void ins(tree *t, int valor) {
  tree aux = *t;
  if (!(*t))
    maketree(t, valor);
  else {
    while (1) {
      if (valor < aux->inf) {
        if (aux->left)
          aux = aux->left;
        else {
          setleft(aux, valor);
          break;
        }
      } else {
        if (aux->right)
          aux = aux->right;
        else {
          setright(aux, valor);
          break;
        }
      }
    }
  }
}
int info(tree t) { return (t->inf); }

tree left(tree t) { return (t->left); }

tree right(tree t) { return (t->right); }

void preordem(tree t) {
  if (t) {
    printf(" %d", info(t));
    preordem(left(t));
    preordem(right(t));
  }
}
void inordem(tree t) {
  if (t) {
    inordem(left(t));
    printf(" %d", info(t));
    inordem(right(t));
  }
}

void posordem(tree t) {
  if (t) {
    posordem(left(t));
    posordem(right(t));
    printf(" %d", info(t));
  }
}
// void fusioremove(tree *t){
//     tree aux = *t;
//     if((*t)){
//         if(!((*t)->right)){
//             if((*t)->left){
//                 (*t)->left->father = (*t)->father;
//                 *t = (*t)->left;
//             }
//         }
//         else if((*t)->left == NULL){
//             (*t)->right->father = (*t)->father;
//             *t = (*t)->right;
//         }
//         else{
//             aux = aux->left;
//             while(aux->right)   
//                 aux = aux->right;
//             aux->right = (*t)->right;
//             if(aux->right)
//                 aux->right->father = aux;
//             (*t)->left->father = (*t)->father;
//             aux = *t;
//             *t = (*t)->left;
//         }
//         free(aux);
//     }
//     if((*t)->father == NULL && (*t)->left == NULL && (*t)->right == NULL)
//         *t == NULL;
// }
// void removecomplete(tree *t, int valor){
//     tree aux = *t;
//     while (1) {
//       if (valor < aux->inf) {
//         if (aux->left)
//           aux = aux->left;
//         else if(aux->inf == valor){
//           fusioremove(&aux);
//           break;
//         }
//       } else {
//         if (aux->right)
//           aux = aux->right;
//         else if(aux->inf == valor){
//           fusioremove(&aux);
//           break;
//         }
//       }
//     }
//   }
int main() {
  int casos, valor, n, v = 1,*p;
  tree t = NULL;

  scanf("%d", &casos);
  while (v <= casos) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &valor);
      ins(&t, valor);
    }
    printf("Case %d:\nPre.:", v);
    preordem(t);
    printf("\nIn..:");
    inordem(t);
    printf("\nPost:");
    posordem(t);
    printf("\n");
    v++;
    t = NULL;
    printf("\n");
  }
}
