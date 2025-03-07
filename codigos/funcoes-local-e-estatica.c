#include <stdio.h>

void teste(){
	int local = 2;
	static int estatica=2;
	
	local*=2;//se perder (reinicia) na memoria
	estatica*=2;//fica salvo na memoria
	
	printf("\nVariavel Local %i ",local);
	printf("\nVariavel Estatica %i",estatica);
	
}

int main(void){
	
	teste();
	teste();
	teste();
	
	return 0;
	
}