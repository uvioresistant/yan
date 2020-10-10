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





























