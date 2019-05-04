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

//---------------------------------------
//	1. Inicialização
//	DESCRIÇÃO: inicializa a árvore AVL 
//	vazia
//---------------------------------------
tNo *inicializaAVL (void) {
	return NULL;
}

//---------------------------------------
//	2. Cria nó
//	DESCRIÇÃO: aloca memória para novo nó,
//	com ponteiro pai para NULL e fator de
//	balanceamento 0
//---------------------------------------
tNo *criaNo (int c) {
	tNo *no = malloc (sizeof (tNo));
	no->chave = c;
	no->dir = NULL;
	no->esq = NULL;
	no->pai = NULL;
	no->fb = 0; 
	return no;
}

//---------------------------------------
//	3. Insere
//---------------------------------------
tNo *insere (int v, tNo *no) { // recebe a raiz

	if (no == NULL)
		return criaNo (v);
	if (v == no->chave)
		return no;
	if (v < no->chave)
		no->esq = insere (v, no->esq);
	else
		no->dir = insere (v, no->dir);
	return no;
}

//---------------------------------------
//	4. Busca
//---------------------------------------
tNo *busca (int c, tNo *no) { // recebe a raiz
	if (no == NULL)
		return NULL;
	if (c == no->chave)
		return no;
	if (c < no->chave)
		return search (c, no->esq);
	else
		return search (c, no->dir);
}
/*
//---------------------------------------
//	5. Remove
//---------------------------------------
void remove (tNo *no) {


}
*/
