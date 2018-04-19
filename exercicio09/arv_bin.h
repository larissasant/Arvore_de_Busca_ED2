
typedef struct no {
	int info;
	struct no *esquerda;
	struct no *direita;
}Nodo;

typedef struct arv_bin {
	Nodo * raiz;
}Arv_bin;


Arv_bin* arv_cria();

Nodo* insere_no(Nodo *raiz, int valor);
void insere(Arv_bin *arv, int valor);

void arv_imprime(Arv_bin *arv);
void arv_imprime_no(Nodo *raiz);
void arv_imprime_formatado(Arv_bin* arv);
void arv_imprime_formatado_no(Nodo* raiz);

