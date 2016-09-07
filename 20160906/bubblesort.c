#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 30

int main(){
	int vet[TAMANHO] = {0, 10, 8, 7, 5, 9, 77, 8, 5, 0, 1, 11, 21, 23, 43, 45,
				 56, 76, 23, 54, 76, 12, 48, 55, 22, 11, 2, 3, 2, 6};

	int i, j, aux;
	for(i = 0; i < TAMANHO; i++){
		for(j = 0; j < TAMANHO - 1; j++){
			if(vet[j] > vet[j + 1]){
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux; 
			}
		}
	}

	for(i = 0; i < TAMANHO; i++)
		printf("%d ", vet[i]);
	printf("\n");

	return 0;
}