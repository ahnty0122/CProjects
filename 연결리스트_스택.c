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

int main()
{
    stackType list;
    init(&list);
    
    push(&list, 1); printstack(&list);
    push(&list, 2); printstack(&list);
    push(&list, 3); printstack(&list);
    push(&list, 4); printstack(&list);

    pop(&list); printstack(&list);
    pop(&list); printstack(&list);
}
