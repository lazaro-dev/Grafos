typedef struct arvore Arvore;

Arvore* criar();
int vazia(Arvore* A);
void insere(Arvore** A,int item);
void busca(Arvore** A,int item);
void remover(Arvore** A , int item);
int menor(Arvore** A);
void imprimir_ord(Arvore* A);
void imprimir_pre(Arvore* A);
void imprimir_pos(Arvore* A);

void imprimir_nivel(Arvore* A);

int maior_ele(Arvore* A);
int menor_ele(Arvore* A);
int Quantidade(Arvore* A);
int altura(Arvore** A);

void rot_dir(Arvore** A);
void rot_esq(Arvore** A);
void esq_dir(Arvore** A);
void dir_esq(Arvore** A);
/*
Arvore* rot_dir(Arvore** A);
Arvore* rot_esq(Arvore** A);
Arvore* esq_dir(Arvore** A);
Arvore* dir_esq(Arvore** A);
*/

