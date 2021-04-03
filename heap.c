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

void downHeap(HeapType *h)
{
    int temp = h->heap[1];
    int parent = 1, child = 2;

    while(child <= h->heap_size)
    {
        if((child < h->heap_size) && (h->heap[child] > h->heap[child + 1]))
            child++;
        if(temp <= h->heap[child])
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
}

int removeMin(HeapType *h)
{
    int key = h->heap[1]; // 루트 키
    h->heap[1] = h->heap[h->heap_size]; // 마지막을 루트로
    h->heap_size -= 1; // retreatLast
    downHeap(h); // downheap
    return key; // key값 리턴
}

void printHeap(HeapType *h)
{
    for(int i = 1; i <= h->heap_size; i++)
        printf("[%d] ", h->heap[i]);
    printf("\n");
}

void heapSort(HeapType *h, int list[]) // 인자: 원본 힙, 정렬된 결과 저장할 배열
{
    HeapType heap; // 구조체 선언
    init(&heap);
    for(int i = 1; i <= h->heap_size; i++)
    {
        heap.heap[i] = h->heap[i]; // 포인터 아니니까 .으로 접근
        heap.heap_size++;
    }  
    for(int i = 1; i <= h->heap_size; i++)
        list[i] = removeMin(&heap); // 작은 값부터 순서대로 저장됨
}

void printArray(int list[], int n)
{
    for(int i = 1; i <= n; i++)
        printf("[%d] ", list[i]);
    printf("\n");
}

void main()
{
    HeapType heap;
    int list[MAX_ELEMENT] = {0};
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

    // 힙 정렬
    heapSort(&heap, list);
    printArray(list, heap.heap_size);

    // 힙 삭제
    // printf("deleted key: %d\n", removeMin(&heap));
    // printHeap(&heap); 
}
