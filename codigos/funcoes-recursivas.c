#include <stdio.h>

int fatorial(int x){
	int soma=1;
	
	if(x==0){
		soma = 1;
	}else{
		soma = x * fatorial(x-1); //loop até chegar em 0 e retorna multiplicando de 1 ao numero digitado na sequencia.
	}
	return soma;
}

int main(void){
	int numero, resultado;

	printf("Digite um numero: ");
	scanf("%i",&numero);
	
	resultado = fatorial(numero);
	
	printf("O fatorial do numero %i! e = %i\n",numero,resultado);
	
	
	system("pause");
	return 0;
}