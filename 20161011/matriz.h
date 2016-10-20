#ifndef MATRIZ_H
#define MATRIZ_H

int **criar_matriz_bloco(int linhas, int colunas);
int **criar_matriz_distribuida(int linhas, int colunas);
void preencher_matriz(int **m, int linhas, int colunas);
void imprimir_matriz(int **m, int linhas, int colunas);
void destruir_matriz_bloco(int **m);
void destruir_matriz_distribuida(int **m, int linhas);

#endif
