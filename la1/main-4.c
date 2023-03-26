#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
//#define tam 4

//gcc -c lista-adj.c main-4.c && gcc lista-adj.o main-4.o && a

int main()
{
    Graph G = GRAPHrandTournament(5);

    GRAPHprint(G);

    return 0;
}
