#include <stdio.h>
#include <string.h>

int main(){
	
	char saudacao[100];
	int tamanho;
	
	printf("Escreva seu nome:");
	gets(saudacao);
	tamanho = strlen(saudacao); //funcao usada para quantificar as letras digitadas ao todo.
	//scanf("%s",saudacao);//pega so o primeiro nome não pega apos o espaço
	printf("\nOla %s, seja bem-vindo!",saudacao);
	printf("\nO nome digitado acima tem %d letras.",tamanho);
	
	return 0;
}