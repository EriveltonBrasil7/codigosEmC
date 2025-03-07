#include <stdio.h>

int main(void){
	
	const int bimestresAnuais = 4;
	const int numeroDeAlunos= 4;
	
	float notasAlunos[4][4] = {0};
	float mediasAlunos[4] = {0};
	
	float media =0;
	
	printf("Insira as 4 notas do aluno 1:\n");
	
	for(int i=0;i<numeroDeAlunos;i++){
		for(int j=0;j<bimestresAnuais;j++){
			scanf("%f",&notasAlunos[i][j]);
			media += notasAlunos[i][j];
		}
		mediasAlunos[i] = media/bimestresAnuais;
		media=0;
		printf("Insira as 4 notas do aluno %i:\n ",i+2);
	}
		
	for (int i=0; i<numeroDeAlunos;i++){
		printf("A media do aluno %i e %.2f\n", i+1, mediasAlunos[i]);
	}
	
	return 0;
}