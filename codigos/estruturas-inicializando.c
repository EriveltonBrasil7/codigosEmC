#include <stdio.h>


int main(void){
	
	struct horario{
		int horas, minutos, segundos;
}agora = {10, 20, 30};

	printf("%i:%i:%i \n",agora.horas,agora.minutos,agora.segundos);
	
	system("pause");
	return 0;
}