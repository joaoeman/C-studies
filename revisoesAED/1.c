#include <stdio.h>

  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
typedef struct ListNode * list;

int tam(list p){
    int cont;
    for(cont = 0; p; p = p->next);
    return cont;
}

int potencia(list p,int n){
    int poww=1;
    while(n>0){
        poww*=2;
        p = p->next;
        n--;
    }
    return poww;
}
int getDecimalValue(list head) {
    int l =tam(head)-1,soma=0;
    while(l){
        if(head->val != 0)
            soma += potencia(head,l);
        l--;
        head = head->next;
    }
    return soma;
}
