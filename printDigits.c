#include <stdio.h>
#include <stdlib.h>

// printDigits는 재귀 rPrintDigits를 구동하여 양의 정수를 한 라인에 한 숫자씩 인쇄한다
// 3408 입력하면 3 4 0 8 한 라인씩 나옴

void rPrintDigits(int n)
{
    if(n < 10)
        printf("%d\n", n);
    else
    {
        rPrintDigits(n / 10);
        printf("%d\n", n % 10);
    }
    
}

void printDigits()
{
    // 숫자 입력 받아서
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    if(n < 0)
        // 음수인 경우 해당 X
        printf("Negative!\n");
    else
        // 음수인 경우 재귀 호출
        rPrintDigits(n);
}

void main()
{
    printDigits();
}