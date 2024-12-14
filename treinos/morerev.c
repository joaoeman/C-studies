#include <stdio.h>
#include <stdlib.h>
#define tam 100

typedef struct{
    int info;
    int next;
    int point;
    int distancia;
    int time;
    int pai;
    char cor;
}nodo;
typedef nodo nodos[tam];

typedef struct node{
    int inf;
    struct node *next;
}nox;

typedef struct{
    struct node *inicio;
    struct node *fim;
}descritor;

typedef descritor* fila;

void cria_fila(fila *);
void inserir(fila,int);
int cons_ret(fila);
int adjacent(nodos,int,int);

void percursolargura2(nodos node, int graph, int origem){
    int current,arestas;
    fila f;

    current = graph;
    while(current >= 0){
        if(current != origem){
            node[current].distancia = -1;
            node[current].cor = 'B';
        }
        else{
            node[current].distancia = 0;
            node[current].cor = 'C';
        }
        node[current].pai=-1;
        current = node[current].next;
    }
    cria_fila(&f);
    inserir(f,origem);
    while(f->inicio){
        current = cons_ret(f);
        arestas = node[current].point;
        while(arestas>=0){
            if(node[node[arestas].point].cor == 'B'){
                node[node[arestas].point].cor = 'C';
                node[node[arestas].point].distancia = node[current].distancia+1;
                node[node[arestas].point].pai = current;
                inserir(f,node[arestas].point);
            }
            arestas = node[arestas].next;
        }
        node[current].cor = 'P';
    }
}
int tempo;
void visita(nodos node, int current){
    int arestas;
    node[current].cor = 'C';
    node[current].distancia = ++tempo;
    arestas = node[current].point;

    while(arestas >= 0){
        if(node[node[arestas].point].cor == 'B'){
            node[node[arestas].point].pai = current;
            visita(node,node[arestas].point);
        }
        arestas = node[arestas].next;
    }
    node[current].cor = 'P';
    node[current].time = ++tempo;
}

void percursoprofundidade(nodos node, int graph){
    int current = graph;
    while(current>=0){
        node[current].cor = 'B';
        node[current].pai = -1;
        node[current].distancia = -1;
    }
    current = graph;
    tempo = 0;
    while(current>=0){
        if(node[current].cor == 'B'){
            visita(node,current);
        }
        current = node[current].next;
    }
}

void imprimir(nodos node, int origem, int a){
    if(origem == a)
        printf("%d ", node[origem].info);
    else
        if(node[a].pai == -1)
            printf("caminho nao encontrado");
        else{
            imprimir(node,origem,node[a].pai);
            printf("%d ", node[a].info);
        }
}

void criavazio(int *nodosvazios, nodos node){
    int i;
    for(i=1;i<tam;i++)
        node[i-1].next = i;
    node[i-1].next = -1;

    *nodosvazios = 0;
}
int getnode(int *nodosvazios, nodos node){
    int i = *nodosvazios;
    if(i!=-1){
        *nodosvazios = node[i].next;
        return i;
    }
    else 
        exit(0);
}

void freenode(int *nodosvazios, nodos node, int current){
    node[current].next = *nodosvazios;
    *nodosvazios = current;
}

void join(nodos node, int *nodosvazios, int a, int b, int peso){
    int current = node[a].point,ant =-1;

    while(current>=0 && node[current].point != b){
        ant = current;
        current = node[current].next;
    }
    if(current<0){
        node[current].info = peso;
        return;
    }
    current = getnode(nodosvazios, node);
    node[current].point = b;
    node[current].next=-1;
    node[current].info = peso;
    (ant<0)?(node[a].point = current):(node[ant].point = current);
}

void remov(nodos node, int *nodosvazios, int a,int b, int peso){
    int current = node[a].point,ant = -1;
    while(current >=0 && node[current].point != b){
        ant = current;
        current = node[current].next;
    }
    if(current>=0){
        (ant<0)?(node[a].point = node[current].next):(node[ant].next = node[current].next);
        node[current].info = peso;
        freenode(nodosvazios,node,current);
    }
}

int removnode(int *nodosvazios, int *graph, nodos node, int a){
    int current = *graph, ant,arestas,arestasant,retorno = 0,aux;

    while(current>=0){
        if(current == a){
            if(current == *graph)
                *graph = node[*graph].next;
            else
                node[ant].next = node[current].next;
            arestas = node[current].point;
            while(arestas>=0){
                arestasant = arestas;
                arestas = node[arestas].next;
                freenode(nodosvazios,node,current);
            }
            ant = current;
            current = node[current].next;
            freenode(nodosvazios,node,current);
            retorno = 1;
        }
        else{
            arestas = arestasant = node[current].next;
            while(arestas>=0){
                if(node[arestas].point == a){
                    if(arestas == arestasant)
                        node[current].point = node[arestas].next;
                    else
                        node[arestasant].next = node[arestas].next;
                    aux = arestas;
                    arestasant = arestas;
                    arestas = node[arestas].next;
                    freenode(nodosvazios,node,current);
                }
                else{
                    arestasant = arestas;
                    arestas = node[arestas].next;
               }
            }
            ant = current;
            current = node[current].next;
        }
    }
    return retorno;
}

int adjacent(nodos node, int a, int b){
    int current = node[current].point;
    while(current>=0){
        if(node[current].point==b)
            return 1;
        else
            current = node[current].next;
    }
    return 0;
}

int findnode(nodos node, int graph, int a){
    int current = graph;
    while(current>=0){
        if(node[current].info == a)
            return current;
        else
            current = node[ current].next;
    }
    return -1;
}
int addnode(nodos node, int *graph, int *nodosvazios, int x){
    int current = getnode(nodosvazios,node);
    node[current].info = x;
    node[current].point = -1;
    node[current].next = *graph;
    *graph = current;

    return current;
}