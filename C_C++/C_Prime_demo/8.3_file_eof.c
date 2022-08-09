// 打开一个文件并显示其内容
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int ch;
    FILE * fp;
    char fname[50];     //用于存放文件名

    printf("Enter the name of the file: ");
    scanf("%s", fname);
    fp = fopen(fname, "r"); //打开文件以供读取
    if (fp == NULL) //尝试打开文件失败
    {
        printf("Failed to open file. Bye\n");
        exit(1);
    }
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
    return 0;
}