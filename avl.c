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
	no->pai = pai;				// o ponteiro pai é ajustado
	return no;
}

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
//	5. Ajusta pai
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

//---------------------------------------
//	0. Exclusão
//---------------------------------------
tNo *exclui (tNo *no) {

}




//---------------------------------------
//	0. Ajusta Árvore AVL
//---------------------------------------
void ajustaAVL(tNo *no, *raiz) {

}


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


//---------------------------------------
//	11. Minimum
//---------------------------------------
tNode min (tNode *node) {
	if (node->left == NULL)
		return node->key;
	else
		return min (node->left);
}

//---------------------------------------
//	13. Successor
//---------------------------------------
tNode successor (tNode *node) {
	if (node->rigth != NULL)
		return min (node->right);
	else {
		tNode *s = node->father;
		while ((s != NULL) && (node == s->right)) {
			node = s;
			s = s->father;
		}
	}
	return s;
}


//---------------------------------------
//	17. Right rotation
//---------------------------------------
tNode *rightRotation (tNode *node) {
	tNode *aux;
	aux = node->left;
	node->left = aux->right;
	aux->father = node->father;
	node->father = aux;
	aux->right->father = node;
	aux->right = node;
	return aux;
}

//---------------------------------------
//	18. Left rotation
//---------------------------------------
tNode *leftRotation (tNode *node) {
	tNode *aux;
	aux = node->rigth;
	node->right = aux->left;
	aux->father = node->father;
	node->father = aux;
	aux->left->father = node;
	aux->left = node;
	return aux;
}

//---------------------------------------
//	16. Delete
//---------------------------------------
void del (tNode *node) {
	if ((node->left == NULL) && (node->rigth == NULL)) {
		adjustFather (node, NULL);
		remove (node);									// verificar se eh um free mesmo
	}
	else 
		if (node->left == NULL) {
		adjustFather (node, node->right);
		remove (node);
		}
		else
			if (node->right == NULL) {
				adjustFather (node, node->left);
				remove (node);
			}
			else {
				tNode *s = successor (node);
				adjustFather (s, s->right);
				s->left = node->left;
				s->right = node->right;
				adjustFather (node, s);
				remove (node);
			}
}
