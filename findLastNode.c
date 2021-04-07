#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct 
{
    int V[SIZE];
    int n; 
    int top;
}stack; 

void init_stack(stack* L) 
{
    L->n = 0;
}

void traverse(stack* L) 
{
    for(int i = 0; i < L->n; i++) 
        printf("[%d] ", L->V[i]); 
    printf("\n");
}

void push(stack* L, int item)
{
    L->V[L->n] = item;
    L->n++;
}

int pop(stack* L) 
{ 
    int item = L->V[L->n - 1];
    L->n--; 
    return item;
}

int isEmpty(stack* L) 
{
    return L->n == 0; 
}

typedef struct 
{
    int heap[SIZE]; 
    int heap_size;
}HeapType;

void init_heap(HeapType *h)
{
    h->heap_size = 0;
}

void upHeap(HeapType *h)
{
    int i = h->heap_size;
    int key = h->heap[i];
    while((i != 1) && (key < h->heap[i / 2]))
    {
            h->heap[i] = h->heap[i / 2]; 
            i /= 2;
    }
    h->heap[i] = key;
}

void insertItem(HeapType *h, int key)
{
    h->heap_size += 1; 
    h->heap[h->heap_size] = key;
    upHeap(h);
}

void printHeap(HeapType *h)
{
    for(int i = 1; i <= h->heap_size; i++)
        printf("[%d] ", h->heap[i]);
    printf("\n");
}

void binaryExpansion(int num, HeapType *h, stack* L)
{
    while(num >= 2)
    {
        push(L, num % 2);
        num = num / 2;
    }   
    push(L, num);
}

int findLastNode(HeapType *h, int num)
{
    stack S;
    init_stack(&S);
    binaryExpansion(num, h, &S);
    printf("---------이진수열 출력---------\n");
    traverse(&S);
    pop(&S);
    int v = 1;
    while(isEmpty(&S) != 1)
    {
        int bit = pop(&S);
        if(bit == 0)
            v = v * 2;
        else   
            v = v * 2 + 1;
    }
    return v;
}

void main()
{
    HeapType heap;
    init_heap(&heap);
    int num;
    printf("노드 개수 입력: ");
    scanf("%d", &num);  
    for(int i = 0; i < num; i++)
        insertItem(&heap, rand() % 100);
    printf("-----------힙 출력-----------\n");    
    printHeap(&heap);
    printf("%d", heap.heap[findLastNode(&heap, num)]);
}