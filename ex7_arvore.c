#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool empty(arvore p){
    if(p == NULL) return true;
    else return false;
}


void search(arvore p, int *m){

    if(p == NULL) return;


    if(p->pDir != NULL){
        if(*m < p->pDir->dado){
            *m = p->pDir->dado;
        }
        search(p->pDir,m);
        return;
    }




}




void main(){

    arvore p;
    int n,key,higher;

    reset(&p);

    do{
        printf("1) Push\n2) Exit\n3) Higher: ");
        scanf("%d", &n);

        switch(n){
        case 1:
                printf("Key: ");
                scanf("%d", &key);

                push(&p,key);

                break;

        case 2: exit(1);

        case 3:
                if(!empty(p)){
                higher = p->dado;
                search(p, &higher);
                printf("Biggest: %d\n", higher);
                }

                else printf("Tree is empty\n");

                break;

        default: printf("This option doesn't exist\n");
        }
    }while(n!=2);

}
