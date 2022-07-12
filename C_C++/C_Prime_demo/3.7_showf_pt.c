/* 以两种方式显示浮点值 */
#include <stdio.h>
int main(void)
{
    float aboat = 32000.0;
    double abet = 2.4e9;
    long double dip = 5.32e-5;
    printf("%f can be written %e\n", aboat, aboat);
    printf("%f can be writeen %e\n", abet, abet);
    printf("%f can be writeen %e\n", dip, dip);
    return 0;
}