#include <stdio.h>
#include <stdlib.h>

struct data{
    char nome[20];
    int idade;
};

struct tree{
    struct data inf;
    struct tree *pEsq,*pDir;
};

typedef struct data dado;
typedef struct tree *arvore;

void reset(arvore *b);
void push(dado x,arvore *p);
void search(dado *x,arvore p);
void preorder(arvore p);
void inorder(arvore p);
void central(arvore p);

void reset(arvore *b) { // inicializa.
    *b = NULL;
}

void push(dado x,arvore *p){
    if(*p == NULL) { // Cria a raiz/chega até a folha.
        *p = (arvore) malloc (sizeof(struct tree));
        (*p)->inf = x;
        (*p)->pDir = NULL;
        (*p)->pEsq = NULL;
        return;
    }

    if(x.idade < (*p)->inf.idade){
        push(x, &(*p)->pEsq);
        return;
    }

    if(x.idade > (*p)->inf.idade)
        push(x, &(*p)->pDir);
    else printf("Error: The register is already on the tree\n\n");

}

void search(dado *x, arvore p){

    if(p == NULL){ // Chega na folha, e se não achar o registro, retorna a mensagem de erro.
        printf("Error: The register is not in the tree\n\n");
        return;
    }

    if(x->idade < p->inf.idade) {
        search(x, p->pEsq);
        return;
    }

    if(x->idade > p->inf.idade) {
        search(x, p->pDir);
        return;
    }

    else *x = p->inf; // Caso for igual.

}

// referência: https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

void preorder(arvore p) { // pré-ordem.
    if(p == NULL) return; // Quando chegar na folha, retorna.
    preorder(p->pEsq);
    preorder(p->pDir);
    printf("Name: %s\n", p->inf.nome);
    printf("Age: %d\n", p->inf.idade);
}

void central(arvore p){ // central.
    if(p == NULL)return;
    central(p->pEsq);
    printf("Name: %s\n", p->inf.nome);
    printf("Age: %d\n", p->inf.idade);
    central(p->pDir);

}

void inorder(arvore p){ // Pós-ordem.
    if(p == NULL) return; // Quando chegar na folha, retorna.
    printf("Name: %s\n", p->inf.nome);
    printf("Age: %d\n", p->inf.idade);
    preorder(p->pEsq);
    preorder(p->pDir);
}




int main()
{
    arvore pinheiro;
    int n;
    dado x;

    reset(&pinheiro);

    do{
        printf("Choose a option\n1) Push\n2) Pre-Order\n3) Central\n4) In-order\n5) Search\n6) Quit: ");
        scanf("%d", &n);

        switch(n){
            case 1:
                printf("Say the name: ");
                scanf("%s", x.nome);
                printf("Tell the age: ");
                scanf("%d", &x.idade);

                push(x, &pinheiro);
            break;

            case 2:
                preorder(pinheiro);
                break;

            case 3:
                central(pinheiro);
                break;

            case 4:
                inorder(pinheiro);
                break;

            case 5:
                printf("Say the age: "); // provisório.
                scanf("%d", &x.idade);
                search(&x,pinheiro);
                break;

            case 6: exit(1);

            default: printf("This option doesn't exist\n\n");
        }
    }while(n!=6);

    free(p);

    return 0;
}
