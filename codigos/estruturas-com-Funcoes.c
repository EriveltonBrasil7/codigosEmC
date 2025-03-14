#include <stdio.h>

struct horario{
		int horas, minutos, segundos;
};

int main(void){
	
	struct horario teste (struct horario x);
		
	struct horario agora;
	agora.horas = 10;
	agora.minutos = 42;
	agora.segundos = 58;
	
	struct horario proxima;
	proxima = teste(agora);
	
	printf("%i:%i:%i \n",proxima.horas,proxima.minutos,proxima.segundos);
	
	system("pause");
	return 0;
}
struct horario teste (struct horario x){
	
	printf("%i:%i:%i \n",x.horas,x.minutos,x.segundos);
	
	x.horas = 15;
	x.minutos = 27;
	x.segundos = 31;
	
	return x;
}