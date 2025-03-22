#include <stdio.h>
//aula 54
int main(void){
	void alfabetico (char variavel);
	
	char nome[20];
	printf("Digite uma palavra:");
	scanf("%s",&nome);
	
	int i = 0;
	while(nome[i] != '\0'){
		alfabetico(nome[i]);
		i++;
	}	
	
	system("pause");
	return 0;
}

void alfabetico(char variavel){
	if((variavel>='a' && variavel<='z') || (variavel>='A' && variavel<='Z')){
		printf("Alfabetico!\n");
	}else{
		printf("Nao Alfabetico!\n");
	}
}