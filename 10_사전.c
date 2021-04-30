#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15

typedef struct
{
    int key;
    char value[10];
}element;

typedef struct
{
    element dict[SIZE]; // element 배열로 사전 만들기
    int size;
}DictType;

void init(DictType* d)
{
    d->size = 0;
}

void insertKey(DictType* d)
{
    for(int i = 0; i < SIZE; i++)
    {
        d->dict[i].key = rand() % 30 + 1;
        for(int j = 0; j < i; j++)
            // 유일 key 사전->원래 있는 값이면 안됨
            if(d->dict[i].key == d->dict[j].key)
                i--;
    }
}

void insertValue(DictType* d)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < 5; j++)
            d->dict[i].value[j] = rand() % 26 + 97;
        d->size++;
    }
}

void makeDict(DictType* d)
{
    insertKey(d);
    insertValue(d);
}

void printDict(DictType* d)
{
    printf("Key value \n========== \n");
    for(int i = 0; i < d->size; i++)
    {
        printf("%2d  ", d->dict[i].key);
        for(int j = 0; j < 5; j++)
            printf("%c", d->dict[i].value[j]);
        printf("\n");
    }
}

int main()
{
    DictType d;
    init(&d);
    srand(time(NULL));
    makeDict(&d);
    printDict(&d);
}