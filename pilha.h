typedef struct no{
    char elem;
    struct no *prox;
} tipoNO;

typedef struct{
    tipoNO *topo;
} tipoPilha;

void criar(tipoPilha *pilha);

int vazia(tipoPilha *pilha);

void inserir(tipoPilha *pilha, char elem);

int remover(tipoPilha *pilha);

void libera (tipoPilha *pilha);

char topoPilha(tipoPilha *pilha);
