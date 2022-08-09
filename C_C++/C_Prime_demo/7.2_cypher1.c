// 改变输入，只保留其中的空格
#include <stdio.h>
#define SPACE ' '   //SPCAE相当于引号-空格-引号
int main(void)
{
    char ch;
    ch = getchar();
/*     while (ch != '\n')
    {
        if(ch == SPACE)
            putchar(ch);
        else
            putchar(ch + 1);
        ch = getchar();
    }
    putchar(ch); */
    while((ch = getchar()) != '\n')
    {
        if(ch == SPACE)
            putchar(ch);
        else
            putchar(ch + 1);
    }
    return 0;
}