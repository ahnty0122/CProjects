// �迭�� �� ����

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
    // 1. ��Ʈ�ƴ��� 2. �Էµ� key�� �θ� key ���� (�θ����� key �� ���� ������) Ȯ�� --> swap
    while((i != 1) && (key < h->heap[i / 2]))
    {
            h->heap[i] = h->heap[i / 2]; // ���� i�� index�� �θ��� index ����
            i /= 2; // i�� �θ����� index ��
    }
    // ��Ʈ�ų� key�� ũ�ų� ������ �̵� ���߰� key �Ҵ�
    h->heap[i] = key;
}

void insertItem(HeapType *h, int key)
{
    h->heap_size += 1; // �� key �� �����ؾ��ϴϱ� ũ�� +1
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
    int key = h->heap[1]; // ��Ʈ Ű
    h->heap[1] = h->heap[h->heap_size]; // �������� ��Ʈ��
    h->heap_size -= 1; // retreatLast
    downHeap(h); // downheap
    return key; // key�� ����
}

void printHeap(HeapType *h)
{
    for(int i = 1; i <= h->heap_size; i++)
        printf("[%d] ", h->heap[i]);
    printf("\n");
}

void heapSort(HeapType *h, int list[]) // ����: ���� ��, ���ĵ� ��� ������ �迭
{
    HeapType heap; // ����ü ����
    init(&heap);
    for(int i = 1; i <= h->heap_size; i++)
    {
        heap.heap[i] = h->heap[i]; // ������ �ƴϴϱ� .���� ����
        heap.heap_size++;
    }  
    for(int i = 1; i <= h->heap_size; i++)
        list[i] = removeMin(&heap); // ���� ������ ������� �����
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

    // �� ����
    heapSort(&heap, list);
    printArray(list, heap.heap_size);

    // �� ����
    // printf("deleted key: %d\n", removeMin(&heap));
    // printHeap(&heap); 
}
