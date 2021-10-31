#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "lista.h"
#include "utils.h"


struct node_ {
    ITEM* item;
    NODE* prev;
    NODE* next;
};

struct lista_ {
    NODE* fim;
    int tamanho;
};


LISTA* criar_lista() {
    LISTA *lista = (LISTA*) malloc(sizeof(LISTA));
    if(lista != NULL)
    {
        lista->fim = (NODE*) malloc(sizeof(NODE)); 
        lista->fim->item = criar_item_vazio();

        if(lista->fim == NULL) {
            return NULL;
        }
        lista->fim->next = NULL;
        lista->fim->prev = NULL;
        lista->tamanho = 0;
    }
    return lista;
}


ITEM* get_item(char* line) {

    if(line != NULL) {

        ITEM* item = criar_item_vazio();

        char* split = strtok(line, ";");
        char* titulo = (char*) malloc(strlen(split)+1);
        strcpy(titulo, split);

        split = strtok(NULL, ";");
        char* ano = (char*) malloc(strlen(split)+1);
        strcpy(ano, split);


        split = strtok(NULL, ";");
        char* produtora = (char*) malloc(strlen(split));
        strcpy(produtora, split);

        item = item_criar(titulo, ano, produtora);

        return item;

    }


    return NULL;
}


ITEM* read_line(FILE* fp) {
    char linha[1024];
    char *produtora;
    char *titulo;
    char *ano;

    ITEM* item;

    if(fgets(linha, sizeof(linha), fp) == NULL) 
        return NULL;

    if(strcmp(linha, "\n") == 0 || strcmp(linha, "\r\n") == 0)
        return NULL;

    linha[strcspn(linha, "\n")] = 0;
    linha[strcspn(linha, "\r")] = 0;

    item = get_item(linha);

    return item;
}



int lista_inserir(ITEM* item, LISTA* lista) {

    if(lista != NULL) {
        NODE* novo_no = (NODE*) malloc(sizeof(NODE));

        if(novo_no != NULL) {
            novo_no->item = item;
            if(lista->tamanho == 0) {
                lista->fim = novo_no;
                lista->fim->next = lista->fim;
                lista->fim->prev = lista->fim;
            }
            else {
                novo_no->next = lista->fim->next;
                novo_no->prev = lista->fim;
                lista->fim->next->prev = novo_no;
                lista->fim->next = novo_no;
                lista->fim = novo_no;
                
            } 

            lista->tamanho++;

            return TRUE;
        }
    }

    return ERRO;

}


int apagar_lista(LISTA** lista) {
    if((*lista != NULL) && (*lista)->tamanho != 0) {
        lista_apagar_itens(*lista);
        free(*lista);
        *lista = NULL;
        return TRUE;
    }

    return ERRO;
}

void lista_apagar_itens(LISTA* lista) {
    NODE* node = lista->fim->next;
    for(int i=0; i<lista->tamanho; i++) {
        apagar_item(node->item);
        free(node);
        node = node->next;
    }
}

void print_node(NODE* node) {

    char* titulo = get_item_info(node->item, "titulo");
    char* produtora = get_item_info(node->item, "produtora");
    char* ano = get_item_info(node->item, "ano");

    printf("%s // %s // %s", titulo, ano, produtora);
    FILE* teste = fopen("teste.csv", "w+");
    fprintf(teste, "%s - %s - %s", titulo, ano, produtora);
}

void print_teste(LISTA* lista) {
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node = lista->fim->next;
    do {
        print_node(node);
        node = node->next;
    }  while(node != lista->fim->next);
}


void verifica_remove_duplicados(LISTA* lista) {
    NODE* no = (NODE*) malloc(sizeof(NODE));
    NODE* tmp = (NODE*) malloc(sizeof(NODE));
    //NODE* aux = (NODE*) malloc(sizeof(NODE));
    int tamanho = lista->tamanho;
    no = lista->fim->next;
    tmp = no->next;
    char* nome = get_titulo(no->item);

    for(int i=0; i<tamanho-1; i++) {
        for(int j=i+1; j<tamanho; j++) {
            if(strcmp(get_titulo(tmp->item), get_titulo(no->item)) == 0) {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                tmp->prev = NULL;
                tmp->next = NULL;
                lista->tamanho--;
                
                
            }
            tmp = tmp->next;
        }
        no = no->next;
        nome = get_titulo(no->item);
        tmp = no->next;
    }

}


void busca_por_produtora(LISTA* lista, char* produtora) {
    printf("%s\n", produtora);
    NODE* node = (NODE*) malloc(sizeof(NODE));

    node = lista->fim;

    do {
        node = node->next;
        printf("%d\n", strcmp(get_produtora(node->item), produtora));
        printf("%s\n", get_produtora(node->item));


        if(strcmp(get_produtora(node->item), produtora) == 0) {
            printf("%s\n", produtora);
        }

    } while(node != lista->fim);
}

// void free_pointer(LISTA* lista) {
//     free(lista->head->item);
//     lista->head->item = NULL;
//     free(lista->head);
//     lista->head = NULL;
//     free(lista);
//     lista = NULL;
// }

int lista_tamanho(LISTA* lista) {
    return lista->tamanho;
}