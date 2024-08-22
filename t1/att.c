#include <stdio.h>
#include <stdlib.h>
#include "att.h"

void encontraAtt(int idArquivo, Atributo** atts, int* n){
    FILE* file = fopen("t1/att.dat", "rb");
    if(file == NULL){
        return;
    }
    Atributo att;
    while(fread(&att, sizeof(Atributo), 1, file)){
        if(att.id_arquivo_att == idArquivo){
            *n += 1;
            *atts = (Atributo*)realloc(*atts, *n * sizeof(Atributo));
            (*atts)[*n - 1] = att;
        }
    }
    fclose(file);
}