#include <stdio.h>

int main(){
	int num1, num2;
	
	printf("Digite 2 numeros: ");
	scanf("%d %d",&num1,&num2);
	
	if (num2==0){
		printf("Divisao por 0 nao permitido.\n");
	}
	else{
		if(num1%num2 == 0){
			printf("%d e divisivel por %d", num1, num2);
		}
		else{
			printf("%d nao e divisivel por %d",num1,num2);
		}
	}
	
	return 0;
}