#include <stdio.h>
#include <math.h>

/*Escreva  uma  função  para  calcular  a  distância
entre  dois  pontos  (x1,  y1)  e  (x2,  y2).  Todos  os  números  e  o 
valor de retorno devem ser do tipo double*/ 

double mentz(int x1, int y1, int x2, int y2);

int main(void) {
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("%.3f\n", mentz(x1,y1,x2,y2));
	return 0;
}
		
double mentz(int x1, int y1, int x2, int y2) {
	double c = x2 - x1;
	double d = y2 - y1;
	double resp = sqrt(c*c + d*d);
	return resp;

}
	
