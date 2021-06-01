#include <stdio.h>
#include <stdlib.h>

#define N 100

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("[%d ] ", arr[i]);
    printf("\n");
}

void subset(int arr[], int setSize, int n, int idx)
{
    if(idx == n)
    {
        printArr(arr, setSize);
        return;
    }

    arr[setSize] = idx;

    subset(arr, setSize + 1, n, idx + 1); // ����
    subset(arr, setSize, n, idx + 1); // ������
}

int main()
{
    int arr[N], n; // ������ ����
    scanf("%d", &n);

    subset(arr, 0, n, 0); // �迭, �κ������� size, ������ ����, ���� index
}