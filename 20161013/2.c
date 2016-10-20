#include <stdio.h>

union numero {
	int a;
	double b;
}; // aloca o maior tamanho de memoria dentre os definidos dentro dela. Neste caso é 12 bytes (double).

int main(void) {
	union numero n;
	n.a = 100;
	printf("n.a = %d\nn.b = %.2lf\n",n.a,n.b);
	n.b = 50.0;
	printf("n.a = %d\nn.b = %.2lf\n",n.a,n.b);

	return 0;
}