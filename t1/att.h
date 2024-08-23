#ifndef ATRIBUTO_H
#define ATRIBUTO_H

struct att{
    int id_arquivo_att;
    char nome_att[20];
    char tipo;
    int tamanho;
}; typedef struct att Atributo;

int readFile(char nomeLog[20]);
void encontraAtt(int idArquivo, Atributo** atts, int* n);

#endif