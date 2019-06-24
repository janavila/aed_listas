#include <stdio.h>
#include <stdlib.h>

struct tree{
    int dado;
    struct tree *pEsq,*pDir
};

typedef struct tree *arvore;

void reset(arvore *p){
    *p = NULL;
}




int main(){

    arvore p;

    reset(&p);


    return 0;
}
