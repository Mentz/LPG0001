#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

Agenda *inicializa_agenda(void) {
	Agenda *ret = NULL;
	
	if (!(ret = (Agenda *) malloc(sizeof(Agenda)))) {
		printf("[inicializa_agenda] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	ret -> contatos = NULL;
	ret -> elementos = 0;
	return ret;
}

void libera_agenda(Agenda *a) {
	int i;
	for (i = 0; i < a -> elementos; i++) {
		libera_contato(a -> contatos[i]);
	}
	free(a -> contatos);
	free(a);
}

Contato *novo_contato(void) {
	Contato *ret = NULL;
	printf("1\n");
	if (!(ret = (Contato *) malloc(sizeof(Contato *)))) {
		printf("[novo_contato] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	printf("2\n");
	ret -> nasc.dia = 0;
	ret -> nasc.mes = 0;
	ret -> nasc.ano = 0;
	/*ret -> nome*/ char *teste = (char *) malloc(sizeof(char) * TAM_NOME);
	if (ret -> nome == NULL) {
		printf("[novo_contato] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	printf("3\n");
	ret -> telefone = (char *) malloc(sizeof(char) * TAM_TELEFONE);
	if (ret -> telefone == NULL) {
		printf("[novo_contato] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	printf("4\n");
	ret -> end = novo_endereco();
	return ret;
}

void inserir_contato(Agenda *a) {
	int tam_atual = a -> elementos;

	if (!(a -> contatos = (Contato **) realloc(a -> contatos, (tam_atual + 1) * sizeof(Contato *)))) {
		printf("[inserir_contato] Temporariamente sem memória\n");
		return;
	}

	a -> contatos[a -> elementos] = novo_contato();

	printf("Prezado usuário. Informe os dados para o índice %d\n", a -> elementos);
	printf("Informe dia, mês e ano de nascimento\n");
	scanf("%d%d%d", &a -> contatos[a -> elementos] -> nasc.dia,
					&a -> contatos[a -> elementos] -> nasc.mes,
					&a -> contatos[a -> elementos] -> nasc.ano);
	printf("Informe o nome e telefone\n");
	scanf("%80s%80s", a -> contatos[a -> elementos] -> nome,
				  a -> contatos[a -> elementos] -> telefone);
	printf("Informe seu endereço, complemento e UF\n");
	scanf("%80s%80s%2s", a -> contatos[a -> elementos] -> end -> endereco,
					 a -> contatos[a -> elementos] -> end -> complemento,
					 a -> contatos[a -> elementos] -> end -> uf);

	a -> elementos = a -> elementos + 1;
}

void libera_contato(Contato *c) {
	free(c -> nome);
	free(c -> telefone);
	libera_endereco(c -> end);
	free(c -> end);
	c -> nome = NULL;
	c -> telefone = NULL;
	c -> end = NULL;
	// Não faz nada. Apenas para garantir que não será possível acessar por engano.
	free(c);
}

Endereco *novo_endereco(void) {
	Endereco *ret = NULL;

	if (!(ret = (Endereco *) malloc(sizeof(Endereco)))) {
		printf("[novo_endereco] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	if (!(ret -> endereco = (char *) malloc(sizeof(char) * TAM_ENDERECO))) {
		printf("[novo_endereco] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	if (!(ret -> complemento = (char *) malloc(sizeof(char) * TAM_COMPLEMENTO))) {
		printf("[novo_endereco] Sem memória\n");
		exit(EXIT_FAILURE);
	}
	return ret;
}

void libera_endereco(Endereco *end) {
	free(end -> endereco);
	free(end -> complemento);
	end -> endereco = NULL; 
	end -> complemento = NULL;
	// mesma coisa, essas duas linhas acima não tem efeito algum, é só neurose.
	free(end);
}

void lista_pessoas(Agenda *a) {
	int i;

	if (a -> elementos == 0) {
		printf("Agenda vazia\n");
		return;
	}

	printf("Pessoas cadastradas na agenda:\n");
	for (i = 0; i < a -> elementos; i++) {
		printf("Contato %2d\n", i);
		printf("\tNome: %s\n", a -> contatos[i] -> nome);
		printf("\tData de nascimento: %d/%d/%d\n", a -> contatos[i] -> nasc.dia,
												   a -> contatos[i] -> nasc.mes,
												   a -> contatos[i] -> nasc.ano);
		printf("\t%s %s %s\n", a -> contatos[i] -> end -> endereco,
							   a -> contatos[i] -> end -> complemento,
							   a -> contatos[i] -> end -> uf);
		printf("-----------------\n");
	}
}
