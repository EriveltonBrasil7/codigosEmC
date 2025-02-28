#include <stdio.h>

int main(){
	int i;
	
	printf("Insira um numero inteiro de 1 a 5: ");
	scanf("%i",&i);
	
	switch(i){
		case 1:
			printf("Primeiro\n");
			break;
		case 2:
			printf("Segundo");
			break;
		case 3:
			printf("Terceiro");
			break;
		case 4:
			printf("Quarto");
			break;
		case 5:
			printf("Quinto");
			break;
		default:
			printf("Numero digitado nao esta na lista!");
			break;
	}	
	return 0;
}