#include <stdio.h>
#include <stdbool.h>

// Definição da estrutura dicionário
struct dicionario {
    char palavra[20];
    char definicao[50];
};

// Função que compara duas strings
bool compararStrings(const char palavra1[], const char palavra2[]) {
    int i = 0;
    
    while (palavra1[i] == palavra2[i] && palavra1[i] != '\0' && palavra2[i] != '\0') {
        i++;
    }
    
    if (palavra1[i] == '\0' && palavra2[i] == '\0') {
        return true;    
    } else {
        return false;
    }
}

// Função que procura uma palavra no dicionário
int procurarStrings(const struct dicionario lingua[], const char procurar[], const int numDePalavras) {
    int i = 0;
    
    // Laço de busca
    while (i < numDePalavras) {
        if (compararStrings(procurar, lingua[i].palavra)) {
            return i;  // Palavra encontrada
        }
        i++;  // Incrementa o índice para continuar a busca
    }
    
    return -1;  // Palavra não encontrada
}

int main(void) {
    const int NUMERODEDEFINICOES = 7;
    char palavra[20] = {'\0'};
    int resultadoPesquisa;
    
    // Dicionário com as palavras e suas definições
    const struct dicionario portugues[7] = {
        {"pao", "Comida de farinha"},
        {"mortadela", "Comida de carne"},
        {"feijao", "Comida brasileira"},
        {"tropero", "Tipo de feijão"},
        {"queijo", "De minas"},
        {"macarronada", "Típico de vó"},
        {"pizza", "Típico da Itália"}
    };
    
    // Entrada do usuário
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    // Procura a palavra no dicionário
    resultadoPesquisa = procurarStrings(portugues, palavra, NUMERODEDEFINICOES);
    
    // Verifica o resultado da pesquisa
    if (resultadoPesquisa != -1) {
        printf("%s\n", portugues[resultadoPesquisa].definicao);
    } else {
        printf("Palavra não encontrada!\n");
    }
    
    getchar();  // Para consumir o caractere de nova linha que fica no buffer após a entrada
    return 0;
}
