#include <stdio.h>
//Aula 62 

int main(void){
	
	int x = 10;
	double y = 20.50;
	char z = 'a';
	
	int *pX = &x;
	double *pY = &y;
	char *pZ = &z;
	
	double soma = *pX + *pY;//* pegou os valores que estao no ponteiro.
	
	printf("\nEndereco de memoria X: %i - valor de X: %i",pX,*pX);
	printf("\nEndereco de memoria y: %i - valor de y: %.2f",pY,*pY);
	printf("\nEndereco de memoria z: %i - valor de z: %c",pZ,*pZ);
	
	printf("\nValor da soma x + y (por ponteiro)= %.2f",soma);
	
	
	getchar();
	return 0;
}