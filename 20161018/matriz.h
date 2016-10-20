#ifndef MATRIZ_T // só substituir uma vez, evitar dependências cruzadas
#define MATRIZ_T

typedef struct {
	int linhas;
	int colunas;
	double **mat;
} Matriz;

/* Manipulação da estrutura */ 
Matriz* criar_matriz(int l, int c, double ** (*f)(int ll, int cc));
void inicializar_matriz(Matriz *m);
void imprimir_matriz(Matriz *m);
void liberar_matriz(Matriz *m, void (*f)(double **, int ll, int cc));

/* Manipulação das alocações de matrizes */
double** criar_bloco(int, int);
double** criar_distribuida(int, int);
void liberar_bloco(double **, int, int);
void liberar_distribuida(double **, int, int);

#endif