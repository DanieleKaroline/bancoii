#include "att.h"

int leAtributo(FILE *file, Atributo *entry) {
    return fread(entry, sizeof(Atributo), 1, file) == 1;
}

int buscaAtributo(int idArquivo, Atributo **atts, int *n) {
    FILE *file = fopen("att.dic", "rb");
    if (file == NULL) {
        perror("Error opening att.dic");
        return 0;
    }

    Atributo entry;
    while (leAtributo(file, &entry)) {
        if (entry.idArquivo == idArquivo) {
            *n += 1;
            *atts = (Atributo *)realloc(*atts, *n * sizeof(Atributo));
            (*atts)[*n - 1] = entry;
        }
    }

    fclose(file);
    return 1;
}