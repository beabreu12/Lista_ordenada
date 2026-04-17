#include<stdlib.h>
#include<stdio.h>
#include "mod_lista.h"

// gcc *.c -o programa.exe -lm
// .\programa.exe           

int main() {

    printf("\n \n INICIANDO... \n");

    Lista* l = lista_cria();      // LISTA CRIADA E INICIADA COM NULL

    l = lista_insere(l, 23);      // AO INSERIR 23, A LISTA 'l' PASSA A VALER O ENDEREÇO DO NÓ COM 23
    l = lista_insere(l, 45); 
    l = lista_insere(l, 8); 
    
    lista_imprime(l);

    Lista* achou = lista_busca(l, 45);  // BUSCANDO ELEMENTO NA LISTA
    
    if (achou != NULL) {
        printf("\n O VALOR FOI ENCONTRADO NA LISTA!\n");
    } else {
        printf(" \n VALOR NAO ENCONTRADO NA LISTA.\n");
    }

    l = lista_insere_ordenado(l, 10);

    lista_imprime(l);

    // Liberando tudo
    lista_libera(l);

    printf("\n FIM DO PROGRAMA... \n");
    return 0;
}


// gcc *.c -o programa.exe -lm
// .\programa.exe