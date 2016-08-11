#include <stdio.h>

int main(){
	int alunos = 0, contador = 0, nota = 0;
	double total = 0;
	printf("Informe o número de alunos\n");
	scanf("%d",&alunos);
	while (contador < alunos) {
		printf("Informe a nota do aluno %d entre 0 e 100\n",contador);
		scanf("%d",&nota);
		total += nota;
		contador++;
	}
	total /= alunos;
	printf("Média = %.3f\n", total);

	return 0;
}