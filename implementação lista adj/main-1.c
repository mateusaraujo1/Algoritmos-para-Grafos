#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//gcc -c lista-adj.c main-1.c && gcc lista-adj.o main-1.o && a

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
    //GRAPHinsertArc(G, 4, 2);

    GRAPHprint(G);

    Graph H = GRAPHinit(5);

    GRAPHinsertArc(H, 0, 1);
    GRAPHinsertArc(H, 0, 3);
    GRAPHinsertArc(H, 1, 0);
    GRAPHinsertArc(H, 2, 1);
    GRAPHinsertArc(H, 2, 3);
    GRAPHinsertArc(H, 2, 4);
    GRAPHinsertArc(H, 3, 2);
    //GRAPHinsertArc(H, 3, 1);

    GRAPHequal(G, H);

    return 0;
}
