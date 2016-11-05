/*
 * Autores: Leonardo Valério Anastácio e Lucas Litter Mentz
 * Última modificação: 5 de novembro de 2016
 */

#ifndef _FUNCOES_H_
#define _FUNCOES_H_

#define TAMANHO_ID 100

typedef struct {
	int valor;							// 4b
	char identificador[TAMANHO_ID];		// 100b
} Variavel;								// total 104b

typedef struct {
	int reg1;							// 4b
	int reg2;							// 4b
	char *instrucao;					// 8b
} CPUInt;								// total 16b

typedef struct {
	int elementos;						// 4b
	Variavel *variaveis;				// 8b
} RAMInt;								// total 12b

CPUInt* inicializaCPU(void);
RAMInt* inicializaRAM(void);
void destruirCPU(CPUInt *);
void destruirRAM(RAMInt *);
void declararRAMInt(RAMInt *ram, int valor, char *id);
void removerRAMInt(RAMInt *ram, int valor, char *id);
void executarStoreCPUInt(CPUInt *cpu, RAMInt *ram, char *dest, char *orig);
void executarLoadCPUInt(CPUInt *cpu, RAMInt *ram, char *dest, char *orig);
void ciclo(CPUInt *cpu, char *dest, char *outro, int (*f)(int a, int b));
int execAdd(int a, int b);
int execSub(int a, int b);
int execDiv(int a, int b);
int execMul(int a, int b);
int encontrarVar(RAMInt *ram, char *id);

#endif