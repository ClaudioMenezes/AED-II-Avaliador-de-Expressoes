/* 

O TAD BÁSICO DE ÁRVOREDS FOI OBTIDO A PARTIR DO SITE ABAIXO

COMO AS FUNÇÕES CRIAR, VAZIA, INSERE E IMPRIME

www.GeeksBR.com

*/

/* Implementação de árvore binária */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "arvore_binaria.h"

/* Cada nó armazena três informações:
 nesse caso um número (num),
 ponteiro para subárvore à direita (sad)
 e ponteiro para subárvore à esquerda (sae).*/

/* A estrutura da árvore é representada por um ponteiro
 para o nó raiz. Com esse ponteiro, temos acesso aos
 demais nós. */

/* Função que cria uma árvore */

Tree* createTree(){

    /* Uma árvore é representada pelo endereço do nó raiz,
    essa função cria uma árvore com nenhum elemento,
    ou seja, cria uma árvore vazia, por isso retorna NULL. */

    return NULL;
}

/*
	CRIA UMA FOLHA, OU SEJA, UM NÓ RAIZ RECEBENDO UM CHAR E O NÓ A ESQUERDA E DIREITA APONTANDO PARA NULO.
 */

Tree* criaFolha(char num){

    Tree* folha = createTree();
    *(&folha) = (Tree*)malloc(sizeof(Tree));
    (*(&folha))->sae = NULL; /* Subárvore à esquerda é NULL */
    (*(&folha))->sad = NULL; /* Subárvore à direita é NULL */
    (*(&folha))->num = num; /* Armazena a informação */

    return folha;
}

/*
	FAZ A JUNÇÃO ENTRE OS OPERANDOS DA PILHA DE OPERANDO, COM O NÓ RAIZ LIDO, QUE É UM OPERADOR,
	RETORNANDO A NOVA ÁRVORE COM O NÓ OPERADOR, E AS FOLHAS OPERANDOS.
 */

Tree* criaTronco(char num, Tree* sae, Tree* sad){

    Tree* tronco = createTree();
    *(&tronco) = (Tree*) malloc(sizeof(Tree)); /* aloca uma estrutura do tipo Arv, e retorna o ponteiro dela para elem */
    (*(&tronco))->num = num; /*o item da arvore criada recebe o item passado por parametro */
    (*(&tronco))->sae = sae; /* o sae da arvore criada recebe o sae passado por parametro */
    (*(&tronco))->sad = sad; /* o sad da arvore criada recebe o sad passado por parametro */

    return tronco; /* retorna o ponteiro para o a estrutra criada */
}

/* Função que verifica se uma árvore é vazia */

int treeIsEmpty(Tree* t){
    /* Retorna 1 se a árvore for vazia e 0 caso contrário */
    return t == NULL; 
}

/* SE FOR VAZIA A ESQUERDA E VAZIA A DIREITA, É FOLHA, RETORNE 1 */

int verificaFolha(Tree* t){
    
    if (treeIsEmpty(t->sae) && treeIsEmpty(t->sad)){
        return 1;
    }
    
    else
        return 0;
}

/* 
	A FUNÇÃO PERCORRE ARQUIVO VAI DE NÓ A NÓ RECURSIVAMENTE ATÉ QUE ENCONTRE UM NÓ FOLHA
	QUANDO ENCONTRA RETORNA UM INTEIRO PERTENCENTE A FOLHA DA ÁRVORE.

	SE O NÓ FOR RAIZ, OU SEJA, UM OPERADOR, A FUNÇÃO REALIZA O SEU RESPECTIVO CASO (+,-,*,/)
	E GUARDA O RESULTADO NA VARIÁVEL resultado_inteiro.

	CRÉDITOS AO PROFESSOR DIEGO, QUE NOS AJUDOU COM A RECURSÃO
*/

float percorre_avalia(Tree* t){
    /* Essa função imprime os elementos de forma recursiva */

    float operando1_inteiro = 0, operando2_inteiro = 0, resultado_inteiro = 0;
    
    if(!treeIsEmpty(t)) /* se a árvore não for vazia... */
	{		

		/* verifica se o nó é folha */

		if (verificaFolha(t)){
			return atoi(&t->num);
		}

		else{
		  	
			operando1_inteiro = percorre_avalia(t->sae); /* mostra a sae (subárvore à esquerda) */
		    operando2_inteiro = percorre_avalia(t->sad); /* mostra a sad (subárvore à direita) */

		    switch (t->num){
		    	case '+':
		    			resultado_inteiro = operando1_inteiro + operando2_inteiro;
		    		break;

		    	case '-' :
		    			resultado_inteiro = operando1_inteiro - operando2_inteiro;
		    		break;

		    	case '*' :
		    			resultado_inteiro = operando1_inteiro * operando2_inteiro;
		    		break;

		    	case '/' :
		    			resultado_inteiro = operando2_inteiro / operando1_inteiro;
		    		break;

		    	default : break;
    		}

    	}

    }

    return resultado_inteiro;

}

/* Função que mostra a informação da árvore */

void showTreePreFixa(FILE *arquivo_out, Tree* t, int menu_saida){
    /* Essa função imprime os elementos de forma recursiva */
    
    if(!treeIsEmpty(t)) /* se a árvore não for vazia... */
    {
        /* Mostra os elementos em pré-ordem */
        switch (menu_saida){
        	case 0 : 
        		printf("%c ", t->num); /* mostra a raiz */
		        showTreePreFixa(arquivo_out, t->sae, menu_saida); /* mostra a sae (subárvore à esquerda) */
		        showTreePreFixa(arquivo_out, t->sad, menu_saida); /* mostra a sad (subárvore à direita) */
        		break;

        	case 1 :
        		fprintf(arquivo_out, "%s ", &t->num); /* mostra a raiz */
		        showTreePreFixa(arquivo_out, t->sae, menu_saida); /* mostra a sae (subárvore à esquerda) */
		        showTreePreFixa(arquivo_out, t->sad, menu_saida); /* mostra a sad (subárvore à direita) */
        		break;
        }
    }
}

void showTreePosFixa(FILE *arquivo_out, Tree* t, int menu_saida){
    /* Essa função imprime os elementos de forma recursiva */
    if(!treeIsEmpty(t)) /* se a árvore não for vazia... */
    {
        /* Mostra os elementos em pré-ordem */
        switch (menu_saida){
        	case 0 : 
        		showTreePosFixa(arquivo_out, t->sae, menu_saida); /* mostra a sae (subárvore à esquerda) */
		        showTreePreFixa(arquivo_out, t->sad, menu_saida); /* mostra a sad (subárvore à direita) */
        		printf("%c ", t->num); /* mostra a raiz */
        		break;

        	case 1 :
		        showTreePosFixa(arquivo_out, t->sae, menu_saida); /* mostra a sae (subárvore à esquerda) */
		        showTreePosFixa(arquivo_out, t->sad, menu_saida); /* mostra a sad (subárvore à direita) */
        		fprintf(arquivo_out, "%s ", &t->num); /* mostra a raiz */
        		break;
        }
    }
}

/* Função que insere um dado na árvore */
void insertTree(Tree** t, char num){
    /* Essa função insere os elementos de forma recursiva */
    if(*t == NULL)
    {
        *t = (Tree*)malloc(sizeof(Tree)); /* Aloca memória para a estrutura */
        (*t)->sae = NULL; /* Subárvore à esquerda é NULL */
        (*t)->sad = NULL; /* Subárvore à direita é NULL */
        (*t)->num = num; /* Armazena a informação */
    } else {
        if(num <= (*t)->num) /* Se o número for menor então vai pra esquerda */
        {
            /* Percorre pela subárvore à esquerda */
            insertTree(&(*t)->sae, num);
        }
        if(num > (*t)->num) /* Se o número for maior então vai pra direita */
        {
            /* Percorre pela subárvore à direita */
            insertTree(&(*t)->sad, num);
        }
    }
}

/* Função para liberar a memória alocada pela árvore */

Tree* freeTree(Tree* t){

    /* Essa função também usa implementação recursiva */

    if(!treeIsEmpty(t)) /* se a árvore não for vazia... */
    {
        /* Tem que liberar as subárvores primeiro para que o acesso
         não seja perdido. */

        freeTree(t->sae); /* libera a subárvore à esquerda */
        freeTree(t->sad); /* libera a subárvore à direita */
        free(t); /* libera a raiz */
    }
    
    /* Retorna uma árvore vazia, ou seja, NULL */
    
    return NULL;
}
