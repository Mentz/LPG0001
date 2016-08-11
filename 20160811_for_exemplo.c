#include <stdio.h>
#include <math.h>

int main(){
	double t = 0.05; // rendimento ao ano de poupança ao ano
	int n = 10; // anos para cálculo do rendimento
	double vp = 1000; // quantidade de investimento inicial em reais
	double vf = 0; // valor final no término de cada ano
	int ano;
	printf("%-10s%10s\n","Ano", "Saldo");
	for (ano = 0; ano <= n; ano++) {
		vf = vp*pow(1+t,ano);
		printf("%-10d%10.2f\n",ano,vf);
	}

	return 0;
}