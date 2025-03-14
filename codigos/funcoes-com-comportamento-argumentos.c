#include <stdio.h>

void funcaoPrint(int x, int vetor[]){
	// int x esta criando outra variavel na memoria por isso não alterou o  x da main; para alterar teria que retornar, criar uma variavel global ou criar um ponteiro. 3 opcoes
	x = x + 10;
	vetor[1] = 20;
	
	printf("Variavel int na funcao = %i \n",x);
	printf("Vetor na funcao = %i \n\n",vetor[1]);
	
}

int main(void){
	int x = 10;
	int vetor[3]= {10};
	
	funcaoPrint(x,vetor);
	
	printf("Variavel int na funcao principal = %i \n",x);
	printf("Vetor na funcao principal = %i \n",vetor[1]);
	
	system("pause");
	return 0;
}