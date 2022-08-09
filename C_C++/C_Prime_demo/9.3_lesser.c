// 找出两个整数中的较小者
#include <stdio.h>
int imin(int, int);

int main(void)
{
    int evil1, evil2;

    printf("Enter a pair of int int(q to quit): \n");
    while(scanf("%d %d", &evil1, &evil2) == 2)
    {
        printf("The lesser of %d and %d is %d.\n",
        evil1, evil2, imin(evil1, evil2));
    }
    printf("Bye.\n");

    return 0;
}

int imin(int n, int m)
{
    int min;

/*     if(n<m)
        min = n;
    else 
        min = m;
    return min; */
    return (n < m) ? n: m;
}