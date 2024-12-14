#include <stdio.h>
#include <stdlib.h>
#define tam 10

typedef struct hashing {
  char livre;
  int info;
} Hash;

typedef Hash *Tabela[tam];

int funcaohashing(int a) { return a % tam; }

void insercao2(Tabela tabela, int a) {
  int i = 1, pos = funcaohashing(a);
  while (i < tam && tabela[pos]->livre == 'O') {
    pos = (pos + i) % tam;
    i++;
  }
  if (i < tam) {
    tabela[pos]->info = a;
    tabela[pos]->livre = 'O';
  } else {
    printf("camarote cheio\n");
  }
}

int buscar2(Tabela tabela, int a){
  int i = 1, pos = funcaohashing(a);
  while(i<tam && tabela[pos]->livre != 'L' && tabela[pos]->info != a){
    pos = (pos+i)%tam;
    i++;
  }
  if(i<tam)
    return i;
  else
    return tam;
}