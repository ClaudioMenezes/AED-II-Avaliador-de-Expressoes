#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_binaria.h"
#include "pilha_arvore.h"

/*
    TAD PILHA TRADUZIDO DA LINGUAGEM PASCAL PARA LINGUAGEM C, QUE FOI CONSTRUÍDO EM AED 1
    E ADAPTADO PARA RECEBER UM ELEMENTO DO TIPO ÁRVORE
*/

void criar2(tipoPilha2 *pilha){
    pilha->topo2 = NULL;
}

int vazia2(tipoPilha2 *pilha){
    if (pilha->topo2==NULL)
        return 1;
    else
        return 0;
}

void inserir2(tipoPilha2 *pilha, Tree* elem){
    tipoNO2 *novo_noh;
    
    novo_noh = (tipoNO2 *) malloc( sizeof(tipoNO2));
    
    novo_noh->elem = elem;
    
    novo_noh->prox2 = pilha->topo2;
    
    pilha->topo2 = novo_noh;
}

int remover2(tipoPilha2 *pilha){
    tipoNO2 *aux;
    
    if (!vazia2(pilha)){
        aux = pilha->topo2;
        pilha->topo2 = pilha->topo2->prox2;
        free(aux);
        return 1;
    }
    
    else{
        puts("Pilha vazia!");
        return 0;
    }
}

Tree* topoPilha2(tipoPilha2 *pilha){
    return pilha->topo2->elem;
}   
