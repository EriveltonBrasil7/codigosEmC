#include <stdio.h>

int main(void){
	int x = 16;
	int y = 3;
	float resultado;
	
	resultado = (float) x/y; //casting: passar int para float.
	
	printf("%f\n",resultado);
	
	system("pause");
	return 0;
}