// 指针操作
#include <stdio.h>
int main(void)
{
    int urn[5] = {100, 200, 300, 400, 500};
    int * ptr1, * ptr2, * ptr3;

    ptr1 = urn; //使用数组名或地址运算符&来进行地址赋值，把第一个地址赋给指针
    ptr2 = &urn[2]; //取得指针指向的值，并得到指针的地址，ptr2得到urn[2]最后一个元素的地址
    printf("pointer value, dereferenced pointer, pointer, pointer address:\n");
    printf("ptr1 = %p, *ptr1=%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

    // 指针加法
    ptr3 = ptr1 + 4;    // ptr+4的结果等同于&urn[4]
    printf("\nadding an int to a pointer:\n");
    printf("ptr1 +4 = %p, *(ptr4+3) = %d\n", ptr1+4, *(ptr1+3));

    // 递增指针
    ptr1++; // 对指向某数组元素的指针做增量运算，可让指针指向该数组的下一个元素
    printf("\nvalues after ptr1++\n");
    printf("ptr1 = %p, *ptr1=%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1); //ptr1指向urn[1]，ptr1的值是下一个数组元素的地址(000000000061FE04)，*ptr的数值为200(urn[1]的值)，ptr1本身的地址不变&ptr1==&ptr1==000000000061FDF8

    // 递减指针
    ptr2--;
    printf("\nvalues after --ptr2\n");
    printf("ptr2 = %p, *ptr2=%d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);

    
    --ptr1; // 恢复为初始值
    ++ptr2; // 恢复为初始值
    printf("\nPointer reset to original values:\n");
    printf("ptr1 = %p, ptr2=%p, *ptr1=%d, *ptr2=%d \n", ptr1, ptr2, *ptr1, *ptr2);

    // 一个指针减去另一个指针
    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %d\n",ptr2, ptr1, ptr2 - ptr1); //可求出两个指针建的差值。对分别指向同一个数组内，两个元素的指针求差值，求出元素建的距离

    // 一个指针减去一个整数
    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3=%p, ptr3-2=%p\n", ptr3, ptr3-2); //ptr3-2的结果等同于&urn[2],因为ptr3是指向&urn[4]的

    return 0;

}