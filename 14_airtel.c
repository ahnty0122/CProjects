// 분할통치법 (정방향) & 동적프로그래밍 (정방향)
#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x) > (y) ? (x) : (y)) // airtel 최대값 구할 때 사용
#define min(x, y) ((x) < (y) ? (x) : (y)) // airtel 최소값 구할 때 사용

int A[] = {0, 1, 3, 6, 11, 17}; // 항공요금
int H[] = {0, 2, 5, 1, 5, 0}; // 숙박요금
int m[10]; // DP 위한 배열

// 동적프로그래밍 - 배열 이용, 중간값 저장
int airtel(int n)
{
    m[0] = 0;
    int cost;
    for(int d = 1; d < n; d++)
    {
        m[d] = 10000;
        // 경유하는 게 나은가 안 하는 게 나은가 확인
        // k: 경유횟수
        for(int k = 0; k < d; k++)
        {
            cost = m[k] + H[k] + A[d - k];
            m[d] = min(m[d], cost);
        }
    }
    return m[n - 1];
}

// 분할통치법
int rAirtelForward(int d)
{
    if(d == 0)
        return 0;
    
    int minCost = 10000; // 임의의 큰 값 입력
    int cost;

    for(int k = 0; k < d; k++)
    {
        cost = rAirtelForward(k) + H[k] + A[d - k];
        minCost = min(minCost, cost);
    }
    return minCost;
}

int main()
{
    printf("%d\n", rAirtelForward(5));
    printf("%d\n", airtel(5));
    return 0;
}