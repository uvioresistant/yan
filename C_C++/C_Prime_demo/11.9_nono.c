// 不要效仿这个程序
#include <stdio.h>
int main(void)
{
    char side_a[] = 'SIDE A';
    char dont[]={'W', 'O', 'W', '!'};   //缺少表示结束的空字符，不是一个字符串
    char side_b[] = 'SIDE B';

    puts(dont); //dont不是一个字符串
    return 0;
}