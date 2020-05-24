#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"


int main(){
	Arvore* A1;
	A1 = criar();
	printf("\nARVORE VAZIA? %d\n",vazia(A1));
	insere(&A1,30);
	insere(&A1,20);
	insere(&A1,25);
	insere(&A1,10);
	insere(&A1,40);
	insere(&A1,50);
	insere(&A1,45);
	insere(&A1,60);

	
	printf("\nARVORE VAZIA? %d\n\n",vazia(A1));
	imprimir_ord(A1);
	busca(&A1,60);
//	remover(&A1,20);
	imprimir_ord(A1);
	printf("\nMAIOR ELEMENTO =  %d\n",maior_ele(A1));
	printf("\nMENOR ELEMENTO =  %d\n",menor_ele(A1));
	printf("\nQUANTIDADE DE NÓS =  %d\n",Quantidade(A1));
	printf("\nALTURA DA ARVORE = %d\n",altura(&A1));
	imprimir_nivel(A1);
	printf("\n");
	imprimir_pre(A1);
	return 0;
}

/*
	
*/
