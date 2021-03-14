#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// 홀수행은 오름차순, 짝수행은 내림차순
void zigzag(int A[][SIZE])
{
    int value = 1;
    for(int i = 0; i < SIZE; i++)
    {
        if(i % 2 == 0)
            for(int j = 0; j < SIZE; j++)
            {
                A[i][j] = value;
                value++;
            }
        else
            for(int j = SIZE - 1; j >= 0; j--)
            {
                A[i][j] = value;
                value++;
            }
    }
}

// 행렬 출력 함수
void printArray(int A[][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
            printf("%2d ", A[i][j]);
        printf("\n");
    }
}

void main()
{
    // 0으로 다 초기화
    int A[SIZE][SIZE] = {0};
    // 지그재그 행렬 생성
    zigzag(A);
    // 행렬 출력
    printArray(A);
}
