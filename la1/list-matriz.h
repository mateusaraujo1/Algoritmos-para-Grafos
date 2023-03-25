#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define vertex int
//#define MAX_VERTICES 100

struct graph {
    int V;
    int A;
    int **adj;
};

typedef struct graph *Graph;

Graph GRAPHinit( int V);
void GRAPHinsertArc(Graph G, vertex v, vertex w);
void GRAPHremoveArc(Graph G, vertex v, vertex w);
void GRAPHshow(Graph G);
bool GRAPHcheckWalk(Graph G, int v[], int tam);
void GRAPHciclosSimples(Graph G);
void dfs(Graph G, int start);
void print_ciclos(Graph G);
//void dfs(int v, int w, int num_vertices, int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int path[MAX_VERTICES], int tam_path);