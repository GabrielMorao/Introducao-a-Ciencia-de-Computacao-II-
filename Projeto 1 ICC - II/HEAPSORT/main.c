#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void init(int a[], int n, int step, int range);
void heapsort (int a[], int n);
void heapfy (int a[], int p, int n,double *comparacoes,double *atribuicoes );

int main()
{
    srand(time(NULL));
    int k;//variavel para o tamanho do vetor
    int n;
    //vetores aleatorios
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, 5*n);
        printf("\nHEAPSORT APLICADO PARA %d POSICOES(VETOR ALEATORIO)\n",n);
        heapsort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 10, 100);
        printf("\nHEAPSORT APLICADO PARA %d POSICOES(VETOR QUASE ORDENADO)\n",n);
        heapsort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, -1, 100);
        printf("\nHEAPSORT APLICADO PARA %d POSICOES(VETOR QUASE INVERSAMENTE ORDENADO)\n",n);
        heapsort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, n/10);
        printf("\nHEAPSORT APLICADO PARA %d POSICOES(VETOR COM MUITOS VALORES REPETIDOS)\n",n);
        heapsort(a,n);
        //system("PAUSE");
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

void heapsort (int a[], int n){
    int i;
    int temp;
    double comparacoes = 0;
    double atribuicoes = 0;

    for(i = n-1; i >= 0; i--){
        heapfy(a, i, n, &comparacoes, &atribuicoes);
    }
    for (i=n-1; i > 0; i--){
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        atribuicoes+=3;
        heapfy(a,0,i, &comparacoes, &atribuicoes);
    }
    printf("\n\nForam feitas %.f comparacoes e %.f atribuicoes\n\n",comparacoes,atribuicoes);
}



void heapfy (int a[], int p, int n,double *comparacoes,double *atribuicoes ){
    int temp;
    while(p<n){
        int c;
        c = 2*p + 1;
        if(c<n){

            if (c+1 < n && a[c]<a[c+1]){
                c++;
            }
            *comparacoes+=1;
            if (a[c] > a[p]){
                temp = a[p];
                a[p] = a[c];
                a[c] = temp;
                *atribuicoes+=3;
            }
            *comparacoes+=1;
    }
    p = c;
}
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
