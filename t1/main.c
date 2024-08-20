#include <stdio.h>
#include "readFile.h"

typedef struct tabela{
    int id;
    char nome_logico[21];
    char nome_fisico[21];
} Tabela;

typedef struct att{
    int id_arquivo_att;
    char nome_att[20];
    char tipo;
    char opcional;
    int tamanho;
} Att;

int readFile(char nomeLog[20]){
    FILE *arq;
    Att att;
    arq = fopen(nomeLog, "rb");
    if (arq == NULL){
        printf("Erro ao abrir arquivo\n");
        return 0;
    }
    while(fread(&att, sizeof(Att), 1, arq)){
        printf("ID: %d\n", att.id_arquivo_att);
        printf("Nome: %s\n", att.nome_att);
        printf("Tipo: %c\n", att.tipo);
        printf("Opcional: %c\n", att.opcional);
        printf("Tamanho: %d\n", att.tamanho);
    }
    fclose(arq);
    return 1;
}

int main(int argc, char *argv[]){
    //char nomeLog[20];
        //Recebendo nome lógico 
    if (argc>1)
    {
        readFile(argv[1]);
        return 0;
    }
    printf("Missing parameter: logical file name\n");
    return 0;
}
