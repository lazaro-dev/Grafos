#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Arvore.h"

struct arvore{
	int info;
	Arvore* esq;
	Arvore* dir;
};

Arvore* criar(){
	return NULL;}

int vazia(Arvore* A){
	return(A==NULL);}

void insere(Arvore** A,int item){
	if(vazia(*A)){
		Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
		novo->info = item;
		novo->esq = NULL;
		novo->dir = NULL;
		*A = novo;
		printf("\nO ELEMENTO %d FOI INSERIDO NA ARVORE/n",novo->info);
	}else{
		if((*A)->info > item){
			insere(&(*A)->esq,item);
			if((altura(&(*A)->esq)-altura(&(*A)->dir))==2){
				if(item < (*A)->esq->info){
					rot_dir(&(*A));
				}else{
					//*A=esq_dir(&(*A));
					rot_esq(&(*A)->esq);
					rot_dir(&(*A));	
				} 
			}
		}else{
			if((*A)->info < item){
				insere(&(*A)->dir,item);
				if((altura(&(*A)->esq))-(altura(&(*A)->dir))==2){
					if(item>(*A)->dir->info){
						rot_esq(&(*A));
					}else{
						//*A=dir_esq(&(*A));
						rot_dir(&(*A)->dir);
						rot_esq(&(*A));
					}
				}
			}
		}
	}
}

void busca(Arvore** A, int item){
	setlocale(LC_ALL,"portuguese");
	Arvore* aux = *A;
	
	if(!vazia(*A)){
		if((*A)->info == item){
			printf("\nO ELEMENTO %d SE ENCONTRA NA ARVORE\n",(*A)->info);
		}else{
			if((*A)->info > item){
				busca(&(*A)->esq,item);
			}else{
				busca(&(*A)->dir,item);
			}
		}
	}else{
		printf("\nO ELEMENTO %d NÃO SE ENCONTRA NA ARVORE\n",item);
	}	
}
	
void remover(Arvore** A,int item){
	Arvore* NO;
	if(!vazia(*A)){
		if((*A)->info==item){
			NO = *A;
			if((*A)->esq == NULL){/*filho a direita*/
				(*A) = (*A)->dir;
				free(NO);
				printf("\nO ELEMENTO %d FOI REMOVIDO\n",item);
			}else{
				if((*A)->dir == NULL){/*filho a esquerda*/
					(*A) = (*A)->esq;
					free(NO);
					printf("\nO ELEMENTO %d FOI REMOVIDO\n",item);
				}else{
					(*A)->info = menor(&(*A)->dir);
					printf("\nO ELEMENTO %d FOI REMOVIDO\n",item);
				}
			}
		}else{
			if((*A)->info < item){
				remover(&(*A)->dir,item);
			}else{
				if((*A)->info > item){
					remover(&(*A)->esq,item);
				}else{
					printf("\nELEMENTO NAO EXISTE NA ARVORE\n");
				}
			}
		}
	}
}

int menor(Arvore** A){
	Arvore* aux;
	int dado=0;
	if((*A)->esq!=NULL){
		return(menor(&(*A)->esq));
	}else{
		aux = *A;
		dado = (*A)->info;
		*A = (*A)->dir;
		free(aux);
		return dado;
	}
}

void imprimir_ord(Arvore* A){
	if(!vazia(A)){
		imprimir_ord(A->esq);
		printf("%d |",A->info);
		imprimir_ord(A->dir);
	}
}

void imprimir_pre(Arvore* A){
	if(!vazia(A)){
		printf("%d |",A->info);
		imprimir_pre(A->esq);
		imprimir_pre(A->dir);
	}
}

void imprimir_pos(Arvore* A){
	if(!vazia(A)){
		imprimir_pos(A->esq);
		imprimir_pos(A->dir);
		printf("%d |",A->info);
	}
}

void imprimir_nivel(Arvore* A){
	if(!vazia(A)){
		printf("%d(",A->info);
		imprimir_nivel(A->esq);
		imprimir_nivel(A->dir);
		printf(") ");
	}
}

int maior_ele(Arvore* A){
	return ((A->dir!=NULL) ? maior_ele(A->dir) : (A->info));
}

int menor_ele(Arvore* A){
	return ((A->esq!=NULL) ? menor_ele(A->esq) : (A->info));
}

int Quantidade(Arvore* A){
	if(vazia(A)){
		return 0;
		}else{
			if(A->dir!=NULL && A->esq!=NULL){
				return 1 + (Quantidade(A->dir) + Quantidade(A->esq));
			}else{
				if((A->dir==NULL) && (A->esq!=NULL)){
					return 1 + Quantidade(A->esq);
				}else{
					if((A->dir!=NULL) && (A->esq==NULL)){
						return 1 + Quantidade(A->dir);
					}else{
						return 1;
					}		
					
				}
			}
		}
}
int altura(Arvore** A){
	int esq,dir;
	if(vazia(*A)){
		return -1;
	}else{
		esq = altura(&(*A)->esq);
		dir = altura(&(*A)->dir);
		if(esq < dir){
			return dir+1;
		}else{
			return esq+1;
		}
	}
}
void esq_dir(Arvore** A){
	rot_esq(&(*A)->esq);
	rot_dir(&(*A));	
}
void dir_esq(Arvore** A){
	rot_dir(&(*A)->dir);
	rot_esq(&(*A));
}
void rot_dir(Arvore** A){
	Arvore* aux;
	if(!vazia(*A)){
		aux = (*A)->esq;
		(*A)->esq = aux->dir;
		aux->dir = (*A);
		(*A) = aux;
	}
}
void rot_esq(Arvore** A){
	Arvore* aux;
	if(!vazia(*A)){
		aux = (*A)->dir;
		(*A)->dir = aux->esq;
		aux->esq = (*A);
		(*A) = aux;
	}
}

