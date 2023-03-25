#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//gcc -c lista-adj.c main-3.c && gcc lista-adj.o main-3.o && a

int main()
{
    Graph G = GRAPHcompleto(8);
    
    GRAPHprint(G);

    return 0;
}
