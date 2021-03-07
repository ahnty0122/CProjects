// 비트행렬에서 최대 1행 찾기
// mostOnesButSlow 함수는 O(N^2) 시간 복잡도
// mostOnes는 O(2N) 시간 복잡도

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 난수생성

#define ROWS 8
#define COLS 8

// 배열 생성 함수: 2차원 배열 전달 받아 8 * 8 행렬 만들 것
void makeArray(int A[][COLS])
{
	for(int r = 0; r < ROWS; r++)
	{
	    int count = rand() % 8;
	    for(int i = 0; i < count; i++)
	        A[r][i] = 1;
	    for(int j = count; j < COLS; j++)
	        A[r][j] = 0;
	}
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

void mostOnesButSlow(int A[][COLS])
{
    int jmax = 0;
    int i, j, row; // i가 행을 움직이고 j가 열 움직임
    for(i = 0; i < ROWS; i++)
    {
        j = 0;
        while(j < COLS && A[i][j] == 1)
            j++;
        if(j > jmax)
        {
            row = i;
            jmax = j;
        }
    }
    printf("%d행에 %d개의 1이 최대값임\n", row, jmax);
}

// 1차원 배열이 함수 매개변수로 전달될 땐 인덱스 생략해서 전달해야함
// 2차원 배열이 함수 매개변수로 전달될 땐 행 인덱스는 생략해도 되지만 열 인덱스는 생략 시 에러남
int mostOnes(int A[][COLS])
{
    int i = 0, j = 0;
    int row;
    
    while(1)
    {
        while(A[i][j] == 1)
        {
            j++;
            if(j == COLS - 1)
                return i; // 행 값 return
        }
        // while문 빠져나오면
        row = i; // row 에다가 i 할당
        while(A[i][j] == 0)
        {
            i++;
            if(i == COLS - 1)
                return row;
        }
    }
}

void main()
{
	int A[ROWS][COLS]; // 2차원 배열 선언
	srand(time(NULL)); // seed 값 변경, srand안하면 계속 똑같은 값 발생
    makeArray(A); 
	printArray(A); 
    getchar(); // 화면 잠깐 멈춰주기
    
    printf("최대 1행은 %d행입니다.\n", mostOnes(A));
    // mostOnesButSlow(A);
}