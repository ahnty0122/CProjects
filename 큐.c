#include <stdio.h>
#include <stdlib.h>

// 자기참조구조체로 선언
typedef struct QueueNode
{
    int data;
    struct QueueNode* link;
}QueueNode;

// front, rear 위치 기억할 변수 필요함
typedef struct
{
    QueueNode* front;
    QueueNode* rear;
}LinkedQueue;

void init(LinkedQueue* queue)
{
    queue->front = queue->rear = NULL;
}

int is_empty(LinkedQueue* queue)
{
    return queue->front == NULL;
}

// enqueue에 front, rear 정보 가지는 queue 받고 queue node에 저장할 데이터 값도 가짐
void enqueue(LinkedQueue* queue, int data)
{
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->link = NULL; // 해당 노드의 링크 필드는 null (단순 연결 리스트의 마지막에 붙기 때문)
    if(is_empty(queue)) // 연결된 큐가 공백상태인지 아닌지 파악해야함
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else
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
        data = temp->data;
        queue->front = temp->link;
        if(queue->front == NULL)
            queue->rear = NULL;
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