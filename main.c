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
	tNo *no;

	char op = getchar();
	scanf("%d", &valor);
	raiz = insere(valor, raiz);

	op = getchar ();					// enter ou barra ene

	while (1) {
		op = getchar ();
		if (op == EOF) break;
		scanf("%d", &valor);
		//printf("operação: %c, valor: %d\n", op, valor);

		if (op == 'i') {
			no = insere(valor, raiz);
			//ajustaAVL(no, raiz);
		}

/*		if (op == 'r')
			no = busca(valor, raiz);
			remove(no);
*/

		op = getchar(); 						// Recebe o "Enter" ou '\n'
	}

	imprimeEmOrdem (raiz, 0);

	// impressao
}