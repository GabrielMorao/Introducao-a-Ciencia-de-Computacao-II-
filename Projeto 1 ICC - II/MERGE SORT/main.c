#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void merge_sort(int *vet, int n);
void init(int a[], int n, int step, int range);

void print_vector(int a[],int tam){
    for(int i=0; i<tam; i++){
        printf("%d ",a[i]);
    }
}

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
        printf("\nMERGE SORT APLICADO PARA %d POSICOES(VETOR ALEATORIO)\n",n);
        merge_sort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 10, 100);
        printf("\nMERGE SORT APLICADO PARA %d POSICOES(VETOR QUASE ORDENADO)\n",n);
        merge_sort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, -1, 100);
        printf("\nMERGE SORT APLICADO PARA %d POSICOES(VETOR QUASE INVERSAMENTE ORDENADO)\n",n);
        merge_sort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    for(k = 2; k<=6; k++){
        n = (float)pow(10,k);
        int *a;
        a = (int *)malloc(n*sizeof(int));
        init(a, n, 0, n/10);
        printf("\nMERGE SORT APLICADO PARA %d POSICOES(VETOR COM MUITOS VALORES REPETIDOS)\n",n);
        merge_sort(a,n);
        //system("PAUSE");
        //system("CLS");
    }
    return 0;
}

void merge_sort(int *vet, int n){
    double comparacoes = 0;
    double atribuicoes = 0;
    int *auxiliar = (int *)malloc(n*sizeof(int));
    int tamanho_bloco;
    for(tamanho_bloco = 1; tamanho_bloco<n; tamanho_bloco *= 2){
        int pos = 0;
        for(pos = 0; pos<n ; pos++){
            auxiliar[pos] = vet[pos];
            atribuicoes++;
        }
        pos = 0;
        while(pos < n){
            int cl1 = pos;
            int cl2 = cl1+tamanho_bloco;
            int fl1 = cl1+tamanho_bloco;
            int fl2 = cl2+tamanho_bloco;
            if(fl1 > n){
                fl1 = n;
            }
            if (fl2 > n) {
                fl2 = n;
            }
            while(cl1 < fl1 && cl2<fl2){
                comparacoes++;
                if(auxiliar[cl1] <= auxiliar[cl2]){
                    vet[pos++] = auxiliar[cl1++];
                    atribuicoes++;
                }
                else{
                    vet[pos++] = auxiliar[cl2++];
                    atribuicoes++;
                }
            }
            while(cl1<fl1){
                vet[pos++] = auxiliar[cl1++];
                atribuicoes++;
            }
            while(cl2<fl2){
                vet[pos++] = auxiliar[cl2++];
                atribuicoes++;
            }
        }
    }
    free(auxiliar);
    printf("\n\nForam feitas %.0lf comparacoes e %.0lf atribuicoes\n\n",comparacoes,atribuicoes);
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
