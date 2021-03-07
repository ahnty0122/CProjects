#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 난수생성

#define SIZE 8

// 배열 생성 함수: 1차원 배열
void makeArray(int A[])
{
	for(int i = 0; i < SIZE; i++)
	    A[i] = rand() % 50 + 50; // 50부터 99까지 임의의 숫자
}

void printArray(int A[])
{
	for(int i = 0; i < SIZE; i++)
	    printf("[%d]", A[i]);	
	printf("\n");
}

// 중첩된 반복문 --> O(N^2)
void prefixAvg1(int A[])
{
    int X[SIZE]; // 누적 합 저장할 배열
    int sum;
    for(int i = 0; i < SIZE; i++)
    {
        sum = 0;
        for(int j = 0; j <= i; j++)
            sum += A[j];
        X[i] = sum / (i + 1); // 누적 평균
    }
    printArray(X); // 정답 배열 출력
}

// 선형시간 알고리즘으로 변경
void prefixAvg2(int A[])
{
    int X[SIZE]; // 누적 합 저장할 배열
    int sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        sum += A[i];
        X[i] = sum / (i + 1); // 누적 평균
    }
    printArray(X); // 정답 배열 출력
}

void main()
{
	int A[SIZE]; // 1차원 배열 선언
	srand(time(NULL)); // seed 값 변경, srand안하면 계속 똑같은 값 발생
    makeArray(A); 
	printArray(A); 
    getchar(); // 화면 잠깐 멈춰주기
    // prefixAvg1(A);  // O(N^2) 알고리즘
    prefixAvg2(A); // O(N) 알고리즘
}