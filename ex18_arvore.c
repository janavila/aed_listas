#include <stdio.h>
#include <stdlib.h>

struct tree{
    char dado;
    struct tree *pEsq,*pDir;
};

typedef struct tree *arvore;

void reset(arvore *p){
    *p = NULL;
}

void push(arvore *p, char c){

    if(*p == NULL){
        *p = (arvore) malloc (sizeof(struct tree));
        (*p)->dado = c;
        (*p)->pDir = NULL;
        (*p)->pEsq = NULL;
        return;
    }

    if(c > (*p)->dado){
        push(&(*p)->pDir,c);
        return;
    }

    if(c < (*p)->dado){
        push(&(*p)->pEsq, c);
        return;
    }

    else printf("Error: The register is already on the tree...\n");

}

void preorder(arvore p){
    if(p == NULL) return;

    preorder(p->pEsq);
    preorder(p->pDir);

    printf("%c ", p->dado);

}

void main(){

    arvore p;
    int n,key;

    reset(&p);

    push(&p,'M');
    push(&p,'F');
    push(&p,'S');
    push(&p,'D');
    push(&p,'J');
    push(&p,'P');
    push(&p,'U');
    push(&p,'A');
    push(&p,'E');
    push(&p,'H');
    push(&p,'Q');
    push(&p,'T');
    push(&p,'W');
    push(&p,'K');

    preorder(p);

    free(p);
}
