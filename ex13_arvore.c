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

// o dado pode ser diferente.
bool similar(arvore p,arvore q){

	if(p == NULL && q == NULL){
		return true;
	}

	if(p->pEsq != NULL && q->pEsq != NULL){
        similar(p->pEsq,q->pEsq);
        return true;
	}

    if(p->pDir == NULL && q->pDir == NULL){
		similar(p->pDir,q->pDir);
      return true;
	}

	else return false;

}

void main(){

    arvore p,q;
    int n,key;

    reset(&p);
    reset(&q);

    do{
        printf("1) Push(P)\n2) Push(Q)\n3) Similar\n4) Exit: ");
        scanf("%d", &n);

        switch(n){
        case 1:
                printf("Key(P): ");
                scanf("%d", &key);

                push(&p,key);

                break;
        case 2:
        		printf("Key(Q): ");
                scanf("%d", &key);

                push(&q,key);

        		break;


        case 3:
        		if(similar(p,q)) printf("They are similar\n");

        		else printf("They are not similar\n");

        		break;

        case 4: exit(1);

        default: printf("This option doesn't exist\n");
        }
    }while(n!=4);


    free(p);
    free(q);
}
