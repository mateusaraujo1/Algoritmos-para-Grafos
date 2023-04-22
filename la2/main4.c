/* Autor: Alex Martins - josealex.pm@gmail.com 
*  Códigos base: https://www.ime.usp.br/~pf/algoritmos_para_grafos/
*  Implementações de exercícios e personalização de programas.
*  Compilar: gcc -o main main.c list_basic.c
*  Lista mínima de arquivos (main.c, list_basic.h, list_basic.c)
*/

//gcc main4.c list_basic.c -c && gcc main4.o list_basic.o && a

#include "list_basic.h"

int main(){

	Graph G;

	G = GRAPHinit(10);
	GRAPHshow(G);
	GRAPHdfs(G);
	return 0;
}