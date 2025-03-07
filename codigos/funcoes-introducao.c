#include <stdio.h>
float calcularAreaRetang(float base, float altura){
	
	float area;
	
	area = base*altura;
	
	return area;
}


int main(void){
	
	float resultado;
	
	resultado = calcularAreaRetang(10.0,20.0);
	printf("O resultado da Area do retangulo = %.2f",resultado);
	
	
	return 0;
}