#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"
#include "lista.h"

struct item {
    char* titulo;
    char* produtora;
    char* ano;
};

ITEM* criar_item_vazio() {

	ITEM* item;
	
	item = (ITEM*) malloc(sizeof(ITEM));

	return item;
}

ITEM* item_criar(char* titulo, char* ano, char* produtora) {
    ITEM* item;

    item = (ITEM*) malloc(sizeof(ITEM));
    item->titulo = (char*) malloc(sizeof(titulo));
    item->ano = (char*) malloc(sizeof(ano));
    item->produtora = (char*) malloc(sizeof(produtora));

    if (item != NULL)
    {
        strcpy(item->titulo, titulo);
        strcpy(item->ano, ano);
        strcpy(item->produtora, produtora);
        //printf("%s-%s-%s", titulo, ano, produtora);
        return item;
    }

    return NULL;
}

char* get_item_info(ITEM* item, char* parte) {
    if(strcmp(parte, "titulo") == 0) {
        return item->titulo;
    }

    if(strcmp(parte, "produtora") == 0) {
        return item->produtora;
    }

    if(strcmp(parte, "ano") == 0) {
        return item->ano;
    }

    return NULL;
}


void apagar_item(ITEM* item) {
    free(item->produtora);
    free(item->ano);
    free(item->titulo);
}

char* get_titulo(ITEM* item) {

    return item->titulo;
}

char* get_produtora(ITEM* item) {

    return item->produtora;
}