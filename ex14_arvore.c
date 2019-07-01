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

// o dado tem que ser igual.
bool equal(arvore p,arvore q){

	if(p == NULL && q == NULL){ // se for vazia.
		return true;
	}

	if(p->dado == q->dado){
        equal(p->pEsq,q->pEsq);
        equal(p->pDir,q->pDir);
        return true;
    }

    else if(p->dado != q->dado) return false;
}

void main(){

    arvore p,q;
    int n,key;

    reset(&p);
    reset(&q);

    do{
        printf("1) Push(P)\n2) Push(Q)\n3) Equal\n4) Exit: ");
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
        		if(equal(p,q)) printf("They are equal\n");

        		else printf("They are not equal\n");

        		break;

        case 4: exit(1);

        default: printf("This option doesn't exist\n");
        }
    }while(n!=4);


    free(p);
    free(q);
}
