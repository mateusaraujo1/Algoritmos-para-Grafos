#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list-matriz.h"
#define tam 4

//gcc -c matriz-adj.c main-5-2.c && gcc matriz-adj.o main-5-2.o && a

int main()
{
    Graph G = GRAPHinit(5);
    int v[tam] = {1, 0, 3, 2};

    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 0, 3);
    GRAPHinsertArc(G, 1, 0);
    GRAPHinsertArc(G, 2, 1);
    GRAPHinsertArc(G, 2, 3);
    GRAPHinsertArc(G, 2, 4);
    GRAPHinsertArc(G, 3, 2);
    GRAPHinsertArc(G, 4, 1);

    GRAPHshow(G);

    bool var = GRAPHcheckWalk(G, v, tam);
    
    if (var)
        printf("é um passeio");
    else
        printf("não é um passeio");
    

    return 0;
}
