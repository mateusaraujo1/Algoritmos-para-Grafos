/* Autor: Alex Martins - josealex.pm@gmail.com 
*  Códigos base: https://www.ime.usp.br/~pf/algoritmos_para_grafos/
*  Implementações de exercícios e personalização de programas.
*  Compilar: gcc -o main main.c list_basic.c
*  Lista mínima de arquivos (main.c, list_basic.h, list_basic.c)
*/

//gcc main1.c list_basic.c -c && gcc main1.o list_basic.o && a

#include "list_basic.h"

int main(){

	/*
	G->A = 0
	A função dfsR será chamada V vezes, marcando os vértices como visitados, mas como não há arestas não haverá recursividade

	G->V = 1
	Entrará na função dfsR e marcará o vértice como visitado, mas não vai chegar a usar recursividade
	*/

	Graph G;

	G = GRAPHinit(1);
	//GRAPHinsertArc(G, 0, 2);
	//GRAPHshow(G);
	GRAPHdfs(G);
	return 0;
}