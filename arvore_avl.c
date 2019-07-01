
#include <stdio.h>
#include <stdlib.h>

struct tree{
    int dado;
    struct tree *pEsq,*pDir;
};

typedef struct tree *arvore;

void reset(arvore *p);
int push(arvore *p,int d);
int Altura(arvore p);
int fator_balanceamento(arvore p);
void rot_simples_esq(arvore *p);
void rot_simples_dir(arvore *p);
int balanca_esquerda(arvore *p);
int balanca_direita(arvore *p);
int balanceamento(arvore *p);
void preorder(arvore p);

void reset(arvore *p){
    *p = NULL;
}

int push(struct tree **p, int d){

    if(*p == NULL){
         *p = (arvore) malloc (sizeof(struct tree));
        (*p)->dado = d;
        (*p)->pDir = NULL;
        (*p)->pEsq = NULL;
        return 1;
    }

    else if(d > (*p)->dado){
        push(&(*p)->pDir,d);
            if(balanceamento(p)) return 0;
            else return 1;
    }

    else if(d < (*p)->dado){
        push(&(*p)->pEsq, d);
            if(balanceamento(p)) return 0;
            else return 1;
    }

    else {
    printf("Error: The register is already on the tree...\n");
    return 0;
    }

}

int Altura(struct tree *p){ // Calcula a diferença entre as sub-árvores da direta e esquerda, sendo que podem ter o tamanho de diferença de no máximo 1.

    int iEsq,iDir;

    if(p == NULL) return 0;

    iEsq = Altura(p->pEsq);
    iDir = Altura(p->pDir);

    if( iEsq > iDir) return iEsq + 1;
    else return iDir + 1;


}

int fator_balanceamento(struct tree *p){ // É a diferença entre a altura da sub-árvore esquerda comparado a sub-árvore da direta.

    if(p == NULL) return 0;

    return Altura(p->pEsq) - Altura(p->pDir);

}

void rot_simples_esq(struct tree **p){ // FB < -1 (subárvore esquerda menor que subárvore direita).

    struct tree *aux;
    aux = (*p)->pDir;
    (*p)->pDir = aux->pEsq;
    aux->pEsq = *p;
    *p = aux; // talvez de problema aqui
}


void rot_simples_dir(struct tree **p){ // FB > 1 (subárvore esquerda maior que subárvore direita).
    struct tree *aux; // auxiliar para posição de memória.

    aux = (*p)->pEsq;
    (*p)->pEsq = aux->pDir;
    aux->pDir = *p;
    *p = aux; // talvez de problema aqui
}

int balanca_esquerda(struct tree **p){

    int fator_bal_esq = fator_balanceamento((*p)->pEsq);

    if(fator_bal_esq > 0){
       rot_simples_dir(p);
       return 1;
    }

    else if( fator_bal_esq < 0){ // Rotação Dupla Direita.

        rot_simples_esq(&((*p)->pEsq));
        rot_simples_dir(p);
        return 1;

    }
    return 0;

}


int balanca_direita(struct tree **p){

    int fator_bal_dir = fator_balanceamento( (*p)->pDir);

    if(fator_bal_dir > 0){
        rot_simples_esq(p);
        return 1;
    }

    else if( fator_bal_dir < 0){ // rotação dupla esquerda.
        rot_simples_dir(&((*p)->pDir));
        rot_simples_esq(p);
        return 1;
    }
    return 0;
}


int balanceamento(struct tree **p) {
    int fb = fator_balanceamento(*p);

    if(fb > 1){
        return balanca_esquerda(p);
    }

    else if (fb < -1){
        return balanca_direita(p);
    }

    else return 0;
}

void preorder(arvore p){

    if(p == NULL) return;

    preorder(p->pEsq);
    preorder(p->pDir);

    printf("Dado: %d\n", p->dado);

}

int check(arvore p){ // verifica se a árvore é avl.

    int fb;
    if(p == NULL) return 1;

    if(!(check(p->pEsq))) return 0;
    if(!(check(p->pDir))) return 0;

    fb = fator_balanceamento(p);
    if((fb > 1) || (fb < -1)) return 0;
    else return 1;
}


void main(){

    arvore p;
    int n,key;

    reset(&p);

    do{
        printf("1) Push\n2) List(Preorder)\n3) Verify\n4) Exit: ");
        scanf("%d", &n);

        switch(n){
        case 1:
                printf("Key: ");
                scanf("%d", &key);

                push(&p,key);

                break;

        case 2:
                preorder(p);
                break;
        case 3:
                if(check(p)) printf("It is AVL\n");
                else printf("It is not AVL\n");
                break;

        case 4: exit(1);

        default: printf("This option doesn't exist\n");
        }
    }while(n!=4);


    free(p);
}
