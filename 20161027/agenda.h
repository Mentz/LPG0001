#ifndef AGENDA_H
#define AGENDA_H

#define TAM_NOME 80
#define TAM_COMPLEMENTO 80
#define TAM_ENDERECO 80
#define TAM_TELEFONE 20

typedef struct {
	int dia;			// 4b
	int mes;			// 4b
	int ano;			// 4b
} Nascimento;			// T: 12b

typedef struct {
	char *endereco;		// 8b
	char *complemento;	// 8b
	char uf[2];			// 2b
} Endereco;				// T: 18b

typedef struct {
	char *nome;			// 8b
	char *telefone;		// 8b
	Nascimento nasc;	// 12b
	Endereco *end;		// 8b
} Contato;				// T: 36b

typedef struct {
	Contato **contatos;	// 8b
	int elementos; 		// 4b
} Agenda;				// T: 12b

Agenda *inicializa_agenda(void);
void libera_agenda(Agenda *a);

Contato *novo_contato(void);
void inserir_contato(Agenda *a);
void libera_contato(Contato *c);
Endereco *novo_endereco(void);
void libera_endereco(Endereco *end);

void lista_pessoas(Agenda *a);

#endif