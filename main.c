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
			printf("###### insere %d ######\n", valor);
			no = insere(valor, raiz);
			imprimeEmOrdem(raiz, 0);
			raiz = ajustaAVL(no);
		}
		printf("====================================================\n");
		if (op == 'r') {
			printf("###### remove %d ######\n", valor);
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
}