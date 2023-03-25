#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list-matriz.h"
//#define tam 4

//gcc -c matriz-adj.c main-6m.c && gcc matriz-adj.o main-6m.o && a

int main()
{
    Graph G = GRAPHinit(4);
    //int v[tam] = {1, 0, 3, 2};

    GRAPHinsertArc(G, 0, 2);
    GRAPHinsertArc(G, 1, 0);
    GRAPHinsertArc(G, 2, 1);
    GRAPHinsertArc(G, 2, 3);
    GRAPHinsertArc(G, 3, 0);
    GRAPHinsertArc(G, 3, 1);
    //GRAPHshow(G);
    print_ciclos(G);

    return 0;
}
