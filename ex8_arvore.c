
#include <stdio.h>
#include <stdlib.h>

struct tree{
    int dado;
    struct tree *pEsq,*pDir;
};

typedef struct tree *arvore;

void reset(arvore *p);
void push(arvore *p,int d);
void search(arvore p);
void pop(arvore *p);
void antecessor(arvore q, arvore *r);


void reset(arvore *p){
    *p = NULL;
}

void push(arvore *p, int d){

    if(*p == NULL){
        *p = (arvore) malloc (sizeof(struct tree));
        (*p)->dado = d;
        (*p)->pDir = NULL;
        (*p)->pEsq = NULL;
        return;
    }

    if(d > (*p)->dado){
        push(&(*p)->pDir,d);
        return;
    }

    if(d < (*p)->dado){
        push(&(*p)->pEsq, d);
        return;
    }

    else printf("Error: The register is already on the tree...\n");

}

void search(arvore p){

    if(p == NULL) {
    printf("The tree is empty\nReturning...\n");
    return;
    }

    if(p->dado%2==0){
        pop(&p);
        search(p->pEsq);
        search(p->pDir);
        return;
    }

}


void pop(arvore *p){
    arvore aux;

    if(*p == NULL){
        return;
    }

    if((*p)->pDir == NULL){
        aux = *p;
        *p = (*p)->pEsq;
        free(aux);
        return;
    }

    if((*p)->pEsq != NULL){
        antecessor(*p, &(*p)->pEsq);
        return;
    }

    aux = *p;
    *p = (*p)->pDir;
    free(aux);

}

void antecessor(arvore q, arvore *r){
    arvore aux;

    if((*r)->pDir != NULL){
        antecessor(q,&(*r)->pDir);
        return;
    }

    q->dado = (*r)->dado;
    aux = *r;
    *r = (*r)->pEsq;
    free(aux);
}

void preorder(arvore p){
    if(p == NULL){
        return;
    }

    preorder(p->pEsq); // p->pEsq primeiro pois ele imprime da esquerda para direita.
    preorder(p->pDir);

    printf("Dado: %d\n", p->dado);
}

void main(){

    arvore p;
    int n,key;

    reset(&p);

    do{
        printf("1) Push\n2) Pop(Pair)\n3) List\n4) Exit: ");
        scanf("%d", &n);

        switch(n){
        case 1:
                printf("Key: ");
                scanf("%d", &key);

                push(&p,key);

                break;

        case 2:
                search(p);
                break;

        case 3:
                preorder(p);
                break;

        case 4: exit(1);

        default: printf("This option doesn't exist\n");
        }
    }while(n!=4);


    free(p);
}
