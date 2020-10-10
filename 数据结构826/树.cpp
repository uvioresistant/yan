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

//后序遍历
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


/*层序遍历*/
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

//中序线索化(王道书)
void InThread(ThreadTree p, ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild, pre);   //递归，线索化左子树
        if(p->lchild==NULL){        //左子树为空，建立前驱线索
        p->lchild=pre;
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

//中序线索化二叉树T
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





























