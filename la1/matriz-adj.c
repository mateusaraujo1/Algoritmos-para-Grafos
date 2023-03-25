#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list-matriz.h"
#define MAX_VERTICES 100

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

//questão 6

void GRAPHciclosSimples(Graph G) {

    int vet[G->A+1];
    int i = 0;
    bool have;
    int vertVisitados = 0;

    for (vertex v = 0; v < G->V; ++i) {
        for (vertex w = 0; w < G->V; ++w) 
            if (G->adj[v][w] == 1){

                for (int j = 0; j < i; j++)
                    if (w == vet[j])
                        have = 1;
                        //print
                
                if (!have)
                {
                    vet[i] = v;
                    v = w;
                    
                    if (i == G->A)
                        v = G->V;
                    
                    break; 
                }
                else
                {
                    /* code */
                }
                
            }
    }

    for (int i = 0; i <= G->A; i++)
        printf("%d->", vet[i]);

    printf("\n");
    
}

void dfs_helper(Graph G, int v, bool visited[], int path[], bool in_path[]) {
    visited[v] = true;
    path[v] = v;

    for (int i = 0; i < G->V; i++) {
        if (G->adj[v][i] == 1) {
            if (!visited[i]) {
                in_path[i] = true;
                dfs_helper(G, i, visited, path, in_path); // chama a função recursivamente para o próximo vértice
                in_path[i] = false;
                path[i] = -1;
            } else if (in_path[i]) {
                // encontrou um ciclo
                printf("%d", i);
                for (int j = v; j != i; j = path[j]) {
                    printf(" -> %d", j);
                }
                printf(" -> %d\n", i);
            }
        }
    }
    in_path[v] = false;
}


// Função de busca em profundidade
void dfs(Graph G, int start) {
    bool visited[MAX_VERTICES];
    int path[MAX_VERTICES];
    bool in_path[MAX_VERTICES];

    for (int i = 0; i < G->V; i++) {
        visited[i] = false;
        path[i] = -1; // inicializa o vetor de caminho com -1
        in_path[i] = false;
    }

    dfs_helper(G, start, visited, path, in_path);
}

void print_ciclos(Graph G) {
    printf("Ciclos simples no grafo:\n");

    for (int i = 0; i < G->V; i++) {
        dfs(G, i);
    }
}