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
void execAdd(CPUInt *cpu, char *dest, char *outro);
void execSub(CPUInt *cpu, char *dest, char *outro);
void execDiv(CPUInt *cpu, char *dest, char *outro);
void execMul(CPUInt *cpu, char *dest, char *outro);
int encontrarVar(RAMInt *ram, char *id);

#endif