#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

/* Manipulação da estrutura */
Matriz* criar_matriz(int l, int c, double ** (*f)(int ll, int cc)) {
	Matriz *r = NULL;
	if (!(r = (Matriz *) malloc(sizeof(Matriz)))) {
		printf("Erro ao alocar memória\n");
		exit(EXIT_FAILURE);
	}
	r->linhas = l;
	r->colunas = c;
	r->mat = (*f)(l, c);

	return r;
}

void inicializar_matriz(Matriz *m) {
	int i, j;
	for (i = 0; i < m->linhas; i++) {
		for (j = 0; j < m->colunas; j++) {
			m->mat[i][j] = rand()%100/100.0;
		}
	}
}

void imprimir_matriz(Matriz *m) {
	int i, j;
	printf("Imprimindo matriz com %d linhas e %d colunas\n", m->linhas, m->colunas);
	for (i = 0; i < m->linhas; i++) {
		for (j = 0; j < m->colunas; j++) {
			printf("%.2lf\t", m->mat[i][j]);
		}
		printf("\n");
	}
}

void liberar_matriz(Matriz *m, void (*f)(double **m, int ll, int cc)) {
	(*f)(m->mat, m->linhas, m->colunas);
	free(m);
}


/* Manipulação das alocações de matrizes */

double** criar_bloco(int l, int c) {
	int i;
	double **n = NULL;
	double *dados = NULL;
	n = (double **) malloc(sizeof(double *) * l);
	if (!n) {
		printf("Erro ao alocar memória\n");
		exit(EXIT_FAILURE);
	}
	dados = (double *) malloc(sizeof(double) * l * c);
	if (!dados) {
		printf("Erro ao alocar memória\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < l; i++) {
		n[i] = dados+(c*i);
	}

	return n;
}

double** criar_distribuida(int l, int c) {
	int i;
	double **n = NULL;
	n = (double **) malloc(sizeof(double *) * l);
	if (!n) {
		printf("Erro ao alocar memória\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < l; i++) {
		n[i] = (double *) malloc(sizeof(double) * c);
		if (!n[i]) {
			printf("Erro ao alocar memória\n");
			exit(EXIT_FAILURE);
		}
	}

	return n;
}

void liberar_bloco(double **m, int l, int c) {
	printf("Liberando matriz de %d linhas e %d colunas\n", l, c);
	free(m[0]);
	free(m);
}

void liberar_distribuida(double **m, int l, int c) {
	int i;
	printf("Liberando matriz de %d linhas e %d colunas\n", l, c);
	for(i = 0; i < l; i++) {
		free(m[i]);
	}
	free(m);
}
