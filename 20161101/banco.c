#include <stdio.h>
#include "banco.h"

int menu(void) {
	int op = -2;
	printf("Informe -1 para sair\n"
		   "0 para devedores\n"
		   "1 para credores\n"
		   "2 para zerados\n");
	while(op < -1 || op > 2) {
		scanf("%d", &op);
	}

	return op;
}

void relatorio(FILE *arquivo, int (*f)(double saldo)){
	int conta = 0;
	double saldo = 0;
	char nome[30];
	fscanf(arquivo, "%d%lf%s", &conta, &saldo, nome);
	while (!feof(arquivo)) {
		if ((*f)(saldo)) {
			printf("%d %s %lf\n",conta, nome, saldo);
		}
		fscanf(arquivo, "%d%lf%s", &conta, &saldo, nome);
	}
}

int devedor(double saldo){
	return saldo < 0;
}

int credor(double saldo){
	return saldo > 0;
}

int zerado(double saldo){
	return saldo == 0;
}
