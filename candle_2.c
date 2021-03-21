#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct
{
    int V[SIZE];  
    int n; 
}ArrayList;

void buildList(ArrayList* L, int n)
{
    for(int r = 0; r < n; r++)
    {
        L->V[r] = r + 1;
    }
}

void remove1(ArrayList* L, int pos, int n)
{
    int item = L->V[pos];
    for(int i = pos + 1; i <= n - 1; i++)
        L->V[i - 1] = L->V[i];
}

void traverse(ArrayList* L, int n)
{
    for(int i = 0; i < n; i++)
        printf("[%d] ", L->V[i]);
    printf("\n");
}

int runSimulation(ArrayList* L, int n, int k)
{
    int r = 0;
    while(n > 1)
    {
        r = (r + k) % n;
        remove1(L, r, n);
        n = n - 1;
    }
    // traverse(L, n);
    return L->V[0];
}

int candle(ArrayList *L, int n, int k)
{
    buildList(L, n);
    // traverse(L, n);
    printf("특수 양초 위치: ");
    return runSimulation(L, n, k);
}

void main()
{
    int n;
    int k;
    printf("n와 k의 값 입력: ");
    scanf("%d", &n);
    scanf("%d", &k);

    ArrayList list;
    printf("%d\n", candle(&list, n, k));
}