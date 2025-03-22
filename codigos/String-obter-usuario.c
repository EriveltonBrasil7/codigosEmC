#include <stdio.h>
//aula 52

int main(void){
	
	char nome[20];
	char sobrenome[20];
	
	printf("Digite o nome e o sobrenome: ");
	scanf("%s%s",&nome,&sobrenome);
	
	printf("%s %s\n",nome,sobrenome);
	
	system("pause");
	return 0;
}