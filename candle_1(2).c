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

int runSimulation(ArrayList* L, int n, int k)
{
    int r = 0;
    int N = n;
    while(n > 1)
    {
        int i = 0;
        while(i < k)
        {
            r = (r + 1) % N;
            if(L->V[r] != 0)   
                i = i + 1;
        }   
        L->V[r] = 0;   
        n = n - 1;
        while(L->V[r] == 0)
            r = (r + 1) % N;
    }
    return L->V[r];
}

void traverse(ArrayList* L, int n)
{
    for(int i = 0; i < n; i++)
        printf("[%d] ", L->V[i]);
    printf("\n");
}

int candle(ArrayList* L, int n, int k)
{
    buildList(L, n);
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

    printf("특수 양초 위치: ");
    printf("%d\n", candle(&list, n, k));
}