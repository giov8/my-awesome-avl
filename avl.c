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
//	FUNÇÕES PARA INICIALIZAÇÃO/ INSERÇÃO
//---------------------------------------

//---------------------------------------
//	1. Inicialização OK
//---------------------------------------
tNo *inicializaAVL(void)
{
	return NULL;						//inicializa a AVL vazia
}

//---------------------------------------
//	2. Cria nó OK
//	DESCRIÇÃO: aloca memória para novo nó,
//	com ponteiro pai para NULL e fator de
//	balanceamento 0
//---------------------------------------
tNo *criaNo(int c)				
{
	tNo *no = malloc(sizeof (tNo)); 	//aloca memória para novo nó
	no->chave = c;
	no->dir = NULL;
	no->esq = NULL;
	no->pai = NULL;						//ponteiro pai para NULL, pois é raiz
	no->fb = 0; 						//fator de balanceamento 0
	return no;
}

//---------------------------------------
//	3. Inserção iterativa com ajuste do pai OK
//---------------------------------------
tNo *insere(int v, tNo *raiz)  			// recebe a raiz	
{	
	tNo *no, *pai;
	if (raiz == NULL) 					// se a raiz for nula
		return criaNo(v);				// cria o primeiro nó na raiz
	no = raiz;
	while (no != NULL) {				// caso contrário, percorre a AVL para inserir na folha
		pai = no;
		if (v < no->chave)
			no = no->esq;
		else
			no = no->dir;
	}
	no = criaNo(v);						// cria o nó na folha e, na sequência, ajusta os ponteiros
	if (v < pai->chave)
		pai->esq = no;
	else
		pai->dir = no;
	no->pai = pai;
	return no;
}

//---------------------------------------
//	FUNÇÕES PARA AJUSTE AVL
//---------------------------------------

//---------------------------------------
//	4. Altura da árvore OK
//---------------------------------------
// RETORNA 0 SE ARVORE VAZIA, 1 SE TIVER SO
// A RAIZ, 2 SE TIVER 2 FILHOS...
// FAZER ITERATIVO
int altura(tNo *no)
{
	if (no == NULL)
		return 0;					// retorna 0 se a árvore estiver vazia
	int he = altura(no->esq);
	int hd = altura(no->dir);
	if (he > hd)
		return he + 1;
	else 
		return hd + 1; 
}

//---------------------------------------
//	5. Calcula fator de balanceamento
//---------------------------------------
int calculaFB(tNo *no)
{
	return altura(no->dir) - altura(no->esq);
}

//---------------------------------------
//	6. Rotação para direita 
//---------------------------------------
tNo *rotDir(tNo *no)
{
	tNo *aux = no->esq;
	no->esq = aux->dir;
	if (no->pai != NULL) {
		if (no->pai->esq == no)
			no->pai->esq = aux;
		else
			no->pai->dir = aux;
	}
	if (aux->dir != NULL)	// apenas se o no aux tiver filho direito
		aux->dir->pai = no;
	aux->dir = no;
	aux->pai = no->pai;
	no->pai = aux;
	return aux;
}

//---------------------------------------
//	7. Rotação para esquerda 
//---------------------------------------
tNo *rotEsq(tNo *no)
{
	tNo *aux = no->dir;
	no->dir = aux->esq;
	if (no->pai != NULL) {
		if (no->pai->esq == no)
			no->pai->esq = aux;
		else
			no->pai->dir = aux;
	}
	if (aux->esq != NULL)	// apenas se o no aux tiver filho esquerdo
		aux->esq->pai = no;
	aux->esq = no;
	aux->pai = no->pai;
	no->pai = aux;

	return aux;
}

//-----------------------------------------
//	8. Ajusta Árvore AVL: esquerda-esquerda
//-----------------------------------------
void ajustaEsqEsq(tNo *no)
{
	printf("ajustaEsqEsq\n");
	printf("no a ser rotacionado? %d\n", no->chave);
	no = rotDir(no);
	printf("no esq esq: %d\n", no->chave);						// rotaciona o nó para direita
	//printf("pai %d\n", no->pai->chave);
	no->fb = calculaFB(no);

	printf("nao deu merda acima\n");
	no->dir->fb = calculaFB(no->dir);
	printf("ainda nao deu merda\n");                                                                                                                                                                                           
}

//-----------------------------------------
//	9. Ajusta Árvore AVL: direita-direita
//-----------------------------------------
void ajustaDirDir(tNo *no)
{
	printf("ajustaDirDir\n");
	printf("no a ser rotacionado? %d\n", no->chave);
	no = rotEsq(no);
	printf("no dir dir: %d\n", no->chave);
	no->fb = calculaFB(no);
	no->esq->fb = calculaFB(no->esq);
}

//-----------------------------------------
//	10. Ajusta Árvore AVL: esquerda-direita
//-----------------------------------------
void ajustaEsqDir(tNo *no)
{
	printf("ajustaEsqDir\n" );
	printf("no a ser rotacionado? %d\n", no->esq->chave);
	no = rotEsq (no->esq);
	printf("no esq dir: %d\n", no->chave);
	no->fb = calculaFB(no);
	no->esq->fb = calculaFB(no->esq);
	ajustaEsqEsq (no->pai);
}

//-----------------------------------------
//	11. Ajusta Árvore AVL: direita-esquerda
//-----------------------------------------
void ajustaDirEsq(tNo *no)
{
	printf("ajustaDirEsq\n");
	no = rotDir(no->dir);
	no->fb = calculaFB(no);
	no->dir->fb = calculaFB(no->dir);
	ajustaDirDir(no->pai);
}

//---------------------------------------
//	12. Ajusta Árvore AVL 
//---------------------------------------
tNo *ajustaAVL(tNo *no)
{											// fazer versao iterativa ? fica o questionamento!
	tNo *raiz = no;
	tNo *aux = no;
	while (aux != NULL) {					// vai percorrer a árvore do nó passado até a raiz
		aux->fb = calculaFB(aux);
		printf("***********************************\n");
		printf("no recebido para ajuste AVL: %d fator: %d\n", aux->chave, aux->fb);
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


//---------------------------------------
//	FUNÇÃO PARA BUSCA
//---------------------------------------

//---------------------------------------
//	13. Busca iterativa OK
//---------------------------------------

// ATENÇÃO: a busca não está tratando os casos em que o nó não está na árvore. Vamos tratar? Se sim, como fica na continuação do programa?

tNo *busca (int c, tNo *no)					// busca a partir da raiz
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
//	FUNÇÕES PARA EXCLUSÃO
//---------------------------------------

//---------------------------------------
//	14. Ajusta pai 
//---------------------------------------
void ajustaPai (tNo *no, tNo *novo)
{
	if ((no->pai == NULL) && (novo != NULL)) {	// se o nó original for a raiz e o novo nó não for NULL				
		novo->pai = NULL;					// ponteiro pro pai do novo nó aponta para NULL
		return;
	}
	else  {
		if (no->pai->esq == no) 			// se o nó original é um filho da esquerda
			no->pai->esq = novo;			// ajusta ponteiro da esquerda do pai para o novo nó
		else 								// se o nó original é um filho da direita
			no->pai->dir = novo;			// ajusta ponteiro da direita do pai para o novo nó
		if (novo != NULL)							
			novo->pai = no->pai;			// ponteiro pro pai do novo nó aponta para NULL
		return;
	}
}


//---------------------------------------
//	15. Máximo
//---------------------------------------
tNo *max(tNo *raiz)
{
	tNo *aux = raiz;
	while (aux->dir != NULL) {
		aux = aux->dir;
	}
	return aux;
}


//---------------------------------------
//	15. Mínimo OK
//---------------------------------------
tNo *min(tNo *no)
{
	if (no->esq == NULL)
		return no;
	else
		return min(no->esq);
}

//---------------------------------------
//	16. Antecessor
//---------------------------------------
tNo *antecessor (tNo *no)
{
	tNo *s = NULL;
	if (no->esq != NULL)
			return max(no->esq);
	else {
		s = no->pai;
		while ((s != NULL) && (no == s->esq)) {
			no = s;
			s = s->pai;
		}
	}
	return s;
}


//---------------------------------------
//	16. Sucessor 
//---------------------------------------
// RETORNA NULL SE FOR O NUMERO MAIS ALTO! (Segmentation Fault)
// IMPORTANTE PARA A EXCLUSÂO ESSA INFORMAÇÂO
tNo *sucessor(tNo *no)
{
	tNo *s = NULL;
	if (no->dir != NULL)
		return min(no->dir);
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
//	17. Exclusão - Versão Antecessor
//---------------------------------------
tNo *exclui(tNo *no) 
{
	tNo *pai = no->pai;								// guarda pai do nó para retornar e fazer ajuste de AVL a partir daí
	if ((no->esq == NULL) && (no->dir == NULL)) {	// se o nó a ser removido for um no folha
		ajustaPai(no, NULL);
		free(no);
	}
	else if (no->esq == NULL) {						// se o nó a ser removido tiver apenas filho direito
			ajustaPai(no, no->dir);					// é substituído pelo filho direito
			free(no);
		}
		else if (no->dir == NULL) {					// se o no a ser removido tiver apenas filho esquerdo
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
//	17. Exclusão - VERSÃO SUCESSOR!
//---------------------------------------
/*tNo *exclui(tNo *no) 
{
	tNo *pai = no->pai;								// guarda pai do nó para retornar e fazer ajuste de AVL a partir daí
	if ((no->esq == NULL) && (no->dir == NULL)) {	// se o nó a ser removido for um no folha
		ajustaPai(no, NULL);
		free(no);
	}
	else if (no->esq == NULL) {						// se o nó a ser removido tiver apenas filho direito
			ajustaPai(no, no->dir);					// é substituído pelo filho direito
			free(no);
		}
		else if (no->dir == NULL) {					// se o no a ser removido tiver apenas filho esquerdo
				ajustaPai(no, no->esq);				// é substituído pelo filho esquerdo
				free(no);
			}
			else {
				tNo *s = sucessor(no);				// usa técnica do sucessor caso o nó tenha dois filhos
				pai = s->pai;						// guarda o pai do sucessor para retornar e fazer ajuste da AVL a partir daí
				ajustaPai(s, s->dir);				// conecta filho direito do sucessor ao pai do sucessor
				s->esq = no->esq;					// transforma filho esquerdo do nó que será removido em filho esquerdo do sucessor
				no->esq->pai = s;					// ajusta ponteiro para pai do filho esquerdo 
				s->dir = no->dir;					// transforma filho direito do nó que será removido em filho direito do sucessor
				no->dir->pai = s;					// ajusta ponteiro para pai do filho direito 
				ajustaPai(no, s);					// conecta sucessor ao pai do nó que será removido					
				free (no);
			}
	return pai;										// tem de retornar este nó para fazer o ajuste da AVL no main
}*/

//---------------------------------------
//	FUNÇÃO PARA IMPRESSÃO
//---------------------------------------

//---------------------------------------
//	18. Visita OK
//---------------------------------------
void visita(tNo *no, int h) 
{
	printf("%d,%d, fb: %d\n", no->chave, h, no->fb);	// APAGAR FB
	//if (no->pai != NULL)
	//	printf("o nó pai de %d é %d\n", no->chave, no->pai->chave);
	return;
}

//---------------------------------------
//	19. Impressão em Ordem OK
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
