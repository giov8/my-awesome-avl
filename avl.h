//**************"API AVL"****************
//	Autores: 							*
//			Giovani Marciniak 			*
//			Marisa Sel Franco			*
//	Informática Biomédica - UFPR 		*
//	Algoritmos e Estrutura de Dados III	*
//***************************************

#ifndef __AVL__
#define __AVL__

typedef struct tNo {
	int chave, fb;
	struct tNo *esq, *dir, *pai;
} tNo;

tNo *inicializaAVL (void);
tNo *criaNo (int c);

tNo *insere (int v, tNo *raiz);
tNo *busca (int c, tNo *no); 
tNo *exclui (tNo *no); 
void visita (tNo *no, int h);
void imprimeEmOrdem (tNo *no, int h);
void ajustaAVL(tNo *no, *raiz);

#endif