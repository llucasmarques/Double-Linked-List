/*
 * UFMT - Ciência da Computação
 * ED  1 - Prof. Ivairton
 * Aluno: Oséias Ayres Ferreira
 * Implementação de lista encadeada
 * 
 * 
 */

#ifndef LISTA_C
#define LISTA_C


#include <stdio.h>
#include <stdlib.h>

//Definição do tipo nó
struct estruturaLista{
    int dado;
    struct estruturaLista *prox;
    struct estruturaLista *ant;
};
typedef struct estruturaLista tipoLista;


//prototipos
void insereFim(tipoLista **lst,int valor);
tipoLista* alocaNo(int valor);
void imprimeLista(tipoLista *lst);
void inversao(tipoLista **lst);


//Função que faz a inserção no fim
void insereFim(tipoLista **lst,int valor){
      tipoLista *novoNO,*aux;
    novoNO = NULL;
    
    //se caso nao tiver nada
    if(*lst == NULL){
        novoNO = alocaNo(valor);//aloca esse valor
        *lst = novoNO;
        
    //se tover mais valores
    }else{
        novoNO = alocaNo(valor);//aloca
        aux = *lst;//auxiliar receber a primeiro elemento
        while(aux->prox != NULL){//vai indo para o proximo ate achar a ultima posição
            aux = aux->prox;
            
        }
        novoNO->ant = aux;//recebe o auxiliar que eh o atual ultimo
        aux->prox = novoNO;// o atual ultimo recebe o novo valor 
    }
    
}

//Função que realiza a alocação de um novo nó
tipoLista* alocaNo(int valor){
    tipoLista *novoNo;
    
    novoNo = novoNo = (tipoLista*) malloc(sizeof(tipoLista));
    if(novoNo){
        novoNo->dado = valor;
        novoNo->prox = NULL;
        
    }
    return novoNo;
    
}



//Função para impressao da lista
void imprimeLista(tipoLista *lst){
    while(lst != NULL){
        printf("[%d]",lst->dado);
        lst = (tipoLista *) lst->prox;
        
    }
    printf("\n");
}


void inversao(tipoLista **lst){

    tipoLista *aux, *aux2;
    aux = (*lst)->prox;//inicializando os ponteiros aux
    aux2 = (*lst)->prox->prox;// inicializa na frente de aux
    
    (*lst)->ant = (*lst)->prox;//primeiro no
    (*lst)->prox = NULL;
    
    
    while(aux2 != NULL){
        //modificando os do meio
        aux->prox = aux->ant;
        aux->ant = aux2;
        //andando com os auxiliares
        aux = aux2;
        aux2 = aux2->prox;
    }
    //trabalhando 
    aux->prox = aux->ant;
    aux->ant = NULL;
    (*lst) = aux;
    
}

#endif 