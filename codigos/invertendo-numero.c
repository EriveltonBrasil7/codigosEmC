#include <stdio.h>

int main(){
	
	int numero, cifra;
	
	printf("Digite um numero inteiro: ");
	scanf("%i",&numero);
	
	if(numero>=0){
		do{
			cifra = numero % 10;
			printf("%i",cifra);
			numero/=10;
			
		}while(numero!=0);
		printf("\n");
	}
	else if(numero<0){
		printf("-");	
		numero*=-1;
		do{
			
			cifra = numero % 10;
			printf("%i",cifra);
			numero/=10;
			
		}while(numero!=0);
		printf("\n");
	}
	
	return 0;
}