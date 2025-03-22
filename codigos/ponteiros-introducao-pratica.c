#include <stdio.h>
//aula 61

int main(void){
	
	int x = 10;
	
	int *p = &x;
	
	printf("Endereco de memoria: %i ",&x);//& endereço de memoria
	printf("\nponteiro: %i",*p);//com * recebe o valor; sem * endereco de memoria
	
	
	
	getchar();
	return 0;
}