// span 1. 정의 적용 방법

#include <stdio.h>

#define SIZE 6

void spans(int X[], int S[])
{
    int s;
    for(int i = 0; i < SIZE; i++)
    {
        s = 1;
        while((s <= i) && (X[i - s] <= X[i]))
            s++;
        S[i] = s;
    }
}

void main()
{
    int X[SIZE] = {6, 3, 4, 2, 5, 3}; // data 배열
    int S[SIZE] = {0}; // 0으로 초기화, 기간 배열
    spans(X, S);

    for(int i = 0; i < SIZE; i++)
        printf("[%d] ", S[i]);
    printf("\n");
}
