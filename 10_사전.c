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

void insertion_sort(DictType* d)
{
    int i, j;
    element item;
    for(i = 1; i < SIZE; i++)
    {
        item = d->dict[i];
        for(j = i - 1; j >= 0 && d->dict[j].key > item.key; j--)
            d->dict[j + 1] = d->dict[j];
        d->dict[j + 1] = item;
    }
}

int rFindElement(DictType* d, int key, int l, int r)
{
    int mid;
    if(l <= r)
    {
        mid = (l + r) / 2;
        if(key == d->dict[mid].key)
            return mid;
        else if(key < d->dict[mid].key)
            return rFindElement(d, key, l, mid - 1);
        else
            return rFindElement(d, key, mid + 1, r);
    }
    return -1;
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
    getchar();
    printf("\n");
    insertion_sort(&d);
    printDict(&d);
    getchar();

    printf("\n검색할 키값을 입력: ");
    int key;
    scanf("%d", &key);
    int index = rFindElement(&d, key, 0, SIZE - 1);
    if(index == -1)
        printf("\n검색에 실패하였음\n");
    else
    {
        printf("\n위치 %d에서의 키: %d, 값: ", index + 1, key);
        for(int j = 0; j < 5; j++)
            printf("%c", d.dict[index].value[j]);
        printf("이 검색되었음\n");
    }

    return 0;
}