#define MaxSize 10  // ����ջ��Ԫ�ص������� 
typedef struct{  
    ElemType data[MaxSize]; // ��̬������ջ��Ԫ�� 
    int top;    // ջ��ָ�� 
}SqStack;   //Sq:sequence---˳�� 

void testStack(){
    SqStack S;  //����һ��˳��ջ(����ռ�)
    //...��������... 
} 

/*��ʼ������*/
#define MaxSize 10  //����ջ��Ԫ�ص������� 
typedef struct{
    ElemType data[MaxSize]; //��̬������ջ��Ԫ�� 
    int top;    //ջ��ָ�� 
}SqStack; 

//��ʼ��ջ
void InitStack(SqStack &S){
    S.top=-1    //��ʼ��ջ��ָ�� 
} 

void testStack(){
    SqStack S;  //����һ��˳��ջ(����ռ�)
    InitStack(S); 
}

//�ж�ջ��
bool StackEmpty(SqStack S){
    if(S.top==-1)   //ջ��
        return true;
    else            //���� 
        return false; 
} 


//��ջ����
#define MaxSize 10      //����ջ��Ԫ�ص������� 
typedef struct{
    ElemType data[MaxSize]; //��̬������ջ��Ԫ�� 
    int top;    //ջ��ָ�� 
}SqStack; 

//��Ԫ����ջ
bool Push(SqStack &S, ElemType x){
    if(S.top==MaxSize-1)    //ջ��������
        return false;
    S.top = S.top + 1;  //ָ���ȼ�1
    S.data[S.top]=x;    //��Ԫ����ջ �ȼ��� S.data[++S.top]=x; 
    return true; 
} 

//��ջ����
#define MaxSize 10
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

bool Pop(SqStack &S, ElemType &x){
    if(S.top==-1)   //ջ�գ�����
        return false;
    x=S.data[S.top];    //ջ��Ԫ���ȳ�ջ
    S.top=S.top-1;      //ָ���ټ�1 �ȼ���x=S.data[S.top--]; 
} 


//��ջ��Ԫ�ز���
#define MaxSize 10      //����ջ��Ԫ�ص������� 
typedef struct{
    ElemType data[MaxSize]; //��̬������ջ��Ԫ��
    int top                 // ջ��ָ�� 
}SqStack; 

//��ջ����
bool Pop(SqStack &S, ElemType &x){
    if(S.top=-1)    //ջ�գ�����
        return false;
    x=S.data[S.top--];  //�ȳ�ջ��ָ���ټ�1
    return true; 
} 

//��ջ��Ԫ��
bool GetTop(SqStack S, ElemType &x){
    if(S.top==-1)   //ջ�գ�����
        return false;
    x=S.data[S.top];    //x��¼ջ��Ԫ��
    return true; 
} 

/*����ջ*/
#define MaxSize 10  //����ջ��Ԫ�ص�������
typedef struct{
    ElemType data[MaxSize]; //��̬������ջ��Ԫ��
    int top0;       //0��ջ��ָ��
    int top1;       //1��ջ��ָ�� 
}ShStack;

//��ʼ��ջ
void InitStack(ShStack &S){
    S.top0=-1;      //��ʼ��ջ��ָ��
    S.top1=MaxSize; 
} 

/*��ջ�Ķ���*/
typedef struct Linknode{
    ElemType data;      //������ 
    struct Linknode *next;  // ָ���� 
}*LiStack;  //ջ���Ͷ���


/*���е�˳��ʵ��*/
#define MaxSize 10  //������л���Ԫ���е������� 
typedef struct{
    ElemType data[MaxSize]; //�þ�̬�����Ŷ���Ԫ��~�����Ĵ洢�ռ䣬��СMaxSize*sizeof(ElemType) 
    int front, rear;    //��ͷָ��Ͷ�βָ��~rearָ���βԪ�صĺ�һ��λ��(��һ��Ӧ�ò����λ��);frontָ���ͷԪ�� 
}SqQueue;   //˳�� 

//��ʼ������
#define MaxSize 10  //���������Ԫ�ص�������
typedef struct{
    ElemType data[MaxSize]; //�þ�̬�����Ŷ���Ԫ��
    int front, rear;        //��ͷָ��Ͷ�βָ�� 
}SqQueue;

//��ʼ������
void InitQueue(SqQueue &Q){
    //��ʼʱ ��ͷ����βָ��ָ��0
    Q.rear=Q.front=0; 
} 

void testQueue(){
    //����һ������(˳��洢)
    SqQueue Q;
    InitQueue(Q);
    //...��������... 
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue Q){
    if(Q.rear==Q.front) //�ӿ�����
        return true;
    else
        return false; 
} 
 
/*��Ӳ���*/
#define MaxSize 10  //���������Ԫ�ص�������
typedef struct{
    ElemType data[MaxSize]; //�þ�̬�����Ŷ���Ԫ��
    int front, rear;        //��ͷָ��Ͷ�βָ�� 
}SqQueue;

//���
bool EnQueue(SqQueue &Q, ElemType x){
    if((Q.rear+1)%MaxSize==Q.front) //�ж϶��� 
        return false;       //�����򱨴�
    Q.data[Q.rear]=x;       //��Ԫ�ز����β
    Q.rear=(Q.rear+1)%MaxSize; //��βָ���1ȡģ,���ַ�ʽ������ѭ������
    return true; 
} 

//����(ɾ��һ����ͷԪ�أ�����x����)
bool DeQueue(SqQueue &Q, ElemType &x){
    if(Q.rear==Q.front) //�ж϶ӿ�
        return false;   //�ӿ��򱨴�
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize; //��ͷָ����� 
    return true;
} 

//��ö�ͷԪ�ص�ֵ����x����
bool GetHead(SqQueue Q, ElemType &x){
    if(Q.rear==Q.front)
        return false;   //�ӿ��򱨴�
    x=Q.data[Q.front];
    return true; 
} 

/*���������ж϶�������/�ѿ�*/
#define MaxSize 10;
typedef struct{
    ElemType data[MaxSize];
    int front, rear;
    int size;   //���е�ǰ���ȣ���ʼ��ʱ��rear=front=0; size=0; 
}SqQueue;


/*���������ж϶�������/�ѿ�*/
#define MaxSize 10;
typedef struct {
    ElemType data[MaxSize];
    int front,rear;
    int tag; //������е���ɾ��/����~ɾ��Ϊ0������Ϊ1����ʼ��ʱrear=front=0;tag=0; 
}SqQueue;
 
/*���е���ʽʵ�� */
typedef struct LinkNode{    //��ʽ���н��
    ElemType data;
    struct LinkNode *next; 
}LinkNode;

typedef struct{ //��ʽ���� 
    LinkNode *front, *rear; //���еĶ�ͷ�Ͷ�βָ�� 
}LinkQueue;

/*��ʼ��(��ͷ���)*/
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}; 

//��ʼ������(��ͷ���)
void InitQueue(LinkQueue &Q){
    //��ʼʱ front��rear ��ָ��ͷ���
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL; 
} 

void testLinkQueue(){
    LinkQueue Q;    //����һ������
    InitQueue(Q);   //��ʼ������
    //...��������... 
}

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear)
        return true;
    else
        return false;
} 

//��ʼ��(����ͷ���)
void InitQueue(LinkQueue &Q){
    //��ʼʱ front��rear ��ָ��NULL
    Q.front=NULL;
    Q.rear=NULL; 
} 

//�ж϶����Ƿ�Ϊ��(����ͷ���)
bool IsEmpty(LinkQueue Q){
    if(Q.front==NULL)
        return true;
    else
        return false;
} 

//��Ԫ�����(��ͷ���)
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s; //�½����뵽rear֮��
    Q.rear=s;   //�޸ı�βָ��  
}

/*���(����ͷ���)*/
//��Ԫ�����(����ͷ���)
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    if (Q.front==NULL){ //�ڿն����в����һ��Ԫ�� 
        Q.front=s;      //�޸Ķ�ͷ��βָ�� 
        Q.rear=s;       //����ͷ���Ķ��У���һ��Ԫ�����ʱ����Ҫ�ر��� 
    }else {
        Q.rear->next=s; //�½����뵽rear���֮��
        Q.rear=s;       //�޸�rearָ�� 
    } 
} 

/*����(��ͷ���)*/
//��ͷԪ�س���(����ͷ���)
bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.front==Q.rear)
        return false;   //�ն�
    LinkNode *p=Q.front->next;
    x=p->data;  //�ñ���x���ض�ͷԪ��
    Q.front->next=p->next;  //�޸�ͷ����nextָ��
    if(Q.rear==p)       //�˴������һ��������
        Q.rear=Q.front; //�޸�rearָ��
    free(p);        //�ͷŽ��ռ�
    return true; 
} 

/*����(����ͷ���)*/
//��ͷԪ�س���(����ͷ���)
bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.front==NULL)
        return false;   //�ն�
    LinkNode *p=Q.front;    //pָ��˴γ��ӵĽڵ�
    x=p->data;          //�ñ���x���ض�ͷԪ��
    Q.front=p->next;    //�޸�frontָ��
    if(Q.rear=p){       //�˴������һ��������
        Q.front=Null;   //frontָ��NULL
        Q.rear=NULL;    //rearָ��NULL 
    } 
    free(p);            //�ͷŽ��ռ�
    return true; 
} 




























































