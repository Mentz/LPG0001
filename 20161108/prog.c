#include <stdio.h>
#include "banco_binario.h"

int main(int argc, char *argv[]) {
	FILE *arquivo = NULL;
	int op = 0;
	void (*f[]) (FILE *) = {cadastrar_cliente, remover_cliente, atualizar_cliente, relatorio};

	if (argc < 2) {
		printf("Uso: %s arquivo_binário.dat\n", argv[0]);
		return 1;
	}

	arquivo = fopen(argv[1], "rb+");

	if (!arquivo) {
		printf("Erro ao acessar o arquivo %s\n", argv[1]);
		return 1;
	}

	while ((op = menu()) != -1) {
		f[op](arquivo);
	}

	return 0;
}