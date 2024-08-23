#include <stdio.h>
#include <string.h>
#include "table.h"

int entradaTabela(const char* nomeLogico, Tabela* tabela){ //recebe o buffer e o nome lógico da tabela
    FILE* file = fopen("t1/table.dat", "rb"); //leitura binária
    if(file == NULL){
        return 0;
    }
    while(fread(tabela, sizeof(Tabela), 1, file)){ //lê o arquivo e armazena na struct tabela
        if(strcmp(tabela->nome_logico, nomeLogico) == 0){  //compara o nome lógico da tabela com o nome lógico passado
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void printTabela(const char* nomeLogico, Atributo* atts, int n){ //recebe o nome lógico da tabela
    Tabela tabela;
    if(entradaTabela(nomeLogico, &tabela)){
        printf("Tabela: %s\n", tabela.nome_fisico);
        printf("Atributos:\n");
        for(int i = 0; i < n; i++){
            printf("Nome: %s\n", atts[i].nome_att);
            printf("Tipo: %c\n", atts[i].tipo);
            printf("Tamanho: %d\n", atts[i].tamanho);
        }
    }
    else{
        printf("Tabela não encontrada\n");
    }
}