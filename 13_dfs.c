// 단순연결리스트로 그래프 구현 + dfs
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int vNum1;
    int vNum2;
    int isTree;
    struct Edge* next;
}Edge;

typedef struct IncidentEdge
{
    int adjVertex;
    Edge* e;
    struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex
{
    int num;
    int isFresh;
    struct Vertex* next;
    IncidentEdge* top; // 인접간선들 기억
}Vertex;

Vertex* vHead = NULL; 
Edge* eHead = NULL; // 단순연결리스트니까 head 필요
int vCount; // 정점 개수
int eCount; // 간선 개수

void makeVertices()
{
    Vertex* p = (Vertex*)malloc(sizeof(Vertex));
    p->num = ++vCount;
    p->top = NULL;
    p->next = NULL;
    p->isFresh = 0;
    Vertex* q = vHead;
    if(q == NULL) // 연결리스트 비어있으면
        vHead = p;
    else
    {
        while(q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

void insertIncidentEdge(Vertex* v, int av, Edge* e)
{
    IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    p->adjVertex = av;
    p->e = e;
    p->next = NULL;
    IncidentEdge* q = v->top;
    if(q == NULL)
        v->top = p;
    else
    {
        while(q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

Vertex* findVertex(int v)
{
    Vertex* p = vHead;
    while (p->num != v)
        p = p->next;
    return p;
}

void insertEdges(int v1, int v2)
{
    Edge* p = (Edge*)malloc(sizeof(Edge));
    p->vNum1 = v1;
    p->vNum2 = v2;
    p->isTree = 0;
    p->next = NULL;
    Edge* q = eHead;
    if(q == NULL) // 연결리스트 비어있으면
        eHead = p;
    else
    {
        while(q->next != NULL)
            q = q->next;
        q->next = p;
    }
    // 정접과 간선 사이 인접간선들 연결
    Vertex* v = findVertex(v1);
    insertIncidentEdge(v, v2, p);
    v = findVertex(v2); // 양쪽 정점 모두 간선 연결
    insertIncidentEdge(v, v1, p);
}

void dfs(Vertex* v)
{
    IncidentEdge* q;
    if(v->isFresh == 0)
    {
        printf("[%d] ", v->num);
        v->isFresh = 1;
    }
    for(q = v->top; q != NULL; q = q->next)
    {
        v = findVertex(q->adjVertex);
        if(v->isFresh == 0)
            dfs(v);
    }
}

void bfs(Vertex* v)
{
    IncidentEdge* q;
    Vertex* p;
    if(v->isFresh == 0)
    {
        printf("[%d] ", v->num);
        v->isFresh = 1;
    }
    while(v != NULL)
    {
        for(q = v->top; q != NULL; q = q->next)
        {
            p = findVertex(q->adjVertex);
            if(p->isFresh == 0)
            {
                printf("[%d] ", p->num);
                p->isFresh = 1;
            }
        }
        v = v->next;
        bfs(v);
    }
    return;
}

void print()
{
    Vertex* p = vHead;
    IncidentEdge* q;
    for(; p!= NULL; p = p->next)
    {
        printf("정점 %d : ", p->num);
        for(q = p->top; q!= NULL; q = q->next)
            printf("[%d] ", q->adjVertex);
        printf("\n");
    }
}

int main()
{
    for(int i = 0; i < 9; i++)
        makeVertices();

    insertEdges(1, 2);
    insertEdges(1, 3);
    insertEdges(2, 4);
    insertEdges(2, 5);
    insertEdges(3, 5);
    insertEdges(3, 6);
    insertEdges(4, 7);
    insertEdges(5, 7);
    insertEdges(5, 8);
    insertEdges(6, 8);
    insertEdges(7, 9);
    insertEdges(8, 9);
    
    // insertEdges(1, 2);
    // insertEdges(1, 5);
    // insertEdges(2, 3);
    // insertEdges(4, 5);
    // insertEdges(5, 2);
    // insertEdges(5, 3);
    // insertEdges(5, 6);
    // insertEdges(6, 3);
    print();
    // dfs(vHead);
    bfs(vHead);
}