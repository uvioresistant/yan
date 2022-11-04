// strcpy()示例
#include <stdio.h>
#include <string.h>
#define WORDS "beast"
#define SIZE 40

int main(void)
{
    char *orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char * ps;

    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig);    //strcpy()从源字符串复制空字符，空字符覆盖了that中的第一个t，新字符串以beast结尾
                                    //意味着“把orig字符串的内容复制到此处”
    puts(copy);
    puts(ps);   //ps指向copy的第8个元素，因为第一个参数是copy+7。因此,puts(ps)从这个地方开始输出字符串

    return 0;
}