
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

void main(){

    arvore p;
    int n,key;

    reset(&p);

    do{
        printf("1) Push\n2) Exit: ");
        scanf("%d", &n);

        switch(n){
        case 1:
                printf("Key: ");
                scanf("%d", &key);

                push(&p,key);

                break;

        case 2: exit(1);

        default: printf("This option doesn't exist\n");
        }
    }while(n!=3);


    free(p);
}
