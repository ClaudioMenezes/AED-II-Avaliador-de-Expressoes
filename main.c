/*
    Nome: main.c
    Copyright (c) 2014 IFMG. All rights reserved.

    =================== Membros ===================

    Bruno Tomé - 0011254 - ibrunotome@gmail.com
    Cláudio Menezes - 0011255 - claudiomenezio@gmail.com

    =========== Instruções de compilação ==========

    Abra o Terminal e digite:

    cd <DIRETÓRIO>
    gcc main.c funcoes.c pilha.c arvore_binaria.c pilha_arvore.c -omain.bin -Wall -pedantic -ansi
    ./main.bin

    ============ Objetivo do programa ============

    Criação de um software interpretador e conversor de expressões aritméticas 
    usando o conceito de árvore de expressão. O objetivo específico é exercitar 
    o conceito e aplicações da estrutura de dados árvore, notadamente da estrutura 
    de dados Árvore binária.
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
    
    int menu_entrada = 0, menu_saida = 0;
    char expressao[256];

    system("clear");
    
    printf("Escolha a forma de entrada de dados\n");
    printf("0 = Entrada via console\n");
    printf("1 = Entrada via arquivo texto\n\n");
    printf("Escolha: ");
    scanf("%d", &menu_entrada);

    printf("\nEscolha a forma de saída de dados\n");
    printf("0 = Saída via console\n");
    printf("1 = Saída via arquivo texto\n\n");
    printf("Escolha: ");
    scanf("%d", &menu_saida);

    if (menu_saida == 1)
    	printf("\nArquivo saida.txt criado com sucesso!");
    
    switch (menu_entrada) {
        case 0:
            printf("\n\nDigite a expressão na forma infixa: ");
            expressao_via_console(expressao); /* Chama a função que lerá a entrada de dados via console */
            printf("\n\n========================================================================\n");
            separa_string(expressao, menu_saida); /* Serapa a expressão em caracteres e empilha nas pilhas de char e de árvores*/
            break;

        case 1:
        	remove("saida.txt"); /* Essa função incluída no stdio.h remove o conteúdo anterior do saita.txt a cada vez que o programa é rodado */
            expressao_via_arquivo(expressao, menu_saida); /* Chama a função que lerá a entrada de dados via arquivo texto */
            break;
            
        default:
            printf("Você não escolheu a opção 0 ou 1\n");
            break;
    }

    printf("\n\n");
    
    return 0;
}
