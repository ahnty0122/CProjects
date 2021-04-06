#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MAX_SIZE 15

int sorted[MAX_SIZE]; // 정렬된 결과물 저장할 배열

void merge(int list[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int l; // 반복문에 들어갈 변수 l
    
    while(i <= mid && j <= right)
    {
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if(i > mid) // 오른쪽 sub 배열을 전부 sorted에 넣기
        for(l = j; l <= right; l++)
            sorted[k++] = list[l];
    else
        for(l = i; l <= mid; l++)
            sorted[k++] = list[l];
    for(l = left; l <= right; l++)
        list[l] = sorted[l]; // 대입
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

void main()
{
    int list[MAX_SIZE]; // 입력받을 배열
    srand(time(NULL));
    // 배열 초기화
    for(int i = 0; i < MAX_SIZE; i++)
    {
        list[i] = rand() % 100;
        for(int j = 0; j < i; j++)
            if(list[i] == list[j])
            i--; // 중복되지 않게 같으면 입력 취소
    }
    for(int i = 0; i < MAX_SIZE; i++)
        printf("[%d] ", list[i]);
    printf("\n\n");

    merge_sort(list, 0, MAX_SIZE - 1);
    for(int i = 0; i < MAX_SIZE; i++)
    {
        printf("[%d] ", list[i]);
        Sleep(500); // 0.5초에 하나씩 출력
    }
    printf("\n");
}