#include <stdio.h>
#include <stdlib.h>

// 자기참조구조체로 선언
typedef struct QueueNode
{
    int data; // data 필드
    struct QueueNode* link; // 링크 필드
}QueueNode;

// front, rear 위치 기억할 두 개의 포인터 변수 필요함
typedef struct
{
    QueueNode* front;
    QueueNode* rear;
}LinkedQueue;

void init(LinkedQueue* queue)
{
    queue->front = queue->rear = NULL; // 초기화
}

int is_empty(LinkedQueue* queue)
{
    return queue->front == NULL; // 큐의 front 필드가 널이면 isempty
}

// enqueue에 front, rear 정보 가지는 queue 받고 queue node에 저장할 데이터 값도 가짐
void enqueue(LinkedQueue* queue, int data)
{
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode)); // 노드 생성
    temp->data = data; // 해당 노드의 data 필드
    temp->link = NULL; // 해당 노드의 링크 필드는 null (단순 연결 리스트의 마지막에 붙기 때문)
    if(is_empty(queue)) // 연결된 큐가 공백상태인지 아닌지 파악해야함
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else // 공백 상태 아닐 때
    {
        queue->rear->link = temp;
        queue->rear = temp;
    }
}

void print_queue(LinkedQueue* queue)
{
    QueueNode* p;
    for(p = queue->front; p != NULL; p = p->link)
        printf("|%d| -> ", p->data);
    printf("|NULL|\n");
}

int dequeue(LinkedQueue* queue)
{
    QueueNode* temp = queue->front;
    int data;
    if(is_empty(queue)) // 비어있는 큐를 대상으로 dequeue하면 에러
    {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    else
    {
        data = temp->data; // 삭제할 데이터 값을 변수에 저장
        queue->front = temp->link; // 삭제될 link 필드는 두 번째 노드의 주소 들어있음, 이게 이제 큐의 front
        if(queue->front == NULL) // 큐의 front가 null 이면 이제 아무것도 없으니까
            queue->rear = NULL; // 큐의 rear도 null로 해줘야함. (안해주면 없는 값 가리키기 때문에)그 전에는 temp를 가리켰었는데 이제 null로 가리켜야함
        free(temp);
        return data;
    }
}

void main()
{
    LinkedQueue queue;
    init(&queue); // 초기화하는 함수
    
    enqueue(&queue, 10); print_queue(&queue);
    enqueue(&queue, 20); print_queue(&queue);
    enqueue(&queue, 30); print_queue(&queue);
    getchar();
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
}