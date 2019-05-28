//**************"API AVL"****************
//	Autores: 							*
//			Giovani Marciniak 			*
//			Marisa Sel Franco			*
//	Informática Biomédica - UFPR 		*
//	Algoritmos e Estrutura de Dados III	*
//***************************************

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main () {

	int valor = 0;
	tNo *raiz = inicializaAVL();
	tNo *no = NULL;

	char op = getchar();
	scanf("%d", &valor);
	raiz = insere(valor, raiz);

	imprimeEmOrdem(raiz, 0);

	op = getchar ();					// enter ou barra ene

	while (1) {							// looping infinito para tratar entradas seguintes
		printf("====================================================\n");
		op = getchar ();
		if (op == EOF) break;			// sai do looping quando chega ao fim das entradas
		scanf("%d", &valor);
		//printf("operação: %c, valor: %d\n", op, valor);

		if (op == 'i') {
			no = insere(valor, raiz);
			imprimeEmOrdem(raiz, 0);
			raiz = ajustaAVL(no);
		}
		printf("====================================================\n");
		if (op == 'r') {
			no = busca (valor, raiz);
			//exclui(no, raiz);
			tNo *pai = exclui(no);
			imprimeEmOrdem(raiz, 0);
			raiz = ajustaAVL(pai);

			//raiz = ajustaAVL(exclui(busca(valor, raiz)))
		}
		printf("====================================================\n");
		imprimeEmOrdem(raiz, 0);

/*		if (op == 'r')
			no = busca(valor, raiz);
			remove(no);
*/
		op = getchar(); 						// Recebe o "Enter" ou '\n'
	}
	imprimeEmOrdem(raiz, 0);

	no = max(raiz);
	printf("MAXIMO=%d\n", no->chave);
	no = antecessor(busca(20, raiz));
	printf("ANTECESSOR DO 20 É: %d\n", no->chave);
	no = antecessor(busca(30, raiz));
	printf("ANTECESSOR DO 30 É: %d\n", no->chave);
	no = antecessor(busca(40, raiz));
	printf("ANTECESSOR DO 40 É: %d\n", no->chave);
	no = antecessor(busca(45, raiz));
	printf("ANTECESSOR DO 45 É: %d\n", no->chave);
	no = antecessor(busca(48, raiz));
	printf("ANTECESSOR DO 48 É: %d\n", no->chave);
	no = antecessor(busca(50, raiz));
	printf("ANTECESSOR DO 50 É: %d\n", no->chave);
	no = antecessor(busca(10, raiz));
	printf("ANTECESSOR DO 10 É: %d\n", no->chave);
}