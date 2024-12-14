#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int info;
  struct node *next;
  struct node *point;
} nodee;

typedef nodee *tad;

void inicializa(tad *g) { *g = NULL; }

void join(tad a, tad b, int peso) {
  tad current = a->point, novo, ant = NULL;

  while (current && current->point != b) {
    ant = current;
    current = current->next;
  }
  if (current) {
    current->info = peso;
    return;
  }
  novo = (tad)calloc(sizeof(nodee), 1);
  novo->info = peso;
  (ant == NULL) ? (a->point = current) : (ant->next = current);
}

void remv(tad a, tad b, int peso) {
  tad current = a->point, ant = NULL;

  while (current && current->point != b) {
    ant = current;
    current = current->next;
  }
  if (current) {
    (!ant) ? (a->point = current->next) : (ant->next = current->next);
    free(current);
  }
}

char adjacent(tad a, tad b) {
  tad current = a->point;
  while (current) {
    if (current->point == b)
      return 1;
    else
      current = current->next;
  }
  return 0;
}

tad findnode(tad *g, int valor) {
  tad current = *g;
  while (current) {
    if (current->info == valor)
      return current;
    else
      current = current->next;
  }
  return NULL;
}

tad addnode(tad *g, int valor) {
  tad current = (tad)calloc(sizeof(nodee), 1);
  current->info = valor;
  current->next = *g;
  *g = current;

  return current;
}

int remvnode(tad *graph, tad node) {
  tad current = *graph, ant = NULL, arestas, arestasant;
  int retorno = 0;
  while (current) {
    if (current == node) {
      if (current == *graph)
        *graph = (*graph)->next;
      else
        ant->next = current->next;
      arestas = current->point;
      while (arestas) {
        arestasant = arestas;
        arestas = arestas->next;
        free(arestasant);
      }
      ant = current;
      current = current->next;
      free(current);
      retorno = 1;
    } else {
      arestas = arestasant = current->point;
      while (arestas) {
        if (arestas->point == node) {
          if (arestas == arestasant)
            current->point = arestas->next;
          else
            arestasant->next = arestas->next;
          free(arestasant);
          arestasant = arestas;
          arestas = arestas->next;
        } else{
            arestasant = arestas;
            arestas = arestas->next;
        }
        ant = current;
        current = current->next;
      }
    }
    return retorno;
  }
}