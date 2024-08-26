#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nomeLogico[20];
    char nomeFisico[20];
} entradaTabela;

int leTabela(FILE *file, entradaTabela *entry);
int buscaTabela(const char *nomeLogico, entradaTabela *entry);
