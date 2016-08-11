#include <stdio.h>

int main(){
	int i = 0, nota = 0;
	double total = 0;
	printf("Informe a nota entre 0 e 100 ou -1 para sair\n");
	scanf("%d",&nota);
	while (nota > -1) {
		total += nota;
		i++;
		printf("Informe a nota entre 0 e 100 ou -1 para sair\n");
		scanf("%d",&nota);
	}
	printf("Média = %.2f\n", total/i);

	return 0;
}