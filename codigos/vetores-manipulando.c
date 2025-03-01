#include <stdio.h>

int main(void){
	
	float notas[5]={};
	float media, total=0;
	
	printf("-----ENCONTRANDO A MEDIA-----\n");
	
	for(int i=0;i<5;i++){
		printf("Digite a nota:");
		scanf("%f",&notas[i]);
		total+=notas[i];
	}
	media = total/5;
	
	printf("A media das notas: %f",media);
	
	return 0;
}