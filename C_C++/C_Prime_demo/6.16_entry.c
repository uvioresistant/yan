// 入口条件循环
#include <stdio.h>
int main(void)
{
    const int secret_code = 13;
    int code_entered;

    printf("To enter .\n");
    printf("please enter the secret code number:");
    scanf("%d", &code_entered);

    while (code_entered != secret_code)
    {
        printf("To enter .\n");
        printf("please enter the secret code number:");
        scanf("%d", &code_entered);
    }
    printf("Congratulation! You are cured!\n");
    return 0;
    
}