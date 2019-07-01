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

    push(&p,'A');
    push(&p,'B');
    push(&p,'C');
    push(&p,'D');
    push(&p,'E');
    push(&p,'F');
    push(&p,'G');
    push(&p,'H');
    push(&p,'I');
    push(&p,'J');
    push(&p,'K');
    push(&p,'L');
    push(&p,'M');
    push(&p,'N');
    push(&p,'O');
    push(&p,'P');
    push(&p,'Q');
    push(&p,'R');
    push(&p,'S');
    push(&p,'T');
    push(&p,'U');
    push(&p,'V');
    push(&p,'W');
    push(&p,'X');
    push(&p,'Y');
    push(&p,'Z');

    preorder(p);

    free(p);
}
