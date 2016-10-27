#include <stdio.h>
#include <string.h>
#include "aloca_memoria.h"
#include "funcoes.h"

#define DEBUG			// comente ou descomente essa linha para exibir debug no terminal

#ifdef DEBUG
#define PRINTD printf
#else
#define PRINTD(format, args...) ((void)0)
#endif

CPUInt* inicializaCPU(void) {
	CPUInt *cpu = NULL;
	cpu = (CPUInt *) alocar_memoria(sizeof(CPUInt));
	cpu -> reg1 = 0;
	cpu -> reg2 = 0;
	cpu -> instrucao = NULL;
	PRINTD("CPU_INICIALIZADA\n");
	return cpu;
}

RAMInt* inicializaRAM(void) {
	RAMInt *ram = NULL;
	ram = (RAMInt *) alocar_memoria(sizeof(RAMInt));
	ram -> elementos = 0;
	ram -> variaveis = NULL;
	PRINTD("RAM_INICIALIZADA\n");
	return ram;
}

void destruirCPU(CPUInt *cpu) {
	cpu -> instrucao = NULL;
	desalocar_memoria(cpu);
	PRINTD("CPU_DESTRUIDA\n");
}

void destruirRAM(RAMInt *ram) {
	if (ram -> variaveis != NULL) {
		desalocar_memoria(ram -> variaveis);
		ram -> variaveis = NULL;
	}
	desalocar_memoria(ram);
	PRINTD("RAM_DESTRUIDA\n");
}

void declararRAMInt(RAMInt *ram, int valor, char *id) {
	if (ram -> elementos == 0) 
		ram -> variaveis = (Variavel *) alocar_memoria(sizeof(Variavel) * (ram -> elementos + 1));
	else 
		ram -> variaveis = (Variavel *) realocar_memoria(ram -> variaveis, sizeof(Variavel) * (ram -> elementos + 1));
	ram -> elementos++;
	ram -> variaveis[ram -> elementos - 1].valor = valor;
	strcpy(ram -> variaveis[ram -> elementos - 1].identificador, id);
	PRINTD("DECLARADO %s = %d\n", ram -> variaveis[ram -> elementos - 1].identificador,
								  ram -> variaveis[ram -> elementos - 1].valor);
}

void removerRAMInt(RAMInt *ram, int valor, char *id) {
	int pos = encontrarVar(ram, id);
	int i = 0;

	if (pos != -1) {
		for (i = pos; i < ram -> elementos - 1; i++) {
			ram -> variaveis[i] = ram -> variaveis[i + 1];
		}
		if (ram -> elementos == 1) {
			desalocar_memoria(ram -> variaveis);
			ram -> variaveis = NULL;
		} else {
			ram -> variaveis = (Variavel *) realocar_memoria(ram -> variaveis, sizeof(Variavel) * (ram -> elementos - 1));
		}
		ram -> elementos--;
		PRINTD("RAM_ELEMENTOS = %d\n", ram -> elementos);
	} else {
		PRINTD("VAR_NAO_ENCONTRADA\n");
	}

}

void executarStoreCPUInt(CPUInt *cpu, RAMInt *ram, char *dest, char *orig) {
	int pos = encontrarVar(ram, dest);
	if (pos != -1) {
		if (strcmp(orig, "reg1") == 0) 
			ram -> variaveis[pos].valor = cpu -> reg1;
		else if (strcmp(dest, "reg2") == 0)
			ram -> variaveis[pos].valor = cpu -> reg2;
		PRINTD("MEMORIA_GUARDADA_COM = %d\n", ram -> variaveis[pos].valor);
	} else {
		PRINTD("MEMORIA_INEXISTENTE\n");
	}
}

void executarLoadCPUInt(CPUInt *cpu, RAMInt *ram, char *dest, char *orig) {
	int pos = encontrarVar(ram, orig);
	if (pos != -1) {
		if (strcmp(dest, "reg1") == 0) 
			cpu -> reg1 = ram -> variaveis[pos].valor;
		else if (strcmp(dest, "reg2") == 0)
			cpu -> reg2 = ram -> variaveis[pos].valor;
		PRINTD("MEMORIA_LIDA_COM = %d\n", ram -> variaveis[pos].valor);
	} else {
		PRINTD("MEMORIA_INEXISTENTE\n");
	}
}

void execAdd(CPUInt *cpu, char *dest, char *outro) {
	if (strcmp(dest, "reg1") == 0)  {
		cpu -> reg1 += (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		PRINTD("RESULT_ADD = %d\n", cpu -> reg1);
	}
	else if (strcmp(dest, "reg2") == 0) {
		cpu -> reg2 += (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		PRINTD("RESULT_ADD = %d\n", cpu -> reg2);
	}
}

void execSub(CPUInt *cpu, char *dest, char *outro) {
	if (strcmp(dest, "reg1") == 0) {
		cpu -> reg1 -= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		PRINTD("RESULT_SUB = %d\n", cpu -> reg1);
	}
	else if (strcmp(dest, "reg2") == 0) {
		cpu -> reg2 -= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		PRINTD("RESULT_SUB = %d\n", cpu -> reg2);
	}
}

void execDiv(CPUInt *cpu, char *dest, char *outro) {
	if (strcmp(dest, "reg1") == 0) {
		cpu -> reg1 /= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		PRINTD("RESULT_DIV = %d\n", cpu -> reg1);
	}
	else if (strcmp(dest, "reg2") == 0) {
		cpu -> reg2 /= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		PRINTD("RESULT_DIV = %d\n", cpu -> reg2);
	}
}

void execMul(CPUInt *cpu, char *dest, char *outro) {
	if (strcmp(dest, "reg1") == 0) {
		cpu -> reg1 *= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		PRINTD("RESULT_MUL = %d\n", cpu -> reg1);
	}
	else if (strcmp(dest, "reg2") == 0) {
		cpu -> reg2 *= (strcmp(outro, "reg2") == 0) ? cpu -> reg2 : cpu -> reg1;
		PRINTD("RESULT_MUL = %d\n", cpu -> reg2);
	}
}

int encontrarVar(RAMInt *ram, char *id) {
	int pos = -1, i = 0;
	for (i = 0; i < ram -> elementos; i++) {
		if (strcmp(id, ram -> variaveis[i].identificador) == 0) {
			pos = i;
			break;
		}
	}
	
	return pos;
}