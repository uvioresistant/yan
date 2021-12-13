/* 2020.8.1邻接表的存储结构 */
#define MaxVertexNum 100
typedef struct ArcNode{     //边表结点
    int adjvex;
    struct ArcNode *next;   //指向下一条弧的指针
}ArcNode;

typedef struct VNode{   //图的顶点表
    VertexType data;
    ArcNode *first;     //指向第一条依附该顶点的弧的指针
}VNode, AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices;  //邻接表
    int vexnum, arcnum; //图的顶点数和弧数
}ALGraph;

/* 2020.8.2. 删除图中所有到顶点j(数组下标)的边的算法 */


/* 2020.10.双链表da，在链表da的第i个之后，插入元素值为x的结点，
可直接利用函数depth(da,x)来查找插入位置,写出双链表da的存储结构 */



/* 2020.11.二叉树的所有结点存储在一维数组BT[1~2^h-1]中，计算该二叉树的叶子结点个数 */



/* 2020.12 递归判断二叉排序树 */
/* 思路：二叉排序树的中序遍历序列为一个递增有序序列。因此，对给定二叉树进行中序遍历，若始终能保持前一个值比后一个值小，说明二叉树是一棵二叉排序树 */
KeyType predt=-32767;       //predt为全局变量，保存当前结点中序前驱的值，初值为-∞

int JugeBST(BiTree bt){
    int b1, b2
    if(bt==NULL)            //空树，是二叉排序树，返回1，正确
        return 1;
    else{
        b1=JugeBST(bt->lchild); //判断左子树是否是二叉排序树
        if(b1==0||predt>=bt->data)  //若左子树返回值为0或前驱大于等于当前结点，则不是二叉排序树，返回0，失败
            return 0;
        predt=bt->data;         //保存当前结点的关键字
        b2=JugeBST(bt->rchild); //判断右子树，返回右子树的结果
        return b2;
    }
}

/* 2019.8. 求n个数据中的最大值，写出最大语句频度，该算法的时间复杂度 */


/* 2018.10. 将结点数据降序排列的单向链表中的重复结点删除 */

/* 2018.11.1. 无向图G以邻接表G作为存储结构，写出邻接表存储结构的定义 */
#define MaxVertexNum 100
typedef struct ArcNode{     //边表结点
    int adjvex;
    struct ArcNode *next;
}ArcNode;

typedef struct VNode{   //顶点表
    VertexType data;
    ArcNode *first;
}VNode, AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}AlGraph;

/* 2018.11.2.输出图中的所有简单环路(除第一个和最后一个结点相同，其余结点均不同的一条路径 */
/* 思路：基于递归的深度优先遍历算法，从结点u出发，递归深度优先遍历图中结点，若访问到结点v，则输出该搜索路径上的结点。
设置一个path数组来存放路径上的结点(初始为空)；
d表示路径长度(初始为-1)
查找从顶点u到v的简单路径过程 ：
1） FindPath(G, u, v, path, d): d++; path[d]=u; 若找到u的未访问过的相邻结点u1，则继续下去，否则置visited[u]=0并返回
2） FindPath(G, u1,v, path, d): d++; path[d]=u1; 若找到u1的未访问过的相邻结点u2，则继续下去，否则置visited[u1]=0 
3） 以此类推，继续上述递归过程，直到ui=v,输出path*/
void FindPath(AlGraph *G, int u, int v, int path[], int d){
    int w, i;
    ArcNode *p;
    d++;
    path[d]=u;
    visited[u]=1;
    if(u==v)
        print(path[])
    p=G->AdjList[u].firstarc;
    while(p!=NULL){
        w=p->adjvex;
        if(visited[w]==0)
            FindPath(G, w, v, path, d);
        p=p->nextarc;           //p指向u的下一个邻接点
    }
    visited[u]=0
}

/* 2017.14.1. 一棵以孩子兄弟表示法表示的树，求出该树中度为2的结点个数 */

/* 2017.14.1. 一棵以孩子兄弟表示法表示的树，求出该树的度 */


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


/* 2016.18. 一棵二叉链表表示的二叉排序树T，输入整数k(k存在于T），
编写程序输出值为k的结点所在的层次(根结点处于第1层)，并求出其平衡因子(值为k的结点的左右子树高度差)*/







/* 2016.19.1. 对于邻接表表示的有向图G，写出邻接表的存储结构定义 */
#define MaxVertexNum 100;
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
    //InfoType info;        //网的边权值
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode, AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;


/* 2016.19.1. 对于邻接表表示的有向图G，对于G中任意两个顶点Vi和Vj，
如果同时存在<Vi, Vj>和 <Vj, Vi>两条有向边，则将这两条边删除*/




/* 2015.17. L为带头结点头指针的单链表，且链表长度大于2，设计算法删除链表L的尾结点，
并将该结点插入到链表L的首结点之前(即头结点之后) */




/* 2015.18. 无向图g各个顶点(不超过100)，只存储单个字符信息，
采用邻接矩阵表示，编写函数 void fun2(MGraph &g, char vi, char vj), 
将顶点vi与vj之间的无向边(vi, vj),插入到图g中(假设原先vi与顶点vj之间无边相连)
无向图g的邻接矩阵类型定义:
typedef struct{
    char vexs[100];     //顶点向量
    int arcs[100][100]; //邻接矩阵，0表示无边，1表示有边
    int vexnum, arcnum; //顶点数，边数
}MGraph;
*/



/* 2014.15. 判断一棵二叉链表表示的二叉树T，是否是二叉排序树，并输出其中数据域最大的结点 */



/* 2014.16. 一个邻接表表示的有向图，编写程序判断从顶点i至顶点j是否有简单路径，
有则打印出该路径上的顶点路径，先描述图的存储结构，查找邻接点灯关于图的操作要自己处理*/


/* 2013.17. 单向链表的类型定义如下： 
typedef int ElemType;
typedef int LNode{
    ElemType data;
    Node *next;
}*LinkList;
编写函数LinkList CopyListFrom(LinkList list),返回已知的带头结点单链表list的1个拷贝(备份)链表
*/


/* 2013.18. 设BST以二叉链表为存储结构，删除BST中值最大的结点 */


/* 2012.18. 编写非递归与递归算法，输出不带头结点的单向链表L的各个元素值 */


/* 2012.19. 设BST以二叉链表为存储结构，删除BST中值最大的结点 */


/* 2011.16. L为带头结点头指针的单链表，且表中结点值均为正整数，
设计算法将表中值最小结点，插入到值最大结点之前 */



/* 2011.17. 二叉链表表示的二叉树，每个结点都有2个指针(lchild,rchild)，该二叉树的根结点指针为t，
编写一个基于中序遍历的非递归算法函数，求二叉树的叶子结点数目 */



/* 2010.06. A是带头结点的单链表头指针，链表长度大于2，且表中结点值均为正整数，
编写算法，从A的表头向表尾方向行进，同时实现下列两个功能：
1) 若结点的数据域值是偶数，则将其与直接后继结点的数值交换
2) 若该数值是奇数，则将其直接后继结点删除。*/


/* 2010.07. 有向图G用邻接表表示，编写算法输出图G中入度最大的顶点的数据 */


/* 2010.08. 设BST以二叉链表为存储结构，计算BST中有多少叶子结点的数据域值等于x */


/* 2008.06. 设A，B分别是带表头结点的单链表头指针，表A，B中的结点元素值按值递增有序排列(同一表中元素值各不相同)，
编写算法生成C表(C是头指针)，使得C表中结点元素既在A中出现，也在B中出现。
要求C表中元素值也按值递增有序(注意，算法不破坏A表和B表的结构) */


/* 2008.07.已知有向图G的数组表示，试编写算法，创建有向图G的邻接表表示 */


/* 2008.08.BST以二叉链表为存储结构，编写算法，在BST中查找值为x的结点，
若查找成功，则返回该结点位置，并置成功标志；
若查找不成功，则在树中插入一个值为x的新结点，返回新结点的位置，并置不成功标志。 */























