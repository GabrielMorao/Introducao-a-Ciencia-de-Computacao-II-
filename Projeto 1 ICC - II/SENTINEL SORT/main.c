#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void init(int a[], int n, int step, int range);
void bubble_sort_sentinela(int a[],int n);
void print_vector(int a[],int tam);

int main()
{
    srand(time(NULL));
    int k;//variavel para o tamanho do vetor
    int n;

    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, 5*n);
        printf("\nBUBBLE SORT APLICADO PARA %d POSICOES(VETOR ALEATORIO)\n",n);
        bubble_sort_sentinela(a,n);
        //system("PAUSE");
        //system("CLS");
    }

    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 10, 100);
        printf("\nBUBBLE SORT APLICADO PARA %d POSICOES(VETOR QUASE ORDENADO)\n",n);
        bubble_sort_sentinela(a,n);
        //system("PAUSE");
        //system("CLS");
    }

    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, -1, 100);
        printf("\nBUBBLE SORT APLICADO PARA %d POSICOES(VETOR QUASE INVERSAMENTE ORDENADO)\n",n);
        bubble_sort_sentinela(a,n);
        //system("PAUSE");
        //system("CLS");
    }

    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, n/10);
        printf("\nBUBBLE SORT APLICADO PARA %d POSICOES(VETOR COM MUITOS VALORES REPETIDOS)\n",n);
        bubble_sort_sentinela(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    return 0;
}
//FUNÇÃO QUE GERA VETORES ALEATORIOS
void init(int a[], int n, int step, int range) {
        int i;
        for (i = 0; i < n; i++) {
                int base = i * step;
                int offset = rand() % range;
                a[i] = base + offset;
        }
}

void bubble_sort_sentinela(int a[],int n){
    double num_comparacoes = 0;
    double numero_atribuicoes = 0;
    int i = n - 1;
    while(i > 0) {
        int s = -1;
        int k;
        for(k = 0; k < i; k++) {
            if(a[k] > a[k+1]) {
            s = k;
            int t = a[k];
            a[k] = a[k+1];
            a[k+1] = t;
            numero_atribuicoes +=3;
            }
            num_comparacoes++;
        }
        i = s;
    }
    printf("\n\nForam feitas %.0lf comparacoes e %.0lf atribuicoes\n\n",num_comparacoes,numero_atribuicoes);
}



void print_vector(int a[],int tam){
    for(int i=0; i<tam; i++){
        printf("%d ",a[i]);
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
