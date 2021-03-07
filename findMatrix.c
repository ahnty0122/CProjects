// 행렬에서 특정 원소 찾기

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 난수생성

#define ROWS 8
#define COLS 8

// 배열 생성 함수: 2차원 배열 전달 받아 8 * 8 행렬 만들 것
void makeArray(int A[][COLS])
{
	for(int r = 0; r < ROWS; r++)
		for(int c = 0; c < COLS; c++)
			A[r][c] = rand() % 100; // 0부터 99 사이의 수
}

void printArray(int A[][COLS])
{
	for(int r = 0; r < ROWS; r++)
	{
		for(int c = 0; c < COLS; c++)
			printf("%2d ", A[r][c]);
		printf("\n");
	}
	printf("\n");
}

int findRow(int A[], int key)
{
    for(int c = 0; c < COLS; c++)
        if(A[c] == key)
            return c;
    return -1;
}

void findMatrix(int A[][COLS], int key)
{
    int r = 0;
    int index; // findRow에서 return값 받을 변수
    
    while(r < ROWS)
    {
        index = findRow(A[r], key); // 1차원 배열, key 값 입력 받음
        if(index >= 0)
        {
            printf("%d행 %d열에서 %d발견\n", r, index, key);
            return; // 종료
            
        }
        else // index -1이면 찾지 못한 것이므로 다음 행 전달
            r++;
    }
    // while문 반복 다 했는데 아무 일 없었다면
    printf("Not Found\n");
}

void main()
{
	int A[ROWS][COLS]; // 2차원 배열 선언
	srand(time(NULL)); // seed 값 변경, srand안하면 계속 똑같은 값 발생
    makeArray(A); 
	printArray(A); 
	
	int key;
	printf("Input a key value: ");
	scanf("%d", &key);
	findMatrix(A, key);
}