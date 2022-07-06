#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no{
    int dados;
    struct no *prox;
}noptr;

noptr *insere_lista(noptr *inicio,noptr *novo, int valor){
    novo->dados = valor;
    if(inicio==NULL)
        novo->prox = NULL;
    else
        novo->prox = inicio;
    inicio=novo;
    return inicio;
}

void listar_todos(noptr *inicio){
    printf("\nTODOS OS ELEMENTOS DA LISTA");
    if(inicio == NULL){
        printf("\nLista vazia");
        return;
    }
    noptr *p;
    p = inicio;
    while(p!=NULL){
        printf("\nDado: %d",p->dados);
        p = p->prox;
    }
    printf("\n");
}

noptr *preencher(noptr *inicio){
    noptr *info;
    int valor;
    do{
        printf("\nDigite o valor: ");
        scanf("%d",&valor);
        if(valor!=0){
            info =(struct no*) malloc(sizeof(noptr));
            if(!info){
                printf("\nSem memoria!");
                return;
            }
            inicio = insere_lista(inicio,info,valor);
        }
    }while(valor != 0);
    return inicio;
}

noptr *troca_lista(noptr *inicio){
    noptr *p;
    noptr *p1;
    noptr *paux;
    noptr *paux1;
    p = inicio;
    p1 = inicio;
    paux = NULL;
    paux1 = NULL;

    int verifica;
    int valor1, valor2;
    do{
        printf("Digite 1o valor a ser trocado: ");
        scanf("%d",&valor1);
        while(p && p->dados!=valor1){
            paux = p;
            p = p->prox;
        }
        if(p==NULL)
            verifica = 0;
        else
            verifica = 1;
    }while(verifica != 1);

    do{
        printf("Digite 2o valor a ser trocado: ");
        scanf("%d",&valor2);
        while(p1 && p1->dados!=valor2){
            paux1 = p1;
            p1 = p1->prox;
        }
        if(p1==NULL)
            verifica = 0;
        else
            verifica = 1;
    }while(verifica != 1);
     if(paux == NULL)
        inicio = p1;
     else
        paux->prox = p1;
     if(paux1 == NULL)
        inicio = p;
    else
        paux1->prox = p;
    paux = p1->prox;
    p1->prox = p->prox;
    p->prox = paux;

    return inicio;
}

int main(){
    noptr *inicio;
    inicio = NULL;
    inicio = preencher(inicio);
    listar_todos(inicio);
    inicio = troca_lista(inicio);
    listar_todos(inicio);
    system("pause");
    return 0;
}
