// 에어텔 문제의 2D 버전 - 동적프로그래밍
#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

int m[8][8];
int A[8][8] = 
{
    {1, 3, 7, 2, 11, 17, 16, 25},
    {6, 2, 3, 4, 7, 2, 12, 15},
    {11, 4, 6, 8, 8, 1, 9, 14},
    {20, 8, 8, 11, 6, 3, 3, 9}, 
    {0, 10, 9, 8, 7, 15, 17, 22}, 
    {17, 12, 7, 10, 3, 1, 8, 13}, 
    {19, 25, 10, 15, 14, 11, 3, 3}, 
    {21, 18, 16, 20, 15, 13, 19, 0}
};

int minGold(int n)
{
    m[0][0] = A[0][0];
    int i, j, k;
    int minRight, minDown;
    int cost;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)
                continue;
                    
            minRight = 10000;
            for(k = j - 1; k >= 0; k--)
            {
                cost = m[i][k] + A[i][j];
                minRight = min(minRight, cost);
            }

            minDown = 10000;
            for(k = i - 1; k >= 0; k--)
            {
                cost = m[k][j] + A[i][j];
                minDown = min(minDown, cost);
            }
            m[i][j] = min(minRight, minDown);
        }
    }
    return m[n - 1][n - 1];
}

int main()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
            printf("%02d ", A[i][j]);
        printf("\n");
    }
    minGold(8);
    printf("\n");
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
            printf("%02d ", m[i][j]);
        printf("\n");
    }
    return 0;
}