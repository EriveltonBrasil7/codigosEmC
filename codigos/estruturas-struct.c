#include <stdio.h>

int main(void){
	
	struct horario
	{
		int horas, minutos, segundos;
		double teste;
		char letra;		
	};
	
	struct horario agora;
	
	agora.horas = 11;
	agora.minutos = 23;
	agora.segundos = 45;
	
	struct horario depois;

	depois.horas = agora.horas + 10;
	depois.minutos = agora.minutos;
	depois.teste = 50.55/123;
	depois.letra = 'a';
	
	printf("%i:%i:%i \n",agora.horas, agora.minutos, agora.segundos);
	printf("%i:%i\n",depois.horas,depois.minutos);
	printf("Divisao: %f e Letra: %c\n",depois.teste,depois.letra);
	
	system("pause");
	return 0;
}