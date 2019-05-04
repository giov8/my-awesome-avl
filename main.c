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

	char op = '\n';
	int valor = 0;
	tNo *raiz = inicializaAVL();
	tNo *no;

	while (1) {
		op = getchar ();
		if (op == EOF) break;
		scanf("%d", &valor);
		//printf("operação: %c, valor: %d\n", op, valor);

		if (op == 'i') 
			no = insere(valor, raiz);
		printf ("O inserido é: %d \n", no->chave);
/*		if (op == 'r')
			no = busca(valor, raiz);
			remove(no);
*/

		op = getchar();
		//printf("OP: %c\n", op); // apagar
	}

	// impressao
}