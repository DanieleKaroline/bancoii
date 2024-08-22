#include "att.h"
#ifndef TABELA_H
#define TABELA_H

typedef struct {
    int id;
    char nome_logico[21];
    char nome_fisico[21];
} Tabela;


int entradaTabela(const char* nomeLogico, Tabela* tabela);
void printTabela(const char* nomeLogico, Atributo* atts, int n);

#endif