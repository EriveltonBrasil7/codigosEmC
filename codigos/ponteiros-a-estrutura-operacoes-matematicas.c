#include <stdio.h>
//aula  64

int main(void){
	
	struct horario{
		int hora;
		int minuto;
		int segundo;
	};
	
	struct horario agora,*depois;
	depois = &agora;
	
	depois->hora=22;
	depois->minuto=53;
	depois->segundo=38;
	
	int somatorio =100;
	
	struct horario antes;
	
	antes.hora = somatorio + depois->segundo;
	antes.minuto = agora.hora * depois->minuto;
	antes.segundo = depois->segundo - depois->minuto;
	
	printf("Time: %i:%i:%i",antes.hora,antes.minuto,antes.segundo);
	
	getchar();
	return 0;
}