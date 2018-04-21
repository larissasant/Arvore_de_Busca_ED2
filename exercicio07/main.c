#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.h"


int main (){
    int tam01, tam02, i, info;
        Arv_bin *arvore01 = arv_cria();
        Arv_bin *arvore02 = arv_cria();

        printf("__________________ARVORE 01 BINARIA DE BUSCA______________________\n\n");
        printf("-Tamanho da arvore:\n");
        scanf("%d", &tam01);
        printf("\n-Digite os valores da arvore:\n");
        for(i = 0; i < tam01; i++){
            scanf("%d", &info);
            insere(arvore01, info);
        }
        printf("__________________ARVORE 02 BINARIA DE BUSCA______________________\n\n");
        printf("-Tamanho da arvore:\n");
        scanf("%d", &tam02);
        printf("\n-Digite os valores da arvore:\n");
        for(i = 0; i < tam02; i++){
            scanf("%d", &info);
            insere(arvore02, info);
        }
        printf("\n-Questao 07\n\n");

        arv_igual(arvore01, arvore02);

}

