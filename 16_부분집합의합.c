// m을 만드는 부분집합이 있는지 확인하는 프로그램
// 이 문제 응용하면 도둑 배낭 문제도 해결 가능
#include <stdio.h>
#include <stdlib.h>

int c[15][150];

void calculate_subset_sum(int s[], int n, int m)
{
    int i, j;
    // 동적프로그래밍 방식
    for(i = 0; i <= n; i++)
        c[i][0] = 1;
    
    for(i = 1; i <= n; i++)
        c[0][i] = 0;
    
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            c[i][j] = 0;

            if(j >= s[i - 1])
                if(c[i - 1][j - s[i - 1]] == 1)
                    c[i][j] = 1;
            
            if(c[i - 1][j] == 1)
                c[i][j] = 1;
        }
    }
}

void main()
{
    int m, n;
    printf("input m, n: ");
    scanf("%d %d", &m, &n);
    int* s = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);

    calculate_subset_sum(s, n, m);
    
    if(c[n][m])
}