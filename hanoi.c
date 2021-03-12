#include <stdio.h>
#include <stdlib.h>

// 직접 재귀로 하노이탑 구현
void rHanoi(int n, char from, char aux, char to)
{
    if(n == 1)
        printf("Disk %d : Move from %c to %c\n", n, from, to);
    else
    {
        rHanoi(n - 1, from, to, aux); // n-1개 원판을 가운데 aux로 놓기
        printf("Disk %d : Move from %c to %c\n", n, from, to);
        rHanoi(n - 1, aux, from, to);
    }
}

void main()
{
    rHanoi(4, 'A', 'B', 'C');
}