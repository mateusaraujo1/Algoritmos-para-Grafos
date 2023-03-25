#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define vertex int

typedef struct node *link;
typedef struct graph *Graph;

struct graph {
    int V;
    int A;
    link *adj;
};

struct node {
    vertex w;
    int visited;
    link next;
};

Graph GRAPHinit( int V);
void GRAPHinsertArc( Graph G, vertex v, vertex w);
void GRAPHprint(Graph G);
void GRAPHequal(Graph G, Graph H);
void GRAPHremoveArc(Graph G, vertex v, vertex w);
Graph GRAPHcompleto(vertex v);
bool GRAPHcheckWalk(Graph G, int v[], int tam);
//void GRAPHciclosSimples(Graph G);
void print_ciclos(Graph G);
void GRAPHprint(Graph G);