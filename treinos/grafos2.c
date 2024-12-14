#include <stdlib.h>
#include <stdlib.h>
#define tam 500

typedef struct nodetype{
    int info;
    int point;
    int next;
}nodo;

typedef nodo nodos[tam];

void crialistavazia(int *nodosvazios, nodos node){
    int i;
    for(i=1;i<tam;i++)
        node[i-1].next = i;
    node[i-1].next = -1;
    *nodosvazios = 0;
}
int getnode(int *nodosvazios,nodos node){
    int i = *nodosvazios;
    if(i != -1){
        *nodosvazios = node[i].next;
        return i;
    }
    else
        exit(0);
}
void freenode(int *nodosvazios, int a, nodos node){
    node[a].next = *nodosvazios;
    *nodosvazios = a;
}

void inserep(int *nodosvazios, nodos node, int a,int b, int peso){
    int current = node[a].point, ant=-1;
    while(current >= 0 && node[current].point != b){
        ant = current;
        current = node[current].next;
    }
    if(current >= 0){
        node[current].info = peso;
        return;
    }
    current = getnode(nodosvazios, node);
    node[current].info = peso;
    node[current].next = -1;
    node[current].point = b;
    (ant < 0)? (node[a].point = current): (node[ant].next = current);
}

void removep(int a,int b,int peso,int *nodosvazios, nodos node){
    int current = node[a].point, ant;
    while(current>=0 && node[current].point != b){
        ant = current;
        current = node[current].point;
    }
    if(current >=0){
        if(ant < 0)
            node[a].point = node[current].next;
        else
            node[ant].next = node[current].next;
        node[current].info = peso;
        freenode(nodosvazios, a, node);
        return;
    }
}

int adjacente(int a, int b, nodos node){
    int current = node[a].point;

    while(current>=0){
    if(node[current].point == b)
        return 1;
    else
        current = node[current].next;
    }
    return 0;
}

int findnode(int *graph, int a, nodos node){
    int current = *graph;
    while(current>=0){
        if(node[current].info == a)
            return current;
        else
            current = node[current].next;
    }
    return -1;
}

int addnode(int *graph, int a, int *nodosvazios, nodos node){
    int current = getnode(nodosvazios, node);

    node[current].next = *graph;
    node[current].point = -1;
    node[current].info = a;
    *graph = current;

    return current;
}

int removeV(int a, int *graph, int *nodosvazios, nodos node){
    int current = *graph,anterior=*graph,arestas,arestasant,retorno = 0;
    while(current>=0){
        if(node[current].info == a){
            if(current == *graph)
                *graph = node[current].next;
            else
                node[anterior].next = node[current].next;
            arestas = node[current].point;
            while(arestas>=0){
                arestasant = arestas;
                arestas = node[arestas].next;
                freenode(nodosvazios,arestasant,node);//liberandos arestas 
            }
            anterior = current;
            current = node[current].next;
            freenode(nodosvazios, anterior, node);
            retorno = 1;
        }
        else{
            arestas= arestasant = node[current].point;
            while(arestas>=0){
                if(node[arestas].point == a){
                    if(arestas == arestasant)
                        node[current].point = node[current].next;
                    else
                        node[arestasant].next = node[arestas].next;
                    arestasant = arestas;
                    arestas = node[arestas].next;
                    freenode(nodosvazios, arestasant, node);
                }
                else{
                  arestasant = arestas;
                  arestas = node[arestas].next;  
                }
            }
            anterior = current;
            current = node[current].next;
        }
    }
    return retorno;
}