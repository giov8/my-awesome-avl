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
	int valor = 0;						// Variável que guarda valor a ser lido
	tNo *raiz = inicializaAVL();		// Inicializa árvore vazia

	// ** LEITURA DAS ENTRADAS ** //
	while (1) {							// loop infinito para tratar entradas seguintes
		char op = getchar ();			// op (operação) vai receber a operação (insere [i] ou remove [r]) 
		if (op == EOF) break;			// sai do looping quando chega ao fim das entradas
		scanf("%d", &valor);			// lê o valor da chave a ser adicionada ou removida

		if (op == 'i') 										// A função 'insere' retorna o nó que foi inserido
			raiz = ajustaAVL(insere(valor, raiz)); 			// Esse nó, será mandando pra função 'ajustaAVL', que retorna a nova raíz da árvore
		else 
			if (op == 'r') 										// A função 'busca' é chamada e retorna o nó que se encontra o valor a ser removido
				raiz = ajustaAVL(exclui(busca(valor, raiz))); 	// Esse nó, será mandando pra função 'ajustaAVL', que retorna a nova raíz da árvore

			else {
				printf("ERRO NA ENTRADA! Comando inválido\n");
				exit(1);
			}

		op = getchar(); 				// Recebe o "Enter" ou '\n'
	}

	// ** IMPRESSÃO / SAÍDA ** //
	imprimeEmOrdem(raiz, 0);
}