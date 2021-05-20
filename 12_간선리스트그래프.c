#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char vName;
}Vertex;

typedef struct
{
    int eNo; // 간선번호
    int weight; // 가중치
    Vertex v1, v2;
}Edge;

typedef struct
{
    Vertex v[10]; // 정점 배열
    Edge e[30]; // 간선 배열
    int vCount;
    int eCount;
}Graph;

void init(Graph* G)
{
    G->vCount = 0;
    G->eCount = 0;
}

void makeVertex(Graph* G)
{
    G->v[G->vCount].vName = 97 + G->vCount; // 정점의 이름을 알파벳으로 입력
    G->vCount++; // 정점 개수 카운팅
}

void insertEdge(Graph* G, int w, Vertex v1, Vertex v2)
{
    G->e[G->eCount].eNo = G->eCount;
    G->e[G->eCount].weight = w;
    G->e[G->eCount].v1 = v1;
    G->e[G->eCount].v2 = v2;
    G->eCount++;
}

int main()
{
    Graph G;
    init(&G);
    for(int i = 0; i < 6; i++)
        makeVertex(&G);
    
    insertEdge(&G, 1, G.v[0], G.v[1]); // a, b
    insertEdge(&G, 1, G.v[0], G.v[2]); // a, c
    insertEdge(&G, 1, G.v[0], G.v[3]); // a, d
    insertEdge(&G, 2, G.v[0], G.v[5]); // a, f
    insertEdge(&G, 1, G.v[1], G.v[2]); // b, c
    insertEdge(&G, 4, G.v[2], G.v[4]); // c, e
    insertEdge(&G, 3, G.v[4], G.v[5]); // e, f

    for(int i = 0; i < G.vCount; i++)
        printf("[%c] ", G.v[i].vName);
    printf("\n");

    
    for(int i = 0;i < G.eCount; i++)
        printf("[%d : %c - %c - %d] ", G.e[i].eNo, G.e[i].v1.vName, G.e[i].v2.vName, G.e[i].weight);
    printf("\n");
}