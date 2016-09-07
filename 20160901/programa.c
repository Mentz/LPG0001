#include <stdio.h>
#include "lpg.h"
#include "lpg.c"
#include <stdlib.h>
#include <time.h>

int main(void) {
	int notas[ALUNOS][PROVAS] = {0};
	int i, j;
	int op;
	srand(time(NULL));
	for (i = 0; i < ALUNOS; i++) {
		for (j = 0; j < PROVAS; j++) {
			notas[i][j] = rand()%10;
		}
	}

	while ((op = menu()) != 0) {
		if (op==1) {
			imprimir(notas);
		} else if (op==2) {
			printf("Média da turma = %.2f\n",media_turma(notas));
		} else if (op==3) {
			printf("Maior nota = %.2f\n",maior_nota(notas));
		} else if (op==4) {
			printf("Menor nota = %.2f\n",menor_nota(notas));
		} else if (op==5) {
			printf("Média dos alunos\n");
			for (i = 0; i < ALUNOS; i++) {
				printf("Alunos %d = %.2f\n",i,media_aluno(notas[i]));
			}
		} else {
			printf("Opção inválida\n");
		}
	} //fim while

	return 0;
}
