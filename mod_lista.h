#ifndef MOD_LISTA_H
#define MOD_LISTA_H

typedef struct lista Lista;                     // ESTRUTURA PARA CADA NÓ DA LISTA

Lista* lista_cria();                            // FUNCAO PARA CRIAR UMA LISTA VAZIA

Lista* lista_insere(Lista* l, int elem);        // FUNCAO PARA INSERIR ELEMENTOS NA LISTA

void lista_imprime(Lista* l);                   // FUNCAO PARA IMPRIMIR A LISTA

int lista_vazia(Lista* l);                      // FUNCAO PARA VERIFICAR SE A LISTA ESTA VAZIA

Lista* lista_busca(Lista* l, int elem);         // FUNCAO PARA BUSCAR ELEMENTOS NA LISTA

void lista_libera(Lista* l);                    // FUNCAO PARA LIBERAR A MEMORIA DO PONTEIRO DA LISTA

Lista* lista_insere_ordenado(Lista* l, int elem);   // FUNCAO PARA INSERIOR ELEMENTO EM ORDEM

#endif

