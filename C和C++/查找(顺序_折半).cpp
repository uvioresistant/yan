/*13.查找*/
/*1.顺序查找*/
//查找k=24：10 12 15 24 6 12 35 40 98 55
int SqSearch(int elem[], int n, int key)
//数组elem[0] - elem[n-1]
{
    int i;
    for (i=0; i<n && elem[i]!=key; i++);
    if(i<n)
        return i;
    else
        return -1;	
}

/*2.折半查找*/
int BinSearch(int elem[], int n, int key)
// 数组elem[0]-elem[n-1]存放查找集合
{
    int low=0;high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (key==elem[mid])
            return mid;
        else if(keyM<=elem[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

