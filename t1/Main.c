#include <stdio.h>
#include "table.h"
#include "att.h"

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
