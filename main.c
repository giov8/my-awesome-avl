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

int main ()
{
	// **INICIALIZAÇÕES ** //
	int valor = 0;						// Variável valor a ser lido
	tNo *raiz = inicializaAVL();		// Inicializa árvore vazia

	// ** LEITURA DAS ENTRADAS ** //
	while (1) {							// looping infinito para tratar entradas seguintes
		char op = getchar ();			// op (operação) vai receber a operação (insere [i] ou remove [r]) 
		if (op == EOF) break;			// sai do looping quando chega ao fim das entradas
		scanf("%d", &valor);			// lê o valor da chave a ser adicionada ou removida

		if (op == 'i')
			// Para INSERIR um novo nó, a função 'insere' é chamada e retorna o nó que foi inserido
			// Esse nó, será mandando pra função 'ajustaAVL', que retorna a nova raíz da árvore.
			raiz = ajustaAVL(insere(valor, raiz));
		if (op == 'r')
			// Para REMOVER um novo nó, a função 'busca' é chamada e retorna o nó que se encontra
			// o valor a ser removido.
			// Esse nó, será mandando pra função 'ajustaAVL', que retorna a nova raíz da árvore.
			raiz = ajustaAVL(exclui(busca(valor, raiz)));

		op = getchar(); 						// Recebe o "Enter" ou '\n'
	}

	// ** IMPRESSÃO / SAÍDA ** //
	imprimeEmOrdem(raiz, 0);
}