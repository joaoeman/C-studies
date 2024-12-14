#include <stdio.h>
#include <stdlib.h>
#define tam 10

typedef struct{
    int chave;
    char livre;
}Hash;

typedef Hash* Tabela[tam];
int funcaohashing(int valor){
    return valor%tam;
}
void insercao(int valor, Tabela tabela){
    int pos = funcaohashing(valor);
    int i = 0;
    while(tabela[pos+1]->livre == 'O' && i<tam)
        i++;
    if(i<tam){
        tabela[pos+i]->chave = valor;
        tabela[pos+i]->livre = 'O';
    }
    else {
        printf("camarote lotado papai\n");
    }
}
int busca(int valor, Tabela tabela){
    int pos = funcaohashing(valor);
    int i =0;
    while(i<tam && tabela[pos+i]->livre != 'L' && tabela[pos+i]->chave != valor)
        i++;
    if(tabela[pos+i]->chave == valor && tabela[pos+i]->livre == 'O')
        return (pos+i)%tam;
    else
        return tam;
}
void remocao(Tabela tabela, int valor){
    int pos = busca(valor, tabela);
    if(pos<tam){
        tabela[pos]->livre = 'R';
    }
    else 
        printf("nao ta no camarote\n");
}