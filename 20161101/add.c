/* 	2016 11 01

	Hoje vamos aprender a trabalhar com arquivos
	em disco. Sabemos que existem duas maneiras
	de manipular os dados do disco: a maneira
	fácil, formatada, e a maneira chata, em
	binário.

	Vamos implementar um sistema de Banco que
	vai guardar Conta, Saldo e Nome. 
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	int conta = 0;
	double saldo = 0;
	char nome[30];
	FILE *arquivo = NULL;
	if (argc != 2) {
		printf("Informe o nome do arquivo\n");
		return 1;
	}

	arquivo = fopen(argv[1], "a");
	if (!arquivo) {
		printf("Não foi possível criar o arquivo\n");
		return 1;
	}
	printf("Informe conta, saldo e nome\n");
	printf("ou EOF (Ctrl + d) para terminar\n");
	scanf("%d%lf%s",&conta,&saldo,nome);
	while(!feof(stdin)) {
		fprintf(arquivo, "%d %lf %s\n", conta, saldo, nome);
		printf("Informe conta, saldo e nome\n");
		printf("ou EOF (Ctrl + d) para terminar\n");
		scanf("%d%lf%s",&conta,&saldo,nome);
	}
	fclose(arquivo);

	return 0;
}