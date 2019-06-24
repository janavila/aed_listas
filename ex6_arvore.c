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

    if(*p == NULL) {
        *p = (arvore) malloc (sizeof(struct tree));
        (*p)->dado = d;
        (*p)->pEsq = NULL;
        (*p)->pDir = NULL;
        return;
    }

    if(d < (*p)->dado) {
        push(&(*p)->pEsq, d);
        return;
    }

    if(d > (*p)->dado) {
        push(&(*p)->pDir, d);
        return;
    }

    else printf("Error: The register is already on the list\n\n");

}

void search_impar();


int main(){

    arvore p;

    reset(&p);
    push(&p,1);
    push(&p,2);
    push(&p,3);
    push(&p,4);

    return 0;
}
