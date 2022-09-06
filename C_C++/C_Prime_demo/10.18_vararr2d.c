// 使用变长数组的函数
#include <stdio.h>
#define ROWS 3
#define COLS 4
int sum2d(int rows, int cols, int ar[rows][cols]);
int main(void)
{
    int i, j;
    int rs = 3;
    int cs = 10;
    int junk[ROWS][COLS] = {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6}
    };

    int morejunk[ROWS-1][COLS+2] = {    //2行6列
        {20, 30, 40, 50, 60, 70},
        {5, 6, 7, 8, 9, 10}
    };

    int varr[rs][cs];   //变长数组

    for(i=0; i<rs; i++) // 0 1 2
        for(j=0; j<cs; j++) //j:0~9
            varr[i][j] = i * j + i; //0*0~9+0=0, 1*0~9+1=0~10; 2*0~9+2=0~20
        printf("3x5 array\n");
    printf("Sum of all elements = %d\n", sum2d(ROWS, COLS, junk)); // 80
    printf("2x6 array\n");
    printf("Sum of all elements = %d\n", sum2d(ROWS-1, COLS+2, morejunk)); //315
    printf("3x10 VLA\n");
    printf("Sum of all elements=%d\n", sum2d(rs, cs, varr)); //3行10列 110+55=165
    return 0;
}

int sum2d(int rows, int cols, int ar[rows][cols])
{
    int r;
    int c;
    int tot = 0;
    for(r=0; r<rows; r++)
        for(c=0; c<cols; c++)
            tot += ar[r][c];
    return tot;
}