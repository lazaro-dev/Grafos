#include<stdio.h>
#include<stdlib.h>
#define VERDE 0
#define AZUL 1

int mat[100][100]= {{0,1,0,0,0,0,0},
					{1,0,1,0,1,0,0},
					{0,1,0,1,0,0,0},
					{0,0,1,0,1,0,1},
					{0,1,0,1,0,1,0},
					{0,0,0,0,1,0,1},
					{0,0,0,1,0,1,0}};					
/*
int mat[100][100]= {{0,1,1},//K3
					{1,0,1},
					{1,1,0},
				};						

int mat[100][100]= {{0,1,1,1,1},//K5
					{1,0,1,1,1},
					{1,1,0,1,1},
					{1,1,1,0,1},
					{1,1,1,1,0},
					};
*/								
int cor[7]={-1,-1,-1,-1,-1};//vetor para colorir
int nao[7]={-1,-1,-1,-1,-1};//vetor para indicar qual cor não deve colorir o outro vertice da aresta

int bipartido(){
	int i=0,j=0;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(mat[i][j]==1&&i<j){//Colorindo o grafo com 2 cores(Pois o bipartido so tem 2 cores)
				if(cor[i]==-1&&nao[i]==-1){
					cor[i]=AZUL;
				}
				if(cor[i]==VERDE&&nao[j]==-1){
					nao[j]=VERDE;
				}else if(cor[i]==AZUL&&nao[j]==-1){
					nao[j]=AZUL;
				}
				if(cor[j]==-1&&nao[j]==VERDE){
					cor[j]=AZUL;
				}else{
					if(cor[j]==-1&&nao[j]==AZUL){
						cor[j]=VERDE;                    
					}
				}											
			}
			
		}
	}
}

int saber(){
	int i=0,j=0;	
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(mat[i][j]==1&&i<=j){
				if(cor[i]==cor[j])//validando se Existe ligação entre vertices do mesmo conjunto
					return 0;
			}
			if(mat[i][j]==1&&i==j){//validando se tem loop
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	int i=0,j=0;
	printf("\nArestas\n\n");
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){//Mostrando as arestas existentes
			if(mat[i][j]!=0&&i<j){
				printf("%d,%d ",i,j);
			}	
		}
		printf("\n");
	}
	printf("\n");
	bipartido();
	//mostrando os dois conjuntos
	printf("VERDE: ");
	for(i=0;i<7;i++){
		if(cor[i]==VERDE)
			printf("%d ",i);
	}
	printf("\nAZUL: ");
	for(i=0;i<7;i++){
		if(cor[i]==AZUL)
			printf("%d ",i);
	}
	printf("\n\nBIpartido Nao-0 SIM-1 \n\n R = %d ",saber());
	printf("\n");
	return 0;
}
