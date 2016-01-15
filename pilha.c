#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

/*
	TAD PILHA TRADUZIDO DA LINGUAGEM PASCAL PARA LINGUAGEM C, QUE FOI CONSTRUÍDO EM AED 1	
*/

void criar(tipoPilha *pilha){
    pilha->topo = NULL;
}

int vazia(tipoPilha *pilha){
    if (pilha->topo==NULL)
        return 1;
    else
        return 0;
}

void inserir(tipoPilha *pilha, char elem){
    tipoNO *novo_noh;
    
    novo_noh = (tipoNO *) malloc( sizeof(tipoNO));
    
    novo_noh->elem = elem;
    
    novo_noh->prox = pilha->topo;
    
    pilha->topo = novo_noh;
}

int remover(tipoPilha *pilha){
    tipoNO *aux;
    
    if (!vazia(pilha)){
        aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(aux);
        return 1;
    }
    
    else{
        puts("Pilha vazia!");
        return 0;
    }
}

char topoPilha(tipoPilha *pilha){
    return pilha->topo->elem;
}   
