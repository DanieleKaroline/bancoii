#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listasimples.h"

struct table {
    int id;
    char nome[20];
    char arquivo[20];
} typedef Table;

int main(int argc, char *argv[]) {
    char *argumento = argv[1];

    FILE *f;

    //FASE 1: OBTER AS INFORMAÇÕES DE table.dic
    Table *arq = malloc(sizeof(Table));

    f = fopen("table.dic", "r");

    if (f == NULL){
        printf("File does not exist!");
        return 0;
    }

    //Loop para encontrar a tabela desejada
    do {
        fread(arq, sizeof(Table), 1, f);
    } while (strcmp(arq->nome, argumento) != 0 && !feof(f));

    if (feof(f)){
        printf("Arquivo nao encontrado\n");
        fclose(f);
        return 1;
    }

    fclose(f);

    //FASE 2: MONTAR LISTA COM AS COLUNAS DA TABELA
    f = fopen("att.dic", "r");

    Lista *primeiro = NULL;
    Att *att;

    // Aloca a memoria e adiciona a coluna a lista caso pertenca ao id correspondente
    do {
        att = malloc(sizeof(Att));
        fread(att, sizeof(Att), 1, f);
        if (att->id == arq->id){
            primeiro = adiciona_fim(primeiro, att);
        }
    } while (!feof(f));

    // Imprime o cabeçalho
    imprimir(primeiro);
    fclose(f);
    

    // FASE 3: IMPRIMIR DADOS
    f = fopen(arq->arquivo, "r");

    if (f == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Imprime os dados da tabela
    while (1) {
        Lista *aux = primeiro;

        // Itera sobre os atributos
        while (aux != NULL) {
            char *valor = malloc(aux->dado->tamanho);

            // Verifica se a leitura foi bem-sucedida
            if (fread(valor, aux->dado->tamanho, 1, f) != 1) {
                free(valor);
                break;
            }

            // Imprime seguindo o tipo especificado
            switch (aux->dado->tipo) {
                case 'S':
                    printf("%-*s |", aux->dado->tamanho, valor);
                    break;
                case 'I':
                    printf("%d |", *(int *)valor);
                    break;
                case 'D':
                    printf("%lf |", *(double *)valor);
                    break;
                default:
                    printf("Tipo de dado desconhecido: %c\n", aux->dado->tipo);
            }

            free(valor);

            aux = aux->proximo;
        }

        // Como fread retorna erro na ultima iteracao, feof é capaz de identificar o final do arquivo como esperado
        if (feof(f)) {
            break;
        }

        printf("\n");
    }

    return 0;
}