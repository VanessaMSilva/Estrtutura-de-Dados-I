#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

typedef struct no{
    char nome[30];
    float notaFinal;
    struct no *prox;
} noptr;

noptr *insere_lista(noptr *inicio,noptr *novo, float valor,char nomeA[]){
    novo->notaFinal = valor;
    strcpy(novo->nome,nomeA);
    if(inicio==NULL)
        novo->prox = NULL;
    else
        novo->prox=inicio;
    inicio = novo;
    return inicio;
}

void listar_lista(noptr *inicio){
    if(inicio==NULL)
    {
        printf("\nLista vazia!");
        return;
    }
    noptr *p;
    p=inicio;
    while(p!=NULL)
    {
        if(p->notaFinal>=7){
             printf("\n______________________________");
                printf("\n\tALUNO APROVADO:");
                printf("\n------------------------------");
                printf("\nNome aluno(a): %s",p->nome);
                printf("\nNota final do aluno(a): %.2f",p->notaFinal);
                printf("\n______________________________");
        }
        p = p->prox;
    }
    printf("\n");

}

int main(){
    noptr *info;
    noptr *inicio;
    inicio = NULL;
    char nome[30];
    float nota;
    int op;
    do{
        printf("______________________________\n");
        printf("\n(1) CADASTRAR ALUNO");
        printf("\n(2) MOSTRAR ALUNOS APROVADOS");
        printf("\n(3) SAIR");
        printf("\n______________________________\n");
        printf("\nDigite a opcao: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("\n______________________________");
                printf("\n\tCADASTRAR ALUNO:");
                printf("\n------------------------------");
                info =(struct no*) malloc(sizeof(noptr));
                if(!info){
                    printf("\nSem memoria!");
                    return;
                }
                setbuf(stdin,NULL);
                printf("\nNome aluno(a): ");
                scanf("%s",nome);
                printf("\nNota final do aluno(a): ");
                scanf("%f",&nota);
                inicio = insere_lista(inicio,info,nota,nome);
                printf("\n------------------------------");
                break;
            case 2:
                listar_lista(inicio);
                break;
            case 3:
                printf("\nSAINDO");
                break;
            default:
                printf("\nOPCAO INVALIDA TENTE NOVAMENTE");
                break;

        }
        printf("\n");
        system("pause");
        system("cls");
    }while(op!=3);

    printf("\n");
    return 0;
}
/*Faça um programa que cadastre alunos. Para cada aluno devem ser cadastrados nome e
notafinal. Os dados devem ser armazenados em uma lista encadeada. Em seguida, o
programadeve mostrar apenas o nome dos alunos aprovados, ou seja, alunos com nota
 final de nomínimo 7. Se nenhum aluno estiver aprovado, mostrar mensagem.*/
