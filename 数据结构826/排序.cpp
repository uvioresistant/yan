//8.2.插入排序
/*8.2.1.直接插入排序算法InsertSort*/
//王道
void InsertSort(ElemType A[], int n){
	int i, j;
	for(i=2; i<=n; i++)			//依次将A[2]~A[n]插入到前面已排序序列
		if(A[i]<A[i-1]){		//若A[i]关键码小于其前驱，将A[i]插入有序表
			A[0]=A[i];			//复制为哨兵，A[0]不存放元素
			for(j=i-1;A[0]<A[j];--j)	//从后往前查找待插入位置
				A[j+1]=A[j];	//向后挪位
			A[j+1]=A[0];		//复制到插入位置
		}
	
}


void InsertSort(int r[], int n)
{
	for (i=2; i<=n; i++)	//将第一个记录看成是初始有序区，从第二个记录起，依次插入到这个有序区中，直到将第n个记录插入完毕
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
//8.3.交换排序
/*8.3.1.冒泡排序*/
//王道
void BubbleSort(ElemType A[], int n){
	for(i=0; i<n-1; i++){
		flag=false;					//表示本趟冒泡是否发生交换的标志
		for(j=n-1; j>i; j--)		//一趟冒泡过程
			if(A[j-1]>A[j]){		//若为逆序
				swap(A[j-1], A[j]);	//交换
				flag=true;
			}
		if(flag==false)
			return;					//本趟遍历后没有发生交换，说明表已经有序
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


/*8.3.2. 快速排序依次划分算法Partition*/
//王道
void QuickSort(ElemType A[], int low, int high){
	if(low<high){		//递归跳出的条件
		int pivotpos=Partition(A, low, high);	//Partition()是划分操作，将表A[low...high]划分为上述条件的两个子表
		QuickSort(A,low,pivotpos-1);	//依次对两个子表进行递归排序
		QuickSort(A,pivotpos+1,high);
	}
}


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
//8.4.选择排序
/*8.4.1.简单选择排序*/
//王道
void SelectSort(ElemType A[], int n){
	for(i=0; i<n-1; i++){				//一共进行n-1趟
		min=i;							//记录最小元素位置
		for(j=i+1; j<n; j++)			//在A[i, n-1]中选择最小的元素
			if(A[j]<A[min]) min=j;		//更新最小元素位置
		if(min!=i) swap(A[i], A[min]);	//封装的swap()共移动元素3次
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

/* 8.4.2.堆排序算法 */
//建立大根堆的算法(王道)
void BuildMaxHeap(ElemType A[], int len){
	for(int i=len/2; i>0; i--)	//从i=[n/2]~1,反复调整堆
		HeadAdjust(A, i, len);
}

void HeadAdjust(ElemType A[], int k, int len){	//将元素k为根的子树进行调整
	A[0]=A[k];		//A[0]暂存子树的根结点
	for(i=2*k; i<=len; i*=2){		//沿key较大的子结点向下筛选
		if(i<len&&A[i]<A[i+1])		//取key较大的子结点的下标
			i++;
		if(A[0]>=A[i])	break;		//筛选结束
		else{
			A[k]=A[i];				//将A[i]调整到双亲结点上
			k=i;					//修改k值，以便继续向下筛选
		}
	}
	A[k]=A[0];						//被筛选结点的值放入最终位置
}

/*堆排序算法HeapSort(王道)*/
void HeapSort(ElemType A[], int len){
	BuildMaxHeap(A, len);		//初始建堆
	for(i=len; i>1; i--){		// n-1趟的交换和建堆过程
		Swap(A[i], A[1]);		//输出堆顶元素(和堆底元素交换)
		HeadAdjust(A, 1, i-1);	//调整，把剩余的i-1个元素整理成堆
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

/* 8.5.1.归并排序 */
//归并排序（王道）
ElemType *B=(ElemType *) malloc((n+1)*sizeof(ElemType));	//辅助数组B
void Merge(ElemType A[], int low, int mid, int high){		//表A的两段A[low..mid]和A[mid+1...high]各自有序，将它们合并成一个有序表
		for(int k=low; k<=high; k++)
			B[k]=A[k];										//将A中所有元素复制到B中
		for(i=low, j=mid+1, k=i; i<mid&&j<=high; k++){
			if(B[i]<=B[j])									//比较B的左右两段中的元素
				A[k]=B[i++];								//将较小值复制到A中
			else
				A[k]=B[j++];
	}//for
	while(i<=mid)	A[k++]=B[i++];							//若第一个表未检测完，复制
	while(j<=high)	A[k++]=B[j++];							//若第二个表未检测完，复制
}

//递归的2路归并排序_基于分治(王道)
void MergeSort(ElemType A[], int low, int high){
	if(low<high){
		int mid=(low+high)/2;		//从中间划分两个子序列
		MergeSort(A, low, mid);		//对左侧子序列进行递归排序
		MergeSort(A, mid+1, high);	//对右侧子序列进行递归排序
		Merge(A, low, mid, high);	//归并
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


























