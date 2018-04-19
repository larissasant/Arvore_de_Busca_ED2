
typedef struct no {
	int info;
	struct no *esquerda;
	struct no *direita;
}Nodo;

typedef struct arv_bin {
	Nodo * raiz;
}Arv_bin;


Arv_bin* arv_cria();
//Arv_bin* vazia();

void arv_imprime(Arv_bin* arv);
void arv_imprime_no(Nodo* raiz);

void arv_libera(Arv_bin* arv);
void arv_libera_no(Nodo* raiz);

Nodo* arv_busca(Arv_bin* arv, int c);
Nodo* arv_busca_no(Nodo* raiz, int c);

Nodo* insere_no(Nodo* raiz, int valor);
int insere(Arv_bin * arv, int valor);

Nodo* remover_no(Nodo* raiz, int valor);
void remover(Arv_bin *arv, int valor);
int verificar_no(Nodo *raiz);

Nodo* menor_elemento_no(Nodo *raiz);
void menor_elemento(Arv_bin *arv);

int numeros_folhas_no(Nodo *raiz);
void numeros_folhas(Arv_bin *arv);
