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


/*快速排序依次划分算法Partition*/
int Partition(int r[], int first, int end)
{
	i=first; j=end;		//初始化
	while(i<j)
	{
		while(i<j && r[i]<= r[j]) j--;	//右侧扫描
		if(i<j){
			r[i]<-->r[j];	//将较小记录交换到前面
			i++;
		}
		while(i<j && r[i]<= r[j]) i++;	//左侧扫描
		if(i<j){
			r[j]<-->r[i];	//将较大记录交换到后面
			j--;
		}
	}
	return i;	//i为轴值记录的最终位置

}

/*快速排序算法QuickSort*/
void QuickSort(int r[], int first, int end)
{
	if(first<end){	//递归结束
		pivot = Partition(r, first, end);	//一次划分
		QuickSort(r, first, pivot-1);	//递归地对左侧子序列进行快速排序
		QuickSort(r, pivot+1, end);		//递归地对右侧子序列进行快速排序	
	}
}

/*简单选择排序算法SelectSort*/
void SelectSort(int r[], int n)
{
	for(i=1; i<n; i++) //对n个记录进行n-1趟简单选择排序
	{
		index=i;
		for(j=i+1; j<=n; j++)	//在无序区中选取最小记录
			if(r[j]<r[index]) index=j;
		if(index != i) r[i]<-->r[index];
	}
}


/*筛选法调整堆的算法Sift*/
void Sift(int r[], int k, int m)
{
	i=k; j=2*i;		//置i为要晒的结点，j为i的左孩子
	while(j<=m)		//筛选还没有进行到叶子
	{
		if(i<m && r[j]<r[j+1]) j++;	//比较i的左右孩子，j为较大者
		if(r[i]>r[j]) break;		//根结点已经大于左右孩子中的较大者
			else{
				r[i]<-->r[j];	//将根结点与结点j交换
				i=j; j=2*i;		//被筛结点位于原来结点j的位置
			}
	}
	
}

/*堆排序算法HeapSort*/
void HeapSort(int r[], int n)
{
	for(i=n/2; i>=1; i--)	//初始建堆，从最后一个非终端结点至根结点
		Sift(r, i, n)
	for(i=1; i<n; i++)		//重复执行移走堆顶及重建堆的操作
	{
		r[i]<-->r[n-i+1];
		Sift(r, 1, n-1);
	}
	
}

/*一次归并算法Merge*/
void Merge(int r[], int r1[], int s, int m, int t)
{
	i=s; j=n+1; k=s;
	while(i<=n && j<=t)
	{
		if(r[i]<=r[j]) r1[k++]=r[i++];	//取r[i]和r[j]中较小者放入r1[k]
			else r1[k++]=r[j++];
	}
	if(i<=n) while(i<=m)	//若第一个子序列没处理完，则进行收尾处理
		r1[k++]=r[i++];
	else while(j<=t)		//若第二个子序列没处理完，则进行收尾处理
		r1[k++]=r[j++];
	
}


/*一趟归并排序算法MergePass*/
void MergePass(int r[], int r1[], int n, int h)
{
	i=1;
	while(i<=n-2h+1)	//待归并记录至少有两个长度为h的子序列
	{
		Merge(r, r1, i, i+h-1, i+2*h-1);
		i+=2*h;
	}
	if(i<n-h+1) Merge(r, r1, i, i+h-1, n);	//待归并序列中有一个长度小于h
		else for(k=i; k<=n; k++)	//带归并序列中只剩一个子序列
			r1[k]=r[k];
}

/*归并排序非递归算法MergeSort1*/
void MergeSort1(int r[], int r1[], int n)
{
	h=1;
	while(h<n)
	{
		MergePass(r1, r, n, h);
		h=2*h;
	}
}

/*归并排序的递归算法MergeSort2*/
void MergeSort2(int r[], int r1[], int s, int t)
{
	if(s==t) r1[s]=r[s];
	else{
		m=(s+t)/2;
		MergeSort2(r, r1, s, m);	//归并排序前半个子序列
		MergeSort2(r, r1, m+1, t);	//归并排序后半个子序列
		Merge(r1, r, s, m, t);		//将两个已排序的子序列归并
	}
}


























