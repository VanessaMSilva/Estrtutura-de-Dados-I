#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    int dado;
    struct no *prox;
} noptr;

noptr *insere_lista(noptr *inicio,noptr *novo, int valor)
{
    novo->dado = valor; //(*novo).dados = valor
    if(inicio==NULL)//se for o 1°elemento
        novo->prox = NULL;//o proximo recebe a posicao nula
    else
        novo->prox=inicio; // o prox recebe a posicao que lista esta apontando
    inicio = novo; //a variavel lista recebe aonde o (novo) esta apontando

    return inicio;
}

void lista_todos(noptr *inicio)
{
    if(inicio==NULL)
    {
        printf("\nLista vazia!");
        return;
    }
    noptr *p; // declara um ponteiro auxiliar que vai pegar o endereco da variavel
    p=inicio; //pega o endereco do inicio da lista(o ultimo elemento inserido)
    printf("\n________________________________________ ");
    printf("\n\tLISTAGEM FILA:");
    while(p!=NULL)  //enquanto p for diferente de nulo
    {
        printf("\nDado: %d",p->dado); // (*p).dados  p=endereco em que se encontra o dados
        p = p->prox; // p vai receber o endereco do proximo endereco
    }
    printf("\n________________________________________ ");
    printf("\n");

}

noptr *preencher(noptr *inicio)
{
    int valor;
    noptr *info;
    printf("________________________________________ ");
    printf("\n                                        ");
    printf("\nPARA PARAR DE PREENCHER A LISTA DIGITE 0");
    printf("\n________________________________________");
    printf("\n\n\tPREENCHER LISTA\n");
    do
    {
        printf("\nDigite um numero: ");
        scanf("%d",&valor);
        if(valor!=0)
        {
            info =(struct no*) malloc(sizeof(noptr));
            if(!valor)
            {
                printf("\nSem memoria!");
                return;
            }
            inicio = insere_lista(inicio,info,valor);
        }
    }
    while(valor!=0);
    return inicio;
}

void inserir_novaCelula(inicio)
{
    int valor;
    int dado;
    noptr *info;
    bool verifica;
    noptr *p,*auxan=NULL,*auxp=NULL;;
    printf("Digite o valor a ser inserido: ");
    scanf("%d",&valor);
    do
    {
        p = inicio;
        auxp = p->prox;
        verifica = true;
        printf("\nDigite qual apos qual dado sera inserido: ");
        scanf("%d",&dado);
        info =(struct no*) malloc(sizeof(noptr));
        while(p!=NULL)
        {
            if(p->dado==dado)
            {
                verifica = false;
                info->dado = valor;
                if(auxan==NULL)
                {
                    p->prox = info;
                    info->prox = auxp;
                }
                else
                {
                    auxp = p->prox;
                    p->prox = info;
                    info->prox = auxp;
                }
            }
            auxan = p;
            p = p->prox;

        }
        printf("\n");
    }
    while(verifica);
}

int main()
{
    noptr *inicio;
    inicio = NULL;
    inicio = preencher(inicio);
    lista_todos(inicio);
    inserir_novaCelula(inicio);
    lista_todos(inicio);
    return 0;
}
/*Escreva uma função que insira uma nova célula imediatamente depois da k-ésima célula
de uma lista encadeada formada por números inteiros.*/
