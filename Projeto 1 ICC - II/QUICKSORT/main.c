#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void init(int a[], int n, int step, int range);
void qs(int a[], int lo, int hi, double *comparacoes, double *atribuicoes);
void troca(int a[], int i, int j);
void printa(int a[], int n);

int main()
{
    srand(time(NULL));
    int k;//variavel para o tamanho do vetor
    int n;
    double comparacoes = 0;
    double atribuicoes = 0;
    //vetores aleatorios
   for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, 5*n);
        printf("\nQUICK SORT APLICADO PARA %d POSICOES(VETOR ALEATORIO)\n",n);
        qs(a,0,n-1, &comparacoes, &atribuicoes);
        printf("\n\nForam feitas %.f comparacoes e %.f atribuicoes\n\n",comparacoes,atribuicoes);
        //system("PAUSE");
        comparacoes = 0;
        atribuicoes = 0;
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 10, 100);
        printf("\nQUICK SORT APLICADO PARA %d POSICOES(VETOR QUASE ORDENADO)\n",n);
        qs(a,0,n-1, &comparacoes, &atribuicoes);
        printf("\n\nForam feitas %.f comparacoes e %.f atribuicoes\n\n",comparacoes,atribuicoes);
        //system("PAUSE");
        comparacoes = 0;
        atribuicoes = 0;
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, -1, 100);
        printf("\nQUICK SORT APLICADO PARA %d POSICOES(VETOR QUASE INVERSAMENTE ORDENADO)\n",n);
        qs(a,0,n-1, &comparacoes, &atribuicoes);
        printf("\n\nForam feitas %.f comparacoes e %.f atribuicoes\n\n",comparacoes,atribuicoes);
        //system("PAUSE");
        comparacoes = 0;
        atribuicoes = 0;
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, n/10);
        printf("\nQUICK SORT APLICADO PARA %d POSICOES(VETOR COM MUITOS VALORES REPETIDOS)\n",n);
        qs(a,0,n-1, &comparacoes, &atribuicoes);
        printf("\n\nForam feitas %.f comparacoes e %.f atribuicoes\n\n",comparacoes,atribuicoes);
        //system("PAUSE");
        comparacoes = 0;
        atribuicoes = 0;
        //system("CLS");
    }
    return 0;
}

void init(int a[], int n, int step, int range) {
        int i;
        for (i = 0; i < n; i++) {
                int base = i * step;
                int offset = rand() % range;
                a[i] = base + offset;
        }
}

void qs(int a[], int lo, int hi, double *comparacoes, double *atribuicoes){

    int r = (rand()%(hi-lo+1))+lo;
    int p = a[r];
    *atribuicoes+=1;
    int i = lo;
    int j = hi;

    while(i <= j){
        while(a[i] < p){
            *comparacoes+=1;
            i++;
        }
        while(a[j] > p){
            *comparacoes+=1;
            j--;
        }
        if(j >= i){
            troca (a, i, j);
            *atribuicoes+=3;
            i++;
            j--;
        }
        *comparacoes+=2;
    }

    if(lo < j){
        qs(a, lo, j, comparacoes, atribuicoes);
    }
    if (i<hi){
        qs(a,i,hi, comparacoes, atribuicoes);
    }
}

void troca(int a[], int i, int j){
    int tmp;

    tmp = a[j];
    a[j] = a[i];
    a[i] = tmp;
}

/*PARAMETROS PARA GERAR OS VETORES
    Vetor aleatório
    init(a, n, 0, 5*n);

    Vetor quase ordernado
    init(a, n, 10, 100);

    Vetor quase inversamente ordenado
    init(a, n, -1, 100);

    Vetor com muitos valores repetidos
    init(a, n, 0, n/10);
*/
