#include <stdio.h>
#include <stdlib.h>
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
      //  raiz = NULL;
    }
}

void arv_libera(Arv_bin* arv){
    //if(arv!=NULL)
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

int insere(Arv_bin *arv, int valor){
    arv ->raiz = insere_no(arv->raiz, valor);
}

Nodo* remover_no(Nodo *raiz, int valor){
    int num;
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
        num = verificar_no(raiz);
        if(num == 0){
            free(raiz);
            raiz = NULL;

        }else if(num==1){
            if(raiz->esquerda){
            Nodo* t = raiz;
            raiz= raiz->direita;
            free(t);
        }else{
            Nodo* t = raiz;
            raiz= raiz->esquerda;
            free(t);
        }
        }else if(num ==2){
            Nodo* f = raiz->direita;
            while(f->esquerda != NULL){
                f= f->esquerda;
            }
            raiz->info = f->info;
            f->info = valor;
            raiz->direita = remover_no(raiz->direita, valor);


        }

    }

    return raiz;
}

void remover(Arv_bin *arv, int valor){
   arv->raiz = remover_no(arv->raiz, valor);
}

int verificar_no(Nodo *raiz){
    if(raiz->esquerda ==NULL && raiz->direita ==NULL){
        return 0;
    }
    if(raiz->esquerda !=NULL && raiz->direita ==NULL){
        return 1;
    }
    if(raiz->esquerda ==NULL && raiz->direita !=NULL){
        return 1;
    }
    if(raiz->esquerda !=NULL && raiz->direita !=NULL){
        return 2;
    }
}

Nodo *menor_elemento_no(Nodo *raiz){
    while(raiz !=NULL && raiz->esquerda != NULL)
      raiz = raiz->esquerda;
       return raiz->info;

}
void menor_elemento(Arv_bin* arv){
    arv->raiz = menor_elemento_no(arv->raiz);
}

int numeros_folhas_no(Nodo *raiz){
    int cont = 0;
    if (raiz==NULL){
        return 0;
    }
    else if (verificar_no(raiz)==1){
        cont++;
        cont = 1+ numeros_folhas_no(raiz->esquerda);
        cont = 1+ numeros_folhas_no(raiz->direita);
        return cont;
    }
}

void numeros_folhas(Arv_bin *arv){
    //arv->raiz = numeros_folhas_no(arv->raiz);
    printf("\n%d\n", numeros_folhas_no(arv->raiz));
}

