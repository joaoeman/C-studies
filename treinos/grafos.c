#include <stdio.h>
#include <stdlib.h>
#define tam 10

struct node{
    int info;
};//vertice

struct arc{
    int adj;
    int peso;
};//arco

struct graph{
    struct node nodes[tam];
    struct arc arcs[tam][tam];
};

void ligarp(struct arc adj[][tam], int peso, int a, int b){
    adj[a][b].adj = 1;
    adj[a][b].peso = peso;
}

void removerp(struct arc adj[][tam], int peso, int a,int b){
    adj[a][b].adj = 0;
    adj[a][b].peso = peso;
}
int adjacente(struct arc adj[][tam], int a,int b){
    return adj[a][b].adj;
}

int procura(struct arc adj[][tam], int n,int a, int b){
    int c;
    if(n==1)
        return adjacente(adj,a,b);
    for(c = 0;c<tam;c++){
        if(adjacente(adj, a, c) && procura(adj, n-1, c, b))
            return 1;
        return 0;
    }

}