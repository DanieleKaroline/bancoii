#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListaSimples.h"

Lista* adiciona_fim(Lista *primeiro, Att *dado) {
    Lista *novo = malloc(sizeof(Lista)); // Aloca memória para o novo nó
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    novo->dado = dado; // Atribui os dados ao novo nó
    novo->proximo = NULL; // O próximo do novo nó é NULL, pois ele será o último da lista

    if (primeiro == NULL) {
        // Se a lista estiver vazia, o novo nó será o primeiro
        return novo;
    }

    Lista *aux = primeiro;
    while (aux->proximo != NULL) {
        // Percorre a lista até encontrar o último nó
        aux = aux->proximo;
    }

    // O próximo do último nó atual é o novo nó
    aux->proximo = novo;

    return primeiro;
}


void imprimir(Lista *primeiro){
    Lista *aux;
    for(aux = primeiro; aux != NULL; aux = aux->proximo){
        printf("%-*s |", aux->dado->tamanho, aux->dado->nome);
    }
    printf("\n"); // Adiciona uma quebra de linha após imprimir todos os elementos
}

