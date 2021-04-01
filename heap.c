// 배열로 힙 구현

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct 
{
    int heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

void init(HeapType *h)
{
    h->heap_size = 0;
}

void upHeap(HeapType *h)
{
    int i = h->heap_size;
    int key = h->heap[i];
    // 1. 루트아닌지 2. 입력된 key와 부모 key 조건 (부모노드의 key 값 보다 작으면) 확인 --> swap
    while((i != 1) && (key < h->heap[i / 2]))
    {
            h->heap[i] = h->heap[i / 2]; // 현재 i의 index에 부모노드 index 저장
            i /= 2; // i는 부모노드의 index 값
    }
    // 루트거나 key가 크거나 같으면 이동 멈추고 key 할당
    h->heap[i] = key;
}

void insertItem(HeapType *h, int key)
{
    h->heap_size += 1; // 새 key 값 삽입해야하니까 크기 +1
    h->heap[h->heap_size] = key;
    upHeap(h);
}

void printHeap(HeapType *h)
{
    for(int i = 1; i <= h->heap_size; i++)
        printf("[%d] ", h->heap[i]);
    printf("\n");
}

void main()
{
    HeapType heap;
    init(&heap);
    insertItem(&heap, 5);
    insertItem(&heap, 3);
    insertItem(&heap, 7);
    insertItem(&heap, 4);
    insertItem(&heap, 1);
    insertItem(&heap, 4);
    insertItem(&heap, 8);
    insertItem(&heap, 2);
    printHeap(&heap);
}
