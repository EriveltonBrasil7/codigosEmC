#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10  // Define o tamanho máximo da lista

typedef struct {
    int elementos[MAX];
    int tamanho;
} Lista;

// Função para verificar se a lista está vazia
int listaVazia(Lista* lista) {
    return lista->tamanho == 0;
}

// Função para verificar se a lista está cheia
int listaCheia(Lista* lista) {
    return lista->tamanho == MAX;
}

// Função para informar o tamanho atual da lista
int tamanhoLista(Lista* lista) {
    return lista->tamanho;
}

// Função para inserir um elemento em uma posição informada
void inserirElemento(Lista* lista, int elemento, int posicao) {
    if (listaCheia(lista)) {
        printf("Lista cheia! Não é possível inserir elementos.\n");
    } else if (posicao < 0 || posicao > lista->tamanho) {
        printf("Posição inválida! Insira uma posição entre 0 e %d.\n", lista->tamanho);
    } else {
        for (int i = lista->tamanho; i > posicao; i--) {
            lista->elementos[i] = lista->elementos[i - 1];
        }
        lista->elementos[posicao] = elemento;
        lista->tamanho++;
        printf("Elemento inserido com sucesso!\n");
    }
}

// Função para exibir a lista completa
void exibirLista(Lista* lista) {
    if (listaVazia(lista)) {
        printf("Lista vazia!\n");
    } else {
        printf("Elementos da lista: ");
        for (int i = 0; i < lista->tamanho; i++) {
            printf("%d ", lista->elementos[i]);
        }
        printf("\n");
    }
}

// Função para encontrar o elemento de uma determinada posição da lista
void encontrarElemento(Lista* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posição inválida!\n");
    } else {
        printf("Elemento na posição %d: %d\n", posicao, lista->elementos[posicao]);
    }
}

// Função para encontrar a posição de um determinado elemento da lista
void encontrarPosicao(Lista* lista, int elemento) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == elemento) {
            printf("Elemento %d encontrado na posição %d.\n", elemento, i);
            return;
        }
    }
    printf("Elemento não encontrado!\n");
}

// Função para remover um elemento de uma determinada posição da lista
void removerElemento(Lista* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posição inválida!\n");
    } else {
        for (int i = posicao; i < lista->tamanho - 1; i++) {
            lista->elementos[i] = lista->elementos[i + 1];
        }
        lista->tamanho--;
        printf("Elemento na posição %d removido com sucesso!\n", posicao);
    }
}

int main() {
    Lista lista;
    lista.tamanho = 0;

    int opcao, elemento, posicao;

    do {
        // Menu com acentuação em português
        printf("\nEDITOR DE LISTAS\n");
        printf("1 – VERIFICAR SE A LISTA ESTÁ VAZIA.\n");
        printf("2 – VERIFICAR SE A LISTA ESTÁ CHEIA.\n");
        printf("3 – INFORMAR O TAMANHO ATUAL DA LISTA.\n");
        printf("4 – INSERIR UM ELEMENTO EM UMA POSIÇÃO INFORMADA.\n");
        printf("5 – EXIBIR A LISTA COMPLETA.\n");
        printf("6 – ENCONTRAR O ELEMENTO DE UMA DETERMINADA POSIÇÃO DA LISTA.\n");
        printf("7 – ENCONTRAR A POSIÇÃO DE UM DETERMINADO ELEMENTO DA LISTA.\n");
        printf("8 – REMOVER UM ELEMENTO DE UMA DETERMINADA POSIÇÃO DA LISTA.\n");
        printf("0 – ENCERRAR EDITOR DE LISTAS.\n");
        printf("DIGITE SUA OPÇÃO: ");  // Aqui "opção" com acento
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (listaVazia(&lista)) {
                    printf("A lista está vazia.\n");
                } else {
                    printf("A lista não está vazia.\n");
                }
                break;

            case 2:
                if (listaCheia(&lista)) {
                    printf("A lista está cheia.\n");
                } else {
                    printf("A lista não está cheia.\n");
                }
                break;

            case 3:
                printf("Tamanho atual da lista: %d\n", tamanhoLista(&lista));
                break;

            case 4:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                printf("Digite a posição para inserção (0 a %d): ", lista.tamanho);
                scanf("%d", &posicao);
                inserirElemento(&lista, elemento, posicao);
                break;

            case 5:
                exibirLista(&lista);
                break;

            case 6:
                printf("Digite a posição do elemento a ser encontrado: ");
                scanf("%d", &posicao);
                encontrarElemento(&lista, posicao);
                break;

            case 7:
                printf("Digite o elemento para encontrar sua posição: ");
                scanf("%d", &elemento);
                encontrarPosicao(&lista, elemento);
                break;

            case 8:
                printf("Digite a posição do elemento a ser removido: ");
                scanf("%d", &posicao);
                removerElemento(&lista, posicao);
                break;

            case 0:
                printf("Encerrando o Editor de Listas...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
