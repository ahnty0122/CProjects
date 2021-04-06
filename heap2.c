#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENT 100

struct Heap
{
    int H[MAX_ELEMENT]; // 구조체 heap 안에 배열 생성
    int n;
}_Heap; // 전역으로 구조체 변수 선언

void downHeap(int i)
{
    if(i * 2 > _Heap.n) return; // 비교할 자식노드 없으면 리턴
    // 왼쪽 자식노드, 오른쪽 자식노드가 더 큰 경우
    if(_Heap.H[i] < _Heap.H[i * 2] || _Heap.H[i] < _Heap.H[i * 2 + 1])
    {
        // 왼쪽 자식노드가 오른쪽보다 더 큰 경우
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

// 상향식 힙정렬 비재귀적
void buildHeap()
{
    for(int i = _Heap.n / 2; i >= 1; i--)
        downHeap(i);
}

// 상향식 힙 생성 재귀적
void rBuildHeap(int i)
{
    if(i > _Heap.n)
        return;
    if(i * 2 <= _Heap.n) // 왼쪽 자식 있으면
        rBuildHeap(2 * i); // 재귀호출
    if(i * 2 + 1 <= _Heap.n) // 오른쪽 자식 있으면
        rBuildHeap(2 * i + 1); // 재귀호출
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
        key = removeMax(); // 최대값 받아오기
        _Heap.H[_Heap.n + 1] = key; // 인덱스는 오른쪽 끝부터 삽입
    }
}

void printHeap()
{
    for(int i = 1; i <= _Heap.H[i]; i++)
        printf("[%d] ", _Heap.H[i]);
    printf("\n");
}

// 제자리힙정렬 하면 n이 0 되니까 printheap으로는 출력 불가
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
    printf("입력할 원소의 개수: ");
    scanf("%d", &_Heap.n);
    // 상향식 힙 생성의 경우 리스트 먼저 만듦
    for(int i = 1; i <= _Heap.n; i++)
        _Heap.H[i] = rand() % 100;
    // buildHeap(); // 비재귀적방법 빌드힙
    rBuildHeap(1); // 재귀적 방법
    printHeap();
    // getchar();
    inPlaceHeapSort();
    printArray();
}