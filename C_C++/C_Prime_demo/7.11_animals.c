// 使用switch语句
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    printf("Give me a letter of the alphabet, and I will give");
    printf("an animal name\n beginning with that letter.\n");
    printf("please type in a letter: type # to end my act.\n");
    while((ch = getchar()) != '#')
    {
        if('\n' == ch)
            continue;
        if(islower(ch)) /* 只识别小写字母 */
            switch (ch)
            {
            case 'a':
                printf("argali, a wild sheep of Asia\n");
                break;
            
            default:
                printf("That's a stumper!\n");
            }
        else
            printf("I recognize only lowercase letter.\n");
        while (getchar() != '\n')
            continue;
        printf("Please type another letter or a #.\n");
    }
    printf("Bye!\n");
    return 0;
}