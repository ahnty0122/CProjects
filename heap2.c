#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENT 100

struct Heap
{
    int H[MAX_ELEMENT]; // ����ü heap �ȿ� �迭 ����
    int n;
}_Heap; // �������� ����ü ���� ����

void downHeap(int i)
{
    if(i * 2 > _Heap.n) return; // ���� �ڽĳ�� ������ ����
    // ���� �ڽĳ��, ������ �ڽĳ�尡 �� ū ���
    if(_Heap.H[i] < _Heap.H[i * 2] || _Heap.H[i] < _Heap.H[i * 2 + 1])
    {
        // ���� �ڽĳ�尡 �����ʺ��� �� ū ���
        if(_Heap.H[i * 2] > _Heap.H[i * 2 + 1])
        {
            int temp;
            temp = _Heap.H[i];
            _Heap.H[i] = _Heap.H[i * 2];
            _Heap.H[i * 2] = temp;
            downHeap(i * 2);
        }
        else
        {
            int temp;
            temp = _Heap.H[i];
            _Heap.H[i] = _Heap.H[i * 2 + 1];
            _Heap.H[i * 2 + 1] = temp;
            downHeap(i * 2 + 1);
        }
    } 
    else
    {
        return;
    }
}

// ����� ������ �������
void buildHeap()
{
    for(int i = _Heap.n / 2; i >= 1; i--)
        downHeap(i);
}

// ����� �� ���� �����
void rBuildHeap(int i)
{
    if(i > _Heap.n)
        return;
    if(i * 2 <= _Heap.n) // ���� �ڽ� ������
        rBuildHeap(2 * i); // ���ȣ��
    if(i * 2 + 1 <= _Heap.n) // ������ �ڽ� ������
        rBuildHeap(2 * i + 1); // ���ȣ��
    downHeap(i);
}

int removeMax()
{
    int key = _Heap.H[1];
    _Heap.H[1] = _Heap.H[_Heap.n--];
    downHeap(1);
    return key;
}

void inPlaceHeapSort()
{
    int size = _Heap.n;
    int key;
    for(int i = 0; i < size; i++)
    {
        key = removeMax(); // �ִ밪 �޾ƿ���
        _Heap.H[_Heap.n + 1] = key; // �ε����� ������ ������ ����
    }
}

void printHeap()
{
    for(int i = 1; i <= _Heap.H[i]; i++)
        printf("[%d] ", _Heap.H[i]);
    printf("\n");
}

// ���ڸ������� �ϸ� n�� 0 �Ǵϱ� printheap���δ� ��� �Ұ�
void printArray()
{
    for(int i = 1; _Heap.H[i] > 0; i++)
    {
        printf("[%d] ", _Heap.H[i]);
    }
    printf("\n");
}

void main()
{
    _Heap.n = 0;
    srand(time(NULL));
    printf("�Է��� ������ ����: ");
    scanf("%d", &_Heap.n);
    // ����� �� ������ ��� ����Ʈ ���� ����
    for(int i = 1; i <= _Heap.n; i++)
        _Heap.H[i] = rand() % 100;
    // buildHeap(); // ���������� ������
    rBuildHeap(1); // ����� ���
    printHeap();
    // getchar();
    inPlaceHeapSort();
    printArray();
}