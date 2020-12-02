/*直接插入排序算法InsertSort*/
void InsertSort(int r[], int n)
{
	for (i=2, i<=n, i++)	//将第一个记录看成是初始有序区，从第二个记录起，依次插入到这个有序区中，直到将第n个记录插入完毕
	{
		r[0]=r[i];	//设置哨兵
		for (j=i-1; r[0]<=r[j]; j--) //寻找插入位置~自i-1起，往前查找的过程中，同时后移记录
			r[j+1]=r[j];			 //记录后移
		r[j+1]=r[0];	//退出循环，说明找到了插入位置，因为r[j]刚刚比较完毕,j+1为正确的插入位置，将待插记录插入到有序表中
	}
	
}