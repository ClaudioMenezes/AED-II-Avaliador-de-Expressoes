typedef struct tree{
    char num;
    struct tree* sad;
    struct tree* sae;
} Tree;

Tree* createTree();

Tree* criaFolha(char num);

Tree* freeTree(Tree* t);

Tree* criaTronco(char item, Tree* sae, Tree* sad);

int treeIsEmpty(Tree* t);

float percorre_avalia(Tree* t);

int verificaFolha(Tree* t);

void insertTree(Tree** t, char num);

void showTreePreFixa(FILE *arquivo_out, Tree* t, int menu_saida);

void showTreePosFixa(FILE *arquivo_out, Tree* t, int menu_saida);
