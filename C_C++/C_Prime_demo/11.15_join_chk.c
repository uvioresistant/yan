// 连接两个字符串，并检查第一个字符串的大小
#include <stdio.h>
#include <string.h>
#define SIZE 30
#define BUGSIZE 13

int main(void)
{
    char flower[SIZE];
    char zaddon[] = "s smell like old shoes.";
    char bug[BUGSIZE];
    int available;

    puts("What is your favorite flower?");
    gets(flower);
    if((strlen(zaddon) + strlen(flower) +1) <= SIZE)
        strcat(flower, zaddon);
    puts(flower);
    puts("What is your favorite bug?");
    gets(bug);
    available = BUGSIZE - strlen(bug) -1;
    strncat(bug, zaddon, available);
    puts(bug);

    return 0;
}