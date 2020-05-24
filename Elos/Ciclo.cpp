#include<stdio.h>
#include<stdlib.h>
int  busca(int conj[], int vert);
void elos();
int i,j;
int nvert = 5;
int mat[100][100] ={{0, 1, 1, 1, 1 },
					{1, 0, 1, 1, 1 },
					{1, 1, 0, 1, 1 },
					{1, 1, 1, 0, 1 },
					{1, 1, 1, 1, 0 },	
				};
int  main (){
	printf("Arestas retiradas:\n");
	elos();
}
void elos(){
	int vert1,vert2;
	int conj[nvert];
	for(i=0;i<nvert;i++){
		conj[i] = -1;
	}
	for(i = 0;i < nvert;i++){
		for(j = i;j < nvert; j++){
			if(mat[i][j] == 1){
				vert1 = busca(conj, i);
				vert2 = busca(conj, j);
				if (vert1 == vert2){
					printf("%d,%d \n",i+1,j+1);
				}else{
					conj[vert1] = vert2;
				}
			}
		}
	}
}
int  busca(int conj[], int vert){
	if (conj[vert] == - 1 ){
		return vert;
	}else{
		return busca(conj, conj[vert]);
	}
}
