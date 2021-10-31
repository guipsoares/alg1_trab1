#ifndef _UTILS_
#define _UTILS_H
#include "lista.h"

#define TRUE 0
#define ERRO (-1)

typedef struct item ITEM;

ITEM* criar_item_vazio();
ITEM* item_criar(char* titulo, char* produtora, char* ano);
char* get_item_info(ITEM* item, char* parte);
void apagar_item(ITEM* item);
char* get_titulo(ITEM* item);
char* get_produtora(ITEM* item);

#endif