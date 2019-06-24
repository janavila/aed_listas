#include <stdio.h>
#include <stdlib.h>

//Faca um programa que armazene a informacao de varias pessoas.
//O programa so deve sair quando o usuario disser que nao deseja mais entrar com os dados de outra pessoa.
//Antes de sair o programa deve apresentar, de forma organizada, os dados de todas as pessoas.

typedef struct dado{
	char nome[30];
	int idade,altura;
}pessoa;


void adicionar(pessoa g[],int n) {
	int k,aux_2=1;
	pessoa aux;
	
	printf("n: %d\n", n);
	aux_2 = aux_2 + n;
	printf("aux_2: %d\n", aux_2);
	if(n==1) g = (pessoa*) malloc (aux_2*sizeof(pessoa));
	
	else g = (pessoa*) realloc (g, aux_2*sizeof(pessoa));
	
	
		printf("Diga o nome da pessoa: ", k+1);
		scanf("%s", g[n].nome);
		printf("Diga a idade da pessoa: ", k+1);
		scanf("%d", &g[n].idade);
		printf("Diga a altura da pessoa: ", k+1);
		scanf("%d", &g[n].altura);
		
		printf("Nome : %s\n", g[n].nome);
		printf("Idade : %d\n", g[n].idade);
		printf("Altura : %d\n", g[n].altura);
	
				
	}
	
void organizar(pessoa *g, int n) {
	int k;
	pessoa aux;

	printf("\n\tOrganizando por idade\n\n\n");
	
	for(k=0; k<n-1; ++k) {
		
		if(g[k].idade > g[k+1].altura ) {
			aux = g[k];
			g[k] = g[k+1];
			g[k+1] = aux; 
		}
		
		
	}
	
	
}

void mostrar(pessoa *g, int n) {
	int k;
	
	for(k=0; k<n; ++k) {
		printf("Nome: %s\n", g[k].nome);
		printf("Idade: %d\n", g[k].idade);
		printf("Altura: %d\n", g[k].altura);
	}
	
}
	
	
	


void main() {
	int n,cont=0;
	pessoa *global;
	
	do{
		
	printf("Voce deseja adicionar pessoas?\n\n[1]Sim\t[0]Nao ");
	scanf("%d", &n);
	
	if(n==0) break;
	
		adicionar(global,cont);
		cont++;
		//if(cont>1) organizar(global,cont);
	//	mostrar(global,cont);
	
		
	}while(n!=0);
	
	
	
}
