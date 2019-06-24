#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Faca a implementacao da funcao malloc, voce deve utilizar a funcao malloc para isso
// void* realloc(void *point, size_t newsize);

void* reallocar(void *pos,int new_size) {
	void *aux;
	 
	aux = pos;
	
	memcpy(aux, pos, new_size);
	
	pos = aux;
	
	free(pos);
	
}

int main() {
	int n,new_size;
	void *m;
	int k;
	
	printf("Diga o tamanho inicial: ");
	scanf("%d", &n);
	
	m = (int*) malloc (n*sizeof(int));
	
	printf("Diga o tamanho que voce deseja realocar: ");
	scanf("%d", &new_size);
	
	reallocar(m,new_size*sizeof(int));
	
	return 0;
}
