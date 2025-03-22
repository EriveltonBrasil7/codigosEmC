#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista encadeada
typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

// Função para criar um novo nó
Node* criarNo(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo != NULL) {
        novo->valor = valor;
        novo->proximo = NULL;
    }
    return novo;
}

// Verificar se a lista está vazia
int listaVazia(Node* inicio) {
    return inicio == NULL;
}

// Verificar se a lista está cheia (checagem de memória)
int listaCheia() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
        return 1;
    free(temp);
    return 0;
}

// Retornar o tamanho da lista
int tamanhoLista(Node* inicio) {
    int contador = 0;
    while (inicio != NULL) {
        contador++;
        inicio = inicio->proximo;
    }
    return contador;
}

// Inserir elemento em posição informada
Node* inserirElemento(Node* inicio, int valor, int posicao) {
    Node* novo = criarNo(valor);
    if (!novo) {
        printf("Erro de alocacao de memoria!\n");
        return inicio;
    }

    if (posicao == 0) {
        novo->proximo = inicio;
        return novo;
    }

    Node* atual = inicio;
    int contador = 0;

    while (atual != NULL && contador < posicao - 1) {
        atual = atual->proximo;
        contador++;
    }

    if (atual == NULL) {
        printf("posicao invalida.\n");
        free(novo);
    } else {
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    return inicio;
}

// Exibir lista completa
void exibirLista(Node* inicio) {
    if (listaVazia(inicio)) {
        printf("A lista esta vazia.\n");
        return;
    }

    Node* atual = inicio;
    int pos = 0;
    while (atual != NULL) {
        printf("posicao %d: %d\n", pos, atual->valor);
        atual = atual->proximo;
        pos++;
    }
}

// Encontrar elemento por posicao
void encontrarElementoPorPosicao(Node* inicio, int posicao) {
    int contador = 0;
    while (inicio != NULL && contador < posicao) {
        inicio = inicio->proximo;
        contador++;
    }

    if (inicio != NULL)
        printf("Elemento na posicao %d: %d\n", posicao, inicio->valor);
    else
        printf("posicao invalida.\n");
}

// Encontrar posicao de um elemento
void encontrarPosicaoDoElemento(Node* inicio, int valor) {
    int posicao = 0;
    while (inicio != NULL) {
        if (inicio->valor == valor) {
            printf("Elemento %d encontrado na posicao %d.\n", valor, posicao);
            return;
        }
        inicio = inicio->proximo;
        posicao++;
    }
    printf("Elemento %d nao encontrado na lista.\n", valor);
}

// Remover elemento por posicao
Node* removerElemento(Node* inicio, int posicao) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    Node* temp;
    if (posicao == 0) {
        temp = inicio;
        inicio = inicio->proximo;
        free(temp);
        return inicio;
    }

    Node* atual = inicio;
    int contador = 0;
    while (atual->proximo != NULL && contador < posicao - 1) {
        atual = atual->proximo;
        contador++;
    }

    if (atual->proximo == NULL) {
        printf("posicao invalida.\n");
        return inicio;
    }

    temp = atual->proximo;
    atual->proximo = temp->proximo;
    free(temp);

    return inicio;
}

// Função principal com menu
int main() {
    Node* lista = NULL;
    int opcao, valor, posicao;

    do {
        printf("\nEDITOR DE LISTAS\n");
        printf("1 VERIFICAR SE A LISTA esta VAZIA.\n");
        printf("2 VERIFICAR SE A LISTA esta CHEIA.\n");
        printf("3 INFORMAR O TAMANHO ATUAL DA LISTA.\n");
        printf("4 INSERIR UM ELEMENTO EM UMA posicao INFORMADA.\n");
        printf("5 EXIBIR A LISTA COMPLETA\n");
        printf("6 ENCONTRAR O ELEMENTO DE UMA DETERMINADA posicao DA LISTA.\n");
        printf("7 ENCONTRAR A posicao DE UM DETERMINADO ELEMENTO DA LISTA\n");
        printf("8 REMOVER UM ELEMENTO DE UMA DETERMINADA posicao DA LISTA.\n");
        printf("0 ENCERRAR EDITOR DE LISTAS.\n");
        printf("DIGITE SUA OPCAO: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (listaVazia(lista))
                    printf("A lista esta vazia.\n");
                else
                    printf("A lista nao esta vazia.\n");
                break;
            case 2:
                if (listaCheia())
                    printf("A lista esta cheia (sem memoria disponivel).\n");
                else
                    printf("A lista nao esta cheia.\n");
                break;
            case 3:
                printf("Tamanho atual da lista: %d\n", tamanhoLista(lista));
                break;
            case 4:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posicao onde deseja inserir: ");
                scanf("%d", &posicao);
                lista = inserirElemento(lista, valor, posicao);
                break;
            case 5:
                exibirLista(lista);
                break;
            case 6:
                printf("Digite a posicao a ser buscada: ");
                scanf("%d", &posicao);
                encontrarElementoPorPosicao(lista, posicao);
                break;
            case 7:
                printf("Digite o valor do elemento a ser buscado: ");
                scanf("%d", &valor);
                encontrarPosicaoDoElemento(lista, valor);
                break;
            case 8:
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                lista = removerElemento(lista, posicao);
                break;
            case 0:
                printf("Encerrando editor de listas...\n");
                break;
            default:
                printf("OPCAO invalida!\n");
        }
    } while (opcao != 0);

    // Liberar memoria
    Node* atual = lista;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
