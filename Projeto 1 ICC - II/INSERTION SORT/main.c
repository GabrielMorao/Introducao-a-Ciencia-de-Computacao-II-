#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void init(int a[], int n, int step, int range);
void insertion_sort(int a[],int n);
void print_vector(int a[],int tam);


int main()
{
    srand(time(NULL));
    int k;
    int n;
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, 5*n);
        printf("\nINSERTION SORT APLICADO PARA %d POSICOES(VETOR ALEATORIO)\n",n);
        insertion_sort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 10, 100);
        printf("\nINSERTION SORT APLICADO PARA %d POSICOES(VETOR QUASE ORDENADO)\n",n);
        insertion_sort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    //vetores quase inversamente ordenado
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, -1, 100);
        printf("\nINSERTION SORT APLICADO PARA %d POSICOES(VETOR QUASE INVERSAMENTE ORDENADO)\n",n);
        insertion_sort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    //vetores com muitos valores repetidos
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, n/10);
        printf("\nINSERTION SORT APLICADO PARA %d POSICOES(VETOR COM MUITOS VALORES REPETIDOS)\n",n);
        insertion_sort(a,n);
        //system("PAUSE");
        //system("CLS");
    }

    return 0;
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


void init(int a[], int n, int step, int range) {
        int i;
        for (i = 0; i < n; i++) {
                int base = i * step;
                int offset = rand() % range;
                a[i] = base + offset;
        }
}

void insertion_sort(int a[],int n){
    double atrib = 0;
    double comparacoes = 0;
    for(int i=1; i<n; i++){
        int tmp = a[i];
        atrib++;
        int k = i-1;
        while(k>=0 && tmp<a[k]){
            comparacoes++;
            a[k+1] = a[k];
            atrib++;
            k--;
        }
        comparacoes++;
        a[k+1] = tmp;
        atrib++;
    }
    printf("\n\nForam feitas %.0lf comparacoes e %.0lf atribuicoes\n\n",comparacoes,atrib);
}

void print_vector(int a[],int tam){
    for(int i=0; i<tam; i++){
        printf("%d ",a[i]);
    }
}
