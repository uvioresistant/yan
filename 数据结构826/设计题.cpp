/* 2017.15 双向起泡 */
void BubbleSort(ElemType A[], int n){
	int low=0, high=n-1;
	bool flag=true;
	while(low<high&&flag){
		flag=false;
		for(i=low;i<high;i++)
			if(A[i]>A[i+1]){
				swap(A[i], A[i+1]);
				flag=true;
			}
		high--;
		for(j=high;j>low;j--)
			if(A[j]<A[j-1]){
				swap(A[j], A[j-1]);
				flag=true;
			}
		low++;
	}
}


/* 对比冒泡排序 */
void BubbleSort(ElemType A[], int n){
	for(i=0;i<=n-1;i++){
		flag=false;
		for(j=n-1;j>i;j--)
			if(A[j-1]>A[j]){
				swap(A[j-1], A[j]);
				flag=true;
		}
		if(flag==false)
			return;
	}
}