#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//gcc -c lista-adj.c main-2.c && gcc lista-adj.o main-2.o && a

int main()
{
    Graph G = GRAPHinit(5);

    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 0, 3);
    GRAPHinsertArc(G, 1, 0);
    GRAPHinsertArc(G, 2, 1);
    GRAPHinsertArc(G, 2, 3);
    GRAPHinsertArc(G, 2, 4);
    GRAPHinsertArc(G, 3, 2);

    GRAPHprint(G);

    GRAPHremoveArc(G, 1, 0);
    GRAPHremoveArc(G, 2, 3);

    printf("\n");
    GRAPHprint(G);

    return 0;
}
