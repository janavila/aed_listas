#include <stdio.h>
#include <stdlib.h>

struct tree{
    int dado;
    struct tree *pEsq,*pDir;
};

typedef struct tree *arvore;

void reset(arvore *p){
    *p = NULL;
}

void push(arvore *p, int d){
    if(*p == NULL){ // chegou na folha.
         *p = (arvore) malloc (sizeof(struct tree));
        (*p)->dado = d;
        (*p)->pEsq = NULL;
        (*p)->pDir = NULL;
        return;
    }

    if((*p)->dado < d) {
        push(&(*p)->pDir, d);
        return;
    }

    if((*p)->dado > d) {
        push(&(*p)->pEsq, d);
        return;
    }

    else printf("Error: The item is already on the list");

}

void count(arvore p, int *c) {

    if(p==NULL) return; // Se chegar aqui, o próximo elemento não existe.

    count(p->pEsq,c); // Conta os da esquerda.
    count(p->pDir,c); // Conta os da direita.
    (*c)++;

}

int main() {

    arvore p;
    int *c=(int*) malloc (sizeof(int));
    reset(&p);
    *c = 0;

    push(&p,1);
    push(&p,2);
    push(&p,3);
    push(&p,4);
    count(p,c);

    printf("Quantidade de nos: %d\n", *c);

    free(c);
    free(p);
    return 0;
}
