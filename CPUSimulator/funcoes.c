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
	printf("CPUOK\n");
	return cpu;
}

RAMInt* inicializaRAM(void) {
	RAMInt *ram = NULL;
	ram = (RAMInt *) alocar_memoria(sizeof(RAMInt));
	ram -> elementos = 0;
	ram -> variaveis = NULL;
	printf("RAMOK\n");
	return ram;
}

void destruirCPU(CPUInt *cpu) {
	cpu -> instrucao = NULL;
	desalocar_memoria(cpu);
	printf("CPUDED\n");
}

void destruirRAM(RAMInt *ram) {
	if (ram -> variaveis != NULL) {
		desalocar_memoria(ram -> variaveis);
		ram -> variaveis = NULL;
	}
	desalocar_memoria(ram);
	printf("RAMDED\n");
}

void declararRAMInt(RAMInt *ram, int valor, char *id) {
	if (ram -> elementos == 0) 
		ram -> variaveis = (Variavel *) alocar_memoria(sizeof(Variavel) * (ram -> elementos + 1));
	else 
		ram -> variaveis = (Variavel *) realocar_memoria(ram -> variaveis, sizeof(Variavel) * (ram -> elementos + 1));
	ram -> elementos++;
	ram -> variaveis[ram -> elementos - 1].valor = valor;
	strcpy(ram -> variaveis[ram -> elementos - 1].identificador, id);
	printf("DECLARADO %s = %d\n", ram -> variaveis[ram -> elementos - 1].identificador,
								  ram -> variaveis[ram -> elementos - 1].valor);
}

void removerRAMInt(RAMInt *ram, int valor, char *id) {
	int i = 0, found = 0;
	for (i = 0; i < ram -> elementos; i++)
		if (strcmp(id, ram -> variaveis[i].identificador) == 0) {
			found = 1;
			break;
		}

	if (found) {
		for (; i < ram -> elementos - 1; i++) {
			ram -> variaveis[i] = ram -> variaveis[i + 1];
		}
		if (ram -> elementos == 1) {
			desalocar_memoria(ram -> variaveis);
			ram -> variaveis = NULL;
		} else {
			ram -> variaveis = (Variavel *) realocar_memoria(ram -> variaveis, sizeof(Variavel) * (ram -> elementos - 1));
		}
		ram -> elementos--;
	}

	printf("RAM_ELEMENTOS = %d\n", ram -> elementos);
}

void executarStoreCPUInt(CPUInt *cpu, RAMInt *ram, char *dest, char *orig) {
	int i = 0;
	for (i = 0; i < ram -> elementos; i++)
		if (strcmp(dest, ram -> variaveis[i].identificador) == 0)
			break;

	if (strcmp(orig, "reg1") == 0) 
		ram -> variaveis[i].valor = cpu -> reg1;
	else if (strcmp(dest, "reg2") == 0)
		ram -> variaveis[i].valor = cpu -> reg2;
	printf("MEMORIA_GUARDADA_COM = %d\n", ram -> variaveis[i].valor);
}

void executarLoadCPUInt(CPUInt *cpu, RAMInt *ram, char *dest, char *orig) {
	int i = 0;
	for (i = 0; i < ram -> elementos; i++)
		if (strcmp(orig, ram -> variaveis[i].identificador) == 0)
			break;

	if (strcmp(dest, "reg1") == 0) 
		cpu -> reg1 = ram -> variaveis[i].valor;
	else if (strcmp(dest, "reg2") == 0)
		cpu -> reg2 = ram -> variaveis[i].valor;
	printf("MEMORIA_LIDA_COM = %d\n", ram -> variaveis[i].valor);
}

void execAdd(CPUInt *cpu, char *dest, char *outro) {
	if (strcmp(dest, "reg1") == 0)  {
		cpu -> reg1 += (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		printf("RESULT_ADD = %d\n", cpu -> reg1);
	}
	else if (strcmp(dest, "reg2") == 0) {
		cpu -> reg2 += (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		printf("RESULT_ADD = %d\n", cpu -> reg2);
	}
}

void execSub(CPUInt *cpu, char *dest, char *outro) {
	if (strcmp(dest, "reg1") == 0) {
		cpu -> reg1 -= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		printf("RESULT_SUB = %d\n", cpu -> reg1);
	}
	else if (strcmp(dest, "reg2") == 0) {
		cpu -> reg2 -= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		printf("RESULT_SUB = %d\n", cpu -> reg2);
	}
}

void execDiv(CPUInt *cpu, char *dest, char *outro) {
	if (strcmp(dest, "reg1") == 0) {
		cpu -> reg1 /= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		printf("RESULT_DIV = %d\n", cpu -> reg1);
	}
	else if (strcmp(dest, "reg2") == 0) {
		cpu -> reg2 /= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		printf("RESULT_DIV = %d\n", cpu -> reg2);
	}
}

void execMul(CPUInt *cpu, char *dest, char *outro) {
	if (strcmp(dest, "reg1") == 0) {
		cpu -> reg1 *= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		printf("RESULT_MUL = %d\n", cpu -> reg1);
	}
	else if (strcmp(dest, "reg2") == 0) {
		cpu -> reg2 *= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		printf("RESULT_MUL = %d\n", cpu -> reg2);
	}
}