#include <stdio.h>

int main(void){
	
	int qtd;
	float media, total=0;
	
	printf("Voce quer digitar quantas notas:");
	scanf("%i",&qtd);
	
	float notas[qtd];
	
	printf("-----ENCONTRANDO A MEDIA-----\n");
	
	for(int i=0;i<qtd;i++){
		printf("Digite a nota:");
		scanf("%f",&notas[i]);
		total+=notas[i];
	}
	media = total/qtd;
	
	printf("A media das notas: %f",media);
	
	return 0;
}