struct att{
    int id;
    char nome[20];
    char tipo;
    char opcional;
    int tamanho;
} typedef Att;

struct lista{
    Att *dado;
    struct lista *proximo;
};
typedef struct lista Lista;

Lista* adiciona_fim(Lista *, Att *);

void imprimir(Lista *);

