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

/*希尔排序算法ShellSort*/
void ShellSort(int r[], int n)
{
	for (d=n/2; d>=1; d=d/2)	//以增量为d进行直接插入排序
	{
		for (i=d+1; i<=n; i++)	//将r[i]插入到所属的子序列中
		{
			r[0]=r[i];	//暂存被插入记录,r[0]只是暂存单元，不是哨兵；
			for(j=i-d; j>0 && r[0]<r[j]; j=j-d)	//插入记录r[i]时，自r[i-d]起，往前跳跃式(跳跃幅度为0)查找待插入位置，在查找过程中，记录后移也是跳跃d个位置
				r[j+d]=r[j];		//记录后移d个位置，保证仍在同一个子序列 ,当搜索位置j<=0或r[0]>=r[j],表示插入位置已找到
			r[j+d]=r[0];
		}
	}	
}

/*起泡排序算法BubbleSort*/
void BubbleSort(int r[], int n)
{
	exchange=n;	//第一趟排序的范围是r[1]到r[n]
	while(exchage)	//仅当上一趟排序有记录交换才进行本趟排序
	{
		bound=exchage; exchage=0;
		for (j=1; j<bound; j++)	//一趟排序
			if(r[j]>r[j+1]){
				r[j]<-->r[j+1];
				exchange=j;	//记录每一次发生记录交换的位置
			}
	}
}













































