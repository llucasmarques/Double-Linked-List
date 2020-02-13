
#include <stdio.h>
#include <stdlib.h>

#include "inverte.c"

int main(){
    
    tipoLista *lista;
    lista = NULL;
    
     //Inserções
   insereFim(&lista,1);
   insereFim(&lista,2);
   insereFim(&lista,3);
   insereFim(&lista,4);
 
    
    printf("Lista original: \n");
    imprimeLista(lista);
    printf("\n\n\n");

    printf("Lista após a inversão: \n");
    inversao(&lista);
    imprimeLista(lista);
    printf("\n\n\n");
    return 1;
}
