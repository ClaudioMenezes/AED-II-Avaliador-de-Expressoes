#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "funcoes.h"
#include "arvore_binaria.h"
#include "pilha_arvore.h"

/*
	RECEBE A EXPRESSÃO VAZIA E RETORNA A EXPRESSÃO DIGITADA PELO USUÁRIO POR REFERÊNCIA
*/

char expressao_via_console(char *expressao){
    
    setbuf(stdin, NULL);
    fgets(expressao, 256, stdin);
    
    return *expressao;
}

/*
	RECEBE A EXPRESSÃO VAZIA E RETORNA AS EXPRESSÃO ENCONTRADAS NO entrada.txt
	E EXECUTA A FUNÇÃO separa_string.
*/

void expressao_via_arquivo(char *expressao, int menu_saida){
        
    FILE *arquivo_in;
    
    arquivo_in = fopen("entrada.txt","r");
    
    while (!feof(arquivo_in)){
        fgets (expressao, 256, arquivo_in);
        separa_string(expressao, menu_saida);
    }

    fclose(arquivo_in);
}

/*
	A FUNÇÃO separa_string RECEBE A EXPRESSÃO, E A OPÇÃO DE SAÍDA DO USUÁRIO
	NELA SÃO CHAMADAS FUNÇÕES COMO: criaTronco, percorre_avalia, CRIAR INSERIR E REMOVER EM PILHAS, INSERIR EM
	PILHAS DE ÁRVORE, CRIAR E INSERIR ELEMENTOS EM ÁRVORES.

	É A FUNÇÃO QUE TRATA A EXPRESSÃO PARA QUE ELA SEJA INSERIDA NA ÁRVORE DE FORMA CORRETA, RESPEITANDO AS PRECEDÊNCIAS
	E RETORNA AS IMPRESSÕES NO CONSOLE, OU EM ARQUIVO. 
*/

void separa_string(char *expressao, int menu_saida){

	FILE *arquivo_out;

    Tree* arvore_aux = createTree();
    Tree* arvore_aux2 = createTree();
    
    int i = 0;
    char topoAux;
    
    tipoPilha2 p_operando; /* Criando pilha */
    tipoPilha p_operador; /* Criando pilha */
    tipoPilha p_aux;

    criar2(&p_operando);
    criar(&p_operador);
    criar(&p_aux);
 
    /* Le expressão e insere na pilha operando */
    
    while ((strcmp(&expressao[i], "") > 0)) {

        if ((strcmp(&expressao[i], " ") > 0) && (strcmp(&expressao[i], "+") > 0) && (strcmp(&expressao[i], "-") > 0) &&
            (strcmp(&expressao[i], "*") > 0) && (strncmp(&expressao[i], "/", 1) > 0) && (strcmp(&expressao[i], "(") > 0) &&
            (strcmp(&expressao[i], ")") > 0)){
            inserir2(&p_operando, criaFolha(expressao[i]));

	        if(!vazia(&p_operador)){

		        switch (topoPilha(&p_operador)){
		            	
		            	case('*') : arvore_aux = p_operando.topo2->elem;
					                remover2(&p_operando);
					                arvore_aux2 = criaTronco(p_operador.topo->elem, arvore_aux, p_operando.topo2->elem);
					                remover2(&p_operando);
					                remover(&p_operador);
					                inserir2(&p_operando, arvore_aux2);
					                break;

					    case('/') : arvore_aux = p_operando.topo2->elem;
					                remover2(&p_operando);
					                arvore_aux2 = criaTronco(p_operador.topo->elem, arvore_aux, p_operando.topo2->elem);
					                remover2(&p_operando);
					                remover(&p_operador);
					                inserir2(&p_operando, arvore_aux2);
					                break;

					    default: break;

		        }
		    }

    	}

        /* Le expressão e insere na pilha operador */
        
        else if ((strncmp(&expressao[i], " ", 1) > 0)){
        
           	if ((strncmp(&expressao[i], ")", 1) > 0) || (strncmp(&expressao[i], "(", 1) == 0)) {
           		inserir(&p_operador, expressao[i]);
           	}

           	else {

           		topoAux = topoPilha(&p_operador);

           		if ((strncmp(&expressao[i], ")", 1) > 0) || (strncmp(&topoAux, "(", 1) == 0)){
           			remover(&p_operador);
           		}

           		else{

					arvore_aux = p_operando.topo2->elem;
					remover2(&p_operando);
					arvore_aux2 = criaTronco(p_operador.topo->elem, arvore_aux, p_operando.topo2->elem);
					remover2(&p_operando);
					remover(&p_operador);
					remover(&p_operador);
					inserir2(&p_operando, arvore_aux2);
				}  
           	}       

        }
        
        i++;
    }

    while (!vazia(&p_operador)){

    	arvore_aux = p_operando.topo2->elem;
        remover2(&p_operando);
        arvore_aux2 = criaTronco(p_operador.topo->elem, arvore_aux, p_operando.topo2->elem);
        remover2(&p_operando);
        remover(&p_operador);
        inserir2(&p_operando, arvore_aux2);
    }

    /* CRIANDO ARQUIVO DE SAÍDA */

    arquivo_out = fopen("saida.txt", "a");

    /* menu_saida CASO 0, IMPRIME NO CONSOLE. CASO 1, IMPRIME NO ARQUIVO */

    switch (menu_saida){
    	case 0 :    printf("\nA Expressão é: %s", expressao);
    				printf("\n\nO resultado da expressão é: %.2f", percorre_avalia(p_operando.topo2->elem));
    				printf("\n\nImprimindo Expressão PreFixada: ");
				    showTreePreFixa(arquivo_out, p_operando.topo2->elem, menu_saida);
				    printf("\n\nImprimindo Expressão PosFixada: ");
				    showTreePosFixa(arquivo_out, p_operando.topo2->elem, menu_saida);
				    printf("\n\n========================================================================\n");
				    break;

		case 1 :    fprintf(arquivo_out, "\n");
                    fprintf(arquivo_out, expressao);
					fprintf(arquivo_out, "\n\nO resultado da expressão é: %.2f", percorre_avalia(p_operando.topo2->elem));
					fprintf(arquivo_out, "\n\nImprimindo Expressão PreFixada: ");
					showTreePreFixa(arquivo_out, p_operando.topo2->elem, menu_saida);
					fprintf(arquivo_out, "\n\nImprimindo Expressão PosFixada: ");
					showTreePosFixa(arquivo_out, p_operando.topo2->elem, menu_saida);
					fprintf(arquivo_out, "\n\n========================================================================\n");
					fclose(arquivo_out);
					break;

		default : printf("\n\nErro na opção saída de arquivo\n\n");
				  break;
    }

    freeTree(arvore_aux);

}
