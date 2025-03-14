#include <stdio.h>

int main(void){
	
	struct horario
	{
		int horas, minutos, segundos;	
	};
	
	struct horario agora;
	
	agora.horas = 15;
	agora.minutos = 17;
	agora.segundos = 30;
	
	printf("%i:%i:%i\n",agora.horas,agora.minutos, agora.segundos);
	
	system("pause");
	return 0;
}