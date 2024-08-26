#include "Libs/table.h"
#include "Libs/att.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char *nomeLogico = argv[1]; //recebe argumento
    entradaTabela entradaTabela;
    if (!buscaTabela(nomeLogico, &entradaTabela)) {
        fprintf(stderr, "Tabela %s nao encontrada em table.dic\n", nomeLogico); //imprime na saida de erro
        return 1;
    }

    Atributo *atts = NULL;
    int n = 0;

    if (!buscaAtributo(entradaTabela.id, &atts, &n)) {
        fprintf(stderr, "Error reading att.dic\n"); //imprime na saida de erro
        return 1;
    }

    FILE *dataFile = fopen(entradaTabela.nomeFisico, "rb"); //abre arquivo para leitura binaria

    if (dataFile == NULL) {
        perror("Erro para abrir arqivo"); //imprime mensagem de erro
        free(atts);
        return 1;
    }

   
    //print dos dados
    printf("Atributos:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", atts[i].nomeAtributo);
    }
    printf("\n");
    while (1) {
        int bytesRead = 0;
        for (int i = 0; i < n; i++) {
            if (atts[i].tipo == 'S') {
                char str[atts[i].tamanho + 1]; //se tipo for string, aloca tamanho + 1 
                bytesRead = fread(str, 1, atts[i].tamanho, dataFile); //le o tamanho do atributo
                if (bytesRead != atts[i].tamanho){
                    break;
                }  //se não leu o tamanho correto, sai do loop
                str[atts[i].tamanho] = '\0'; //adiciona \0 no final da string
                printf("%s ", str);
            } else if (atts[i].tipo == 'I') {
                int value;
                bytesRead = fread(&value, sizeof(int), 1, dataFile); 
                if (bytesRead != 1) break;
                printf("%d ", value);
            } else if (atts[i].tipo == 'D') {
                double value;
                bytesRead = fread(&value, sizeof(double), 1, dataFile);
                if (bytesRead != 1) break;
                printf("%lf ", value);
            }
        }
        if (bytesRead == 0) break; //se não leu nada, sai do loop
        printf("\n");
    }

    fclose(dataFile);
    free(atts); //libera memoria
    return 0;
}