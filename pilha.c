#include <stdio.h>
#include <stdlib.h>

// Reset: Iniciar Estrutura de Dados.
// Push: Inserir elemento.
// Pop: Remover elemento.
// Empty: Testa se a Estrutura de Dados está vazia.
// Clear: Apaga todos os elementos.

void reset();
void push();
void pop();
void empty();
void clear();

typedef struct student{
	char nome[50];
}Alunos;

typedef struct duracell{
	Alunos *aluno;
	int base;
	int topo;
	int limite;
}pilha;

void main() {

	int n;

	do{
	printf("Choose your option:\n0) Reset\n1) Push\n2) Pop\n3) Empty\n4) Clear\n5) Exit\nyour option: ");
	scanf("%d", &n);

		switch(n){
			case 0:// reset();
			break;

			case 1: //push();
				break;

			case 2:// pop();
				break;

			case 3:// empty();
				break;

			case 4:// clear();
				break;

			case 5: printf("See ya!\n");
				exit(1);

			default: printf("\nThis option doesn't exist, try again please\n");
	}
}while(n!=5);	


  

}
