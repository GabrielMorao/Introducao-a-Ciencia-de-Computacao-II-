#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void init(int a[], int n, int step, int range);
void CocktailSort(int a[], int n);

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
        printf("\nBUBBLE COQUETEL APLICADO PARA %d POSICOES(VETOR ALEATORIO)\n",n);
        CocktailSort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 10, 100);
        printf("\nBUBBLE COQUETEL APLICADO PARA %d POSICOES(VETOR QUASE ORDENADO)\n",n);
        CocktailSort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, -1, 100);
        printf("\nBUBBLE COQUETEL APLICADO PARA %d POSICOES(VETOR QUASE INVERSAMENTE ORDENADO)\n",n);
        CocktailSort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, n/10);
        printf("\nBUBBLE COQUETEL APLICADO PARA %d POSICOES(VETOR COM MUITOS VALORES REPETIDOS)\n",n);
        CocktailSort(a,n);
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

void CocktailSort(int a[], int n)
{
    int swap = 0;
    int comeco = 0;
    int fim = n - 1;
    int temp;
    double comparacoes = 0;
    double atribuicoes = 0;

    while(swap == 0 && comeco < fim)
    {
        swap = 1;
        for (int i = comeco; i < fim; i++)
        {
            comparacoes++;
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                atribuicoes+=3;
                swap = 0;
            }
        }
        fim--;

        for (int i = fim; i > comeco; i--)
        {
            comparacoes++;
            if(a[i] < a[i-1])
            {
                temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                atribuicoes+=3;
                swap = 0;
            }
        }
        comeco++;
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
