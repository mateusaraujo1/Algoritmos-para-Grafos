/* Autor: Alex Martins - josealex.pm@gmail.com 
*  Códigos base: https://www.ime.usp.br/~pf/algoritmos_para_grafos/
*  Implementações de exercícios e personalização de programas.
*  Compilar: gcc -o main main.c list_basic.c
*  Lista mínima de arquivos (main.c, list_basic.h, list_basic.c)
*/

//gcc main3.c list_basic.c -c && gcc main3.o list_basic.o && a

#include "list_basic.h"

int main(){

	Graph G;

	G = GRAPHinit(12);
	GRAPHinsertArc(G, 0, 1);
	GRAPHinsertArc(G, 0, 4);
	GRAPHinsertArc(G, 1, 2);
	GRAPHinsertArc(G, 1, 5);
	GRAPHinsertArc(G, 2, 3);
	GRAPHinsertArc(G, 3, 7);
	GRAPHinsertArc(G, 4, 8);
	GRAPHinsertArc(G, 5, 4);
	GRAPHinsertArc(G, 6, 5);
	GRAPHinsertArc(G, 6, 10);
	GRAPHinsertArc(G, 6, 2);
	GRAPHinsertArc(G, 7, 11);
	GRAPHinsertArc(G, 7, 6);
	GRAPHinsertArc(G, 8, 9);
	GRAPHinsertArc(G, 9, 5);
	GRAPHinsertArc(G, 9, 8);
	GRAPHinsertArc(G, 10, 9);
	GRAPHinsertArc(G, 11, 10);
	GRAPHshow(G);
	GRAPHdfs(G);
	return 0;
}