#include <stdio.h>
//Aula 53

int main(void){
	char linha [100], caractere;
	int i=0;
	
	printf("Digite o seu nome completo:");
	do{	
		caractere = getchar();
		linha[i] = caractere;
		i++;
	}while(caractere != '\n');//quando pressionar enter ele finaliza (enter = '\n').
	
	linha[i-1] = '\0';//na ultima posicao do vetor adicionar fator nulo para finalizar os caractere.
	printf("Seu nome: ");
	printf("%s\n",linha);
	
	system("pause");
	return 0;
}
