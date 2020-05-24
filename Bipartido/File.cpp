#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define VERDE 0
#define AZUL 1

int mat[100][100]={0};//matriz de adjacencia
int cor[100];//vetor para colorir
int nao[100];//vetor para indicar qual cor não deve colorir o outro vertice da aresta
FILE *arquivo;//Ponteiro do arquivo
char nome[100]="";//Nome do arquivo  
int i=0,j=0;//variaveis para percorrer a matriz e contar vertices
char conteudo[102]; //vetor para receber o que há dentro do arquivo
int aux=0, k=0,cont=0;//variaveis auxiliares de loop
int validar = 0;//variavel responsavel por validar se o arquivo é valido ou não
int m=0;//arestas 

int saber();
void bipartido();
void verificar();

int main(){
	setlocale(LC_ALL,"Portuguese");
	do{
		system("cls");
		printf("Trabalho dos alunos: Ianny e Jacob\n\n");
		printf("Digite o nome do arquivo ou S para sair: \n");
		scanf("%s",&nome);
		
		strcat(nome,".txt");
		arquivo = fopen(nome,"r");
		
		if(arquivo==NULL&& nome[0]!='s' && nome[0]!='S'){
			printf("Arquivo inexistente, tente novamente!\n\n");
			system("pause");
		}else{
			if(nome[0]!='s' && nome[0]!='S')
				printf("Arquivo localizado com sucesso!\n\n");
		}
	}while(arquivo==NULL && nome[0]!='s' && nome[0]!='S');
	
	
	while(nome[0]!='S'&&nome[0]!='s'){
		for(cont=0;cont<100;cont++){
			cor[cont] = -1;
			nao[cont] = -1;
		}
		//Tratando a informação do arquivo do arquivo para preencher a matriz
		while(fgets(conteudo,102,arquivo)!=NULL){
			while(conteudo[aux]!='\0'&&conteudo[aux]!='\n'){
				if(conteudo[aux]!=' '){
					mat[i][j] = conteudo[aux] - '0';//convertendo em inteiro
					if(mat[i][j]==1) m++;
					j++;
				}
				if(conteudo[aux]!='\0'&&conteudo[aux]!='\n'&&conteudo[aux]!=' '&&conteudo[aux]!='0'&&conteudo[aux]!='1')//verifica se há erro no arquivo
					validar = 1;
				aux++;
			}
			i++;
			j=0;
			aux=0;
		}
		//logica
		if(!validar){
			for(cont=0;cont<i;cont++){
				for(j=0;j<i;j++){
					printf("%d ",mat[cont][j]);
				}
				printf("\n");
			}
		
			printf("\n\n n= %d e m= %d\n\n",i,m);
			bipartido();
			
			if(saber()&&!validar){
				printf("\nÉ bipartido!\n");
				printf("\nCONJUNTO 1: ");
				verificar();
				for(k=0;k<i;k++){
					if(cor[k]==VERDE)
						printf("%d ",k);
				}
				printf("\nCONJUNTO 2: ");
				for(k=0;k<i;k++){
					if(cor[k]==AZUL)
						printf("%d ",k);
				}	
				printf("\n");
				system("pause");
			}else{
				printf("\nNão é Bipartido\n");
				system("pause");
			}
		}else{
			printf("Erro1: O arquivo não possui um grafo\n\n");
			system("pause");
		}
		//logica
		fclose(arquivo);
		do{
			system("cls");
			printf("Trabalho dos alunos: Ianny e Jacob\n\n");
			printf("Digite o nome do arquivo ou S para sair: \n");
			scanf("%s",&nome);
			
			strcat(nome,".txt");
			arquivo = fopen(nome,"r");
			
			if(arquivo==NULL&& nome[0]!='s' && nome[0]!='S'){
				printf("\nArquivo inexistente, tente novamente!\n");
				system("pause");
			}else{
				if(nome[0]!='s' && nome[0]!='S')
					printf("Arquivo localizado com sucesso!\n\n");
			}
		}while(arquivo==NULL && nome[0]!='s' && nome[0]!='S');		
		i=0;
		j=0;
		validar = 0;
		m=0;
	}
	system("exit");
	return 0;
}
void bipartido(){
	int h=0,k=0;	
	for(k=0;k<i;k++){
		for(h=0;h<i;h++){
			if(mat[k][h]==1&&k<h){//Colorindo o grafo com 2 cores(Pois o bipartido so tem 2 cores)
				//colore caso seja possivel entre os 2 vetores
				if(cor[k]==-1&&nao[k]==-1){  
					cor[k]=AZUL;
				}
				//verifico de qual cor está pintado o vertice no vetor e colore o vetor "não" para garantir de não pintar o outro vertice da mesma cor 
				if(cor[k]==VERDE&&nao[h]==-1){
					nao[h]=VERDE;
				}else if(cor[k]==AZUL&&nao[h]==-1){
					nao[h]=AZUL;
				}							
				//colore o outro vertice da ligação da aresta se possivel
				if(cor[h]==-1&&nao[h]==VERDE){
					cor[h]=AZUL;
				}else{
					if(cor[h]==-1&&nao[h]==AZUL){
						cor[h]=VERDE;                    
					}
				}											
			}
		}
	}
}
int saber(){
	int k=0,h=0;	
	for(k=0;k<i;k++){
		for(h=0;h<i;h++){
			if(mat[k][h]==1&&k<h){ 
				if(cor[k]==cor[h])//validando se Existe ligação entre vertices do mesmo conjunto
					return 0;
			}
		}
	}
	return 1;//É bipartido
}

void verificar(){
	int k=0;
	for(k=0;k<i;k++){//Garantir coloração de trivial
		if(cor[k]== -1)
			cor[k]=AZUL;
	}
}
