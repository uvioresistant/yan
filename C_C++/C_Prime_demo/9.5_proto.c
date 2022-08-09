// 使用函数原型
#include <stdio.h>
// int imax(int, int); //原型
int imax(int a, int b){return a > b ? a: b;}

int main(void)
{
    printf("The maximum of %d and %d is %d.\n ", 3, 5, imax(3, 5));
    printf("The maximum of %d and %d is %d.\n ", 3, 5, imax(3.0, 5.0));

    return 0;
}
/* 
int imax(int n, int m)
{
    int max;
    if(n > m)
        max = n;
    else
        max = m;
    return max;
} */
