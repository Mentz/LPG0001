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
	int l = m->linhas;
	int c = m->colunas;
	for (i = 0; i < l; i++) {
		for (j = 0; j < c; j++) {
			m->mat[i][j] = rand()%100/100.0;
		}
	}
}

void imprimir_matriz(Matriz *m) {

}

void liberar_matriz(Matriz *m, void (*f)(double **m, int ll, int cc)) {

}

/* Manipulação das alocações de matrizes */
double** criar_bloco(int l, int c) {
	int i;
	double **n = NULL;
	double *d = NULL;
	n = (double **) malloc(sizeof(double *) * l);
	if (!n) {
		printf("Erro ao alocar memória\n");
		exit(EXIT_FAILURE);
	}
	d = (double) malloc(sizeof(double) * l * c);
	if (!d) {
		printf("Erro ao alocar memória\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < linhas; i++) {
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

}

void liberar_distribuida(double **m, int l, int c) {

}
