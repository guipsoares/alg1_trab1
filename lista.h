#ifndef _LISTA_H
#define _LISTA_H

#include "utils.h"

#define TRUE 0
#define ERRO (-1)

typedef struct node_ NODE;
typedef struct lista_ LISTA;


LISTA* criar_lista();
int lista_inserir(ITEM* item, LISTA* lista);
ITEM* get_item(char* line);
int apagar_lista(LISTA** lista);
void lista_apagar_itens(LISTA* lista);
void print_teste(LISTA* lista);
void print_node(NODE* node);
void verifica_remove_duplicados(LISTA* lista);
void busca_por_produtora(LISTA* lista, char* produtora);
ITEM* read_line(FILE* fp);
int lista_tamanho(LISTA* lista);

#endif