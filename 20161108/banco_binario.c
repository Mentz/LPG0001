#include <stdio.h>
#include "banco_binario.h"

int menu(void) {
	int i = -2;
	printf("Informe -1 para sair.\n0 para cadastrar\n1 para remover\n2 para atualizar\n3 para gerar um relatorio\n");
	while (i < -1 || i > 3) {
		scanf("%d", &i);
	}

	return i;
}

void cadastrar_cliente (FILE *arquivo) {
	Cliente e = {-1, "", "", 0.0};
	int codigo;

	printf("Informe o código do cliente [0, 99]\n");
	scanf("%d", &codigo);

	fseek(arquivo, codigo * sizeof(Cliente), SEEK_SET);
	fread(&e, sizeof(Cliente), 1, arquivo);

	if (e.conta != -1) {
		printf("O código %d já foi ocupado\n", codigo);
		return;
	}

	printf("Informe nome, sobrenome e saldo\n");
	scanf("%s%s%lf", e.nome, e.sobrenome, &e.saldo);

	e.conta = codigo;

	fseek(arquivo, codigo * sizeof(Cliente), SEEK_SET);
	// fseek(arquivo, - sizeof(Cliente), SEEK_CUR); 				// deslocando manualmente
	// fseek(arquivo, 99 - codigo * sizeof(Cliente), SEEK_END);		// deslocando de trás pra frente
	fwrite(&e, sizeof(Cliente), 1, arquivo);
}

void remover_cliente (FILE *arquivo) {
	Cliente e = {-1, "", "", 0.0};
	Cliente v = {-1, "", "", 0.0};

	printf("Informe o código do cliente [0, 99]\n");
	scanf("%d", &e.conta);

	fseek(arquivo, e.conta * sizeof(Cliente), SEEK_SET);
	fread(&e, sizeof(Cliente), 1, arquivo);

	if (e.conta == -1) {
		printf("A conta não foi ocupada\n");
		return;
	}

	printf("Removendo as informações: %s %s %.2lf\n", e.nome, e.sobrenome, e.saldo);

	fseek(arquivo, e.conta * sizeof(Cliente), SEEK_SET);
	fwrite(&v, sizeof(Cliente), 1, arquivo);	
}

void atualizar_cliente (FILE *arquivo) {
	Cliente e = {-1, "", "", 0.0};
	double operacao = 0; // negativo para saque, positivo para depósito.
	int conta;

	printf("Informe o código do cliente [0, 99]\n");
	scanf("%d",&conta);

	fseek(arquivo, conta * sizeof(Cliente), SEEK_SET);
	fread(&e, sizeof(Cliente), 1, arquivo);
	if (e.conta == -1) {
		printf("Cliente não cadastrado\n");
		return;
	}

	printf("Cliente %s %s\nO saldo atual é %.2lf\n", e.nome, e.sobrenome, e.saldo);
	printf("Informe o valor da operação: - para saque\n");
	scanf("%lf", &operacao);
	e.saldo += operacao;
	fseek(arquivo, conta * sizeof(Cliente), SEEK_SET);
	fwrite(&e, sizeof(Cliente), 1, arquivo);
}

void relatorio (FILE *arquivo) {
	FILE *saida = NULL;
	Cliente e = {-1, "", "", 0.0};

	saida = fopen("relatorio.txt", "w");
	if (!saida) {
		printf("Erro ao criar o arquivo de saída\n");
		return;
	}

	rewind(arquivo);
	while (!feof(arquivo)) {
		fread(&e, sizeof(Cliente), 1, arquivo);
		if (e.conta != -1) {
			fprintf(saida, "%d %s %s %.2lf\n", e.conta, e.nome, e.sobrenome, e.saldo);
		}

	}
}