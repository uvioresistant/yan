/* 2. */
// a. void donut(int n)
// b. gear(int n, int m)    -> int gear(int t1, int t2)
// c. void stuff_it(double n, double &m)

/* 3. */
// a. char n_to_char(int n)
// b. int digits(double *n, int *m) ->int digits(double x, int n)
// c. int random(void)

/* 4. */
// int n, m;
// int sum(int, int);

// int sum(int n, int m)
// {
//     int total;
//     total = n + m;
//     return total;
// }
// ->
// int sum(int a, int b)
// {
//     return a + b;
// }

/* 5. */
// double sum(double a, double b)
// {
//     return a + b;
// }

/* 6. */

/* int alter(int * x, int * y)
{
    *x = (*x + *y);
    *y = (*x - *y);
} */

// ->
// void alter(int * pa, int * pb)
// {
//     int temp;
//     temp = *pa + *pb;
//     *pb = *pa - *pb;
//     *pa = temp;
// }

// void alter(int * pa, int * pb)
// {
//     *pa += *pb;
//     *pb = *pa - 2 * *pb;
// }

/* 7.  */
/* 错误，count <= num;num++ 则无限循环 */
// ->
// num应该在salami()的参数列表中,而不是在{}之后声明，且应该是count++而不是num++

/* 8. */
/* int largest(int a1, int a2, int a3)
{
    int max;
    max = a1 > a2 ? a1 : a2;
    max = max > a3 ? max : a3;
    return max;
} */

// ->
// int largest(int a, int b, int c)
// {
//     int max = a;
//     if(b > max)
//         max = b;
//     if(c > max)
//         max = c;
//     return max;
// }

/* 9. */
/* #include <stdio.h>
int choices(int);
int func_b(int, int);
int n;
int a, b;


int choices(int n)
{
    int input;
    printf("Please choose one of the following: \n 1)copy files 2)move files 3)remove files 4)quit \n Enter the number of your choices:");
    input = scanf("%d", n);
    switch (input)
    {
    case 1:
        printf("1) copie files\n");
    case 2:
        printf("2) copie files\n");
    case 3:
        printf("3) copie files\n");
    case 4:
        printf("4) copie files\n");
        break;
    default:
        break;
    }
    return input;
}

int func_b(int a, int b)
{
    if (choices(n) < a || choices(n) > b)
        choices(n);
    else 
        return n;
}

void main(void)
{
    int a, b;
    choices(n);
    func_b(a, b);
};
 */
// ->
// #include <stdio.h>
// void showmenu(void);    /* 声明要用到的函数 */
// int getchoice (int, int);
// main()
// {
//     int res;
//     showmenu();
//     while((res = getchoice(1, 4)) != 4)
//         printf("I like choice %d.\n", res);
//     printf("Bye!\n");
//     return 0;
// }

// void showmenu(void)
// {
//     printf("Please choose one of the following: \n"); 
//     printf("1)copy files 2)move files \n");
//     printf("3)remove files 4)quit \n ");
//     printf("Enter the number of your choices: \n");
    
// }

// int getchoice(int low, int high)
// {
//     int ans;
//     scanf("%d", &ans);
//     while (ans < low || ans > high)
//     {
//         printf("%d is not a valid choice: try again\n", ans);
//         showmenu();
//         scanf("%d", &ans);  //此处自己的回答有误，需注意
//     }
//     return ans;
// }