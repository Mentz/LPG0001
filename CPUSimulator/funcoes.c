#include <stdio.h>
#include <string.h>
#include "aloca_memoria.h"
#include "funcoes.h"

CPUInt* inicializaCPU(void) {
	CPUInt *cpu = NULL;
	cpu = (CPUInt *) alocar_memoria(sizeof(CPUInt));
	cpu -> reg1 = 0;
	cpu -> reg2 = 0;
	cpu -> instrucao = NULL;
	return cpu;
}

RAMInt* inicializaRAM(void) {
	RAMInt *ram = NULL;
	ram = (RAMInt *) alocar_memoria(sizeof(RAMInt));
	ram -> elementos = 0;
	ram -> variaveis = NULL;
	return ram;
}

void destruirCPU(CPUInt *cpu) {
	desalocar_memoria(cpu->instrucao);
	desalocar_memoria(cpu);
}

void destruirRAM(RAMInt *ram) {
	desalocar_memoria(ram->variaveis);
	desalocar_memoria(ram);
}

void declararRAMInt(RAMInt *ram, int valor, char *id) {
	Variavel var;
	var.valor = valor;
	strcpy(var.identificador, id);
	ram -> elementos++;
	ram -> variaveis = (Variavel *) realocar_memoria(ram -> variaveis, sizeof(Variavel) * ram -> elementos);
	ram -> variaveis[ram -> elementos - 1] = var;
}

void removerRAMInt(RAMInt *ram, int valor, char *id) {
	if (valor) {		// sair se o valor não for 0;
		printf("\n");
		return;
	}

	int i = 0;
	for (i = 0; i < ram -> elementos; i++)
		if (strcmp(id, ram -> variaveis[i].identificador) == 0)
			break;

	for (; i < ram -> elementos - 1; i++) {
		ram -> variaveis[i] = ram -> variaveis[i+1];
	}

	ram -> elementos--;
	ram -> variaveis = (Variavel *) realocar_memoria(ram -> variaveis, sizeof(Variavel) * ram -> elementos);
}

void executarStoreCPUInt(CPUInt *cpu, RAMInt *ram, char *dest, char *orig) {
	int i = 0;
	for (i = 0; i < ram -> elementos; i++)
		if (strcmp(dest, ram -> variaveis[i].identificador) == 0)
			break;

	if (strcmp(orig,"reg1") == 0) 
		ram -> variaveis[i].valor = cpu -> reg1;
	else if (strcmp(dest,"reg2") == 0)
		ram -> variaveis[i].valor = cpu -> reg2;
}

void executarLoadCPUInt(CPUInt *cpu, RAMInt *ram, char *dest, char *orig) {
	int i = 0;
	for (i = 0; i < ram -> elementos; i++)
		if (strcmp(orig, ram -> variaveis[i].identificador) == 0)
			break;

	if (strcmp(dest,"reg1") == 0) 
		cpu -> reg1 = ram -> variaveis[i].valor;
	else if (strcmp(dest,"reg2") == 0)
		cpu -> reg2 = ram -> variaveis[i].valor;
}