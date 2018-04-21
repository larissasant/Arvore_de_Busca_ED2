#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.h"


int main (){
    int tam, i, info;
        Arv_bin *arvore = arv_cria();

        printf("__________________ARVORE BINARIA DE BUSCA______________________\n\n");
        printf("-Tamanho da arvore:\n");
        scanf("%d", &tam);
        printf("\n-Digite os valores da arvore:\n");
        for(i = 0; i < tam; i++){
            scanf("%d", &info);
            insere(arvore, info);
        }
        //printf ("\n\n_____Arvore_____\n\n");
        //arv_imprime(arvore);
        printf ("\nQuestao 06\n");
        esimo(arvore->raiz);
        printf("%d\n\n");

}

