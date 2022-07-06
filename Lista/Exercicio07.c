#include <stdio.h>
#include <stdlib.h>

#define max 5

typedef struct no{
    int dados;
    struct no *prox;
}noptr;

void preencher_vetor(int *vetor[]){
    printf("_______________________________");
    printf("\n\n\tPREENCHER VETOR");
    printf("\n-------------------------------\n");
    for(int i=0; i< max ; i++){
        printf("[%d]: ",i);
        scanf("%d",&vetor[i]);
    }
}

void ler_vetor(int *vetor[]){
    printf("_______________________________");
    printf("\n\n\tLEITURA VETOR");
    printf("\n-------------------------------\n");
    for(int i=0; i< max ; i++){
        printf("\n[%d]: %d",i,vetor[i]);

    }

}

void listar_lista(noptr *inicio){
    if(inicio==NULL)
    {
        printf("\nLista vazia!");
        return;
    }
    noptr *p; // declara um ponteiro auxiliar que vai pegar o endereco da variavel
    p=inicio; //pega o endereco do inicio da lista(o ultimo elemento inserido)
    printf("\n_______________________________");
    printf("\n\n\tLEITURA LISTA");
    printf("\n-------------------------------\n");
    while(p!=NULL)  //enquanto p for diferente de nulo
    {
        printf("\nDado: %d",p->dados); // (*p).dados  p=endereco em que se encontra o dados
        p = p->prox; // p vai receber o endereco do proximo endereco
    }
    printf("\n");

}

noptr *insere_lista(noptr *inicio,noptr *novo, int valor){
    novo->dados = valor;
    if(inicio==NULL)
        novo->prox = NULL;
    else
        novo->prox=inicio;
    inicio = novo;
    return inicio;
}

noptr *preencher_lista(noptr *inicio, int *vetor[]){
    noptr *info;
    for(int i=max-1; i>=0; i--){
        info =(struct no*) malloc(sizeof(noptr));
        if(!info){
                printf("\nSem memoria!");
                return;
        }
        inicio = insere_lista(inicio,info,vetor[i]);
    }
    return inicio;
}

int main(){
    noptr *inicio;
    inicio = NULL;
    int vetor[max];
    preencher_vetor(vetor);
    ler_vetor(vetor);
    inicio = preencher_lista(inicio,vetor);
    listar_lista(inicio);
    printf("\n");
    return 0;
}
/*Escreva   uma   função   que   copie   o   conteúdo   de   um   vetor
  para   uma   lista   encadeadapreservando a ordem dos elementos.*/
