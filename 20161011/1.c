//APRENDENDO STRUCT OH YEAH
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int x;
	int y;
}Ponto;

int distancia(Ponto a, Ponto b);

int main(void) {
	int d = 0;
	Ponto p1;
	Ponto p2;
	printf("Coordenadas x e y para P1 e P2, respectivamente:\nP1: ");
	scanf("%d%d",&p1.x,&p1.y);
	printf("\nP2: ");
	scanf("%d%d",&p2.x,&p2.y);
	d = distancia(p1, p2);
	printf("Distância = %d\n", d);

	return 0;
}

int distancia(Ponto a, Ponto b) {
	int x = 0;
	x = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));

	return x;
}