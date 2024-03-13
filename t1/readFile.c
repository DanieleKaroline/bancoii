#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 64 

typedef struct Atributo
{
    int id;
    char nome[20];
    char tipo;
    int opcional;
    int tamanho;
};

//const char: ponteiros para constantes do tipo char
char *busca_nome(const char *nome_logico, const char *arquivo_dic){
    //abre o arquivo para leitura
    FILE *arquivo = fopen(arquivo_dic, "r");
    //se der algum pau, cai em erro
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo de dicionário");
        return NULL;
    }

    char *nome_fisico = NULL;

    char linha[MAX_LINE_SIZE];    
    
    //fgets pra ler uma linha do arquivo.
    //verifica se a função fgets foi capaz de ler uma linha do arquivo com sucesso. Se a função retornar NULL, significa que não há mais linhas para ler e o loop é encerrado
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        //fazer mágica aqui
        }
    }

    fclose(arquivo);
    return nome_fisico;
}