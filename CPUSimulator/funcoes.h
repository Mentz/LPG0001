#ifndef _FUNCOES_H_
#define _FUNCOES_H_

#define TAMANHO_ID 100

typedef struct {
	int valor;
	char identificador[TAMANHO_ID];
} Variavel;

typedef struct {
	int reg1;
	int reg2;
	char *instrucao;
} CPUInt;

typedef struct {
	int elementos;
	Variavel *variaveis;
} RAMInt;

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

#endif