#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "matriz.h"

int main(void)
{

	int **matriz = NULL;
	int linhas, colunas;
	int op;

	srand(time(NULL));

	printf("Informe o número de linhas e colunas\n");
	scanf("%d%d", &linhas, &colunas);


	printf("Você deseja criar uma matriz com bloco de memória (1) ou distribuída na memória? (2)\n");
	scanf("%d", &op);

	if (op == 1) {
		matriz = criar_matriz_bloco(linhas, colunas);
	} else if (op == 2) {
		matriz = criar_matriz_distribuida(linhas, colunas);
	} else {
		printf("Opção inválida!\n");
		exit(EXIT_FAILURE);
	}

	preencher_matriz(matriz, linhas, colunas);
	imprimir_matriz(matriz, linhas, colunas);

	if (op == 1) {
		destruir_matriz_bloco(matriz);
	} else {
		destruir_matriz_distribuida(matriz, linhas);
	}
	return 0;

}
