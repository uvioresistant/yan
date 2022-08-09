// 旅馆房间收费程序
// 与9.10一起编译
#include <stdio.h>
#include "9.10_hotel.c"  //定义常量、声明函数
int main(void)
{
    int nights;
    double hotel_rate;
    int code;

    while((code = menu()) != QUIT)
    {
        switch(code)
        {
            case 1: hotel_rate = HOTEL1;
                break;
            case 2: hotel_rate = HOTEL2;
                break;
            case 3: hotel_rate = HOTEL3;
                break;
            case 4: hotel_rate = HOTEL4;
                break;
            default: hotel_rate = 0.0;
                printf("Oops!\n");
                break;
        }
        nights = getnights();
        showprice(hotel_rate, nights);
    }
    printf("Thanks you and goodbye.");
    return 0;
}