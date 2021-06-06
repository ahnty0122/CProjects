#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define INF 1000000

typedef struct GraphType {
    int n;
    int weight[SIZE][SIZE];
}GraphType;

int A[SIZE][SIZE]; // 결과 저장 배열

void printA(GraphType* g)
{
    int i, j;
    printf("===============================\n");
    for(i = 0; i < g->n; i++)
    {
        for(j = 0; j < g->n; j++)
        {
            if(A[i][j] == INF)
                printf("  * "); // 경로 없으면 * 출력
            else printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("===============================\n");
}

void floyd(GraphType* g)
{
    int i, j, k;
    for(i = 0; i < g->n; i++)
        for(j = 0; j < g->n; j++)
            A[i][j] = g->weight[i][j]; // 새로운 경로 찾는 부분
    printA(g);

    for(k = 0; k < g->n; k++)
    {
        for(i = 0; i < g->n; i++)
            for(j = 0; j < g->n; j++)
                // if(A[i][k] == 1 && A[k][j] == 1)
                //     A[i][j] = 1; // 경로 추가
                if(A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[j][k] + A[k][j];
                    // G에서 1이 경로가 있다는 것을 의미하는 게 아니라 
                    // 어떤 경로에서 경로 사이의 가중치 값이라면
                    // 최적의 탐색하는 경로 구할 때 (MAX 매크로 만들어서 사용 가능)
        printA(g);
    }
}

int main(void)
{
    GraphType g = {5,
    {{0, 1, INF, 1, INF},
    {INF, 0, INF, INF, INF},
    {1, INF, 0, INF, INF},
    {INF, INF, INF, 0, 1},
    {1, INF, INF, INF, 0}} // 경로 존재하면 1, 경로 존재안하면 INF
    };
    floyd(&g);
    return 0;
}