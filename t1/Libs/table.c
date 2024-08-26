#include "table.h"

int leTabela(FILE *file, entradaTabela *entry) {
    return fread(entry, sizeof(entradaTabela), 1, file) == 1;
}

int buscaTabela(const char *nomeLogico, entradaTabela *entry) {
    FILE *file = fopen("table.dic", "rb");
    if (file == NULL) {
        perror("Error opening table.dic"); //perror imprime mensagem de erro
        return 0;
    }

    while (leTabela(file, entry)) {
        if (strcmp(entry->nomeLogico, nomeLogico) == 0) { //compara strings
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

