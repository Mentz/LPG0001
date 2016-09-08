#include <stdio.h>

int fat(int);

int main(void){
	unsigned long long int a;
	printf("mim da um numero\n");
	scanf("%d",&a);
	printf("%15d! = %15d\n",a,fat(a));

	return 0;
}

unsigned long long int fat(int m) {
	if (m<=1) return 1;
	return m*fat(m-1);
}
