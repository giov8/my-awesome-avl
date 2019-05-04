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

tNo *insere (int v, tNo *no); 
tNo *busca (int c); 
/*void remove (tNo *no); 
*/
#endif