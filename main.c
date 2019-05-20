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

	op = getchar ();					// enter ou barra ene

	while (1) {							// looping infinito para tratar entradas seguintes
		op = getchar ();
		if (op == EOF) break;			// sai do looping quando chega ao fim das entradas
		scanf("%d", &valor);
		//printf("operação: %c, valor: %d\n", op, valor);

		if (op == 'i') {
			insere(valor, raiz);
		}

/*		if (op == 'r')
			no = busca(valor, raiz);
			remove(no);
*/

		op = getchar(); 						// Recebe o "Enter" ou '\n'
	}

	imprimeEmOrdem (raiz, 0);

	//no = min(raiz); printf("min: %d\n", no->chave);

	printf("busca: %d\n", busca(20, raiz));
	no = rotEsq(busca(20, raiz));

	imprimeEmOrdem (raiz, 0);

	//printf("altura: %d\n", altura(raiz));

	// impressao
}