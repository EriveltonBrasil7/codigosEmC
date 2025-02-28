#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100 //tamanho maximo da lista

typedef struct{
	int elementos[TAMANHO_MAX];
	int tamanho;
}Lista;

void inicializarLista(Lista *lista){
	lista->tamanho = 0;
}

int listavazia(Lista *lista){
	return lista->tamanho ==0;
}
int listaCheia(Lista *lista){
	return lista->tamanho == TAMANHO_MAX;
}
int tamanhoLista(Lista *lista){
	return lista->tamanho;
}

int inserirElemento(Lista *lista, int elemento, int posicao){
	if (listaCheia(lista) || posicao < 0 || posicao > lista->tamanho){
		return 0;
	}
	for (int i = lista->tamanho; i>posicao; i--){
		lista->elementos[i] = lista->elementos[i-1];
	}
	return 1;
}
void exibirLista(Lista *lista){
	if (listavazia(lista)){
		printf("A lista está vazia.\n");
		return;
	}
	printf("Elementos da lista: ");
	for (int i = 0; i< lista->tamanho; i++){
		printf("%d", lista->elementos[i]);
	}
	printf("\n");
}
int encontrarElemento(Lista *lista, int posicao){
	if (posicao<0 || posicao >= lista->tamanho){
		return -1;
	}
	return lista->elementos[posicao];
}

int encontrarPosicao(Lista *lista, int elemento){
	for (int i = 0; i < lista->tamanho; i++){
		if (lista->elementos[i] == elemento){
			return i;
		}
	}
	return -1;
}

int removerElemento(Lista *lista, int posicao){
	if (listavazia(lista) || posicao <0 || posicao >= lista->tamanho){
		return 0;
	}
	for (int i = posicao; i < lista->tamanho -1; i++){
		lista->elementos[i] = lista->elementos[i+1];
	}
	lista->tamanho--;
	
	return 1;
}

int main(){
	Lista lista;
	inicializarLista(&lista);
	
	int opcao, elemento, posicao;
	
	do{
		printf("\nEDITOR DE LISTAS\n");
		printf("1 - Verifica se a lista esta vazia.\n");
		printf("2 - Verifica se a lista esta cheia.\n");
		printf("3 - Informa o tamanho atual da lista.\n");
		printf("4 - Inserir um elemento em uma posicao informada.\n");
		printf("5 - Exibir a lista completa.\n");
		printf("6 - Encontrar o elemento de uma determinada posicao da lista.\n");
		printf("7 - Encontrar a posicao de um determinado elemento da lista.\n");
		printf("8 - Remover um elemento de uma determinada posicao da lista.\n");
		printf("0 - Encerrar editor de listas.\n");
		printf("Digite a sua opcao:");
		scanf("%d", &opcao);
		
		switch (opcao){
			case 1:
				if (listavazia(&lista)){
					printf("A lista esta vazia.\n");
				}else{
					printf("A lista nao esta vazia. \n");
				}
				break;
			case 2:
				if(listaCheia(&lista)){
					printf("A lista esta cheia.\n");
				}else{
					printf("A lista nao esta cheia.\n");
				}
				break;
			case 3:
				printf("Tamanho da lista: %d\n", tamanhoLista(&lista));
				break;
			case 4:
				printf("Digite o elemento a ser inserido: ");
				scanf("%d",&elemento);
				printf("Digita a posicao de insercao: ");
				scanf("%d",&posicao);
				if (inserirElemento(&lista, elemento, posicao)){
					printf("Elemento inserido com sucesso.\n");
				}else{
					printf("Falha na insercao do elemento.\n");
				}
				break;
			case 5:
				exibirLista(&lista);
				break;
			case 6:
				printf("Digite a posicao do elemento a ser encontrado: ");
				scanf("%d",&posicao);
				elemento = encontrarElemento(&lista, posicao);
				if(elemento != -1){
					printf("Elemento encontrado: %d\n", elemento);
				}else{
					printf("posicao invalida.\n");
				}
				break;
			case 7:
				printf("Digite o elemento a ser encontrado: ");
				scanf("%d",&elemento);
				posicao = encontrarPosicao(&lista, elemento);
				if (posicao != -1){
					printf("Posicao do elemento: %d\n",posicao);
				}else{
					printf("Elemento nao encontrado.\n");
				}
				break;
			case 8:
				printf("Digite a posicao do elemento a ser removido: ");
				scanf("%d",&posicao);
				if(removerElemento(&lista, posicao)){
					printf("elemento removido com sucesso.\n");
				}else{
					printf("Falha na remocao do elemento.\n");
				}
				break;
			case 0:
				printf("Encerrando EDITOR DE LISTAS.\n");
				break;
			default:
				printf("Opcao invalida.\n");
		}
		
	}while(opcao!=0);
	
	return 0;
}
