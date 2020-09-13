#define MaxSize 10  // 定义栈中元素的最大个数 
typedef struct{  
    ElemType data[MaxSize]; // 静态数组存放栈中元素 
    int top;    // 栈顶指针 
}SqStack;   //Sq:sequence---顺序 

void testStack(){
    SqStack S;  //声明一个顺序栈(分配空间)
    //...后续操作... 
} 

/*初始化操作*/
#define MaxSize 10  //定义栈中元素的最大个数 
typedef struct{
    ElemType data[MaxSize]; //静态数组存放栈中元素 
    int top;    //栈顶指针 
}SqStack; 

//初始化栈
void InitStack(SqStack &S){
    S.top=-1    //初始化栈顶指针 
} 

void testStack(){
    SqStack S;  //声明一个顺序栈(分配空间)
    InitStack(S); 
}

//判断栈空
bool StackEmpty(SqStack S){
    if(S.top==-1)   //栈空
        return true;
    else            //不空 
        return false; 
} 


//进栈操作
#define MaxSize 10      //定义栈中元素的最大个数 
typedef struct{
    ElemType data[MaxSize]; //静态数组存放栈中元素 
    int top;    //栈顶指针 
}SqStack; 

//新元素入栈
bool Push(SqStack &S, ElemType x){
    if(S.top==MaxSize-1)    //栈满，报错
        return false;
    S.top = S.top + 1;  //指针先加1
    S.data[S.top]=x;    //新元素入栈 等价于 S.data[++S.top]=x; 
    return true; 
} 

//出栈操作
#define MaxSize 10
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

bool Pop(SqStack &S, ElemType &x){
    if(S.top==-1)   //栈空，报错
        return false;
    x=S.data[S.top];    //栈顶元素先出栈
    S.top=S.top-1;      //指针再减1 等价于x=S.data[S.top--]; 
} 


//读栈顶元素操作
#define MaxSize 10      //定义栈中元素的最大个数 
typedef struct{
    ElemType data[MaxSize]; //静态数组存放栈中元素
    int top                 // 栈顶指针 
}SqStack; 

//出栈操作
bool Pop(SqStack &S, ElemType &x){
    if(S.top=-1)    //栈空，报错
        return false;
    x=S.data[S.top--];  //先出栈，指针再减1
    return true; 
} 

//读栈顶元素
bool GetTop(SqStack S, ElemType &x){
    if(S.top==-1)   //栈空，报错
        return false;
    x=S.data[S.top];    //x记录栈顶元素
    return true; 
} 

/*共享栈*/
#define MaxSize 10  //定义栈中元素的最大个数
typedef struct{
    ElemType data[MaxSize]; //静态数组存放栈中元素
    int top0;       //0号栈顶指针
    int top1;       //1号栈顶指针 
}ShStack;

//初始化栈
void InitStack(ShStack &S){
    S.top0=-1;      //初始化栈顶指针
    S.top1=MaxSize; 
} 

/*链栈的定义*/
typedef struct Linknode{
    ElemType data;      //数据域 
    struct Linknode *next;  // 指针域 
}*LiStack;  //栈类型定义


/*队列的顺序实现*/
#define MaxSize 10  //定义队列汇总元素中的最大个数 
typedef struct{
    ElemType data[MaxSize]; //用静态数组存放队列元素~连续的存储空间，大小MaxSize*sizeof(ElemType) 
    int front, rear;    //队头指针和队尾指针~rear指向队尾元素的后一个位置(下一个应该插入的位置);front指向队头元素 
}SqQueue;   //顺序 

//初始化操作
#define MaxSize 10  //定义队列中元素的最大个数
typedef struct{
    ElemType data[MaxSize]; //用静态数组存放队列元素
    int front, rear;        //队头指针和队尾指针 
}SqQueue;

//初始化队列
void InitQueue(SqQueue &Q){
    //初始时 队头、队尾指针指向0
    Q.rear=Q.front=0; 
} 

void testQueue(){
    //声明一个队列(顺序存储)
    SqQueue Q;
    InitQueue(Q);
    //...后续操作... 
}

//判断队列是否为空
bool QueueEmpty(SqQueue Q){
    if(Q.rear==Q.front) //队空条件
        return true;
    else
        return false; 
} 
 
/*入队操作*/
#define MaxSize 10  //定义队列中元素的最大个数
typedef struct{
    ElemType data[MaxSize]; //用静态数组存放队列元素
    int front, rear;        //队头指针和队尾指针 
}SqQueue;

//入队
bool EnQueue(SqQueue &Q, ElemType x){
    if((Q.rear+1)%MaxSize==Q.front) //判断队满 
        return false;       //队满则报错
    Q.data[Q.rear]=x;       //新元素插入队尾
    Q.rear=(Q.rear+1)%MaxSize; //队尾指针加1取模,这种方式即构成循环队列
    return true; 
} 

//出队(删除一个队头元素，并用x返回)
bool DeQueue(SqQueue &Q, ElemType &x){
    if(Q.rear==Q.front) //判断队空
        return false;   //队空则报错
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize; //队头指针后移 
    return true;
} 

//获得队头元素的值，用x返回
bool GetHead(SqQueue Q, ElemType &x){
    if(Q.rear==Q.front)
        return false;   //队空则报错
    x=Q.data[Q.front];
    return true; 
} 

/*方案二：判断队列已满/已空*/
#define MaxSize 10;
typedef struct{
    ElemType data[MaxSize];
    int front, rear;
    int size;   //队列当前长度，初始化时，rear=front=0; size=0; 
}SqQueue;


/*方案三：判断队列已满/已空*/
#define MaxSize 10;
typedef struct {
    ElemType data[MaxSize];
    int front,rear;
    int tag; //最近进行的是删除/插入~删除为0，插入为1；初始化时rear=front=0;tag=0; 
}SqQueue;
 
/*队列的链式实现 */
typedef struct LinkNode{    //链式队列结点
    ElemType data;
    struct LinkNode *next; 
}LinkNode;

typedef struct{ //链式队列 
    LinkNode *front, *rear; //队列的队头和队尾指针 
}LinkQueue;

/*初始化(带头结点)*/
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}; 

//初始化队列(带头结点)
void InitQueue(LinkQueue &Q){
    //初始时 front、rear 都指向头结点
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL; 
} 

void testLinkQueue(){
    LinkQueue Q;    //声明一个队列
    InitQueue(Q);   //初始化队列
    //...后续操作... 
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear)
        return true;
    else
        return false;
} 

//初始化(不带头结点)
void InitQueue(LinkQueue &Q){
    //初始时 front、rear 都指向NULL
    Q.front=NULL;
    Q.rear=NULL; 
} 

//判断队列是否为空(不带头结点)
bool IsEmpty(LinkQueue Q){
    if(Q.front==NULL)
        return true;
    else
        return false;
} 

//新元素入队(带头结点)
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s; //新结点插入到rear之后
    Q.rear=s;   //修改表尾指针  
}

/*入队(不带头结点)*/
//新元素入队(不带头结点)
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    if (Q.front==NULL){ //在空队列中插入第一个元素 
        Q.front=s;      //修改队头队尾指针 
        Q.rear=s;       //不带头结点的队列，第一个元素入队时，需要特别处理 
    }else {
        Q.rear->next=s; //新结点插入到rear结点之后
        Q.rear=s;       //修改rear指针 
    } 
} 

/*出队(带头结点)*/
//队头元素出队(不带头结点)
bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.front==Q.rear)
        return false;   //空队
    LinkNode *p=Q.front->next;
    x=p->data;  //用变量x返回队头元素
    Q.front->next=p->next;  //修改头结点的next指针
    if(Q.rear==p)       //此次是最后一个结点出队
        Q.rear=Q.front; //修改rear指针
    free(p);        //释放结点空间
    return true; 
} 

/*出队(不带头结点)*/
//队头元素出队(不带头结点)
bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.front==NULL)
        return false;   //空队
    LinkNode *p=Q.front;    //p指向此次出队的节点
    x=p->data;          //用变量x返回队头元素
    Q.front=p->next;    //修改front指针
    if(Q.rear=p){       //此次是最后一个结点出队
        Q.front=Null;   //front指向NULL
        Q.rear=NULL;    //rear指向NULL 
    } 
    free(p);            //释放结点空间
    return true; 
} 




























































