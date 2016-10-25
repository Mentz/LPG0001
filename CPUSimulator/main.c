#include <stdio.h>
#include <string.h>
#include "aloca_memoria.h"
#include "funcoes.h"

char *RAMInt_instrucoes[] = { "int", "rem" };
char *CPUInt_instrucoes[] = { "load", "store", "add", "sub", "div", "mul" };

int main(int argc, char **argv) {
	char inst[10], id1[TAMANHO_ID], id2[TAMANHO_ID];
	int valor;
	CPUInt *cpu = NULL;
	cpu = (CPUInt *) inicializaCPU();
	RAMInt *ram = NULL;
	ram = (RAMInt *) inicializaRAM();
	while(scanf("%s", inst) != EOF) {
		if (strcmp(inst,RAMInt_instrucoes[0]) == 0) { 		// int <var> <valor>
			scanf("%s", id1);
			printf("%s\n",id1);
			scanf("%d",&valor);
			printf("%d\n",valor);
			printf("sua");
			//declararRAMInt(ram, valor, id1);
		} else
		if (strcmp(inst, RAMInt_instrucoes[1]) == 0) {		// rem <var> 0
			scanf("%s%d", id1, &valor);
			removerRAMInt(ram, valor, id1);
		} else
		if (strcmp(inst, CPUInt_instrucoes[0]) == 0) {		// load <reg_destino> <mem_origem>
			scanf("%s%s", id1, id2);
			executarLoadCPUInt(cpu, ram, id1, id2);
		} else
		if (strcmp(inst, CPUInt_instrucoes[1]) == 0) {		// store <mem_destino> <reg_origem>
			scanf("%s%s", id1, id2);
			executarStoreCPUInt(cpu, ram, id1, id2);
		} else
		if (strcmp(inst, CPUInt_instrucoes[2]) == 0) {		// add <reg_b> <reg_a>
			scanf("%s%s", id1, id2);
			execAdd(cpu, id1, id2);
		} else
		if (strcmp(inst, CPUInt_instrucoes[3]) == 0) {		// sub <reg_b> <reg_a>
			scanf("%s%s", id1, id2);
			execSub(cpu, id1, id2);
		} else
		if (strcmp(inst, CPUInt_instrucoes[4]) == 0) {		// div <reg_b> <reg_a>
			scanf("%s%s", id1, id2);
			execDiv(cpu, id1, id2);
		} else
		if (strcmp(inst, CPUInt_instrucoes[5]) == 0) {		// mul <reg_b> <reg_a>
			scanf("%s%s", id1, id2);
			execMul(cpu, id1, id2);
		}
	}
	destruirCPU(cpu);
	destruirRAM(ram);
	cpu = NULL;


	return 0;
}