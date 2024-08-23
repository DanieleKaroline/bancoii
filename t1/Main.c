#include "table.h"
#include "att.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <nome_logico>\n", argv[0]);
        return 1;
    }

    char *nomeLogico = argv[1];
    entradaTabela entradaTabela;
    if (!buscaTabela(nomeLogico, &entradaTabela)) {
        fprintf(stderr, "Table %s not found in table.dic\n", nomeLogico);
        return 1;
    }

    Atributo *atts = NULL;
    int n = 0;
    if (!buscaAtributo(entradaTabela.id, &atts, &n)) {
        fprintf(stderr, "Error reading att.dic\n");
        return 1;
    }

    FILE *dataFile = fopen(entradaTabela.nomeFisico, "rb");
    if (dataFile == NULL) {
        perror("Error opening data file");
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
                char str[atts[i].tamanho + 1];
                bytesRead = fread(str, 1, atts[i].tamanho, dataFile);
                if (bytesRead != atts[i].tamanho) break;
                str[atts[i].tamanho] = '\0'; 
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
        if (bytesRead == 0) break; // Se não leu nada, sai do loop
        printf("\n");
    }

    fclose(dataFile);
    free(atts);
    return 0;
}