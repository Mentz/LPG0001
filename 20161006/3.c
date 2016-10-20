#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float *p = NULL;
	float *tmp = NULL;
	int i, tam, novo;
	printf("Informe o tamanho do vetor\n");
	scanf("%d",&tam);
	p = (float *) malloc(sizeof(float) * tam);
	if(p == NULL) {
		printf("Erro ao alocar\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < tam; i++) {
		printf("p[%d] ? ",i);
		scanf("%f",p+i);
	}
	printf("Mais elementos? -1 para não\n");
	scanf("%d",&novo);
	while(novo != -1) {
		tmp = (float *) realloc(p, tam+novo);
		if(tmp == NULL) {
			printf("Erro ao realocar\n");
		} else {
			p = tmp;
			for(i = 0; i < novo; i++) {
				printf("p[%d] ? ",tam+i);
				scanf("%f",p+tam+i);
			}
			tam += novo;
		}
		printf("Mais elementos? -1 para não\n");
		scanf("%d",&novo);
	}
	printf("Vetor:\n");
	for(i = 0; i < tam; i++) {
		printf("p[%d] = %f\n",i,p[i]);
	}
	free(p);

	return 0;
}