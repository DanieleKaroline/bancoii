#include "att.h"

int leAtributo(FILE *file, Atributo *entry) {
    return fread(entry, sizeof(Atributo), 1, file) == 1; //le um atributo do arquivo e armazena em entry
}

int buscaAtributo(int idArquivo, Atributo **atts, int *n) {
    FILE *file = fopen("att.dic", "rb");
    if (file == NULL) {
        perror("Error opening att.dic"); //perror imprime mensagem de erro
        return 0;
    }

    Atributo entry;
    while (leAtributo(file, &entry)) {
        if (entry.idArquivo == idArquivo) { //compara idArquivo
            *n += 1; //incrementa n que é o numero de atributos
            *atts = (Atributo *)realloc(*atts, *n * sizeof(Atributo)); //realoca memoria para o vetor de atributos
            (*atts)[*n - 1] = entry; //armazena o atributo no vetor e *n-1 porque o vetor começa em 0
        }
    }

    fclose(file);
    return 1;
}