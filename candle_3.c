#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode 
{
    int data; //data field
    struct ListNode* link; // �ڱ����� ����ü
}ListNode;

typedef struct
{
    ListNode* head; // head ������ ����ü
}LinkedListType;

void init(LinkedListType* L)
{
    L->head = NULL; // head�� NULL�� �ʱ�ȭ
}

void buildList(LinkedListType *L, int n)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    L->head = p;
    p->data = 1;
    for (int i = 2; i <= n; i++)
    {
        p->link = (ListNode*)malloc(sizeof(ListNode));
        p = p->link;
        p->data = i;
    }
    p->link = L->head;
}

int runSimulation(LinkedListType* L, int n, int k)
{
    ListNode* p = L->head;
    while(p != p->link)
    {
        for(int i = 1; i <= k - 1; i++)
            p = p->link;
        ListNode* pnext = p->link;
        p->link = p->link->link;
        free(pnext);
        p = p->link;
    }
    return p->data;
}

int candle(LinkedListType* L, int n, int k)
{
    buildList(L, n);
    printf("Ư�� ���� ��ġ: ");
    return runSimulation(L, n, k);
}

void main()
{
    LinkedListType list;
    init(&list);

    int n; int k;
    printf("n, k�� ���� �Է��ϼ���: ");
    scanf("%d", &n);
    scanf("%d", &k);
    printf("%d\n", candle(&list, n, k));
}