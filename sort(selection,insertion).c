#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_SIZE 15
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void selection_sort(int list[], int n)
{
    int least, temp; // least는 min location, 최솟값
    for(int i = 0; i < n - 1; i++)
    {
        least = i;
        for(int j = i + 1; j < n; j++)
            if(list[j] < list[least])
                least = j;
        SWAP(list[i], list[least], temp);
    }
}

void insertion_sort(int list[], int n)
{
    int i, j, save;
    for(i = 1; i < n; i++)
    {
        save = list[i];
        for(j = i - 1; j >= 0 && list[j] > save; j--)
            list[j + 1] = list[j];
        list[j + 1] = save;
    }
}

void inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for(i = first + gap; i <= last; i = i + gap)
    {
        key = list[i];
        for(j = i - gap; j >= first && list[j] > key; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}


void shell_sort(int list[], int n)
{
    int i, gap;
    for(gap = n / 2; gap > 0; gap = gap / 2)
    {
        if(gap % 2 == 0)
            gap++;
        for(i = 0; i < gap; i++)
        {
            inc_insertion_sort(list, i, n - 1, gap);
        }
    }
}

void main()
{
    int list[MAX_SIZE];
    srand(time(NULL)); // seed 값 바꿔주기
    
    for(int i = 0; i < MAX_SIZE; i++)
    {
        list[i] = rand() % 100; // 배열 초기화
        for(int j = 0; j < i; j++)
            if(list[i] == list[j])
                i--; // 중복 허용하지 않고 임의의 수 생성해 배열에 초기화
    }

    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n\n"); getchar();

    // selection_sort(list, MAX_SIZE);
    // insertion_sort(list, MAX_SIZE);
    shell_sort(list, MAX_SIZE);

    for(int i = 0; i < MAX_SIZE; i++)
    {    
        printf("%d ", list[i]);
        Sleep(500); // inclue Windows.h
    }
    printf("\n\n");
}