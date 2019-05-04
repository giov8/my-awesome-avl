#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main () {

	char op = '\n';
	int valor = 0;

	int i = 0;

	while (1) {
		op = getchar ();
		if (op == EOF) break;
		scanf("%d", &valor);
		printf("operação: %c, valor: %d\n", op, valor);

		if (op == 'i') 
			insere(valor, raiz);

		if (op == 'r')
			no = busca(valor, raiz)
			remove(no);

		op = getchar();
		printf("OP: %c\n", op); // apagar

	}

	// 
}