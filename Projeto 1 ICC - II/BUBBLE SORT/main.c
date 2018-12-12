#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void init(int a[], int n, int step, int range);
void bubble_sort(int a[],int n);
void print_vector(int a[],int tam);

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
        printf("\nBUBBLE SORT APLICADO PARA %d POSICOES(VETOR ALEATORIO)\n",n);
        bubble_sort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    //vetores quase ordenados
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 10, 100);
        printf("\nBUBBLE SORT APLICADO PARA %d POSICOES(VETOR QUASE ORDENADO)\n",n);
        bubble_sort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    //vetores quase inversamente ordenado
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, -1, 100);
        printf("\nBUBBLE SORT APLICADO PARA %d POSICOES(VETOR QUASE INVERSAMENTE ORDENADO)\n",n);
        bubble_sort(a,n);
        system("PAUSE");
        system("CLS");
    }
    //vetores com muitos valores repetidos
    for(k = 6; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, n/10);
        printf("\nBUBBLE SORT APLICADO PARA %d POSICOES(VETOR COM MUITOS VALORES REPETIDOS)\n",n);
        bubble_sort(a,n);
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
//BUBBLE SORT MODIFICADO
void bubble_sort(int a[],int n){
    int tmp;
    double numero_atribuicoes = 0;
    double num_comparacoes = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(a[j] > a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                numero_atribuicoes += 3;
            }
            num_comparacoes++;
        }
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
