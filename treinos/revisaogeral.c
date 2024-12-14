#include <stdio.h>
#include <stdlib.h>
#define tam 8

typedef struct node{
    int chave;
    char livre;
}hash;

typedef hash Tabela[tam];

int funcaohashing(int a){
    return a%tam;
}

void inserir(Tabela tabela, int chave){
    int pos = funcaohashing(chave),i=1;

    while( i <tam && tabela[pos].livre == 'O'){
        pos = (pos+i)%tam;
        i++;
    }
    if(i<tam){
        tabela[pos].chave = chave;
        tabela[pos].livre = 'O';
    }
    else {
        printf("camarote lotado\n");
    }
}

int buscar(Tabela tabela, int chave){
    int pos = funcaohashing(chave),i=0;

    while(i<tam && tabela[pos].chave != chave && tabela[pos].chave != 'L'){
        pos = (pos+i)%tam;
        i++;
    }
        
    if(tabela[pos].chave == chave && tabela[pos].livre == 'O')
        return pos;
    else
        return -1;
}

void rmeover(Tabela tabela, int chave){
    int pos = buscar(tabela,chave);
    if(pos>=0)
        tabela[pos].livre = 'R';
    else
       printf("nao encontrado\n");
}