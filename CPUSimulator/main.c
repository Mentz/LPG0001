#include <stdio.h>
#include <string.h>
#include "aloca_memoria.h"
#include "funcoes.h"

//#define MEMDEBUG		// descomente essa linha para exibir estado da alocação de memória no final da execução

char *Comandos[] = { "int", "rem", "load", "store", "add", "sub", "div", "mul", "memuse" };

int main(int argc, char **argv) {
	char inst[10], id1[TAMANHO_ID], id2[TAMANHO_ID];
	int valor;
	CPUInt *cpu = NULL;
	cpu = (CPUInt *) inicializaCPU();
	RAMInt *ram = NULL;
	ram = (RAMInt *) inicializaRAM();
	while(scanf("%10s", inst) != EOF) {
		if (strcmp(inst, Comandos[0]) == 0) { 		// int <var> <valor>
			scanf("%100s%d", id1, &valor);
			cpu -> instrucao = Comandos[0];
			declararRAMInt(ram, valor, id1);
		} else
		if (strcmp(inst, Comandos[1]) == 0) {		// rem <var> 0
			scanf("%100s%d", id1, &valor);
			cpu -> instrucao = Comandos[1];
			removerRAMInt(ram, valor, id1);
		} else
		if (strcmp(inst, Comandos[2]) == 0) {		// load <reg_destino> <mem_origem>
			scanf("%100s%100s", id1, id2);
			cpu -> instrucao = Comandos[2];
			executarLoadCPUInt(cpu, ram, id1, id2);
		} else
		if (strcmp(inst, Comandos[3]) == 0) {		// store <mem_destino> <reg_origem>
			scanf("%100s%100s", id1, id2);
			cpu -> instrucao = Comandos[3];
			executarStoreCPUInt(cpu, ram, id1, id2);
		} else
		if (strcmp(inst, Comandos[4]) == 0) {		// add <reg_b> <reg_a>
			scanf("%100s%100s", id1, id2);
			cpu -> instrucao = Comandos[4];
			ciclo(cpu, id1, id2, execAdd);
		} else
		if (strcmp(inst, Comandos[5]) == 0) {		// sub <reg_b> <reg_a>
			scanf("%100s%100s", id1, id2);
			cpu -> instrucao = Comandos[5];
			ciclo(cpu, id1, id2, execSub);
		} else
		if (strcmp(inst, Comandos[6]) == 0) {		// div <reg_b> <reg_a>
			scanf("%100s%100s", id1, id2);
			cpu -> instrucao = Comandos[6];
			ciclo(cpu, id1, id2, execDiv);
		} else
		if (strcmp(inst, Comandos[7]) == 0) {		// mul <reg_b> <reg_a>
			scanf("%100s%100s", id1, id2);
			cpu -> instrucao = Comandos[7];
			ciclo(cpu, id1, id2, execMul);
		} else
		if (strcmp(inst, Comandos[8]) == 0) {		// memuse - retorna bytes alocados
			memoria_alocada();
			variaveis_alocadas();
			variaveis_ativas();
		}
	}
	destruirCPU(cpu);
	destruirRAM(ram);
	cpu = NULL;

#ifdef MEMDEBUG
	memoria_alocada();
	variaveis_alocadas();
	variaveis_ativas();
#endif


	return 0;
}