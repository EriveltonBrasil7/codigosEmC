#include <stdio.h>

int main(void){
						//colunas
	int matriz [3] [3] = {{1,2,3},//linhas
						  {4,5,6},
						  {7,8,9}};
	//outra forma declarar
	/*int matriz [3] [3] = {{1,2,3,4,5,6,7,8,9}};*/
	
	printf("%i",matriz[1][1]);
	
	return 0;
}