/* Autor: Alex Martins - josealex.pm@gmail.com 
*  Códigos base: https://www.ime.usp.br/~pf/algoritmos_para_grafos/
*  Implementações de exercícios e personalização de programas.
*  Compilar: gcc -o main main.c list_basic.c
*  Lista mínima de arquivos (main.c, list_basic.h, list_basic.c)
*/

//gcc main5.c Queue.c list_basic.c -c && gcc main5.o Queue.o list_basic.o && a.exe < grafo.txt
// << em Linux

#include "list_basic.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	Graph G;
	int v, w;

	G = GRAPHinit(5);
	scanf("%d", &v);
	scanf("%d", &w);
	GRAPHinsertArc(G, v, w);
	scanf("%d", &v);
	scanf("%d", &w);
	GRAPHinsertArc(G, v, w);
	scanf("%d", &v);
	scanf("%d", &w);
	GRAPHinsertArc(G, v, w);
	scanf("%d", &v);
	scanf("%d", &w);
	GRAPHinsertArc(G, v, w);
	scanf("%d", &v);
	scanf("%d", &w);
	GRAPHinsertArc(G, v, w);
	scanf("%d", &v);
	scanf("%d", &w);
	GRAPHinsertArc(G, v, w);
	scanf("%d", &v);
	scanf("%d", &w);
	GRAPHinsertArc(G, v, w);
	GRAPHshow(G);
	return 0;
}