#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *link;
}stack;

typedef struct
{
    stack *top;
}stackType;

void init(stackType* L)
{
    L->top = NULL;
}

int isempty(stackType * L)
{
    return L-> top == NULL;
}

void push(stackType * L, int item)
{
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->data = item;
    temp->link = L->top;
    L->top = temp;
}

int pop(stackType * L)
{
    if(!isempty(L))
    {
        stack * temp = L->top;
        int data = temp->data;
        L->top = temp->link;
        free(temp);
        return data;
    }
}

void printstack(stackType * L)
{
    if(!isempty(L))
    {
        stack * temp = L->top;
        while(temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void spans2(int X[], int S[], int n, stackType * A)
{
    for(int i = 0; i < n; i++)
    {
        while((!isempty(A)) && (X[A->top->data] <= X[i]))
            pop(A);
        if(isempty(A))
            S[i] = i + 1;
        else   
            S[i] = i - A->top->data;
        push(A, i);
    }
    while(!isempty(A))
        pop(A);
    
}

int main()
{
    int X[6] = {60, 30, 40, 20, 50, 30};
    int S[6] = {0};    
    stackType A;
    init(&A);
    spans2(X, S, 6, &A);
    for(int i = 0; i < 6; i++)
        printf("%d ", S[i]);
    printf("\n");
}
