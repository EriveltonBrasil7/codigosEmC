#include <stdio.h>

struct horario{
	int hora,minuto,segundo;	
};

void receberHorarios(struct horario list[5]){
	
	for(int i=0;i<5;i++){
		printf("Digite o %i horario (hh:mm:ss):",i+1);
		scanf("%i:%i:%i",&list[i].hora,&list[i].minuto,&list[i].segundo);
	}
}
void printHorarios(struct horario list[5]){
	for(int i=0;i<5;i++){
		printf("O %i horario e = %i:%i:%i\n",i+1,list[i].hora,list[i].minuto,list[i].segundo);
	}
} 

int main(void){
	
	void receberHorarios(struct horario list[5]);
	void printHorarios(struct horario list[5]);
	
	struct horario listaHorarios[5];
	
	receberHorarios(listaHorarios);
	printHorarios(listaHorarios);
	
	
	system("pause");
	return 0;
}