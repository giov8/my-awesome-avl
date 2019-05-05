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
//	3. Insere iterativa com pai
//---------------------------------------
tNo *insere (int v, tNo *raiz) { // recebe a raiz

	tNo *no, *pai;
	if (raiz == NULL) 
		return criaNo (v);
	no = raiz;
	while (no != NULL){
		pai = no;
		if (v < no->chave)
			no = no->esq;
		else
			no = no->dir;
	}
	no = criaNo(v);
	if (v < pai->chave)
		pai->esq = no;
	else
		pai->dir = no;
	no->pai = pai;
	return no;
}
/*
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
}*/

//---------------------------------------
//	4. Busca iterativa
//---------------------------------------
tNo *busca (int c, tNo *no) { // recebe a raiz
	while ((no != NULL) && (c != no->chave)) {
		if (c < no->chave) 
			no = no->esq;
		else
			no = no->dir;
	}
	return no;
}


//---------------------------------------
//	5. Remove
//---------------------------------------
tNo *exclui (tNo *no) {

}

//---------------------------------------
//	15. Ajusta pai
//---------------------------------------
void ajustaPai (tNo *no, tNo *novo) {
	if (no->pai->esq == no)
		no->pai->dir = novo;
	else
		no->pai->dir = novo;
	if (novo != NULL)
		novo->pai = no->pai;
	return;
}

/*
//---------------------------------------
//	0. Ajusta Árvore AVL
//---------------------------------------
void ajustaAVL(no, raiz) {

}

*/
//---------------------------------------
//	10. Visita
//---------------------------------------
void visita (tNo *no, int h) {
	printf("%d,%d\n", no->chave, h);
	if (no->pai != NULL)
		printf("o nó pai de %d é %d\n", no->chave, no->pai->chave);
	return;
}

//---------------------------------------
//	11. Impressão em Ordem
//---------------------------------------
void imprimeEmOrdem (tNo *no, int h) {
	if (no != NULL){
		imprimeEmOrdem (no->esq, h+1);
		visita (no, h);
		imprimeEmOrdem (no->dir, h+1);
	}
	return;
}