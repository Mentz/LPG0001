#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int **criar_matriz_bloco(int linhas, int colunas){
	int **m = NULL;
	int i;
	m = (int**) malloc(sizeof(int*) * linhas);
	if(m==NULL) {
		printf("Erro ao alocar\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < linhas; i++) {
		*(m+i) = (int*) malloc(sizeof(int) * colunas);
		if(m==NULL) {
			printf("Erro ao alocar\n");
			exit(EXIT_FAILURE);
		}
	}
	return m;
}

int **criar_matriz_distribuida(int linhas, int colunas){
	int **m = NULL;
	int *dados = NULL;
	int i;
	if (!(m = (int**) malloc(sizeof(int*) * linhas))) {
		printf("Erro ao alocar\n");
		exit(EXIT_FAILURE);
	}
	if(!(dados = (int*) malloc(sizeof(int) * linhas * colunas))) {
		printf("Erro ao alocar\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < linhas; i++) {
		*(m+i) = dados+(colunas*i);
	}

	return m;
}

void preencher_matriz(int **m, int linhas, int colunas){
	int i, j;
	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			m[i][j] = rand()%100;
		}
	}
}

void imprimir_matriz(int **m, int linhas, int colunas){
	int i, j;
	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			printf("[%d][%d] = [%d]\n", i, j, m[i][j]);
		}
	}
}

void destruir_matriz_bloco(int **m){
	free(m[0]);
	free(m);
}

void destruir_matriz_distribuida(int **m, int linhas){
	int i;
	for(i = 0; i < linhas; i++) {
		free(m[i]);
	}
	free(m);
}


