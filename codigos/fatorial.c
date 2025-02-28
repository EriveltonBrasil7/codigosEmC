#include <stdio.h>

int main(){
	int fatorial = 10;
	int resposta = 1;
	
	printf("Fatorial de %d",fatorial);
	printf("\n");
	
	for(;fatorial>=1; fatorial--){
		printf("%d x ",fatorial);
		resposta*=fatorial;
	}
		printf("\n RESULTADO deste fatorial = %d",resposta);
	return 0;
}