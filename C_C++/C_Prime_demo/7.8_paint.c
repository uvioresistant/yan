// 使用条件运算符
#include <stdio.h>
#define COVERAGE 200    /* 每桶漆可以喷涂的平方英尺数 */

int main(void)
{
    int sq_feet;
    int cans;

    printf("Enter number of square feet to be painted: \n");
    while(scanf("%d", &sq_feet) == 1)
    {
        cans = sq_feet / COVERAGE;
        cans += ((sq_feet % COVERAGE == 0)) ? 0: 1;
        printf("you need %d %s of paint.\n", cans, cans == 1 ? "can": "cans");
    }
    return 0;
}