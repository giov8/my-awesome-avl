//**************"API AVL"****************
//	Autores: 							*
//			Giovani Marciniak 			*
//			Marisa Sel Franco			*
//	Informática Biomédica - UFPR 		*
//	Algoritmos e Estrutura de Dados III	*
//***************************************

#ifndef __AVL__
#define __AVL__

// ** DEFINIÇÕES ** //
typedef struct tNo {
	int chave, fb;
	struct tNo *esq, *dir, *pai;
} tNo;

// ** 1 - FUNÇÕES DE INICIALIZAÇÃO ** //
tNo *inicializaAVL(void);					
tNo *criaNo(int c);					

// ** 2 - FUNÇÕES PARA AJUSTE ** //
int altura(tNo *no);					
int calculaFB(tNo *no);					
tNo *rotDir(tNo *no);				
tNo *rotEsq(tNo *no);
void ajustaEsqEsq(tNo *no);			
void ajustaDirDir(tNo *no);			
void ajustaEsqDir(tNo *no);			
void ajustaDirEsq(tNo *no);			
tNo *ajustaAVL(tNo *no);

// ** 3 - FUNÇÕES DE APOIO ** //
void ajustaPai(tNo *no, tNo *novo);
tNo *max(tNo *raiz);				
tNo *antecessor(tNo *no);			

// ** 4 - FUNÇÕES DE OPERAÇÕES ** //
tNo *busca(int c, tNo *raiz);
tNo *insere(int v, tNo *raiz);	
tNo *exclui(tNo *no);				

// ** 5 - FUNÇÕES PARA IMPRESSÃO ** // 
void visita(tNo *no, int h);		
void imprimeEmOrdem(tNo *no, int h);
#endif