#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void init(int a[], int n, int step, int range);
void selection(int a[], int n);

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
        printf("\nSELECTION APLICADO PARA %d POSICOES(VETOR ALEATORIO)\n",n);
        selection(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 10, 100);
        printf("\nSELECTION APLICADO PARA %d POSICOES(VETOR QUASE ORDENADO)\n",n);
        selection(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, -1, 100);
        printf("\nSELECTION APLICADO PARA %d POSICOES(VETOR QUASE INVERSAMENTE ORDENADO)\n",n);
        selection(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, n/10);
        printf("\nSELECTION APLICADO PARA %d POSICOES(VETOR COM MUITOS VALORES REPETIDOS)\n",n);
        selection(a,n);
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

void selection(int a[], int n)
{
    int i;
    double comparacoes = 0;
    double atribuicoes = 0;

    for(i = 0; i < n - 1; i++) {
        int m = i;
        int k;
        for(k = i + 1; k < n; k++) {
            if(a[k] < a[m]){
                m = k;
            }
            comparacoes+=1;
        }

    int tmp = a[i];
    a[i] = a[m];
    a[m] = tmp;
    atribuicoes+=3;
    }
    printf("\n\nForam feitas %.f comparacoes e %.f atribuicoes\n\n",comparacoes,atribuicoes);
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
