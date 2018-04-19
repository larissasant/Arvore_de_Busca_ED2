#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.h"
#include <stdbool.h>


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
        printf ("\n\n_____Arvore_____\n\n");
        arv_imprime(arvore);
        printf ("\n-Digite o valor que deseja remover:\n");
        scanf ("%d", &info);
        remover(arvore, info);

        printf ("\n\n______Arvore Atualizada______\n");
        arv_imprime(arvore);

        printf("\n\tQuestao 04");
        printf("\n\n- Maior elemento da arvore:");
        maior_elemento(arvore);
        printf("%d\n\n\n");

}

