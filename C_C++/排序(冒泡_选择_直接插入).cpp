/*13.2排序*/
/*冒泡排序*/
void BubbleSort(ElemType elem[], int n)
//操作结果：在数组elem中用冒泡排序进行排序
//这里的ElemType可以换成在具体过程中的相应类型
{
    for (int i=n-1; i>0; i--)
        {   //第i趟冒泡排序 
            for (int j=0; j<1; j++)
            { // 比较elem[j]与elem[j+1] 
                if (elem[j]>elem[j+1])
                { //如出现逆序，则交换elem[j]和elem[j+1]
                    Swap(elem[j], elem[j+1]);
                    // Swap函数的功能是交换2个参数的值，可自主实现
                }
            }
        } 
 }
 
/*改进版冒泡排序*/
 
