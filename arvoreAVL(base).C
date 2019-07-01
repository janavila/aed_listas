#include <stdio.h>
#include <stdlib.h>

typedef struct Registro {
	int Chave;	
} Registro;

typedef struct No *Apontador;

typedef struct No {
	Apontador pEsq, pDir;
	Registro Reg;
} No;	

void Pesquisa(Apontador p, Registro *x) {
	if (p == NULL) {
		printf("Registro nao esta na arvore.");
		return;	
	}		
	if (x->Chave < p->Reg.Chave) {
		Pesquisa(p->pEsq, x);
		return;
	}	else if (x->Chave > p->Reg.Chave) {
		Pesquisa(p->pDir, x);	
		return; // ISSO A QUI PODE DAR MERDA
	}	else {
		printf("Achei!\n");
		
		*x = p->Reg;	
	}	
		
}	
void inicializa(Apontador *p) {
	
	*p = NULL;
}	 

void limpa(Apontador p) {
	if (p != NULL) {
		limpa(p->pEsq);
		limpa(p->pDir);
		free(p);	
	}		
}	

void Print(Apontador p) {
	if (p != NULL) {
		printf("%d\n", p->Reg.Chave);	
	}		
	if (p->pEsq != NULL) {
		Print(p->pEsq);	
	}	
	if (p->pDir != NULL) {
		Print(p->pDir);	
	}	
}	
int Altura(Apontador pRaiz) {
	
	int iEsq, iDir;
	
	if (pRaiz == NULL) {
		return 0;	
	}	 
	
	iEsq = Altura(pRaiz->pEsq);
	iDir = Altura(pRaiz->pDir);
	
	if (iEsq > iDir) {
		return iEsq + 1;	
	}	
	else {
		return iDir + 1;	
	}	
}	 

int FB (Apontador pRaiz) {
	if (pRaiz == NULL) {
		return 0;	
	}		
	return Altura(pRaiz->pEsq) - Altura(pRaiz->pDir);
}	

void RSD(Apontador *pRaiz) {
	
	Apontador aux;
	
	aux = (*pRaiz)->pEsq;
	(*pRaiz)->pEsq = aux->pDir;
	aux->pDir = (*pRaiz);
	(*pRaiz) = aux;
}	
void RSE(Apontador *pRaiz) {
	
	Apontador aux;
	
	aux = (*pRaiz)->pDir;
	(*pRaiz)->pDir = aux->pEsq;
	aux->pEsq = (*pRaiz);
	*pRaiz = aux;	
	
}	
int BalancaEsquerda(Apontador *pRaiz) {
	int fbe = FB((*pRaiz)->pEsq);
	
	if (fbe > 0) {
		RSD(pRaiz);
		return 1;	
	}	
	else if (fbe < 0){
		RSE(&(*pRaiz)->pEsq);
		RSD(pRaiz);	
		return 1;
	}	
	return 0;
		
}	
int BalancaDireita(Apontador *pRaiz) {
	int fbd = FB((*pRaiz)->pDir);
	
	if (fbd < 0) {
		RSE(pRaiz);
		return 1;	
	}	
	else if (fbd > 0){
		RSD(&(*pRaiz)->pDir);	
		RSE(pRaiz);
		return 1;
	}	
	return 0;
		
}	

int Balanceamento(Apontador *pRaiz) {
	
	int fb = FB(*pRaiz);
	
	if (fb > 1) {
		return BalancaEsquerda(pRaiz);	
	}		
	else if (fb < -1) {
		return BalancaDireita(pRaiz);	
	}	
	else {
		return 0;	
	}	
}	
int Insere(Apontador *pRaiz, Registro x) {
	if (*pRaiz == NULL) {
		*pRaiz = (No *) malloc(sizeof(No));
		(*pRaiz)->pEsq = NULL;
		(*pRaiz)->pDir = NULL;
		(*pRaiz)->Reg = x;
		return 1;	
	}		
	else if ((*pRaiz)->Reg.Chave > x.Chave) {
		Insere(&(*pRaiz)->pEsq, x);
		if (Balanceamento(&(*pRaiz))) {
			return 0;	
		}	else {
			return 1;	
		}	
			
	} else if ((*pRaiz)->Reg.Chave < x.Chave) {
		Insere(&(*pRaiz)->pDir, x);	
		if (Balanceamento(&(*pRaiz))) {
			return 0;	
		}	else {
			return 1;	
		}	
	} else {
		printf("\nErro: Valor ja esta na arvore...\n");	
		return 0;
	}	
}	

int main () {
	
	No *arvore;
	int resposta;
	Registro x;
		
	inicializa(&arvore);
	
	do {
		printf("[1] Inserir\n[2] Pesquisar\n[3] Printar\n[4] Sair\n");
		scanf("%d", &resposta);
		
		switch (resposta) {
			case (1):
				printf("Digite um numero: ");
				scanf("%d", &x.Chave);	
				Insere(&arvore, x);
				break;		
			case (2):
				printf("Digite um número: ");	
				scanf("%d", &x.Chave);
				Pesquisa(arvore, &x);
				break;	
			case (3):
				Print(arvore);
				break;	
		}	
		
		
		
	} while (resposta != 4);

	limpa(arvore);
}
