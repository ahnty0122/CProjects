#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COLUMN 5

// 나선형 행렬 만들기
void spiral(int A[][COLUMN])
{
    int left = 0;
    int right = COLUMN - 1;
    int top = 0;
    int bottom = ROW - 1;
    int value = 1;
    while((left <= right) && (top <= bottom))
    {
        for(int j = left; j <= right; j++)
        {
            A[top][j] = value;
            value++;
        }
        top++;
        if((left <= right) && (top <= bottom))
        {
            for(int i = top; i <= bottom; i++)
            {
                A[i][right] = value;
                value++;
            }
        }
        right--;
        if((left <= right) && (top <= bottom))
        {
            for(int j = left; j <= right; j++)
            {
                A[bottom][right - j + left] = value;
                value++;
            }
        }
        bottom--;
        if((left <= right) && (top <= bottom))
        {
            for(int i = top; i <= bottom; i++)
            {
                A[bottom - i + top][left] = value;
                value++;
            }
        }
        left++;
    }
}

void printArray(int A[][COLUMN])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COLUMN; j++)
            printf("%2d ", A[i][j]);
        printf("\n");
    }
}

void main()
{
    int A[ROW][COLUMN] = {0}; 
    spiral(A);
    printArray(A);
}