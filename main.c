#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "utils.h"

int main() {

    FILE* fp;
    fp = fopen("CSV.csv", "r+");
    ITEM* item;

    int status = TRUE;
    char menu[3];
    char* line = (char*) malloc(1024);   
    char* produtora = (char*) malloc(30);
    int linha_valida = 1;

    LISTA* lista = criar_lista();
    char* titulo;

    /* criacao da lista circular duplamente encadeada
    */
    while(!feof(fp)) {
        
        if((item = read_line(fp)) != NULL && status != ERRO) {
            status = lista_inserir(item, lista);
        }
    }

    printf("%d\n", lista_tamanho(lista));
    
    /*menu de opcoes 
     */
    // scanf("%s", menu);
    // while(strcmp(menu, "f") != 0) {

    //     if(strcmp(menu, "r") == 0) {
    //         print_teste(lista);

    //         //verifica_remove_duplicados(lista);
    //     }

    //     else if(strcmp(menu, "p") == 0) {
    //         scanf("%s", produtora);
    //         busca_por_produtora(lista, produtora);
    //     }

    //     else if(strcmp(menu, "a") == 0) {
                
    //     }

    //     else if(strcmp(menu, "i") == 0) {
                
    //     }

    //     else if(strcmp(menu, "u") == 0) {
                
    //     }

    //     else if(strcmp(menu, "mr") == 0) {
                
    //     }
        
    //     else if(strcmp(menu, "ml") == 0) {

    //     }

    //     scanf("%s", menu);
    // }

    // //print_teste(lista);


    // fclose(portfolio);
    
	return 0;
}