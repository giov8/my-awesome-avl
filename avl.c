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
//	1 - FUNÇÕES DE INICIALIZAÇÃO
//---------------------------------------

//---------------------------------------
//	1.1 Inicialização
// DESCRIÇÃO: inicializa a AVL vazia.
// Criada para manter a característica
// de TAD
//---------------------------------------
tNo *inicializaAVL(void)
{
	return NULL;							// inicializa a AVL vazia
}

//---------------------------------------
//	1.2 Cria nó
//	DESCRIÇÃO: aloca memória para novo nó,
//	com ponteiro pai para NULL e fator de
//	balanceamento 0
//---------------------------------------
tNo *criaNo(int c)				
{
	tNo *no = malloc(sizeof (tNo)); 		// aloca memória para novo nó
	no->chave = c;
	no->dir = NULL;
	no->esq = NULL;
	no->pai = NULL;							// ponteiro pai para NULL, pois é raiz
	no->fb = 0; 							// fator de balanceamento 0
	return no;	
}

//--------------------------------------
//	2 - FUNÇÕES PARA AJUSTE
//--------------------------------------
//---------------------------------------
//	2.1 Altura da árvore
// DESCRIÇÃO: Retorna 0 com árvore vazia,
// 1 se tiver só raiz, 2 se um filho...
//---------------------------------------
int altura(tNo *no)
{
	if (no == NULL)
		return 0;						// retorna 0 se a árvore estiver vazia
	int he = altura(no->esq);			// calcula as alturas dos dois lados
	int hd = altura(no->dir);
	if (he > hd)						// retorna a maior altura + 1
		return he + 1;
	else 
		return hd + 1; 
}

//---------------------------------------
//	2.2 Calcula fator de balanceamento
// DESCRIÇÃO: Retorna um int com o fator
// de balanceamento. Criada, também, pa-
// ra manter a característica de TAD
//---------------------------------------
int calculaFB(tNo *no)
{
	return altura(no->dir) - altura(no->esq);
}

//---------------------------------------
// 2.3 Rotação para direita 
// DESCRIÇÃO: Rotaciona o nó de entrada p/
// a direita, ajusta os pais e retorna o
// nó que ficou na posição onde o nó de
// entrada estava
//---------------------------------------
tNo *rotDir(tNo *no)
{
	tNo *aux = no->esq;						// cria um auxiliar, que é o filho esquerdo do nó
	no->esq = aux->dir;						// o filho direito do auxiliar é filho esquerdo do nó
	if (no->pai != NULL) {					// o filho do pai do nó vira o auxiliar
		if (no->pai->esq == no)
			no->pai->esq = aux;
		else
			no->pai->dir = aux;
	}
	if (aux->dir != NULL)					// se o nó aux tiver filho direito
		aux->dir->pai = no;					// o pai do filho direito de aux vai ser o nó
	aux->dir = no;							// o filho direito de aux será o nó
	aux->pai = no->pai;						// o pai do nó vira pai do aux
	no->pai = aux;							// aux vira pai do nó
	return aux;	
}

//---------------------------------------
//	2.4 Rotação para esquerda 
// DESCRIÇÃO: Rotaciona o nó de entrada p/
// a esquerda, ajusta os pais e retorna o
// nó que ficou na posição onde o nó de
// entrada estava
//---------------------------------------
tNo *rotEsq(tNo *no)
{
	tNo *aux = no->dir;						// cria um auxiliar, que é o filho direito do nó
	no->dir = aux->esq;						// o filho esquerdo do auxiliar é filho esquerdo do nó
	if (no->pai != NULL) {					// o filho do pai do nó vira o auxiliar
		if (no->pai->esq == no)
			no->pai->esq = aux;
		else
			no->pai->dir = aux;
	}
	if (aux->esq != NULL)					// se o nó aux tiver filho esquerdo
		aux->esq->pai = no;					// o pai do filho esquerdo de aux vai ser o nó
	aux->esq = no;							// o filho esquerdo de aux será o nó
	aux->pai = no->pai;						// o pai do nó vira pai do aux
	no->pai = aux;							// aux vira pai do nó
	return aux;
}

//-----------------------------------------
//	2.5 Ajusta Árvore AVL: esquerda-esquerda
// DESCRIÇÃO: faz o ajuste do caso e atua-
// liza os fatores de balanceamento modi-
// ficados
//-----------------------------------------
void ajustaEsqEsq(tNo *no)
{
	no = rotDir(no);
	no->fb = calculaFB(no);
	no->dir->fb = calculaFB(no->dir);                                                                                                                                                                                        
}

//-----------------------------------------
//	2.6 Ajusta Árvore AVL: direita-direita
// DESCRIÇÃO: faz o ajuste do caso e atua-
// liza os fatores de balanceamento modi-
// ficados
//-----------------------------------------
void ajustaDirDir(tNo *no)
{
	no = rotEsq(no);
	no->fb = calculaFB(no);
	no->esq->fb = calculaFB(no->esq);
}

//-----------------------------------------
//	2.7 Ajusta Árvore AVL: esquerda-direita
// DESCRIÇÃO: faz o ajuste do caso e atua-
// liza os fatores de balanceamento modi-
// ficados
//-----------------------------------------
void ajustaEsqDir(tNo *no)
{
	no = rotEsq (no->esq);					// transforma em caso esquerda-esquerda
	no->fb = calculaFB(no);
	no->esq->fb = calculaFB(no->esq);
	ajustaEsqEsq (no->pai);					// ajusta o pai
}

//-----------------------------------------
//	2.8 Ajusta Árvore AVL: direita-esquerda
// DESCRIÇÃO: faz o ajuste do caso e atua-
// liza os fatores de balanceamento modi-
// ficados
//-----------------------------------------
void ajustaDirEsq(tNo *no)
{
	no = rotDir(no->dir);					// transforma em caso direita-direita
	no->fb = calculaFB(no);
	no->dir->fb = calculaFB(no->dir);
	ajustaDirDir(no->pai);					// ajusta o pai
}

//---------------------------------------
//	2.9 Ajusta Árvore AVL 
// DESCRIÇÃO: Procura e corrige desbalan-
// ceamentos na árvore, sempre subindo
// pelo pai. Devolve uma nova raiz para
// a árvore, que pode ter sido modificada
//---------------------------------------
tNo *ajustaAVL(tNo *no)
{		
	tNo *raiz = no;
	tNo *aux = no;
	while (aux != NULL) {					// vai percorrer a árvore do nó passado até a raiz
		aux->fb = calculaFB(aux);
		if (aux->fb < -1) {
			if (aux->esq->esq != NULL)		// se tiver um filho esquerdo, é caso esq-esq
				ajustaEsqEsq(aux);
			else 							// se tiver um filho direito, é caso esq-dir
				ajustaEsqDir(aux);
		}
		if (aux->fb > 1) {
			if (aux->dir->dir != NULL) 		// se tiver um filho direito, é caso dir-dir 
				ajustaDirDir(aux);
			else
				ajustaDirEsq(aux);			// se tiver um filho esquerdo, é caso dir-esq
		}
		raiz = aux;
		aux = aux->pai;
	}
	return raiz;
}

//--------------------------------------
//	3 - FUNÇÕES DE APOIO
//--------------------------------------

//---------------------------------------
// 3.1 Ajusta pai 
// DESCRIÇÃO: faz o ajuste do pai para ser
// possível dar free no nó na exclusão
//---------------------------------------
void ajustaPai (tNo *no, tNo *novo)
{
	if ((no->pai == NULL) && (novo != NULL)) {	// se o nó original for a raiz e o novo nó não for NULL				
		novo->pai = NULL;						// ponteiro pro pai do novo nó aponta para NULL
		return;
	}
	else  {
		if (no->pai->esq == no) 				// se o nó original é um filho da esquerda
			no->pai->esq = novo;				// ajusta ponteiro da esquerda do pai para o novo nó
		else 									// se o nó original é um filho da direita
			no->pai->dir = novo;				// ajusta ponteiro da direita do pai para o novo nó
		if (novo != NULL)							
			novo->pai = no->pai;				// ponteiro pro pai do novo nó aponta para NULL
		return;
	}
}

//---------------------------------------
// 3.2 Máximo
// DESCRIÇÃO: Retorna o máximo valor da
// sub-árvore a partir do nó de entrada
//---------------------------------------
tNo *max(tNo *raiz)
{
	tNo *aux = raiz;
	while (aux->dir != NULL) {
		aux = aux->dir;							// o número mais a direita é o maior (máximo) 
	}
	return aux;
}

//---------------------------------------
// 3.3 Antecessor
// DESCRIÇÃO: Retorna o antecessor do nó
// de entrada. Retorna NULL se já for o
// número mais baixo.
//---------------------------------------
tNo *antecessor (tNo *no)
{
	tNo *s = NULL;
	if (no->esq != NULL)						// o antecessor é o número mais alto da sub-árvore a direita
			return max(no->esq);
	else {
		s = no->pai;
		while ((s != NULL) && (no == s->esq)) { // sobe na árvore enquanto for o nó esquerdo
			no = s;
			s = s->pai;
		}
	}
	return s;
}

//--------------------------------------
//	4 - FUNÇÕES DE OPERAÇÃO
//--------------------------------------

//---------------------------------------
//	4.1 Busca iterativa
// DESCRIÇÃO: Busca uma chave c a partir
// da raiz
//---------------------------------------
tNo *busca (int c, tNo *no)					
{ 
	while ((no != NULL) && (c != no->chave)) {	// percorre  a AVL até achar o nó com o valor C buscado
		if (c < no->chave) 
			no = no->esq;
		else
			no = no->dir;
	}
	return no;
}

//---------------------------------------
//	4.2 Inserção iterativa
// DESCRIÇÃO: insere novo nó, como uma
// BST, e retorna o nó inserido
//---------------------------------------
tNo *insere(int v, tNo *raiz)  				// recebe a raiz	
{	
	tNo *no, *pai;
	if (raiz == NULL) 						// se a raiz for nula
		return criaNo(v);					// cria o primeiro nó na raiz
	no = raiz;

	while (no != NULL) {					// percorre a AVL para inserir na folha
		pai = no;
		if (v < no->chave)
			no = no->esq;
		else
			no = no->dir;
	}

	no = criaNo(v);							// cria o nó na folha e, na sequência, ajusta os ponteiros
	if (v < pai->chave)
		pai->esq = no;
	else
		pai->dir = no;
	no->pai = pai;
	return no;
}

//---------------------------------------
//	4.3 Exclusão - Versão com antecessor
// DESCRIÇÃO: Remove um nó de entrada e
// retorna outro nó para ser usado no a-
// juste da AVL, posteriormente
//---------------------------------------
tNo *exclui(tNo *no) 
{
	tNo *pai = no->pai;								// guarda pai do nó para retornar e fazer ajuste de AVL a partir daí
	if ((no->esq == NULL) && (no->dir == NULL)) {	// se o nó a ser removido for um nó folha
		ajustaPai(no, NULL);
		free(no);
	}
	else if (no->esq == NULL) {						// se o nó a ser removido tiver apenas filho direito
			ajustaPai(no, no->dir);					// é substituído pelo filho direito
			free(no);
		}
		else if (no->dir == NULL) {					// se o nó a ser removido tiver apenas filho esquerdo
				ajustaPai(no, no->esq);				// é substituído pelo filho esquerdo
				free(no);
			}
			else {
				tNo *s = antecessor(no);			// usa técnica do antecessor caso o nó tenha dois filhos
				pai = s->pai;						// guarda o pai do antecessor para retornar e fazer ajuste da AVL a partir daí
				ajustaPai(s, s->dir);				// conecta filho direito do sucessor ao pai do sucessor
				s->esq = no->esq;					// transforma filho esquerdo do nó que será removido em filho esquerdo do sucessor
				no->esq->pai = s;					// ajusta ponteiro para pai do filho esquerdo 
				s->dir = no->dir;					// transforma filho direito do nó que será removido em filho direito do sucessor
				no->dir->pai = s;					// ajusta ponteiro para pai do filho direito 
				ajustaPai(no, s);					// conecta sucessor ao pai do nó que será removido					
				free (no);
			}
	return pai;										// tem de retornar este nó para fazer o ajuste da AVL no main
}

//---------------------------------------
//	5 - FUNÇÕES PARA IMPRESSÃO
//---------------------------------------

//---------------------------------------
// 5.1 Visita
// DESCRIÇÃO: Faz a visita, que no caso é
// a impressão
//---------------------------------------
void visita(tNo *no, int h) 
{
	printf("%d,%d\n", no->chave, h);
	return;
}

//---------------------------------------
// 5.2 Impressão em Ordem
// DESCRIÇÃO: Faz a impressão EM ORDEM
//---------------------------------------
void imprimeEmOrdem(tNo *no, int h)
{
	if (no != NULL) {
		imprimeEmOrdem(no->esq, h+1);
		visita(no, h);
		imprimeEmOrdem(no->dir, h+1);
	}
	return;
}