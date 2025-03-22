#include <stdio.h>

int tamanhoString(char string[]){
	int numCaracteres=0;
	
	while(string[numCaracteres] != '\0'){
		numCaracteres++;
	}
	numCaracteres +=1; //tanto faz ++ ou +=1;
	return numCaracteres;
}

int main(void){
	
	int tamanhoString(char string[]);
	char stringUsuario[20];
	
	printf("Digite uma string:\n");
	scanf("%s",stringUsuario);
	
	int num = tamanhoString(stringUsuario);
	
	printf("A string %s e foram digitadas %i letras.\n",stringUsuario,num);
	
	system("pause");
	return 0;
}