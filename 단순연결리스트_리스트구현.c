// 단순연결리스트로 리스트 ADT 구현

#include <stdio.h>
#include <stdlib.h>

// 구조체 선언 (새 노드)
typedef struct ListNode 
{
    int data; //data field
    struct ListNode* link; // 자기참조 구조체
}ListNode;

typedef struct
{
    ListNode* head; // head 포인터 구조체
}LinkedListType;

void init(LinkedListType* L)
{
    L->head = NULL; // head는 NULL로 초기화
}

void addFirst(LinkedListType* L, int item)
{
    ListNode* node = malloc(sizeof(ListNode)); 
    // getnode 역할, malloc으로 직접 노드 생성
    // malloc 함수는 주소를 리턴하니까 포인터로 받기
    // malloc 함수는 어떤 대상을 위한 공간 만들어질지 몰라 항상 void형 주소 리턴 
    node->data = item; // node의 data 필드에 item 집어넣기
    node->link = L->head; // 내가 먼저 들어가는 것, 현재 헤드가 내 뒤로 들어와야함 --> 현재 head가 node link로
    L->head = node; // 내가 현재 head
}   

void addLast(LinkedListType* L, int item)
{
    ListNode* node = malloc(sizeof(ListNode));
    ListNode* before = L->head;  
    while(before->link != NULL)
        before = before->link; // 오른쪽으로 이동
    node->data = item;
    node->link = NULL;
    before->link = node;
}

void add(LinkedListType* L, int pos, int item)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    for(int i = 0; i < pos - 1; i++)
        before = before->link; // before -> link는 before 오른쪽 노드니까 오른쪽으로 한칸씩 이동
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
    before->link = before->link->link; // 없앨 노드 연결 끊기
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

// position에 있는 값 가져오는 함수
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

// addLast 구현, add랑 비슷한데 for문에서 좀 생각해야 함
// 현재 연결리스트에서 제일 마지막 노드까지 가고 그 노드가 before 노드가 되어 내가 걔랑 연결되어지고 등등..
// remove, removeFirst, removeLast

void main()
{
    LinkedListType list;
    init(&list);
    
    addFirst(&list, 10); printList(&list);
    addFirst(&list, 20); printList(&list);
    addFirst(&list, 30); printList(&list);
    getchar(); // 잠깐 멈춤
    add(&list, 1, 40); printList(&list);
    add(&list, 1, 50); printList(&list);
    add(&list, 3, 60); printList(&list);
    
    addLast(&list, 70); printList(&list);

    removeFirst(&list); printList(&list);
    removeLast(&list); printList(&list);
    remove1(&list, 3); printList(&list);

    int pos;
    printf("\n 몇 번 노드의 값을 반환할까요? ");
    scanf("%d", &pos);
    printf("%d번 노드의 값은 %d\n", pos, get(&list, pos));
}