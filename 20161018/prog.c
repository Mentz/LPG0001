#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int main(void) {
	Matriz *matriz = NULL;
	int linhas, colunas, opcao;
	printf("Informe o número de linhas e colunas\n");
	scanf("%d%d", &linhas, &colunas);
	printf("Informe 1 para bloco e 2 para distribuída\n");
	scanf("%d", &opcao);
	srand(time(NULL));
	if (opcao == 1) {
		matriz = criar_matriz(linhas, colunas, criar_bloco);
	} else if (opcao == 2) {
		matriz = criar_matriz(linhas, colunas, criar_distribuida);
	} else {
		printf("Opção Inválida!\n");
		exit(EXIT_FAILURE);
	}

	inicializar_matriz(matriz);
	imprimir_matriz(matriz);

	if (opcao == 1) {
		liberar_matriz(linhas, colunas, liberar_bloco);
	} else {
		liberar_matriz(linhas, colunas, liberar_distribuida);
	}

	return 0;
}