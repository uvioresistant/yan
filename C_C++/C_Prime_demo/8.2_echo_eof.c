// 重复输入，直到文件的结尾
#include <stdio.h>
int main(void)
{
    int ch;

    while((ch = getchar()) != EOF);
        putchar (ch);
        return 0;
}