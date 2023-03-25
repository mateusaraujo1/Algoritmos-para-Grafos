#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list-matriz.h"

static int **MATRIXint( int r, int c, int val) {

    int **m = malloc( r * sizeof (int *));

    for (vertex i = 0; i < r; ++i)
        m[i] = malloc( c * sizeof (int));

    for (vertex i = 0; i < r; ++i)
        for (vertex j = 0; j < c; ++j)
            m[i][j] = val;
    return m;
}

Graph GRAPHinit( int V) {
    Graph G = malloc( sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = MATRIXint( V, V, 0);
    return G;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w) {

    if (G->adj[v][w] == 0) {
        G->adj[v][w] = 1;
        G->A++;
    }
}

void GRAPHremoveArc( Graph G, vertex v, vertex w) {
    if (G->adj[v][w] == 1) {
        G->adj[v][w] = 0;
        G->A--;
    }
}

void GRAPHshow( Graph G) {

    for (vertex v = 0; v < G->V; ++v) {
        printf( "%2d:", v);

        for (vertex w = 0; w < G->V; ++w)
            if (G->adj[v][w] == 1)
                printf( " %2d", w);

        printf( "\n");
    }
}

//questão 5 usando matriz de adjacência

bool GRAPHcheckWalk(Graph G, int vet[], int tam) {

    int contArcos = 0;
    vertex v = vet[0];
    
    for (int i = 0; i < tam-1; i++)

        for (vertex w = 0; w < G->V; w++)
        
            if (G->adj[v][w] == 1 && v == vet[i] && w == vet[i+1]){
                contArcos++;
                v = w;
            }
    
    if (contArcos == tam-1)
        return 1;
    else
        return 0;
}