#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   int chave;
   int valor;
   struct Node *esq;
   struct Node *dir;
}Node;

typedef struct{
    Node *root;                             //aponta para o inicio da arvore
}abb;

abb* cria_arvore(){
    abb*arv = (abb*)malloc(sizeof(abb));    //crio e aloco o tipo abb
    arv->root = NULL;                       //aponto ele para NULL
    return arv;
}

int insere_arvore(abb *arv,int valor,int chave){
    Node *n_aux;                            //no a ser inserido
    n_aux = (Node*)malloc(sizeof(Node));    //fase de alocação do n_aux
    if(n_aux == NULL){
        return 1;
    }
    n_aux->valor = valor;
    n_aux->chave = chave;
    n_aux->dir = NULL;
    n_aux->esq = NULL;
    //fim da fase de alocação
    Node *atual = arv->root;                //começaremos a busca pelo local de inserção
    Node *ant = NULL;                       //para isso serão instanciados 2 ponteiros
    if(arv->root == NULL){                  //se a arvore(raiz) está vazia o elemento sera a raiz
        arv->root = n_aux;
    }
    else{
        while(atual != NULL){               //loop para achar o local
            if(atual->chave > n_aux->chave){
                ant = atual;
                atual = atual->esq;
            }
            else if(atual->chave < n_aux->chave){
                ant = atual;
                atual = atual->dir;
            }
            else{
                atual->valor = n_aux->valor;
                return 0;
            }
        }
        if(ant->chave > n_aux->chave){
            ant->esq = n_aux;
        }
        else{
            ant->dir = n_aux;
        }
    }
    return 0;
}

int busca_arvore(abb*arv,int chave){
    Node *aux = arv->root;
    int lvlcount = 0;//contara o nivel em que estamos
    if(arv->root == NULL){
        return -2;//flag arvore vazia
    }
    while(aux != NULL){
        if(aux->chave > chave){
            aux = aux->esq;
        }
        else if(aux->chave < chave){
            aux = aux->dir;
        }
        else{
            printf("Nivel em que foi encontrado : %d\n",lvlcount);
            return aux->valor;
        }
        lvlcount++;
    }
    printf("Elemento nao encontrado\n");
    return -1;
}

/*Função que retorna um no que sera para onde o ponteiro anterior, contido na proxima função apontara apos a remoção*/
Node* remove_no(Node*atual){
    Node *no1,*no2;                         //criação de 2 ponteiros auxiliares
    if(atual->esq == NULL){                 //se for uma folha ou se tem 1 so filho sendo esse o da direita
        no2 = atual->dir;
        free(atual);
        return no2;                        //retorno null ou o filho da direita
    }
    no1 = atual;                            //para começarmos a nova busca no1 eh o anterior de no2
    no2 = atual->esq;                       //iremos para a esquerda
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;                     //acharemos o filho da arvore da esquerda mais a direita
    }
    //se não e o caso de 1 filho sendo o da esquerda
    if(no1 != atual){
        no1->dir = no2->esq;               //aponto para a esquerda do filho mais a direita que ou e null ou e uma subarvore
        no2->esq = atual->esq;             //aponto no2 para o mesmo que atual
    }
    no2->dir = atual->dir;                 //se tiver so 1 filho isso e NULL se tiver 2 filhos isso e a subarvore da direita de atual
    free(atual);
    return no2;                             //filho da direita ou o mais a direita da subarvore da esquerda
}

/*Função que acha qual sera removido e muda o poteiro anterior a esse para o correto apos a remoção*/
int remove_da_arvore(abb*arv,int chave){
    if(arv->root == NULL){
        return 1;//erro, arvore vazia nao pode remover
    }
    Node *atual = arv->root;
    Node *ant = NULL;
    while(atual != NULL){
        if(chave == atual->chave){//se for o elemento procurado
            //se o atual for a raiz, e um caso especial
            if(atual == arv->root){
                arv->root = remove_no(atual);
            }
            else{
                //testo se o atual e o da esquerda ou da direita
                if(ant->dir == atual){
                    ant->dir = remove_no(atual);
                }
                else{
                    ant->esq = remove_no(atual);
                }
            }
            return 0;
        }
        //se não for, sigo procurando
        ant = atual; //atualizo ant antes do atual
        //vejo se irei para esquerda ou direita
        if(chave > atual->chave){
        atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return -1;//se saiu do loop e nao achou, retornar erro
}

int main()
{
    int opc;
    int num_aux;
    int chave_aux;
    abb *minha_arvore = cria_arvore();

    while(opc != 4){
        printf("DIGITE A OPERACAO A SER REALIZADA 1) INSERIR, 2) REMOVER, 3) BUSCAR, 4) SAIR :");
        scanf("%d",&opc);
        getchar();
        switch(opc){
        case 1:
            printf("DIGITE O NUMERO A SER INSERIDO E A CHAVE: ");
            scanf("%d",&num_aux);
            scanf("%d",&chave_aux);
            insere_arvore(minha_arvore,num_aux,chave_aux);
            break;
        case 2:
            printf("DIGITE A CHAVE A SER REMOVIDA: ");
            scanf("%d",&chave_aux);
            remove_da_arvore(minha_arvore,chave_aux);
            break;
        case 3:
            printf("DIGITE A CHAVE A SER BUSCADA: ");
            scanf("%d",&chave_aux);
            num_aux = busca_arvore(minha_arvore,chave_aux);
            printf("Valor da busca : %d\n",num_aux);
            break;
        case 4:
            printf("Saindo do programa...");
            break;
        }
    }
    return 0;
}
