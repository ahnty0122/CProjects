#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define INF 1000000

typedef struct GraphType {
    int n;
    int weight[SIZE][SIZE];
}GraphType;

int A[SIZE][SIZE]; // ��� ���� �迭

void printA(GraphType* g)
{
    int i, j;
    printf("===============================\n");
    for(i = 0; i < g->n; i++)
    {
        for(j = 0; j < g->n; j++)
        {
            if(A[i][j] == INF)
                printf("  * "); // ��� ������ * ���
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
            A[i][j] = g->weight[i][j]; // ���ο� ��� ã�� �κ�
    printA(g);

    for(k = 0; k < g->n; k++)
    {
        for(i = 0; i < g->n; i++)
            for(j = 0; j < g->n; j++)
                // if(A[i][k] == 1 && A[k][j] == 1)
                //     A[i][j] = 1; // ��� �߰�
                if(A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[j][k] + A[k][j];
                    // G���� 1�� ��ΰ� �ִٴ� ���� �ǹ��ϴ� �� �ƴ϶� 
                    // � ��ο��� ��� ������ ����ġ ���̶��
                    // ������ Ž���ϴ� ��� ���� �� (MAX ��ũ�� ���� ��� ����)
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
    {1, INF, INF, INF, 0}} // ��� �����ϸ� 1, ��� ������ϸ� INF
    };
    floyd(&g);
    return 0;
}