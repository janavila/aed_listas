#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct dado{
    char nome[20];
    int idade;
};

struct aponta{
    struct dado i;
    struct aponta *prox;
};

typedef struct dado data;
typedef struct aponta lista;

lista *reset(lista *l) {
    l = (lista*) malloc (sizeof(lista));
    l->prox = NULL;
    return l;
}

lista *fim(lista *l) {
    lista *aux;
    for(aux = l; aux->prox != NULL ; aux = aux->prox);
    return aux;
}

void push(lista *l) {
    lista *aux,*l_fim;
    aux = reset(aux);
    l_fim = l;

    printf("Name: ");
    scanf("%s", aux->i.nome);
    printf("Age: ");
    scanf("%d", &aux->i.idade);

    if(l->prox == NULL){
       l->prox = aux;
       aux->prox = NULL;
    }
    else{
    l_fim = fim(l_fim);
    l_fim->prox = aux;
    aux->prox = NULL;
    }
}

bool empty(lista *l){
    if(l->prox == NULL) return true;
    else return false;
}

void list(lista *l){
    lista *aux;

    if(empty(l)){
        printf("The list is empty\nReturning...\n");
        return;
    }

    for(aux=l->prox; aux != NULL; aux = aux->prox) {
        printf("Name: %s\n", aux->i.nome);
        printf("Age: %d\n", aux->i.idade);
    }

}

bool name_verify(lista *l,data s){
    int ent=0;
    lista *aux;

    for(aux=l->prox; aux!=NULL; aux = aux->prox) {
        if(strcmp(aux->i.nome,s.nome)==0) {
        ent = 1;
        return true;
        }
    }

    if(ent == 0) return false;

}


void pop(lista *l) {
    data s;
    lista *l_fim;

    printf("Say the name: ");
    scanf("%s", s.nome);

    if(!name_verify(l,s)) {
        printf("The name is not on the list\nReturning...\n");
        return;
    }

    for(l_fim = l; l_fim != NULL; l_fim = l_fim->prox){

        if(strcmp(l_fim->prox->i.nome,s.nome)==0){
            l_fim->prox = l_fim->prox->prox;
            return;
        }

    }

}


int main()
{
    lista *l,*d;
    int n;

    l = reset(l);
    d = reset(d);

do{
    printf("1) Push\n2) List\n3) Pop\n4) Quit: ");
    scanf("%d", &n);

    switch(n){
        case 1:
        push(l);
        break;


        case 2:
            list(l);
            break;

        case 3:
            pop(l);
            break;

        case 4: exit(1);
        default: printf("Doesn't exist\n");
}
}while(n!=5);

    return 0;
}
