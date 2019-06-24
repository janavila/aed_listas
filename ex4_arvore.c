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

    if(*p == NULL){
        *p = (arvore) malloc (sizeof(struct tree));
        (*p)->dado = d;
        (*p)->pEsq = NULL;
        (*p)->pDir = NULL;
        return; // já que tem muita recursão rs.
    }

    if(d < (*p)->dado){
        push(&(*p)->pEsq,d);
        return;
    }

    if(d > (*p)->dado){
        push(&(*p)->pDir,d);
        return;
    }

    else printf("Error: The register is already on the tree.\n");

}

void count(arvore p,int *c){

    if(p == NULL) return; // cjega no final.

    if(p->pDir == NULL) {
        (*c)++;
        count(p->pDir,c);
        return;
    }

    if(p->pEsq == NULL) {
        (*c)++;
        count(p->pEsq,c);
        return;
    }

    //printf("p->dado: %d\n", p->dado);
}


int main() {

    arvore p;
    int *c = (int*) malloc (sizeof(int));
    *c = 0;

    reset(&p);
    push(&p,1);
    push(&p,2);
    push(&p,3);
    push(&p,4);

    count(p,c);

    printf("Quantidade de nos-folha: %d", *c);

    free(c);
    free(p);

}
