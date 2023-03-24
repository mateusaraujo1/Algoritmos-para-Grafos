#include <stdio.h>
#include <stdlib.h>
#include "list.h"


static link NEWnode( vertex w, link next) {
    link a = malloc(sizeof(struct node));
    a->w = w;
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