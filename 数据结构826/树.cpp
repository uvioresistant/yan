/*��������˳��洢*/
# define MaxSize 100
struct TreeNode{
    ElemType value; //����е�����Ԫ��
    bool isEmpty;   //����Ƿ�Ϊ��
};

TreeNode t[MaxSize];

for (int i=0; i<MaxSize; i++){
    t[i].isEmpty=true;
}

/*����������ʽ�洢*/
//�������Ľ��(��ʽ�洢)
typedef struct BiTNode{
    ElemType data;                      // ������
    struct BiTNode *lchild, *rchild;    //���Һ���ָ��
}BiTNode *BiTree;


struct ElemType{
    int value;
};

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//����һ�ÿ���
BiTree root = NULL;

//��������
root = (BiTree) malloc(sizeof(BiTNode));
root->data = {1};
root->lchild = NULL;
root->rchild = NULL;

//�����½ڵ�
BiTNode *p = (BiTNode *) malloc(sizeof(BiTNode));
p->data = {2};
p->lchild = NULL;
p->rchild = NULL;
root->lchild = p; //��Ϊ����������

//�������� - ������Ҹ����
typedef struct BiTNode{
    ElemType data;                      //������
    struct BiTNode *lchild, *rchild;    //���Һ���ָ��
    struct BiTNode *parent;             //���ڵ�ָ��
}BiTNode, *BiTree;

//�������
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

//�������
typedef struct InOrder(BiTree T){
    if (T!=NULL){
        InOrder(T->lchild);     //�ݹ����������
        visit(T);               //���ʸ����
        InOrder(T->rchild);     //�ݹ����������
    }
}

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//�������
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

//������/��/�����������
void visit(BiTNode *p){
    printf("%c", p->data)
}


//���������
int treeDepth(BiTree T){
    if (T == NULL){
        return 0;
    }
    else{
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        //�������=Max(��������ȣ����������)
        return l>r ? l+1 : r+1;
    }
}


/*�������*/
//�������Ľ��(��ʽ�洢)
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, rchild;
}BiTNode, *BiTNode;

//��ʽ���н��
typedef struct LinkNode{
    BiTNode *data;
    strct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear; //��ͷ����
}LinkQueue;

void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);   //��ʼ����������
    BiTree p;
    EnQueue(Q, T);  //����������
    while(!IsEmpty(Q)){ //���в�����ѭ��
        DeQueue(Q, p);  //��ͷ����ͷ
        visit(p);       //���ʳ��ӽ��
        if(p->lchild!=NULL)
            EnQueue(Q, p->lchild);//�������
        if(p->rchild!=NULL)
            EnQueue(Q, p->rchild);//�Һ������
    }
}


/*�����������Ĵ洢�ṹ*/
//�������Ľ��(��ʽ�洢)
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;    //�����������
}BiTNode, *BiTree;

//�������������
typedef struct THreadNode{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; //����������־, �����������
}ThreadNode, *THreadTree;

/*�����취�ҵ�����ǰ��*/
//�������
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);     //�ݹ����������
        visit(T);               //���ʸ����
        InOrder(T->rchild);     //�ݹ����������
    }
}

//���ʽ��q
void visit(BiTNode * q){
    if(q==p)    //��ǰ���ʽ��պ��ǽ��p
        final = pre;    //�ҵ�p��ǰ��
    else
        pre = q;        //preָ��ǰ���ʵĽ��
}

//����ȫ�ֱ��������ڲ��ҽ��p��ǰ��
BiTNode *p;     //pָ��Ŀ����
BiTNode *pre=NULL; //ָ��ǰ���ʽ���ǰ��
BiTNode *final=NULL; //���ڼ�¼���ս��

/*����������*/
//ȫ�ֱ��� pre, ָ��ǰ���ʽ���ǰ��
ThreadNode *pre=NULL;

//����������������T
void CreateInThread(ThreadTree T){
    pre=NULL; //pre��ʼ��ΪNULL
    if(T!=NULL){        //�ǿն���������������
        InThread(T);    //����������������
        if(pre->rchild==NULL)
            pre->rtag=1;    //������������һ�����
    }
}

//�������������
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; //����������־
}ThreadNode, *ThreadTree;

//���������������һ�߱�����һ��������
void InThread(ThreadTree T){
    if(T!=NULL{
        InThread(T->lchild);    //�������������
        visit(T);               //���ʸ����
        InThread(T->rchild);    //�������������
        }
}

void visit(ThreadNode *q){
    if(q->lchild==NULL){    //������Ϊ�գ�����ǰ������
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;  //����ǰ�����ĺ������
        pre->rtag=1;
        
    }
    pre=q;
}

//����������(������)
void InThread(ThreadTree p, ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild, pre);   //�ݹ飬������������
        if(p->lchild==NULL){        //������Ϊ�գ�����ǰ������
        p->lchild=pre;
        p->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=p;  //����ǰ�����ĺ������
        pre->rtag=1;
    }
    pre=p;
    InThread(p->rchild, pre);
}//if(p!=NULL)
}

//����������������T
void CreateInThread(ThreadTree T){
    ThreadTree pre=NULL;
    if(T!=NULL){            //�ǿն�������������
        InThread(T, pre);   //������������
        pre->rchild=NULL;   //������������һ�����
        pre->rtag=1;
    }
}


/*����������*/
//ȫ�ֱ���pre, ָ��ǰ���ʽ���ǰ��
ThreadNode *pre=NULL;

//����������������T
void CreatePreThread(ThreadTree T){
    pre=NULL;       //pre��ʼ��ΪNULL
    if(T!=NULL){    //�ǿն���������������
        PreThread(T);   //����������������
        if(pre->rchild==NULL)
            pre->rtag=1;    //����ȱ��������һ�����
    }
}

//���������������һ�߱���һ��������
void PreThread(ThreadTree T){
    if(T!=NULL){
        visit(T);   //�ȴ�������
        if(T->ltag==0)  //lchild����ǰ������
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}

void vist(ThreadNode *q){
    if(q->lchil=NULL){  //������Ϊ�գ�����ǰ������
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;  //����ǰ�����ĺ������
        pre->rtag=1;
    }
    pre=q;
}

//����������(������)
void PreThread(ThreadTree p, ThreadTree &pre){
    if(p!=NULL){
        if(p->lchild==NULL){        //������Ϊ�գ�����ǰ������
            p->lchild=pre;
            p->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=p;  //����ǰ�����ĺ������
        pre->rtag=1;
    }
    pre=p;
    if(p->ltag==0)
        InThread(p->rchild, pre);   //����ǰ�����ĺ������
    InThread(p->rchild, pre);
}//if(p!=NULL)
}

//����������������T
void CreateInThread(ThreadTree T){
    ThreadTree pre=NULL;
    if(T!=NULL){            //�ǿն�������������
        PreThread(T, pre);   //������������
        if(pre->rchild==NULL)   //������������һ�����
        pre->rtag=1;
    }
}


/*����������*/
//ȫ�ֱ���pre, ָ��ǰ���ʽ���ǰ��
ThreadNode *pre=NULL;

//����������������T
void CreatePostThread(ThreadTree T){
    pre=NULL;       //pre��ʼ��ΪNULL
    if(T!=NULL){    //�ǿն���������������
        InThread(T);   //����������������
        if(pre->rchild==NULL)
            pre->rtag=1;    //������������һ�����
    }
}

//���������������һ�߱���һ��������
void PostThread(ThreadTree T){
    if(T!=NULL){
        PostThread(T->lchild);  //��������������
        PostThread(T->rchild);  //��������������
        visit(T);   //���ʸ����
    }
}

void vist(ThreadNode *q){
    if(q->lchild==NULL){  //������Ϊ�գ�����ǰ������
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;  //����ǰ�����ĺ������
        pre->rtag=1;
    }
    pre=q;
}

//����������(������)
void PostThread(ThreadTree p, ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild,pre);    //�ݹ飬������������
        InThread(p->rchild,pre);
        if(p->lchild==NULL){        //������Ϊ�գ�����ǰ������
            p->lchild=pre;
            p->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=p;  //����ǰ�����ĺ������
        pre->rtag=1;
    }
    if(p->ltag==0){
        InThread(p->rchild, pre);   //����ǰ�����ĺ������
        InThread(p->rchild, pre);
    }
    pre=p;
}//if(p!=NULL)

//����������������T
void CreateInThread(ThreadTree T){
    ThreadTree pre=NULL;
    if(T!=NULL){            //�ǿն�������������
        PostThread(T, pre);   //������������
        if(pre->rchild==NULL)   //������������һ�����
        pre->rtag=1;
    }
}


/*������������������������*/
//�ҵ���pΪ���������У���һ������������Ľڵ�
ThreadNode *Firstnode(ThreadNode *p){
	//ѭ���ҵ������½ڵ�(��һ����Ҷ���)
	while(p->ltag==0) p=p->lchild;
	return p;
}

//�������������������ҵ����p�ĺ�̽��
ThreadNode *Nextnode(ThreadNode *p){
	//�������������½��
	if(p->rtag==0) return Firstnode(p->rchild);
	else return p->rchild; //rtag==1ֱ�ӷ��غ������
}

//���������������������������(��������ʵ�ֵķǵݹ��㷨)
void Inorder(ThreadNode *T){
	for(ThreadNode *p=Firstnode(T); p!=NULL; p=Nextnode(p))
		visit(p);
}


/*��������������������ǰ��*/
//�ҵ���PΪ���������У����һ������������Ľ��
ThreadNode *Lastnode(ThreadNode *p){
    //ѭ���ҵ������½��(��һ����Ҷ���)
    while(p->rtag==0) p=p->rchild;
    return p; 
} 

//�������������������ҵ����p��ǰ�����
ThreadNode *Prenode(TheradNode *p){
    //�����������½��
    if(p->ltag==0) return Lastnode(p->lchild);
    else return p->lchild; // ltag==1ֱ�ӷ���ǰ������ 
}

//�������������������������������
void RevInorder(ThreadNode *T){
    for(ThreadNode *p=Lastnode(T);p!=NULL; p=Prenode(p))
        visit(p);
} 


/*˫�ױ�ʾ��(˳��ṹ)*/
#define MAX_TREE_SIZE 100   //�����������
typedef struct{             //���Ľ�㶨�� 
    ElemType data;          //����Ԫ��
    int parent; 
}PTNode;

typedef struct{                     //�������Ͷ��� 
    PTNode nodes[MAX_TREE_SIZE];    //˫�ױ�ʾ
    int n;                          //����� 
}PTree;

//ɾ�����
typedef struct{                     //�������Ͷ��� 
    PTNode nodes[MAX_TREE_SIZE];    //˫�ױ�ʾ 
    int n;                          //����� 
}PTree; 


//���ӱ�ʾ��(˳��+��ʽ�洢)
struct CTNode{
    int child; //���ӽ���������е�λ��
    struct CTNode *next;    //��һ������ 
}; 
typedef struct {
    ElemType data;
    struct CTNode *firstChild;  //��һ������ 
}CTBox;
typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r;   //������͸���λ�� 
}CTree;


//�����ֵܱ�ʾ��(��ʽ�洢)
typedef struct CSNode{
    ElemType data;                              //������ 
    struct CSNode *firstchild, *nextsibling;    //��һ������(������ָ��)�����ֵ�ָ��(������ָ��) 
}CSNode, *CSTree; 


/*����ɭ�ֵı���*/
//�����ȸ�����
void PreOrder(TreeNode *R){
    if (R!=NULL){
        visit(R);   //���ʸ��ڵ�
        while(R)    //R������һ������T 
            PreOrder(T);    //�ȸ�������һ������ 
    }
} 


//���ĺ������
void PostOrder(TreeNode *R){
    if (R!=NULL){
        while(R)    //R������һ������T 
            PreOrder(T);    //�ȸ�������һ������ 
        visit(R);   //���ʸ��ڵ�
    }
} 



/*������*/
//����
//�������������
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

//�ڶ����������в���ֵΪkey�Ľ��
BSTNode *BST_Search(BSTree T, int key){
    while(T!=NULL&&key!=T->key){        //�����ջ���ڸ����ֵ�������ѭ�� 
        if(key<T->key) T=T->lchild;     //С�ڣ������������ϲ���
        else T=T->rchild;               //���ڣ������������ϲ��� 
    }
    return T;
} 

//�ڶ����������в���ֵΪkey�Ľ��(�ݹ�ʵ��)
BSTNode *BSTSearch(BSTree T, int key){
    if (T==NULL)
        return NULL;    //����ʧ��
    if (key==T->key)
        return T;       //���ҳɹ�
    else if (key < T->key)
        return BSTSearch(T->lchild, key);   //������������
    else
        return BSTSearch(T->rchild, key);   //������������
} 

//����
//�ڶ�������������ؼ���Ϊk���½��(�ݹ�ʵ��)~��ռ临�Ӷ�O(h)
int BST_Insert(BSTree &T, int k){
    if(T==NULL){        //ԭ��Ϊ�գ��²���Ľ��Ϊ�����
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;      //����1������ɹ� 
    }
    else if(k==T->key)  //���д�����ͬ�ؼ��ֵĽ�㣬����ʧ�� 
        return 0;
    else if(k<T->key)   //���뵽T�������� 
        return BST_Insert(T->lchild, k);
    else                //���뵽T�������� 
        return BST_Insert(T->rchild, k); 
} 

//����
//����str[]�еĹؼ������н�������������
void Create_BST(BSTree &T, int str[], int n){
    T=NULL;         //��ʼʱTΪ����
    int i=0;
    while(i<n){     //���ν�ÿ���ؼ��ֲ��뵽������������
        BST_Insert(T, str[i]);
        i++; 
    } 
} 

//ƽ����������
typedef struct AVLNode{
    int key;        //������
    int balance;    //ƽ������
    struct AVLNode *lchild, *rchild; 
}AVLNode, *AVLTree; 

/*AVL�������ƽ��*/
 





































 






















