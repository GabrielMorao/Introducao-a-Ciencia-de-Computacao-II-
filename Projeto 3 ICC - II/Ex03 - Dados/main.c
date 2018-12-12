#include <stdio.h>
#include <stdlib.h>

unsigned long long int calcula(int n, int m, int x, int num, int val, unsigned long long int cache[num][val]);


int main(int argc, char *argv[])
{
    //n = numero de dados, m = numero de lados de cada dado, x = valor obtido;
    int n, m, x;

    n = atoi(argv[1]);
    m = atoi(argv[2]);
    x = atoi(argv[3]);

    long long int cache[n+1][x+1];
    for(int a = 0; a<=n; a++){
        for (int b = 0; b<=x; b++){
           cache[a][b] = -1;
        }
    }
    printf("Ha %llu modos de se obter %d lancando %d dados com %d lados\n", calcula(n, m, x, n, x, cache), x, n, m);
    return 0;
}


unsigned long long int calcula(int n, int m, int x, int num, int val, unsigned long long int cache[num][val])
{
    unsigned long long int resultado = 0;
    if(cache[n][x] == -1){
// Se valor pedido for menor que 0, soma dos maiores valores do dado forem menores que valor pedido ou se numero de dados for maior que valor pedido, aplica a posição como 0
        if (x < 0 || m * n < x || n > x){
                //printf("oi\n");
                cache[n][x] = 0;
        }
// Se numero de dados for 0, aplica a posição como 1
        else if (n == 1){
            cache[n][x] = 1;
        }

        else{
            // calcula com recursão
            for (int i = 1; i <= m; i++){
                resultado += calcula(n - 1, m, x - i, num, val, cache);
               // printf("%d \n", resultado);
            }
            cache[n][x] = resultado;
        }
    }
    return cache[n][x];

}
