#include <stdio.h>
#include <stdlib.h>
#define min(x, y) ((x) < (y) ? (x) : (y))

int main()
{
    int n;
    scanf("%d", &n);
    int d[n + 1];
    d[0] = 0;
    d[1] = 0;
    for(int i = 2; i <= n + 1; i++)
    {
        d[i] = d[i - 1] + 1;
        if(i % 3 == 0) d[i] = min(d[i], d[(int)(i / 3)] + 1);
        if(i % 2 == 0) d[i] = min(d[i], d[(int)(i / 2)] + 1);
    }
    printf("%d", d[n]);
    
}
