#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list_basic.h"


static link NEWnode( vertex w, link next);

//Parte 1 - Conceitos Básicos

/* A função NEWnode() recebe um vértice w e o endereço next de um nó e devolve
   o endereço a de um novo nó tal que a->w == w e a->next == next. */
static link NEWnode( vertex w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}


/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinit() constrói um
   grafo com vértices 0 1 .. V-1 e nenhum arco. */
Graph GRAPHinit( int V) { 
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (vertex v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}
/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinsertArc() insere um
   arco v-w no grafo G. A função supõe que v e w são distintos, positivos e
   menores que G->V. Se o grafo já tem um arco v-w, a função não faz
   nada. */
void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   for (link a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->A++;
}

//Exercício para criação desta função
void GRAPHremoveArc (Graph G, vertex v, vertex w) {
  link p, q = NULL;
    for (p = G->adj[v]; p != NULL; p = p->next) {
      if (p->w == w) {
        if (q == NULL)
          G->adj[v] = p->next;
        else
          q->next = p->next;
        p = NULL;
        free(p);
        return;
      }
      q = p;
    }
}

void GRAPHshow( Graph G) { 
	
   for (vertex v = 0; v < G->V; ++v){
   		printf( "%2d:", v);
    	for (link a = G->adj[v]; a != NULL; a = a->next) 
    		printf(" %2d", a->w);
    	printf("\n");
	}
}

//Random basic.
//Usar srand()
Graph GRAPHrand( int V, int A) { 
   Graph G = GRAPHinit( V);
   while (G->A < A) {
      vertex v = rand() % V;
      vertex w = rand() % V;
      if (v != w) 
         GRAPHinsertArc( G, v, w);
   }
   return G;
}

//-------------------------Ordenação Topológica--------------
// Recebe uma numeração e um Grafo. E diz se a numerção é 
// topologica para o grafo dado.
//
bool isTopoNumbering( Graph G, int topo[]) {
   for (vertex v = 0; v < G->V; ++v) 
      for (link a = G->adj[v]; a != NULL; a = a->next) 
         if (topo[v] >= topo[a->w]) 
            return false;
   return true;
}

// Recebe um Grafo e gera uma numeração topológica caso o grafo seja
// topológico.

int topo[1000];
bool topol( Graph G) { 
   // implementação muito ineficiente...
   vertex v;
   for (v = 0; v < G->V; ++v) topo[v] = -1;
   int cnt = 0;
   while (cnt < G->V) {
      for (vertex v = 0; v < G->V; ++v) 
         if (GRAPHindeg( G, v) == 0 && topo[v] == -1)
            break;
      if (v >= G->V) return false;
      // v é fonte
      topo[v] = cnt++;
      for (link a = G->adj[v]; a != NULL; a = a->next)
         GRAPHremoveArc( G, v, a->w);
   }
   return true;
}

//Imprime uma numeração topológica calculada por outra função
void SHOWtopo(Graph G){
   printf("topo: [ ");
   for (vertex v = 0; v < G->V; v++){
      printf("%d ", topo[v]);
   }
   printf("]\n");
}

int GRAPHindeg (Graph G, vertex v) {
   //implementar
   return 0;
}

/* A função dfsR() visita todos os vértices de G que podem ser alcançados a partir do
vértice v sem passar por vértices já descobertos. A função atribui cnt+k a pre[x] se
x é o k-ésimo vértice descoberto. (O código supõe que G é representado por listas de
adjacência.) */
static int cnt;
int pre[1000];
int prev[1000];

void printPrev(Graph G, int v[]){
   printf("           ");
   for (int i = 0; i < G->V; i++)
      printf("%2d, ", i);

   printf("\nprev[%2d] = ", G->V);

   for (int i = 0; i < G->V; i++)
       printf("%2d, ", v[i]);
   
   printf("\n");
}

static void dfsR( Graph G, vertex v)
{
   pre[v] = cnt++;

   for (link a = G->adj[v]; a != NULL; a = a->next) {
      vertex w = a->w;
      prev[v] = w;
      if (pre[w] == -1){
         printf("%d->", w);
         dfsR( G, w);
      }
   }
}

/* A função GRAPHdfs() faz uma busca em profundidade no grafo G. Ela atribui um
número de ordem pre[x] a cada vértice x de modo que o k-ésimo vértice descoberto
receba o número de ordem k. (Código inspirado no programa 18.3 de Sedgewick.) */
void GRAPHdfs( Graph G)
{
   cnt = 0;

   for (vertex v = 0; v < G->V; ++v)
      pre[v] = -1;

   for (vertex v = 0; v < G->V; ++v)
      if (pre[v] == -1){
         printf("%d->", v);
         dfsR( G, v); // começa nova etapa
      }

   printf("\n");
   printPrev(G, prev);
}
