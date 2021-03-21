#include <stdio.h>
#include <stdlib.h>

void buildList(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
}

int runSimulation(int A[], int n, int k)
{
    int r = 0;
    int N = n;
    while(n > 1)
    {
        int i = 0;
        while(i < k)
        {
            r = (r + 1) % N;
            if(A[r] != 0)   
                i = i + 1;
        }   
        A[r] = 0;   
        n = n - 1;
        while(A[r] == 0)
            r = (r + 1) % N;
    }
    // printf("%d\n", A[r]);
    return A[r];
}

void printArray(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int candle(int n, int k)
{
    int A[n];
    buildList(A, n);
    return runSimulation(A, n, k);
}

void main()
{
    int n;
    int k;
    printf("n와 k의 값 입력: ");
    scanf("%d", &n);
    scanf("%d", &k);
        
    printf("특수 양초 위치: ");
    printf("%d\n", candle(n, k));
}