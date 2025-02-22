#include <stdio.h>
#include <string.h>

void cabecalho(){
	printf("**************************\n");
	printf("*	JOGO DA FORCA	*\n");
	printf("**************************\n\n");
}//* ponteiro na variavel t.
void chuta(char c[26], int*t){
	//captura um nove chute
	char chute;
	scanf(" %c",&chute);//O espaço na frente do % indica que vai ser dado o enter e que o sistema não precisar ler este.
		
	c[(*t)] = chute;
	(*t)++;//Somar no valor que está dentro deste endereço do ponteiro.
}

int main(){
	char palavrasecreta[20];
	
	sprintf(palavrasecreta,"MELANCIA");
	
	int acertou =0;
	int enforcou =0;
	
	char chutes[26];
	int tentativas = 0;
	
	cabecalho();
	
	do{
		//imprime a palavra secreta
		for (int i =0; i<strlen(palavrasecreta);i++){
			
			int achou=0;
			
			//a letra que foi chutada?
			for (int j=0;j<tentativas;j++){
				if(chutes[j] == palavrasecreta[i]){
					achou=1;
					break;
				}
			}
			if(achou){
				printf("%c ", palavrasecreta[i]);
			}else{
				printf("_ ");
			}
		}
		printf("\n");
		
		chuta(chutes, &tentativas);		
	}while(!acertou && !enforcou);	
}