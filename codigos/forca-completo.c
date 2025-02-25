#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

//variaveis globais
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

void cabecalho(){
	printf("**************************\n");
	printf("*	JOGO DA FORCA	*\n");
	printf("**************************\n\n");
}
void chuta(){
	//captura um nove chute
	char chute;
	scanf(" %c",&chute);//O espaço na frente do % indica que vai ser dado o enter e que o sistema não precisar ler este.
		
	chutes[chutesdados] = chute;
	chutesdados++;//Somar no valor que está dentro deste endereço do ponteiro.
}

void desenhaforca(){
	// Imagem de boneco na forca e mensagem "Perdeu"
		int erros = chuteserrados();
		
    	printf("   _______ 			\n");
    	printf("   |/      | 		\n");
    	printf("   |      %c%c%c	\n", (erros >= 1 ? '(' : ' '),
				(erros >=1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));		
    	printf("   |      %c%c%c	\n", (erros>=3?'\\':' '),
			(erros >=2 ?'|' : ' '),		 (erros >=3 ? '/' : ' '));
    	printf("   |       %c		\n", (erros>=2 ?  '|' : ' '));
    	printf("   |      %c %c		\n", (erros>=4 ?'/' : ' '),
			(erros>=4 ? '\\' : ' '));
    	printf("   | 				\n");
    	printf(" __|___				\n");
    	printf("\n\n");
		//imprime a palavra secreta
	for (int i =0; i<strlen(palavrasecreta);i++){
			
		int achou = jachutou(palavrasecreta[i]);
			
		if(achou){
			printf("%c", palavrasecreta[i]);
		}else{
			printf("_ ");
		}
	}
		printf("\n");		
}
void adicionapalavra(){

	char quer;
	
	printf("Voce quer adicionar uma nova palavra (S/N):");
	scanf(" %c",&quer);
	
	if(quer=='S'){
		
		char novapalavra[TAMANHO_PALAVRA];
		printf("Qual a nova palavra: ");
		scanf("%s",novapalavra);
		
		FILE* f;
		
		f = fopen("palavras.txt","r+");//r+ é leitura e escrita
		
		if( f==0){//tratamento caso não encontre o texto por esta corrompido ou danificado
			printf("Desculpe banco de dados nao disponivel");
			exit(1);//1 pois deu erro; se fosse 0 é porque está funcionando.
		}		
		
		int qtd;
		fscanf(f,"%d",&qtd);
		qtd++;
		
		//fseek: posiciona de onde quer começar a ler.
		fseek(f,0,SEEK_SET);//inicio do txt
		fprintf(f,"%d",qtd);
		
		fseek(f,0,SEEK_END);//adiciona nova palavra ano final da lista

		fprintf(f,"\n%s",novapalavra);
		
		fclose(f);
	}
}
void escolhepalavra(){
	FILE* f;
	
	f = fopen("palavras.txt","r");//abri o arquivo "r" é para leitura (Read).
	if( f==0){//tratamento caso não encontre o texto por esta corrompido ou danificado
		printf("Desculpe banco de dados nao disponivel");
		exit(1);//1 pois deu erro; se fosse 0 é porque está funcionando.
	}
	
	int qtddepalavras;
	fscanf(f,"%d",&qtddepalavras) ;
	
	srand(time(0));
	int randomico = rand()%qtddepalavras;
	
	for(int i=0; i<=randomico;i++){
		fscanf(f,"%s", palavrasecreta);
	}
	
	fclose(f);
}

int acertou(){
	for(int i=0; i<strlen(palavrasecreta);i++){
		if(!jachutou(palavrasecreta[i])){
			return 0;
		}
	}
	return 1;
}
int chuteserrados(){
	int erros = 0;
	
	for(int i =0; i<chutesdados;i++){
		int existe=0;
		
		for(int j=0;j<strlen(palavrasecreta);j++){
			if(chutes[i]== palavrasecreta[j]){
				existe = 1;
				break;
			}
		}
		if(!existe) erros++;
	}
	return erros;
}

int enforcou(){
	
	return chuteserrados() >= 5;
}
int jachutou(char letra){
	int achou=0;
			
	for (int j=0;j<chutesdados;j++){
		if(chutes[j] == letra){
			achou=1;
			break;
		}
	}
	return achou;
}

int main(){
	
	escolhepalavra();
	cabecalho();
	
	do{
		
		desenhaforca();	
		chuta();	
			
	}while(!acertou() && !enforcou());	
	
	adicionapalavra();
	
	if(acertou())	{
			// Nova imagem de troféu e mensagem "Ganhou"
		printf("\n");
		printf("Voce e o VENCEDOR!\n");
    	printf("      _____\n");
    	printf("     /     \\ \n");
    	printf("    |       | \n");
    	printf("    |  * *  | \n");
    	printf("    |   *   | \n");
    	printf("    |  * *  | \n");
    	printf("    |       | \n");
    	printf("     \\     / \n");
    	printf("      |   |   \n");
    	printf("      |   |   \n");
    	printf("      |   |   \n");
    	printf("     /_____/  \n");
    	printf("   Ganhou!\n");
    	printf("\n");
	}else{
		 // Imagem de boneco na forca e mensagem "Perdeu"
		printf("\nPoxa voce foi enforcado!\n");
		printf("A palavra era %s", palavrasecreta);
		printf("\n");
    	printf("   _______ \n");
    	printf("   |/      | \n");
    	printf("   |      ( )\n");
    	printf("   |      /|\\\n");
    	printf("   |      / \\ \n");
    	printf("   | \n");
    	printf(" __|___\n");
    	printf("\n");
    	printf("   Perdeu!\n");
	}
}