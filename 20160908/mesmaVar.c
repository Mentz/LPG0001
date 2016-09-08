#include <stdio.h>

void usoLocal(int a);
void usoGlobal(int a);
void usoStatic(int a);

int x = 100;

int main(void){
	int x = 400;
	printf("x = %d\n",x);
	{
		x = 40;
	}
	printf("x = %d\n",x);
	{
		int x = 10;
		printf("x = %d\n",x);
	}
	usoLocal(x);
	usoGlobal(x);
	usoStatic(x);
	x = 100;
	usoLocal(x);
	usoGlobal(x);
	usoStatic(x);
	printf("x = %d\n",x);

	return 0;
}

void usoLocal(int a) {
	int x = 0;
	x += a;
	printf("x = %d\n",x);
}

void usoGlobal(int a) {
	x += a;
	printf("x = %d\n",x);
}

void usoStatic(int a) {
	static int x = 30;
	x += a;
	printf("x = %d\n",x);
}
