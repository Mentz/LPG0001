#include <stdio.h>

int main(){
	int total = 0, contador = 1, nota = 0;
	while (contador <= 10) {
		printf("Informe a nota do aluno %d entre 0 e 100\n",contador);
		scanf("%d",&nota);
		total += nota;
		contador++;
	}
	printf("Média = %.2f\n",(double)total/10);

	return 0;
}