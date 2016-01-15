typedef struct no2{
    Tree* elem;
    struct no2 *prox2;
} tipoNO2;

typedef struct{
    tipoNO2 *topo2;
} tipoPilha2;

void criar2(tipoPilha2 *pilha);

int vazia2(tipoPilha2 *pilha);

void inserir2(tipoPilha2 *pilha, Tree* elem);

int remover2(tipoPilha2 *pilha);

Tree* topoPilha2(tipoPilha2 *pilha);
