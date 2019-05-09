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
//	3. Inserção iterativa com ajuste do pai 
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
	return NULL;
}


//---------------------------------------
//	8. Altura da árvore 
//---------------------------------------
int altura (tNo *no) {
	int he, hd;

	if (no == NULL)
		return 0;
	he = altura(no->esq);
	hd = altura(no->dir);
	if (he > hd)
		return he + 1;
	else 
		return hd + 1; 
}


//---------------------------------------
//	14. Rotação para direita 
//---------------------------------------
tNo *rotDir (tNo *no) {
	tNo *aux;
	aux = no->esq;
	no->esq = aux->dir;
	aux->pai = no->pai;
	no->pai = aux;
	aux->dir->pai = no;
	aux->dir = no;
	return aux;
}

//---------------------------------------
//	15. Rotação para esquerda 
//---------------------------------------
tNo *rotEsq(tNo *no) {
	tNo *aux;
	aux = no->dir;
	no->dir = aux->esq;
	aux->pai = no->pai;
	no->pai = aux;
	aux->esq->pai = no;
	aux->esq = no;
	return aux;
}


//---------------------------------------
//	0. Ajusta Árvore AVL
//---------------------------------------
/*void ajustaAVL(tNo *no, tNo *raiz) {
	tno *aux = no;
	while (aux != NULL) {
		aux->fb = altura (aux->dir) - altura (aux->esq);
		if ((aux->fb == -1) || (aux->fb == 0) || (aux->fb == 1))
			aux = aux->pai;
		if (aux->fb < -1) {
			if (aux->esq->esq != NULL) {				// caso esquerda-esquerda
				rotDir (aux);							// rotaciona o nó para direita
				aux->fb = altura (aux->dir) - altura (aux->esq);
				aux = aux->pai;
			}
			else {										// caso esquerda-direita
				aux = aux->esq;
				rotEsq (aux);							// rotaciona o filho esquerdo para direita
				aux->fb = altura (aux->dir) - altura (aux->esq);
				aux = aux->pai;
				rotDir (aux);							// rotaciona o nó para direita
				aux->fb = altura (aux->dir) - altura (aux->esq);
				aux = aux->pai;
			}
		}
		else {
			if (aux->dir->dir != NULL) {				// caso direita-direita
				rotEsq (aux);							// rotaciona o nó para esquerda
				aux->fb = altura (aux->dir) - altura (aux->esq);
				aux = aux->pai;
			}
			else {										// caso direita-esquerda
				aux = aux->dir;
				rotDir (aux);							// rotaciona o filho direito para esquerda
				aux->fb = altura (aux->dir) - altura (aux->esq);
				aux = aux->pai;
				rotEsq (aux);							// rotaciona o nó para esquerda
				aux->fb = altura (aux->dir) - altura (aux->esq);
				aux = aux->pai;
			}
		}
	}
}*/


//---------------------------------------
//	10. Visita
//---------------------------------------
void visita (tNo *no, int h) {
	printf("%d,%d\n", no->chave, h);
	//if (no->pai != NULL)
	//	printf("o nó pai de %d é %d\n", no->chave, no->pai->chave);
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
//	12. Mínimo
//---------------------------------------
// FAZER VERSÃO ITERATIVA
tNo *min (tNo *no) {
	if (no->esq == NULL)
		return no;
	else
		return min (no->esq);
}

//---------------------------------------
//	13. Sucessor
//---------------------------------------
// RETORNA NULL SE FOR O NUMERO MAIS ALTO! (Segmentation Fault)
tNo *sucessor (tNo *no) {
	tNo *s = NULL;

	if (no->dir != NULL)
		return min (no->dir);
	else {
		s = no->pai;
		while ((s != NULL) && (no == s->dir)) {
			no = s;
			s = s->pai;
		}
	}
	return s;
}

//---------------------------------------
//	16. Delete
//---------------------------------------
/*void del (tNode *node) {
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
*/