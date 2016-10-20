#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *v = NULL;
	int i = 0;
	int tamanho = 0;
	printf("Informe o tamanho do vetor\n");
	scanf("%d",&tamanho);
	v = (int *) calloc(tamanho, sizeof(int));
	if (!v) {
		printf("Erro ao alocar memória\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < tamanho; i++) {
		printf("Valor para %d\n",i);
		scanf("%d",&v[i]);
	}
	printf("Vetor = \n");
	for(i = 0; i < tamanho; i++) {
		printf("%d\n",*(v+i));
	}
	free(v);

	return 0;
}