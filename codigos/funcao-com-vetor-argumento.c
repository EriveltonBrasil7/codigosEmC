#include <stdio.h>

void ordemCrescente(int vetor [], int n){
	int i, j ,temporaria;
	
	for(i=0;i<n;i++){
		for(j=1+i;j<n;j++){
			if(vetor[i]>vetor[j]){
				temporaria = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temporaria;
			}
		}
	}
}

int main(void){
	
	int vetor[10] = {4,2,3,7,6,8,9,1,5,0};
	int i;
	
	ordemCrescente(vetor,10);
	
	for(int i=0; i<10;i++){
		printf("%i ",vetor[i]);
	}
	
	printf("\n");
	system("pause");
	return 0;
}