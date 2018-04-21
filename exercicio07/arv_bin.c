#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arv_bin.h"


Arv_bin* arv_cria(){
     Arv_bin *arv = (Arv_bin*) malloc(sizeof(Arv_bin));
        arv->raiz = NULL;
    return arv;
}
/*Arv_bin* vazia(){
    return NULL;
}*/

void arv_imprime(Arv_bin* arv){
    return arv_imprime_no(arv->raiz);
}

void arv_imprime_no(Nodo* raiz){
   // printf("e");
    if (raiz!=NULL){
        arv_imprime_no(raiz->esquerda);
        printf("%d\n", raiz->info);
        arv_imprime_no(raiz->direita);
    //printf("c");
    }

}

void arv_libera_no(Nodo *raiz){
    if(raiz!=NULL){
        arv_libera_no(raiz->esquerda);
        arv_libera_no(raiz->direita);
        free(raiz);
    }
}

void arv_libera(Arv_bin* arv){
    arv_libera_no(arv->raiz);
    free(arv);
}

Nodo* arv_busca(Arv_bin* arv, int c){
    return arv_busca_no(arv->raiz,c);
}

Nodo *arv_busca_no(Nodo* raiz, int c){
    if(raiz==NULL || raiz->info == c){
        return raiz;
    }
    if(c < raiz->info){
        return arv_busca_no(raiz->esquerda, c);
    }else{
        return arv_busca_no(raiz->direita, c);
    }
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

Nodo* remover_no(Nodo* raiz, int valor){
    if(raiz== NULL){
        return NULL;
    }
    else if(raiz->info > valor){
        raiz->esquerda = remover_no(raiz->esquerda, valor);
        printf("-Removido com sucesso!\n");
    }
    else if(raiz->info < valor){
        raiz->direita = remover_no(raiz->direita, valor);
       // printf("-Removido com sucesso!\n");
    }else{
        if(raiz->esquerda==NULL && raiz->direita==NULL){
            free(raiz);
            raiz = NULL;

        }else if(raiz->esquerda==NULL){
            Nodo* t = raiz;
            raiz= raiz->direita;
            free(t);
        }
        else if (raiz->direita==NULL){
            Nodo* t = raiz;
            raiz= raiz->esquerda;
            free(t);
        }else{
            Nodo* f = raiz->esquerda;
            while(f->direita != NULL){
                f= f->direita;
            }
            raiz->info = f->info;
            f->info = valor;
            raiz->esquerda = remover_no(raiz->esquerda, valor);


        }

    }

    return raiz;
}

int remover(Arv_bin * arv, int valor){
    return arv->raiz = remover_no(arv->raiz, valor);

}
Nodo *maior_elemento_no(Nodo *raiz){
    if(raiz->direita !=NULL){
            return maior_elemento_no(raiz->direita);

    }else{
        return raiz->info;
    }
}

bool arv_iguais_no(Nodo *a, Nodo *b){

    if (a==NULL && b==NULL){
        return true;
    }else if (a!=NULL && b==NULL){
        return false;
    }else if (a== NULL && b!=NULL){
        return false;
    }
    if (a!= NULL && b!= NULL){
        if (a->info == b->info)
            return true;
        else
            return false;
    }
    return (arv_iguais_no(a->esquerda, b->esquerda) && arv_iguais_no(a->direita, b->direita));
}

int arv_igual(Nodo* arvore01, Nodo* arvore02){
    if (arvore01->info == arvore02->info){
       printf("iguais");
    }else
    printf("diferentes");
}
