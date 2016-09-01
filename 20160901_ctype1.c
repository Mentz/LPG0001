#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int maiusculo(char palavra[]);

int main(){
	char nome[50];
	int contador = 0;
	printf("Informa uma palavra\n");
	scanf("%49s",nome);
	contador = maiusculo(nome);
	printf("%d foram convertidas = %s\n",contador,nome);

	return 0;
}

int maiusculo(char palavra[]) {
	int alt = 0, i = 0;
	while(palavra[i]!='\0') {
		if (islower(palavra[i])) {
			alt++;
			palavra[i] = toupper(palavra[i]);
		}
		i++;
	}
	return alt;
}
