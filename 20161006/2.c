#include <stdio.h>
#include <stdlib.h>

void imprimir_vetor(const int *v, int tam);
int* criar_vetor(int tam);
int* unir_vetores(int *v1, int tam1, int *v2, int tam2);

int main(void) {
	int *a = NULL;
	int *b = NULL;
	int *c = NULL;
	int ta, tb, tc, i;
	printf("Tamanho do vetor A\n");
	scanf("%d",&ta);
	a = criar_vetor(ta);
	for(i = 0; i < ta; i++) {
		printf("A[%d]?\t",i);
		scanf("%d",&a[i]);
	}
	imprimir_vetor(a, ta);
	printf("Tamanho de B\n");
	scanf("%d",&tb);
	b = criar_vetor(tb);
	for(i = 0; i < tb; i++) {
		printf("B[%d]?\t",i);
		scanf("%d",&b[i]);
	}
	imprimir_vetor(b, tb);
	tc = ta+tb;
	c = unir_vetores(a, ta, b, tb);
	imprimir_vetor(c, tc);
	free(a);
	free(b);
	free(c);

	return 0;
}

void imprimir_vetor(const int *v, int tam) {
	printf("Vetor:\n");
	int i;
	for(i = 0; i < tam; i++) {
		printf("[%d] = %d\n",i,*(v+i));
	}
}

int* criar_vetor(int tam) {
	int *ret = NULL;
	if (!(ret = (int *) malloc(sizeof(int) * tam))) {
		printf("Erro ao alocar\n");
		exit(EXIT_FAILURE);
	}

	return ret;
}

int* unir_vetores(int *a, int ta, int *b, int tb) {
	int *c = NULL;
	int i = 0;
	c = criar_vetor(ta+tb);
	for(i = 0; i < ta; i++) {
		c[i] = a[i];
	}
	for(i = 0; i < tb; i++) {
		c[i+ta] = b[i];
	}

	return c;
}

// const int * const p;
// const int --> o valor apontado pelo ponteiro é constante.
// *
// const p --> o valor do ponteiro (endereço apontado) é constante.
// Um vetor é: int * const p; ou seja, valor variável do vetor, ponteiro fixo.