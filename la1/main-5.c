#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#define tam 4

//gcc -c lista-adj.c main-5.c && gcc lista-adj.o main-5.o && a

int main()
{
    Graph G = GRAPHinit(5);
    int v[tam] = {2, 4, 1, 0};

    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 0, 3);
    GRAPHinsertArc(G, 1, 0);
    GRAPHinsertArc(G, 2, 1);
    GRAPHinsertArc(G, 2, 3);
    GRAPHinsertArc(G, 2, 4);
    GRAPHinsertArc(G, 3, 2);
    GRAPHinsertArc(G, 4, 1);

    GRAPHprint(G);

    bool var = GRAPHcheckWalk(G, v, tam);
    
    if (var)
        printf("é um passeio");
    else
        printf("não é um passeio");
    

    return 0;
}
