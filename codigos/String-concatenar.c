#include <stdio.h>

void concatenarString (char string1[],int t1, char string2[],int t2, char string3[]){
	
	for(int i =0;i<t1;i++){
		string3[i] = string1[i];
	}
	for(int j=0;j<t2;j++){
		string3[t1 + j] = string2[j];
	}
}

int main(void){
	
	void concatenarString (char string1[],int t1, char string2[],int t2, char string3[]);
	
	char palavra1[] = {'p','a','o',' '};
	char palavra2[] = {'m','o','r','t','a','d','e','l','a'};
	char novaPalavra[13];
	
	concatenarString(palavra1,4, palavra2,9, novaPalavra);
	
	for(int i =0;i<13;i++){
		printf("%c",novaPalavra[i]);
	}
	
	printf("\n\n");
	
	system("pause");
	return 0;
}