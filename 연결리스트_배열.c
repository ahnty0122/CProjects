#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct // array로 선언
{
    int V[SIZE]; // list 역할을 할 배열 
    int n; // 전체 list 요소 개수 기억하는 변수
}ArrayList; // 이 구조체의 이름을 ArrayList로 선언

void init(ArrayList* L) // 주소 오니까 포인터 L로 받기
{
    L->n = 0; // L 원소의 개수 0개
}

// traverse method (접근 method)
void traverse(ArrayList* L)
{
    for(int i = 0; i < L->n; i++)
        printf("[%d] ", L->V[i]); // data field값
    printf("\n");
}

void add(ArrayList* L, int pos, int item) // pos: rank 역할, item: 삽입될 값
{
    if(L->n == SIZE)
    {
        printf("fullListException...\n");
        exit(1); // 예외처리 후 프로그램 끝내기
    }
    // invalidPosException... 0 <= post <= L->n
    for(int i = L->n - 1; i >= pos; i--)
        L->V[i+1] = L->V[i]; // 한 칸씩 오른쪽으로 위치 이동
    L->V[pos] = item;
    L->n++;
}

int remove1(ArrayList* L, int pos)
{
    // exception 처리
    int item = L->V[pos]; // 나중에 이 값 return
    for(int i = pos + 1; i <= L->n - 1; i++)
        L->V[i - 1] = L->V[i];
    L->n--;
    return item;
}

void main()
{
    ArrayList list; // main에서 ArrayList 선언
    
    init(&list); // 구조체 포인터로 전달하며 초기화 --> 변경되는 내용을 공유할 수 있게
    
    add(&list, 0, 10); traverse(&list);
    add(&list, 0, 20); traverse(&list);
    add(&list, 1, 30); traverse(&list);
    add(&list, 1, 40); traverse(&list);
    add(&list, 3, 50); traverse(&list);
    
    getchar();
    remove1(&list, 1); traverse(&list);
    remove1(&list, 2); traverse(&list);
}
