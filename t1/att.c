#include <stdio.h>
#include <stdlib.h>
#include "att.h"

void encontraAtt(int idArquivo, Atributo** atts, int* n){ //recebe o id do arquivo, um ponteiro para um vetor de atributos
    FILE* file = fopen("t1/att.dat", "rb"); //leitura binária
    if(file == NULL){
        return;
    }
    Atributo att;
    while(fread(&att, sizeof(Atributo), 1, file)){ //lê o arquivo e armazena na struct att
        if(att.id_arquivo_att == idArquivo){
            *n += 1;
            *atts = (Atributo*)realloc(*atts, *n * sizeof(Atributo)); //realoca o vetor de atributos
            (*atts)[*n - 1] = att;
        }
    }
    fclose(file);
}