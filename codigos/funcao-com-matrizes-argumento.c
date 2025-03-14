#include <stdio.h>

void funcaoPrint(int x[3][3]){
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("%i ",x[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	
	int matriz [3][3] = {1,2,3,4,5,6,7,8,9};
	
	funcaoPrint(matriz);
	
	printf("\n");
	system("pause");
	return 0;
}