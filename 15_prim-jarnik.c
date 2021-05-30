// 그래프 구현
#include <stdio.h>
#include <stdlib.h>
#define N 5
#define INF 10000

typedef struct Edge
{
    int vNum1;
    int vNum2;
    int weight;
    struct Edge* next;
}Edge;

typedef struct IncidentEdge // 인접 정점
{
    int adjVertex;
    int weight;
    Edge* e;
    struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex
{
    int num;
    int isFresh; // 정점의 방문 여부 판단 
    struct Vertex* next;
    IncidentEdge* top;
}Vertex;

Vertex* vHead = NULL;
Edge* eHead = NULL;
int vCount;
int eCount;
int dist[N]; // 배낭 역할하는 배열, N은 정점의 개수

void makeVertices()
{
    Vertex* p = (Vertex*)malloc(sizeof(Vertex));
    p->num = ++vCount;
    p->top = NULL;
    p->next = NULL;
    p->isFresh = 0;
    Vertex* q = vHead;
    if(q == NULL)
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
    p->weight = e->weight;
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
    while(p->num != v)
        p = p->next;
    return p; 
}

void insertEdges(int v1, int v2, int w)
{
    Edge* p = (Edge*)malloc(sizeof(Edge));
    p->vNum1 = v1;
    p->vNum2 = v2;
    p->weight = w;
    p->next = NULL;
    Edge* q = eHead;
    if(q == NULL)
        eHead = p;
    else
    {
        while(q->next != NULL)
            q = q->next;
        q->next = p;
    }
    Vertex* v = findVertex(v1);
    insertIncidentEdge(v, v2, p);
    v = findVertex(v2);
    insertIncidentEdge(v, v1, p);
}

int getMinVertex()
{
    int v;
    Vertex* p = vHead;
    for(; p != NULL; p = p->next)
        if(p->isFresh == 0)
        {
            v = p->num - 1;
            break;
        }

    for(p = vHead; p != NULL; p = p->next)
        if(p->isFresh == 0 && (dist[p->num - 1] < dist[v]))
            v = p->num - 1;
    return v;
}

void prim(Vertex* v)
{
    IncidentEdge* q;
    Vertex* p;
    int u; // 정점 번호

    for(int i = 0; i < N; i++)
        dist[i] = INF;
    
    dist[v->num - 1] = 0;

    for(int i = 0; i < N; i++)
    {
        u = getMinVertex(); // 정점 번호 받아오기
        p = findVertex(u + 1);
        p->isFresh = 1; // 방문
        printf("[%d] ", p->num);
        for(q = p->top; q != NULL; q = q->next)
        {
            p = findVertex(q->adjVertex);
            if(p->isFresh == 0)
                dist[q->adjVertex - 1] = q->weight;
        }
    }
}

void print()
{
    Vertex* p = vHead;
    IncidentEdge* q;
    for(; p != NULL; p = p->next)
    {
        printf("정점 %d: ", p->num);
        for(q = p->top; q!= NULL; q = q->next)
            printf("[%d (%d)] ", q->adjVertex, q->weight); // 가중치까지 보기
        printf("\n");
    }
}

int main()
{
    for(int i = 0; i < N; i ++)
        makeVertices();
    
    insertEdges(1, 2, 1);
    insertEdges(1, 4, 2);
    insertEdges(1, 5, 4);
    insertEdges(2, 3, 6);
    insertEdges(2, 5, 7);
    insertEdges(3, 5, 5);
    insertEdges(4, 5, 3);

    print();
    prim(vHead);
}