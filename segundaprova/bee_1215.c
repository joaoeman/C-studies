#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
  char *inf;
  struct nodo *left, *right, *father;
}NODO;

typedef NODO * tree;


void maketree(tree *t, char *c) {
  *t = (tree)malloc(sizeof(NODO));
  (*t)->father = (*t)->left = (*t)->right = NULL;
  (*t)->inf = (char *)malloc((strlen(c) + 1) * sizeof(char));
  strcpy((*t)->inf,c);
}

void setleft(tree t, char *c) {
  t->left = (tree)malloc(sizeof(NODO));
  t->left->left = t->left->right = NULL;
  t->left->father = t;
    t->left->inf = (char *)malloc((strlen(c) + 1) * sizeof(char));
  strcpy(t->left->inf,c);
}
void setright(tree t, char *c) {
  t->right = (tree)malloc(sizeof(NODO));
  t->right->right = t->right->left = NULL;
  t->right->father = t;
  t->right->inf = (char *)malloc((strlen(c) + 1) * sizeof(char));
  strcpy(t->right->inf,c);
}

void ins(tree *t, char *c) {
    tree aux = *t;
  if (!(*t))
    maketree(t, c);
  else {
    while (1) {
      
      if (strcmp(c,aux->inf)>0) {
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
tree left(tree t){
    return t->left;
}
tree right(tree t){
    return t->right;
}
void inordem(tree t){
    if(t){
        inordem(left(t));
        printf("%s\n", t->inf);
        inordem(right(t));
    }
}
int main() {
    char str[201] = " ";
    tree t = NULL;
	int i;
    while (1){
    	scanf(" %s", str);
    	if(!strcmp(str,"exit"))
    		break;
        
        

        // Remove o caractere de nova linha (newline) que fgets captura
//        str[strcspn(str, "\n")] = 0;

        // Converte os caracteres para minúsculas
        for (i = 0; str[i]; i++) {
            if (str[i] < 97 && str[i] >= 65)  // Apenas se for uma letra maiúscula
                str[i] += 32;
        }

        // Insere a string na árvore
        ins(&t, str);
    }

    inordem(t);  // Exibe a árvore
}
