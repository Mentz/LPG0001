#include <stdio.h>
#include <string.h>
#include "aloca_memoria.h"
#include "funcoes.h"

char *CPUInt_instrucoes[] = { "int", "rem", "load", "store", "add", "sub", "div", "mul" };

int main(int argc, char **argv) {
	char inst[10], id1[TAMANHO_ID], id2[TAMANHO_ID];
	int valor;
	CPUInt *cpu = NULL;
	cpu = (CPUInt *) inicializaCPU();
	RAMInt *ram = NULL;
	ram = (RAMInt *) inicializaRAM();
	while(scanf("%10s", inst) != EOF) {
		if (strcmp(inst, CPUInt_instrucoes[0]) == 0) { 		// int <var> <valor>
			scanf("%100s%d", id1, &valor);
			declararRAMInt(ram, valor, id1);
		} else
		if (strcmp(inst, CPUInt_instrucoes[1]) == 0) {		// rem <var> 0
			scanf("%100s%d", id1, &valor);
			removerRAMInt(ram, valor, id1);
		} else
		if (strcmp(inst, CPUInt_instrucoes[2]) == 0) {		// load <reg_destino> <mem_origem>
			scanf("%100s%100s", id1, id2);
			executarLoadCPUInt(cpu, ram, id1, id2);
		} else
		if (strcmp(inst, CPUInt_instrucoes[3]) == 0) {		// store <mem_destino> <reg_origem>
			scanf("%100s%100s", id1, id2);
			executarStoreCPUInt(cpu, ram, id1, id2);
		} else
		if (strcmp(inst, CPUInt_instrucoes[4]) == 0) {		// add <reg_b> <reg_a>
			scanf("%100s%100s", id1, id2);
			execAdd(cpu, id1, id2);
		} else
		if (strcmp(inst, CPUInt_instrucoes[5]) == 0) {		// sub <reg_b> <reg_a>
			scanf("%100s%100s", id1, id2);
			execSub(cpu, id1, id2);
		} else
		if (strcmp(inst, CPUInt_instrucoes[6]) == 0) {		// div <reg_b> <reg_a>
			scanf("%100s%100s", id1, id2);
			execDiv(cpu, id1, id2);
		} else
		if (strcmp(inst, CPUInt_instrucoes[7]) == 0) {		// mul <reg_b> <reg_a>
			scanf("%100s%100s", id1, id2);
			execMul(cpu, id1, id2);
		}
		if (strcmp(inst, "memuse") == 0) {					// memuse - retorna bytes alocados
			memoria_alocada();
			variaveis_alocadas();
			variaveis_ativas();
		}
	}
	destruirCPU(cpu);
	destruirRAM(ram);
	cpu = NULL;
	memoria_alocada();

	return 0;
}