//**************"API AVL"****************
//	Autores: 							*
//			Giovani Marciniak 			*
//			Marisa Sel Franco			*
//	Informática Biomédica - UFPR 		*
//	Algoritmos e Estrutura de Dados III	*
//***************************************

#ifndef __AVL__
#define __AVL__

typedef struct tNo 
{
	int chave, fb;
	struct tNo *esq, *dir, *pai;
} tNo;

tNo *inicializaAVL(void);
tNo *criaNo(int c);
tNo *insere(int v, tNo *raiz);

int altura(tNo *no);
int calculaFB(tNo *no);
tNo *rotDir(tNo *no);
tNo *rotEsq(tNo *no);
void ajustaEsqEsq(tNo *no);
void ajustaDirDir(tNo *no);
void ajustaEsqDir(tNo *no);
void ajustaDirEsq(tNo *no);
tNo *ajustaAVL(tNo *no);

tNo *busca (int c, tNo *raiz);

void ajustaPai (tNo *no, tNo *novo);
tNo *min(tNo *no);
tNo *max(tNo *raiz); //***
tNo *antecessor (tNo *no); //***
tNo *sucessor(tNo *no);
tNo *exclui(tNo *no);

void visita(tNo *no, int h) ;
void imprimeEmOrdem(tNo *no, int h);


#endif