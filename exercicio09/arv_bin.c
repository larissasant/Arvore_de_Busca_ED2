#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.h"


Arv_bin* arv_cria(){
     Arv_bin *arv = (Arv_bin*) malloc(sizeof(Arv_bin));
        arv->raiz = NULL;
    return arv;
}

Nodo* insere_no(Nodo* raiz, int valor){
    if(raiz==NULL){
        raiz=(Nodo*) malloc(sizeof(Nodo));
        raiz->info = valor;
        raiz->direita = NULL;
        raiz->esquerda = NULL;
        printf("%d inserido com sucesso!\n", valor);
    }
    else if(valor < raiz->info){
        raiz->esquerda = insere_no(raiz->esquerda, valor);
    }else
        raiz->direita = insere_no(raiz->direita, valor);
        return raiz;
}

void insere(Arv_bin *arv, int valor){
    arv ->raiz = insere_no(arv->raiz, valor);
}

void arv_imprime(Arv_bin* arv){
    return arv_imprime_no(arv->raiz);
}


void arv_imprime_formatado(Arv_bin* arv){
    arv_imprime_formatado_no(arv->raiz);
   // printf("\n");
}

void arv_imprime_formatado_no(Nodo* raiz){
    //printf("<");
    if(raiz!=NULL){
        printf("%d", raiz->info);
        arv_imprime_formatado_no(raiz->esquerda);
        arv_imprime_formatado_no(raiz->direita);
    }
   // printf(">");
}


void arv_imprime_no(Nodo* raiz){
    if(raiz!=NULL){
        arv_imprime_no(raiz->esquerda);
        printf("%d\n", raiz->info);
        arv_imprime_no(raiz->direita);
    }
}

