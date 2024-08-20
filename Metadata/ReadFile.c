#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSimples.h"

struct table {
    int id;
    char nome[20];
    char arquivo[20];
} typedef Table;


//FASE 1: OBTER AS INFORMAÇÕES DE table.dic
Table read_table(char *argv){
    FILE *f;

    Table *arq = malloc(sizeof(Table));

    f = fopen("table.dic", "r");

    if (f == NULL){
        printf("File does not exist!");
         
    }

    //Loop para encontrar a tabela desejada
    do {
        fread(arq, sizeof(Table), 1, f);
    } while (strcmp(arq->nome, argv) != 0 && !feof(f));

    if (feof(f)){
        printf("Arquivo nao encontrado\n");
        fclose(f);

    }

    fclose(f);
    return *arq;
}