#include <stdlib.h>
#include <stdio.h>
#include "mod_lista.h"

// ESTRUTURA PARA JUNTAR OS NÓS DA LISTA: INFO E PONTEIRO
struct lista {
    int info;
    struct lista* prox;
};  

// FUNCAO CRIAR LISTA, ALOCA MEMORIA PARA UMA LISTA
Lista* lista_cria() {
    return NULL; 
};

// FUNCAO PARA INSERIR ELEMENTOS NA LISTA, NO INICIO
Lista* lista_insere(Lista* l, int elem) {

    Lista* novo = (Lista*) malloc(sizeof(Lista));

    if(novo == NULL){
        printf("\n MEMORIA NAO ALOCADA.");
        exit(1);
    }

    novo->info = elem;  // ARMAZENA O NOVO ELEMENTO NA LISTA
    novo->prox = l;     // O NOVO NÓ APONTA PARA O PRIMEIRO ELEMENTO DE ANTES
    return novo;        // RETORNA O ENDEREÇO DO NOVO NÓ, O NOVO TOPO DA LISTA
};

// FUNCAO PARA IMPRIMIR OS ELEMENTOS DA LISTA
void lista_imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("info: %d\n", p->info);
    }
}

// FUNCAO PARA VERIFICAR SE A LISTA ESTA VAZIA
int lista_vazia(Lista* l) {
    return (l == NULL);
}

// FUNCAO PARA PERCORRER A LISTA E BUSCAR ELEMENTO INSERIDO
Lista* lista_busca(Lista* l, int elem) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == elem) {
            return p; // RETORNA O PONTEIRO DO NÓ ENCONTRADO COM O ELEMENTO DESEJADO
        }
    }
    return NULL; // CASO NAO ENCONTRE O ELEMENTO DESEJADO
}

// FUNCAO PARA LIBERAR A MEMORIA DO NÓ 
void lista_libera(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox; // GUARDO O PRÓXIMO NÓ ANTES DE LIBERAR O ATUAL
        free(p);            // LIBERA O NÓ DA LISTA 
        p = t;              // APONTA PARA O PROXIMO NÓ DA LISTA
    }
}


// FUNCAO PARA ELEMENTOS ORDENADOS
Lista* lista_insere_ordenado(Lista* l, int elem) {
    Lista* novo;       // PONTEIRO PARA O NOVO ELEMENTO
    Lista* ant = NULL; // PONTEIRO PARA O ELEMENTO ANTERIOR 
    Lista* p = l;      // PONTEIRO PARA PERCORRER A LISTA

    // PROCURA A POSICAO DO ELEMENTO
    while (p != NULL && p->info < elem) {   // SE p == NULL, ESTA NO FIM DA LISTA
        ant = p;
        p = p->prox;
    }

    // CRIA A POSICAO PARA O NOVO ELEMENTO
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = elem;

    // ADICIONA O ELEMENTO DA LISTA
    if (ant == NULL) {  // SE O ANTERIOR APONTA PARA NULL, ENTAO COLOCA NA PRIMEIRA POSICAO
        novo->prox = l;
        return novo;    // O NOVO NÓ PASSA A SER O NOVO INICIO 
    }
    else {              // CASO O ANTERIOR NAO SEJA O PRIMEIRO, DEVE INSERIR NO MEIO OU NO FIM 
        novo->prox = ant->prox;
        ant->prox = novo;
        return l;       // O INICIO DA LISTA PERMANACE O MESMO 
    }
}

