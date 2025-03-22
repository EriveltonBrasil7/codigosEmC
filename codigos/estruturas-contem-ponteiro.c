#include <stdio.h>
//aula 65

int main(void){
	
	struct horario {
		int *pHora;
		int *pMinuto;
		int *pSegundo;
	};
	
	struct horario hoje;
	
	int hora=100;
	int minuto=200;
	int segundo=300;
	
	hoje.pHora = &hora;
	hoje.pMinuto = &minuto;
	hoje.pSegundo = &segundo;
	
	printf("hora: %i\n",*hoje.pHora);
	printf("minuto: %i\n",*hoje.pMinuto);
	printf("Segundo: %i\n",*hoje.pSegundo);
	
	*hoje.pSegundo = 1000;
	
	printf("Segundo: %i",*hoje.pSegundo);
	
	getchar();
	return 0;
}
