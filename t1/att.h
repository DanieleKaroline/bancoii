#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int idArquivo;
    char nomeAtributo[20];
    char tipo;
    char opcionalidade;
    int tamanho;
} Atributo;

int leAtributo(FILE *file, Atributo *entry);
int buscaAtributo(int idArquivo, Atributo **atts, int *n);
