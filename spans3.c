#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100
#define LEN 8

// stack 의 top 을 맨 위에 있는 값으로 할지
// stack 에 쌓인 index 값으로 할지 정확히 정의
// top 은 stack 에 쌓인 index 값

typedef struct
{
    int Arr[LEN];
    int top;
}stack;

void init(stack *A)
{
    A->top = -1;
}

int isEmpty(stack *A)
{
    if(A->top == -1)
        return 1;
    else
        return 0;
}

int pop(stack *A)
{
    if(A->top == -1)
    {
        printf("memory error!");
        exit(-1);
    }
    int temp = A->Arr[A->top];
    A->top -= 1;
    return temp;
}


void push(stack *A, int data)
{
    A->top += 1;
    A->Arr[A->top] = data;
}

void printstack(stack *A)
{
    for (int i=0; i < A->top+1; i++)
        printf("%d\n", A->Arr[i]);
}

// 현재 top 의 실제 값을 보기만 하는 함수 필요
int peek(stack *A)
{
    return A->Arr[A->top];
}

void spans2(int X[], int S[], int n, stack *A)
{
    for(int i = 0; i < n; i++)
    {
        while((!isEmpty(A)) && (X[peek(A)] <= X[i]))
            pop(A);
        if(isEmpty(A))
            S[i] = i + 1;
        else   
            S[i] = i - peek(A);
        push(A, i);
    }
    while(!isEmpty(A))
        pop(A);
}

int main()
{
    int X[LEN] = {60, 30, 40, 10, 20, 30, 50, 40};
    int S[LEN] = {0};    
    stack A;
    init(&A);
    spans2(X, S, LEN, &A);
    for(int i = 0; i < LEN; i++)
        printf("%d ", S[i]);
    printf("\n");
}