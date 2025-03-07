#include <stdio.h>

float negativo(float num1, float num2){
	float soma;
	
	if(num1<0){
		num1*=-1;
	}
	if(num2<0){
		num2*=-1;
	}
	soma = num1+num2;
	printf("A soma dos numeros digitados = %f\n",soma);
	
	return soma;
}

int main(void){
	float num1,num2;
	
	printf("Digite um valor:");
	scanf("%f",&num1);
	printf("Digite um valor:");
	scanf("%f",&num2);
	
	negativo(num1,num2);
	
	system("pause");
	return 0;
}