#include <stdio.h>

int main(void){
	
	struct horario{
		int hora, minutos, segundos;
	};
	
	struct horario teste[5] = 
	{{10,20,30},{20,30,40},{50,60,70},{30,40,50},{40,50,60}};
	
	for(int i=0;i<5;i++){
		printf("%i:%i:%i\n",teste[i].hora,teste[i].minutos,teste[i].segundos);
	}
	
	
	system("pause");
	return 0;
}