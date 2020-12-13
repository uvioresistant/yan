/*排序*/
//直接插入排序
void InsertSort(int A[], int n){
	int i,j,temp;
	for(i=1;i<n;i++)			//将各元素插入已排好序的序列中
		if(A[i]<A[i-1]){		//若A[i]关键字小于前驱
			temp=A[i]			//用temp暂存A[i]
			for(j=i-1;j>=0 && A[j]>temp; --j)	//检查所有前面已排好序的元素
				A[j+1]=A[j];	//所有大于temp的元素都往后挪位
			A[j+1]=temp;		//复制到插入位置
		}
	
}

//直接插入排序(带哨兵)
void InsertSort(int A[], int n){
	int i,j;
	for(i=2;i<=n;i++)			//依次将A[2]~A[n]插入到前面已排序序列
		if(A[i]<A[i-1]){		//若A[i]关键码小于其前驱，将A[i]插入有序表
			A[0]=A[i];			//复制为哨兵，A[0]不存放元素
			for(j=i-1;A[0]<A[j];--j)	//从后往前查找待插入位置
				A[j+1]=A[j];	//向后挪位
			A[j+1]=A[0];		//复制到插入位置
		}
	
}

//优化---折半插入排序
void InsertSort(int A[], int n){
	int i,j,low,high,mid;
	for(i=2;i<=n;i++){		//依次将A[2]~A[n]插入前面的已排序序列
		A[0]=A[i];			//将A[i]暂存到A[0]
		low=1;high=i-1;		//设置折半查找范围
		while(low<=high){	//折半查找(默认递增有序)
			mid=(low+high)/2;	//取中间点
			if(A[mid]>A[0]) high=mid-1;	//查找左半子表
			else low=mid+1;	//查找右半子表
		}
		for(j=i-1;j>=high+1;--j)
			A[j+1]=A[j];	//统一后移元素，空出插入位置
		A[high+1]=A[0];		//插入操作
	}
}


//希尔排序
void ShellSort(int A[], int n){
	int d, i, j;
	//A[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
	for(d=n/2; d>=1; d=d/2)	//步长变化
		for(i=d+1; i<=n; ++i)
			if(A[i]<A[i-d]){	//需将A[i]插入有序增量子表
				A[0]=A[i];		//暂存在A[0]
				for(j=i-d; j>0 && A[0]<A[j]; j-=d)
					A[j+d]=A[j];	//记录后移，查找插入的位置
				A[j+d]=A[0];	//插入
			}
}

/*冒泡排序*/
//交换
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

//冒泡排序
void BubbleSort(int A[], int n){
	for(int i=0; i<n-1; i++){
		bool flag=false;			//表示本趟冒泡是否发生交换的标志
		for(int j=n-1; j>i; j--)	//一趟冒泡过程
			if(A[j-1]>A[j]){		//若为逆序
				swap(A[j-1], A[j]);	//交换
				flag=true;
			}
		if(flag=false)
			return;		//本趟遍历后没有发生交换，说明表已经有序
	}
}

/*用第一个元素将待排序序列划分成左右两个部分*/
int Partition(int A[], int low, int high){
	int pivot=A[low];
	while pivot=A[low]{
		while(low<high && A[high]>=pivot) --high;
		A[low]=A[high];
		while(low<high && A[low]<=pivot) ++low;
		A[high]=A[low];
	}
	A[low]=pivot;
	return low;
}

//快速排序
void QuickSort(int A[], int low, int high){
	if(low<high){	//递归跳出的条件
		int pivotPos=Partition(A, low, high);	//划分
		QuickSort(A, low, pivotpos-1);	//划分左子表
		QuickSort(A, pivotpos+1, high);	//划分右子表
	}
	
}

/*算法实现*/
void SelectSort(int A[], int n){
	for(int i=0; i<n-1; i++){	//一共进行n-1趟;
		int min=1;	//记录最小元素位置
		for(int j=i+1; j<n; j++)	//在A[i...n-1]中选择最小的元素
			if(A[j]<A[min]) min=j;	//更新最小元素位置
		if(min!=i) swap(A[i], A[min]);	//封装的swap()函数共移动元素3次
	}
}
//交换
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

/*建立大根堆*/
void BuildMaxHeap(int A[], int len){
	for(int i=len/2; i>0; i--)	//从后往前调整所有非终端结点
		HeadAdjust(A, i, len);
}

//将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len){
	A[0]=A[k];	//A[0]暂存子树的根结点
	for(int i=2*k; i<=len; i*=2){  //沿key较大的子结点向下筛选
		if(i<len &&A[i]<A[i+1])
			i++;	//取key较大的子结点的下标
		if(A(0)>=A[i])	break;	//筛选结束
		else{
			A[k]=A[i];	//将A[i]调整到双亲结点上
			k=i;		//修改k值，以便继续向下筛选
		}
	}
	A[k]=A[0];	//被筛选结点的值放入最终位置
}


//堆排序的完整逻辑
void HeapSort(int A[], int len){
	BuildMaxHeap(A, len);	//初始建堆
	for(int i=len; i>1; i--){	//n-1趟的交换和建堆过程
		swap(A[i], A[1]);	//堆顶元素和堆底元素交换
		HeadAdjust(A, 1, i-1);	//把剩余的待排序元素整理成堆
	}
}


int *B=(int *)malloc(n*sizeof(int));	//辅助数组B

//A[Low...mid]和A[mid+1...high]各自有序，将两个部分归并
void Merge(int A[], int low, int mid, int high){
	int i, j, k;
	for(k=low;k<=high;k++)
		B[K]=A[K];	//将A所有元素复制到B中
	for(i=low, j=mid+1, k=i; i<=mid && j<=high; k++){
		if(B[i]<=B[j])
			A[k]=B[i++];	//将较小值复制到A中
		else
			A[k]=B[j++];
	}
	while(i<=mid)	A[k++]=B[i++];
	while(j<=high)  A[k++]=B[j++];
}

void MergeSort(int A[], int low, int high){
	if(low<high){
		int mid=(low+high)/2;	//从中间划分
		MergeSort(A, low, mid);	//对左半部分归并排序
		MergeSort(A, mid+1, high); //对右半部分归并排序
		MergeSort(A, low, mid, high); //归并
	}
}


























































