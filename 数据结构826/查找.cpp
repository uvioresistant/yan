//1.顺序查找
/*顺序表的顺序查找算法*/
int SeqSearch1(int r[], int n, int k)
{
	r[0]=k;
	i=n;
	while(r[i]!=k)
		i--;
	return i;
}

/*单链表的顺序查找算法*/
int SeqSearch2(Node<int> *first, int k)
{
	p=first->next; j=1;
	while(p!=NULL&&p->data!=k)
	{
		p=p->next;
		j++;
	}
	if(p->data==k) return j;
		else return 0;
}

/*一般无序线性表的顺序查找*/
typedef struct{			//查找表的数据结构
	ElemType *elem;		// 元素存储空间基址，建表时按实际长度分配，0号单元留空
	int TableLen;		// 表的长度
}SSTable;

int Search_Seq(SSTable ST, ElemType key){
	ST.elem[0]=key;		// 哨兵
	for(i=ST.TableLen;St.elem[i]!=key;--i);	//从后往前找
	return i;			// 若表中不存在关键字为key的元素，将查找到i为0时退出for循环
	
}


//2. 折半查找(二分查找)
/*仅适用于有序的顺序表*/
int Binary_Search(SeqList L, ElemType key){
	int low=0, high=L.TableLen-1, mid;
	while(low<=high){
		mid=(low+high)/2;	// 取中间位置
		if(L.elem[mid]==key)
			return mid;		// 查找成功则返回所在位置
		else if(L.elem[mid]>key)	// 中间值大于关键字，则为前部分
			high=mid-1;		// 从前半部分继续查找
		else
			low=mid+1;		// 从后半部分继续查找
	}
	return -1;				// 查找失败，返回-1
}


//有序表{7, 14, 18, 21, 23, 29, 31, 35, 38, 42, 46, 49, 52}中
//1)查找关键码为14的记录
//1)查找关键码为22的记录

//折半查找非递归算法
int BinSearch1(int r[], int n, int k)
{
	low=1; high=n;
	while(low<=high)
	{
		mid=(low+high)/2
		if(k<r[mid]) high=mid-1;
			else if (k>r[mid]) low=mid+1;
				else return mid;
	}
}

//折半查找递归算法
int BinSearch2(int r[], int low, int high, int k)
{
	if(low>high) return 0;	//递归的边界条件
	else{
		mid=(low+high)/2;
		if(k<r[mid]) return BinSearch2(r, low, mid-1, k);
			else if(k>r[mid]) return BinSearch2(r, mid+1, high, k);
				else return mid;
	}
}

/*二叉链表存储*/
//给出对应查找集合{63, 55, 90, 42, 58, 70, 10, 45, 67, 83}的两个二叉排序树
class BiSortTree	//假定只有一个整型数据项
{
public:
	BiSortTree(int a[], int n);	//建立查找集合a[n]的二叉排序树
		BiSortTree();			//析构函数，释放二叉排序树中所有结点，同二叉链表的析构函数
	void InsertBST(BiNode<int> *root, BiNode<int> *s);	//在二叉排序树中插入结点s
	void DeleteBST(BiNode<int> *f);						//删除结点f的左孩子结点p	
	BiNode<int> * SearchBST(BiNode<int> *root, int k);	//查找值为k的结点
private:
	BiNode<int> * root;		//二叉排序树(即二叉链表)的根指针
};

//二叉排序树插入算法InsertBST
void BiSortTree::InsertBST(BiNode<int> * root, BiNode<int> *s)
{
	if(root == NULL) root = s;
		else if (s->data<root->data) InsertBST(root->lchild, s);
			else InsertBST(root->rchild, s);
}

//二叉排序树构造函数算法BiSortTree
BiSortTree::BiSortTree(int r[], int n)
{
		for(i=0; i<n; i++)
		{
			s=new BiNode<int>; s->data=r[i];
			s->lchild=s->rchild=NULL;
			InsertBST(root, s);
		}
}

//二叉排序树的删除算法DeleteBST
void BiSortTree::DeleteBST(BiNode<int> *p, BiNode<int> *f)
{
	if(!p->lchild && !p->rchild)	//p为叶子
		f->lchild=NULL;
		delete p;
}
else if(!p->rchild){		//p只有左子树
	f->lchild=p->lchild;
	delete p;
}
else if(!p->lchild){		//p只有右子树
		f->lchild=p->rchild;
		delete p;
}
else{
	par=p; s=p->rchild;
	while(s->lchild!=NULL)	//查找最左下结点
	{
		par=s;
		s=s->lchild;
	}
	p->data=s->data;
	if(par==p) par->rchild=s->rchild;	//处理特殊情况
		else par->lchild=s->rchild;		//一般情况
	delete s;
}	//左右子树均不空的情况处理完毕

//二叉排序树查找算法SearchBST
BiNode * BiSortTree::SearchBST(BiNode<int> * root, int k)
{
	if (root == NULL) return NULL;
		else if(root->data==k) return root;
			else if (k<root->data) return SearchBST(root ->lchild, k);
				else return SearchBST(root->rchild, k);
}

/*闭散列表的查找算法HashSearch1*/
int HashSearch1(int ht[], int m, int k)
{
	j = H(k);
	if(ht[j] == k) return j;	//没有发生冲突，比较一次查找成功
	i=(j+1) % m;
	while(ht[i]!=Empty && i!=j)
	{
		if(ht[i] == k) return i;	//发生冲突，比较若干次查找成功
		i=(i+1) % m;	//向后探测一个位置
	}
	if(i == j) throw '溢出';
		else ht[i] = k;		//查找不成功时插入
	
}

/*开散列表的查找算法HashSearch2*/
Node<int> * HashSearch2(Node<int> * ht[], int n, int k)
{
	j=H(k);
	p=ht[j];
	while(p && p->data!=k)
		p=p->next;
	if(p->data==k) return p;
		else{
			q=new Node<int>; q->data=k;
			q->next=ht[j];
			ht[j]=q;
		}
	
}







































