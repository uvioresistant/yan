/*二叉树的顺序存储*/
# define MaxSize 100
struct TreeNode{
    ElemType value; //结点中的数据元素
    bool isEmpty;   //结点是否为空
};

TreeNode t[MaxSize];

for (int i=0; i<MaxSize; i++){
    t[i].isEmpty=true;
}

/*二叉树的链式存储*/
//二叉树的结点(链式存储)
typedef struct BiTNode{
    ElemType data;                      // 数据域
    struct BiTNode *lchild, *rchild;    //左、右孩子指针
}BiTNode *BiTree;


struct ElemType{
    int value;
};

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//定义一棵空树
BiTree root = NULL;

//插入根结点
root = (BiTree) malloc(sizeof(BiTNode));
root->data = {1};
root->lchild = NULL;
root->rchild = NULL;

//插入新节点
BiTNode *p = (BiTNode *) malloc(sizeof(BiTNode));
p->data = {2};
p->lchild = NULL;
p->rchild = NULL;
root->lchild = p; //作为根结点的左孩子

//三叉链表 - 方便查找父结点
typedef struct BiTNode{
    ElemType data;                      //数据域
    struct BiTNode *lchild, *rchild;    //左、右孩子指针
    struct BiTNode *parent;             //父节点指针
}BiTNode, *BiTree;

//先序遍历
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);                   
        PreOrder(T->lchild);        
        PreOrder(T->rchild);        
        }
}

// 先序遍历非递归算法(王道)
void PreOrder2(BiTree T){
InitStack(S);   BiTree p=T;     //初始化栈S；p是遍历指针
    while(p||!IsEmpty(S)){      //栈不空或p不空时循环
        if(p){                  //一路向左
            visit(p); Push(S,p);    //访问当前结点，并入栈
            p=p->lchild;            //左孩子不空，一直向左走
        }
        else{
            Pop(S, p);          //出栈，并转向出栈结点的右子树
            p=p->rchild;        //向右子树走，p赋值为当前结点的右孩子
        }                       //返回while循环，继续进入if-else语句
        
    }
}

//中序遍历
typedef struct InOrder(BiTree T){
    if (T!=NULL){
        InOrder(T->lchild);     //递归遍历左子树
        visit(T);               //访问根结点
        InOrder(T->rchild);     //递归遍历右子树
    }
}

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 中序遍历非递归算法(王道)
void InOrder2(BiTree T){
InitStack(S); BiTree p=T;       //初始化栈S；p是遍历指针
    while(p||!IsEmpty(S)){      //栈不空或p不空时循环
        if(p){                  //一路向左
            Push(S, p);         //当前节点入栈
            p=p->lchild;        //左孩子不空，一直向左走
        }
        else{                       //出栈，并转向出栈结点的左子树
            Pop(S, p); visit(p);    //栈顶元素出栈，访问出栈结点
            p=p->rchild;            //向右子树走，p赋值为当前结点的右孩子
        }                           //返回while循环，继续进入if-else语句
    }
}

/* 后序遍历 */
typedef struct BiTNode{
    ElemType data;
    stuct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


typedef struct PostOrder(BiTree T){
    if(T != NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

// 后序遍历非递归算法(王道)
/* 注：每次出栈访问完一个结点，就相当于遍历完以该结点为根的子树，需将p置NULL */
void PostOrder(BiTree T){
	InitStack(S);
	p=T;
	r=NULL;					//辅助指针r
	while(p||!IsEmpty(S)){
		if(p){				//走到最左边
			push(S, p);
			p=p->lchild;
		}
		else{				//向右
			GetTop(S, p);	//读栈顶结点(非出栈)
			if(p->rchild&&p->rchild!=r){	//若右子树存在，且未被访问过
				p=p->rchild;				//转向右
				push(S, p);					//压入栈
				p=p->lchild;				//再走到最左
			}
			else{			//否则，弹出结点并访问
				pop(S, p);					//将结点弹出
				visit(p->data);				//访问该结点
				r=p;						//记录最近访问过的结点
				p=NULL;						//结点访问完后，重置p指针
			}
		}//else
	}//while
}


//分析先/中/后序遍历序列
void visit(BiTNode *p){
    printf("%c", p->data)
}


//求树的深度
int treeDepth(BiTree T){
    if (T == NULL){
        return 0;
    }
    else{
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        //树的深度=Max(左子树深度，右子树深度)
        return l>r ? l+1 : r+1;
    }
}


/*层序/层次遍历*/
/* 二叉树的层次遍历算法(王道) */
void LevelOrder(BiTree T){
    InitQueue(Q);               //初始化辅助队列
    BiTree p;
    EnQueue(Q, T);              //将根结点入队
    while(!IsEmpty(Q)){         //队列不空则循环
        DeQueue(Q, p)           //队头结点出队
        visit(p);               //访问出队结点
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);   //左子树不空，则左子树根结点入队
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);   //右子树不空，则右子树根结点入队
    }
}

//二叉树的结点(链式存储)
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, rchild;
}BiTNode, *BiTNode;

//链式队列结点
typedef struct LinkNode{
    BiTNode *data;
    strct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear; //队头队列
}LinkQueue;

void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);   //初始化辅助队列
    BiTree p;
    EnQueue(Q, T);  //将根结点入队
    while(!IsEmpty(Q)){ //队列不空则循环
        DeQueue(Q, p);  //对头结点出头
        visit(p);       //访问出队结点
        if(p->lchild!=NULL)
            EnQueue(Q, p->lchild);//左孩子入队
        if(p->rchild!=NULL)
            EnQueue(Q, p->rchild);//右孩子入队
    }
}


/*线索二叉树的存储结构*/
typedef struct ThreadNode{
    ElemType data;          //数据元素
    struct ThreadNode *lchild, *rchild; //左、右孩子指针
    int ltag, rtag;         //左、右线索标志
}ThreadNode, *ThreadTree;

//二叉树的结点(链式存储)
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;    //术语：二叉链表
}BiTNode, *BiTree;

//线索二叉树结点
typedef struct THreadNode{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; //左、右线索标志, 术语：线索链表
}ThreadNode, *THreadTree;

/*用土办法找到中序前驱*/
//中序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);     //递归遍历左子树
        visit(T);               //访问根结点
        InOrder(T->rchild);     //递归遍历右子树
    }
}

//访问结点q
void visit(BiTNode * q){
    if(q==p)    //当前访问结点刚好是结点p
        final = pre;    //找到p的前驱
    else
        pre = q;        //pre指向当前访问的结点
}

//辅助全局变量，用于查找结点p的前驱
BiTNode *p;     //p指向目标结点
BiTNode *pre=NULL; //指向当前访问结点的前驱
BiTNode *final=NULL; //用于记录最终结果

/*中序线索化*/
//全局变量 pre, 指向当前访问结点的前驱
ThreadNode *pre=NULL;

//中序线索化二叉树T
void CreateInThread(ThreadTree T){
    pre=NULL; //pre初始化为NULL
    if(T!=NULL){        //非空二叉树才能线索化
        InThread(T);    //中序线索化二叉树
        if(pre->rchild==NULL)
            pre->rtag=1;    //处理遍历的最后一个结点
    }
}

//线索二叉树结点
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; //左、右线索标志
}ThreadNode, *ThreadTree;

//中序遍历二叉树，一边遍历、一边线索化
void InThread(ThreadTree T){
    if(T!=NULL{
        InThread(T->lchild);    //中序遍历左子树
        visit(T);               //访问根结点
        InThread(T->rchild);    //中序遍历右子树
        }
}

void visit(ThreadNode *q){
    if(q->lchild==NULL){    //左子树为空，建立前驱线索
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;  //建立前驱结点的后继线索
        pre->rtag=1;
        
    }
    pre=q;
}

//中序线索化的递归算法(王道书)
void InThread(ThreadTree p, ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild, pre);   //递归，线索化左子树
        if(p->lchild==NULL){        //左子树为空，建立前驱线索
        p->lchild=pre;              //lchild指示左结点的前驱
        p->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=p;  //建立前驱结点的后继线索
        pre->rtag=1;
    }
    pre=p;
    InThread(p->rchild, pre);
    }//if(p!=NULL)
}

//中序遍历，建立中序线索化二叉树的主过程(王道)
void CreateInThread(ThreadTree T){
    ThreadTree pre=NULL;
    if(T!=NULL){            //非空二叉树，线索化
        InThread(T, pre);   //线索化二叉树
        pre->rchild=NULL;   //处理遍历的最后一个结点
        pre->rtag=1;
    }
}

/*先序线索化*/
//全局变量pre, 指向当前访问结点的前驱
ThreadNode *pre=NULL;

//先序线索化二叉树T
void CreatePreThread(ThreadTree T){
    pre=NULL;       //pre初始化为NULL
    if(T!=NULL){    //非空二叉树才能线索化
        PreThread(T);   //先序线索化二叉树
        if(pre->rchild==NULL)
            pre->rtag=1;    //处理比遍历的最后一个结点
    }
}

//先序遍历二叉树，一边遍历一边线索化
void PreThread(ThreadTree T){
    if(T!=NULL){
        visit(T);   //先处理根结点
        if(T->ltag==0)  //lchild不是前驱线索
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}

void vist(ThreadNode *q){
    if(q->lchil=NULL){  //左子树为空，建立前驱线索
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;  //建立前驱结点的后继线索
        pre->rtag=1;
    }
    pre=q;
}

//先序线索化(王道书)
void PreThread(ThreadTree p, ThreadTree &pre){
    if(p!=NULL){
        if(p->lchild==NULL){        //左子树为空，建立前驱线索
            p->lchild=pre;
            p->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=p;  //建立前驱结点的后继线索
        pre->rtag=1;
    }
    pre=p;
    if(p->ltag==0)
        InThread(p->rchild, pre);   //建立前驱结点的后继线索
    InThread(p->rchild, pre);
}//if(p!=NULL)
}

//先序线索化二叉树T
void CreateInThread(ThreadTree T){
    ThreadTree pre=NULL;
    if(T!=NULL){            //非空二叉树，线索化
        PreThread(T, pre);   //线索化二叉树
        if(pre->rchild==NULL)   //处理遍历的最后一个结点
        pre->rtag=1;
    }
}


/*后序线索化*/
//全局变量pre, 指向当前访问结点的前驱
ThreadNode *pre=NULL;

//后序线索化二叉树T
void CreatePostThread(ThreadTree T){
    pre=NULL;       //pre初始化为NULL
    if(T!=NULL){    //非空二叉树才能线索化
        InThread(T);   //中序线索化二叉树
        if(pre->rchild==NULL)
            pre->rtag=1;    //处理遍历的最后一个结点
    }
}

//后序遍历二叉树，一边遍历一边线索化
void PostThread(ThreadTree T){
    if(T!=NULL){
        PostThread(T->lchild);  //后续遍历左子树
        PostThread(T->rchild);  //后续遍历右子树
        visit(T);   //访问根结点
    }
}

void vist(ThreadNode *q){
    if(q->lchild==NULL){  //左子树为空，建立前驱线索
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;  //建立前驱结点的后继线索
        pre->rtag=1;
    }
    pre=q;
}

//后序线索化(王道书)
void PostThread(ThreadTree p, ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild,pre);    //递归，线索化左子树
        InThread(p->rchild,pre);
        if(p->lchild==NULL){        //左子树为空，建立前驱线索
            p->lchild=pre;
            p->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=p;  //建立前驱结点的后继线索
        pre->rtag=1;
    }
    if(p->ltag==0){
        InThread(p->rchild, pre);   //建立前驱结点的后继线索
        InThread(p->rchild, pre);
    }
    pre=p;
}//if(p!=NULL)

//后序线索化二叉树T
void CreateInThread(ThreadTree T){
    ThreadTree pre=NULL;
    if(T!=NULL){            //非空二叉树，线索化
        PostThread(T, pre);   //线索化二叉树
        if(pre->rchild==NULL)   //处理遍历的最后一个结点
        pre->rtag=1;
    }
}


/*中序线索化二叉树找中序后继*/
//找到以p为根的子树中，第一个被中序遍历的节点
ThreadNode *Firstnode(ThreadNode *p){
	//循环找到最左下节点(不一定是叶结点)
	while(p->ltag==0) p=p->lchild;
	return p;
}

//在中序线索二叉树中找到结点p的后继结点
ThreadNode *Nextnode(ThreadNode *p){
	//右子树中最左下结点
	if(p->rtag==0) return Firstnode(p->rchild);
	else return p->rchild; //rtag==1直接返回后继线索
}

//对中序线索二叉树进行中序遍历(利用线索实现的非递归算法)
void Inorder(ThreadNode *T){
	for(ThreadNode *p=Firstnode(T); p!=NULL; p=Nextnode(p))
		visit(p);
}


/*中序线索二叉树找中序前驱*/
//找到以P为根的子树中，最后一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p){
    //循环找到最右下结点(不一定是叶结点)
    while(p->rtag==0) p=p->rchild;
    return p; 
} 

//在中序线索二叉树中找到结点p的前驱结点
ThreadNode *Prenode(TheradNode *p){
    //左子树最右下结点
    if(p->ltag==0) return Lastnode(p->lchild);
    else return p->lchild; // ltag==1直接返回前驱线索 
}

//对中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode *T){
    for(ThreadNode *p=Lastnode(T);p!=NULL; p=Prenode(p))
        visit(p);
} 


/*双亲表示法(顺序结构)*/
#define MAX_TREE_SIZE 100   //树中最多结点数
typedef struct{             //树的结点定义 
    ElemType data;          //数据元素
    int parent;             //双亲位置域
}PTNode;

typedef struct{                     //树的类型定义 
    PTNode nodes[MAX_TREE_SIZE];    //双亲表示
    int n;                          //结点数 
}PTree;

//删除结点
typedef struct{                     //树的类型定义 
    PTNode nodes[MAX_TREE_SIZE];    //双亲表示 
    int n;                          //结点数 
}PTree; 


//孩子表示法(顺序+链式存储)
struct CTNode{
    int child; //孩子结点在数组中的位置
    struct CTNode *next;    //下一个孩子 
}; 
typedef struct {
    ElemType data;
    struct CTNode *firstChild;  //第一个孩子 
}CTBox;
typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r;   //结点数和根的位置 
}CTree;


//孩子兄弟表示法(链式存储)
typedef struct CSNode{
    ElemType data;                              //数据域 
    struct CSNode *firstchild, *nextsibling;    //第一个孩子(看做左指针)和右兄弟指针(看做右指针) 
}CSNode, *CSTree; 


/*树和森林的遍历*/
//树的先根遍历
void PreOrder(TreeNode *R){
    if (R!=NULL){
        visit(R);   //访问根节点
        while(R)    //R还有下一个子树T 
            PreOrder(T);    //先根遍历下一棵子树 
    }
} 


//树的后根遍历
void PostOrder(TreeNode *R){
    if (R!=NULL){
        while(R)    //R还有下一个子树T 
            PreOrder(T);    //先根遍历下一棵子树 
        visit(R);   //访问根节点
    }
} 



/*二叉树*/
//查找
//二叉排序树结点
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

//二叉排序树的非递归查找算法(王道)
BSTNode *BST_Search(BiTree T, ElemType key){
	while(T!=NULL&&key!=T->data){	//若树空或等于根结点值，则结束循环
		if(key<T->data)	T=T->lchild;	//小于，则在左子树上查找
		else T=T->rchild;			// 大于，则在右子树上查找
	}
	return T;
}

//在二叉排序树中查找值为key的结点
BSTNode *BST_Search(BSTree T, int key){
    while(T!=NULL&&key!=T->key){        //若树空或等于根结点值，则结束循环 
        if(key<T->key) T=T->lchild;     //小于，则在左子树上查找
        else T=T->rchild;               //大于，则在右子树上查找 
    }
    return T;
} 

//在二叉排序树中查找值为key的结点(递归实现)
BSTNode *BSTSearch(BSTree T, int key){
    if (T==NULL)
        return NULL;    //查找失败
    if (key==T->key)
        return T;       //查找成功
    else if (key < T->key)
        return BSTSearch(T->lchild, key);   //在左子树中找
    else
        return BSTSearch(T->rchild, key);   //在右子树中找
} 

//插入
//二叉排序树插入操作的算法(王道)
int BST_Insert(BiTree &T, KeyType k){
	if(T==NULL){			//原树为空，新插入的记录为根结点
		T=(BiTree)malloc(sizeof(BSTNode));
		T->key=k;
		T->lchild=T->rchild=NULL;
		return 1;			//返回1，插入成功
	}
	else if(k==T->key)		//树中存在相同关键字的结点，插入失败
		return 0;
	else if(k<T->key)		//插入到T的左子树
		return BST_Insert(T->lchild,k);
	else					//插入到T的右子树
		return BST_Insert(T->rchild,k);
}


//在二叉排序树插入关键字为k的新结点(递归实现)~最坏空间复杂度O(h)
int BST_Insert(BSTree &T, int k){
    if(T==NULL){        //原树为空，新插入的结点为根结点
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;      //返回1，插入成功 
    }
    else if(k==T->key)  //树中存在相同关键字的结点，插入失败 
        return 0;
    else if(k<T->key)   //插入到T的左子树 
        return BST_Insert(T->lchild, k);
    else                //插入到T的右子树 
        return BST_Insert(T->rchild, k); 
} 

//构造
//构造二叉排序树的算法描述(王道)
void Create_BST(BiTree &T, KeyType str[], int n){
	T=NULL;			//初始时T为空树
	int i=0;
	while(i<n){		//依次将每个关键字插入到二叉排序树种
		BST_Insert(T, str[i]);
		i++;
	}
	
}

//按照str[]中的关键字序列建立二叉排序树
void Create_BST(BSTree &T, int str[], int n){
    T=NULL;         //初始时T为空树
    int i=0;
    while(i<n){     //依次将每个关键字插入到二叉排序树种
        BST_Insert(T, str[i]);
        i++; 
    } 
} 

//平衡二叉树结点
typedef struct AVLNode{
    int key;        //数据域
    int balance;    //平衡因子
    struct AVLNode *lchild, *rchild; 
}AVLNode, *AVLTree; 

/*AVL插入调整平衡*/
 





































 






















