#ifndef LPG_H
#define LPG_H
#define ALUNOS 10
#define PROVAS 5

float media_aluno(int notas[]);
float media_turma(int notas[][PROVAS]);
void imprimir(int notas[][PROVAS]);
int maior_nota(int notas[][PROVAS]);
int menor_nota(int notas[][PROVAS]);
int menu();

#endif
