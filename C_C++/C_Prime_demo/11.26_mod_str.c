/* 修改一个字符串 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 80


void ToUpper(char *);
int PunctCount(const char *);

int main(void)
{
    char line[LIMIT];

    puts("Please enter a line : ");
    gets(line);
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n", PunctCount(line));
    return 0;
}

void ToUpper(char * str)
{
    while(*str) // 指向字符串中的每个字符，直到遇见空字符。
    {
        *str = toupper(*str);   //toupper()只改变小写字符
        str++;
    }
}

int PunctCount(const char * str)
{
    int ct = 0;
    while(*str)
    {
        if(ispunct(*str))
            ct++;
        str++;
    }
    return ct;
}