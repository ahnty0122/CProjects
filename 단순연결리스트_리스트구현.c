// �ܼ����Ḯ��Ʈ�� ����Ʈ ADT ����

#include <stdio.h>
#include <stdlib.h>

// ����ü ���� (�� ���)
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

void addFirst(LinkedListType* L, int item)
{
    ListNode* node = malloc(sizeof(ListNode)); 
    // getnode ����, malloc���� ���� ��� ����
    // malloc �Լ��� �ּҸ� �����ϴϱ� �����ͷ� �ޱ�
    // malloc �Լ��� � ����� ���� ���� ��������� ���� �׻� void�� �ּ� ���� 
    node->data = item; // node�� data �ʵ忡 item ����ֱ�
    node->link = L->head; // ���� ���� ���� ��, ���� ��尡 �� �ڷ� ���;��� --> ���� head�� node link��
    L->head = node; // ���� ���� head
}   

void addLast(LinkedListType* L, int item)
{
    ListNode* node = malloc(sizeof(ListNode));
    ListNode* before = L->head;  
    while(before->link != NULL)
        before = before->link; // ���������� �̵�
    node->data = item;
    node->link = NULL;
    before->link = node;
}

void add(LinkedListType* L, int pos, int item)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    for(int i = 0; i < pos - 1; i++)
        before = before->link; // before -> link�� before ������ ���ϱ� ���������� ��ĭ�� �̵�
    node->data = item;
    node->link = before->link;
    before->link = node;
}

// remove
void remove1(LinkedListType* L, int pos)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    for(int i = 0; i < pos - 1; i++)
        before = before->link;
    before->link = before->link->link; // ���� ��� ���� ����
}


void removeFirst(LinkedListType* L)
{
    L->head = L->head->link;
}

void removeLast(LinkedListType* L)
{
    ListNode* before = L->head;
    for(int i = 0; i < sizeof(L); i++)
        before = before->link;
    before->link = NULL;    
}

// position�� �ִ� �� �������� �Լ�
int get(LinkedListType* L, int pos)
{
    ListNode* p = L->head;
    for(int i = 1; i < pos; i++)
        p = p->link;
    return p->data;
}


void set(LinkedListType* L, int pos, int item)
{
    ListNode* p = L->head;
    for(int i = 1; i < pos; i++)
        p = p->link;
    p->data = item;
}

void printList(LinkedListType* L)
{
    for(ListNode* p = L->head; p != NULL; p = p->link)
        printf("[%d] -> ", p->data);
    printf("NULL\n");
}

// addLast ����, add�� ����ѵ� for������ �� �����ؾ� ��
// ���� ���Ḯ��Ʈ���� ���� ������ ������ ���� �� ��尡 before ��尡 �Ǿ� ���� �¶� ����Ǿ����� ���..
// remove, removeFirst, removeLast

void main()
{
    LinkedListType list;
    init(&list);
    
    addFirst(&list, 10); printList(&list);
    addFirst(&list, 20); printList(&list);
    addFirst(&list, 30); printList(&list);
    getchar(); // ��� ����
    add(&list, 1, 40); printList(&list);
    add(&list, 1, 50); printList(&list);
    add(&list, 3, 60); printList(&list);
    
    addLast(&list, 70); printList(&list);

    removeFirst(&list); printList(&list);
    removeLast(&list); printList(&list);
    remove1(&list, 3); printList(&list);

    int pos;
    printf("\n �� �� ����� ���� ��ȯ�ұ��? ");
    scanf("%d", &pos);
    printf("%d�� ����� ���� %d\n", pos, get(&list, pos));
}