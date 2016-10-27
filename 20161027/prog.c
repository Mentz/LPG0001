#include <stdio.h>
#include "agenda.h"

int main(void) {
	Agenda *agenda = NULL;
	int operacao = 0;

	printf("Informe 1 para cadastrar um contato;\n"
		   "2 para listar contatos;\n"
		   "-1 para sair.\n");
	scanf("%d",&operacao);
	while (operacao != -1) {
		if (operacao == 1) {
			inserir_contato(agenda);
		} else if (operacao == 2) {
			lista_pessoas(agenda);
		} else {
			printf("Opção inválida!\n");
		}
		printf("Informe 1 para cadastrar um contato;\n"
			   "2 para listar contatos;\n"
			   "-1 para sair.\n");
		scanf("%d",&operacao);
	}

	return 0;
}