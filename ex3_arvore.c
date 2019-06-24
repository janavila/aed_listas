#include <stdio.h>
#include <stdlib.h>


struct tree{
    int dado;
    struct tree *pEsq,*pDir;
};

typedef struct tree *arvore; //ponteiro duplo para modificar a arvore na main ao mesmo tempo.

void reset(arvore *p){
    *p = NULL;
}

void push(arvore *p,int d){

    if(*p == NULL){ // chega em um elemento que não foi criado ainda.
       *p = (arvore) malloc (sizeof(struct tree)); // cria o espaço.
       (*p)->dado = d;
       (*p)->pDir = NULL;// declara que é nulo para poder entrar nesse if futuramente.
       (*p)->pEsq = NULL; // ""          ""          ""          ""          ""      ""
       return; // sai da função.
    }

    if(d > (*p)->dado){
    push(&(*p)->pDir,d);
    return;
    }

    if(d < (*p)->dado){
    push(&(*p)->pEsq,d);
    return;
    }

    else printf("Error: The register is already on the tree\n\n"); // Caso o dado(chave) for igual.

}

void count(arvore p,int *c) {
    if(p==NULL) return;

    if(p->pEsq != NULL){ // Se for diferente de NULL, ele terá descendente, sendo assim, não é um nó folha.
        (*c)++;
        count(p->pEsq,c);
        return;
    }

    if(p->pDir != NULL){
        (*c)++;
        count(p->pDir,c);
        return;
    }

}



int main(){
    arvore p;
    int *c = (int*) malloc (sizeof(int));
    *c = 0;

    reset(&p);
    push(&p,1);
    push(&p,2);
    push(&p,3);
    push(&p,4);

    count(p,c);

    printf("Numero de nos nao-folhas: %d", *c);

    free(c);
    free(p);

    return 0;
}
