#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#define MAX_VERTICES 100


static link NEWnode( vertex w, link next) {
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->visited = 0;
    a->next = next;
    return a;
}

Graph GRAPHinit( int V) {
    Graph G = malloc( sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = malloc( V * sizeof (link));

    for (vertex v = 0; v < V; ++v)
        G->adj[v] = NULL;

    return G;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w) {

    for (link a = G->adj[v]; a != NULL; a = a->next)
        if (a->w == w) return;
    G->adj[v] = NEWnode( w, G->adj[v]);
    G->A++;
}

void GRAPHprint(Graph G) {

    link node = malloc(sizeof(struct node));

    for (int i = 0; i < G->V; i++)
    {
        printf("%d: ", i);
        node = G->adj[i];
        while (node)
        {
            printf("%d ", node->w);
            node = node->next;
        }
        printf("\n");
    }

}

//questão 1
void GRAPHequal(Graph G, Graph H) {

    link nodeG = malloc(sizeof(struct node));
    link nodeH = malloc(sizeof(struct node));

    if (G->V == H->V && G->A == H->A)
    {
        for (int i = 0; i < G->V; i++)
        {
            printf("\n%d: ", i);
            nodeG = G->adj[i];
            nodeH = H->adj[i];

            while (nodeG && nodeH)
            {
                if (nodeG->w == nodeH->w)
                {
                    printf("G:%d == H:%d  //  ", nodeG->w, nodeH->w);
                    nodeG = nodeG->next;
                    nodeH = nodeH->next;
                    
                    if ((!nodeG && nodeH) || (nodeG && !nodeH))
                    {
                        printf("Os grafos não são iguais");
                        return;
                    }
                }
                else
                {
                    printf("G:%d != H:%d\n", nodeG->w, nodeH->w);
                    printf("Os grafos não são iguais");
                    return;
                }
            }
        }
        printf("\nOs grafos são iguais");
    }
    else
    {
        printf("Os grafos não são iguais: quantia de arestas ou vértices diferentes");
        return;
    }
}

//questão 2
void GRAPHremoveArc(Graph G, vertex v, vertex w) {
    link ant = malloc(sizeof(struct node));
    ant = NULL;

    for (link a = G->adj[v]; a != NULL; a = a->next){
        if (a->w == w)
        {
            if (!ant) 
                G->adj[v] = G->adj[v]->next;
            else
                ant->next = a->next;

            break;
        }
        ant = a;
    }
}

//questão 3

Graph GRAPHcompleto(vertex v) {
    Graph G = GRAPHinit(v);

    for (int i = 0; i < G->V; i++)
    {
        for (int j = 0; j < G->V; j++)
        {
            if (j != i)
                GRAPHinsertArc(G, i, j);
        } 
    }
    return G;
}

//questão 5 usando lista de adjacência

bool GRAPHcheckWalk(Graph G, int v[], int tam) {

    link node = malloc(sizeof(struct node));
    int contArcos = 0;

    node = G->adj[v[0]];

    for (int i = 1; i < tam; i++)
    {
        for (node = G->adj[v[i-1]]; node; node = node->next)
        {
                //printf("teste\n");
            if (node->w == v[i])
            {
                //node = G->adj[v[i]];
                contArcos++;
                break;
            }
        }
    }

    printf("%d\n", contArcos);

    if (contArcos == tam-1)
        return 1;
    else
        return 0;
}

//questão 6

/*

void print(Graph G, link node){
    if (node)
    {
        printf("%d->", node->w);
        if (node->visited != 1)
        {
            node->visited = 1;
            print(G, node->next);
        }
        else
        {
            print(G, G->adj[node->w]);
        }
        
    }
}

void GRAPHciclosSimples(Graph G) {

    link node = malloc(sizeof(struct node));
    int contArcos = 0;
    int visitados[G->A];

    node = G->adj[0];
    /*
    for (int i = 0; i < G->V; i++)
    {
        for (node = G->adj[i]; node; node = node->next)
        {
                //printf("teste\n");
            if (node->w == visitados[i])
            {
                //node = G->adj[v[i]];
                contArcos++;
                break;
            }
        }
    }
    
   print(G, G->adj[0]);
}


void RB_print(RB_node *t, void (*print)(void*, RB_colour)) {
    if (t) {
        printf("(");
        print(t->item, t->colour);
        RB_print(t->left, print);
        RB_print(t->right, print);
        printf(") ");
    }
    else
		printf("~ ");
}
*/

// Função auxiliar para a busca em profundidade

bool dfs(Graph G, int v, int parent, int start, bool* visited) {
    visited[v] = true;

    for (link u = G->adj[v]; u != NULL; u = u->next) {
        if (!visited[u->w]) {
            if (dfs(G, u->w, v, start, visited))
                return true;
        } else if (u->w != parent && u->w == start)
            return true;
    }

    return false;
}

void print_ciclos(Graph G) {
    printf("Ciclos simples no grafo:\n");

    for (int v = 0; v < G->V; v++) {
        bool visited[MAX_VERTICES] = { false };

        if (dfs(G, v, -1, v, visited)) {
            printf("%d", v);

            for (int i = 0; i < G->V; i++) {
                if (visited[i] && i != v)
                    printf(" -> %d", i);
            }

            printf(" -> %d\n", v);
        }
    }
}