/*struct LNode{   //定义单链表结点类型
    ElemType data; //每个节点存放一个数据元素 
    struct LNode *next; // 指针指向下一个节点 
}; 


typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

typedef struct LNode LNode;
typedef struct LNode *LinkList;
要表示一个单链表时，只需声明一个头指针L,指向单链表的第一个结点
LNode*L; //声明一个指向单链表第一个结点的指针
或：
LinkList L; //声明一个指向单链表第一个结点的指针 --代码可读性更强
*/

typedef struct LNode{	//定义单链表结点类型
    ElemType data;		//数据域
    struct LNode *next;	//指针域
}LNode, *LinkList;

LNode *GetElem(LinkList L, int i){
    int j=1;
    LNode *p=L->next;
    if(i==0)
        return L;
    if(i<1)
        return NULL;
    while(p!=NULL && j<i){
        p=p->next;
        j++;
    }
    return p;
}

//头插法建立单链表的算法：
LinkList List_HeadInsert(LinkList &L){ //逆向建立单链表
    LNode *s; int x;
    L=(LinkList)malloc(sizeof(LNode)); //创建头结点
    L->next=NULL; //初始为空链表
    scanf("%d", &x); //输入结点的值
    while(x!=9999){  //输入9999表示结束 
        s=(LNode*)malloc(sizeof(LNode)); //创建新结点，由系统生成一个LNode型的结点，同时将该结点的起始位置赋给指针变量s
        s->data=x;	//~~~s的数据域指向x值
        s->next=L->next;	//~~~s的next指针指向头结点的next指向的地方
        L->next=s;	//将新结点插入表中，L为头指针~~~将头结点的next指针，指向s结点
        scanf("%d", &x); 
    } 
    
} 


typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//初始化一个空的单链表
bool InitList(LinkList &){
    L=Null; //空表，暂时还没有任何结点 -防止脏数据
    return true;     
} 

void test(){
    LinkList L; //声明一个指向单链表的指针 
}



bool InitList(LinkList &L){
    L = (LNode *) malloc(sizeof(LNode));  //分配一个头结点,将malloc返回的地址返回给L，指向data 
    if (L==NULL)
        return false;
        L->next=NULL;  // 将头结点的指针域设置为NULL，头结点不存储数据 
        return true; 
}

void test(){
    LinkList L;  //声明一个指向单链表的指针
    //初始化一个空表
    InitList(L)
    //... 
}

//判断单链表是否为空(带头结点） 
bool Empty(LinkList L) {
    if (L->next == NULL)
        return true;
    else
        return false;
}


 

//按位序插入(带头结点)
//在第i个位置插入元素e(带头结点)
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    LNode *p;  //指针p指向当前扫描到的结点
    int j=0;  //当前p指向的是第几个结点
    p = L;  //L指向头结点 
    while (p!=NULL && j<i-1){  //循环找到第i-1个结点
        p=p->next;
        j++; 
    }
    if(p==NULL)  //i值不合法~
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next=p->next;
    p->next=s;  //将结点s连到p之后~不能与 s->next=p->next;颠倒 
    return true;  //插入成功
     
} 

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//分析:1.如果i=1(插在表头 



/*
按位查找~即按序号查找结点值 
*/
LNode * GetElem(LinkList L, int i){ //按位查找，返回第i个元素(带头结点~第0个)
    if(i<0)
        return NULL;
    LNode *p;   //指针p指向当前扫描到的结点
    int j=0;    // 当前p指向的是第几个结点
    p = L;      // L指向头结点，头结点是第0个结点
    while (p!=NULL && j<i){  //循环找到第i个结点~ p不为空且j<i时
        p=p->next;
        j++; 
    } 
    return p;
} 

// 王道书中的按位查找
LNode * GetElem(LinkList L, int i){
    int j=1;	//计数，初始为1
    LNode *p=L->next;	//头结点指针赋给p
    if(i==0)
        return L;	//若i等于0，则返回头结点
    if(i<1)
        return NULL;	//若i无效，则返回NULL
    while(p!=NULL && j<i){	//从第i个结点开始找，查找第i个结点
        p=p->next;
        j++;
    } 
    return p;	//返回第i个结点的指针，若i大于表长则返回NULL
} 
 

//在第i个位置插入元素e(带头结点)
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    LNode *p = GetElem(L, i-1); //1) 指针p指向当前扫描到的结点
    int j=0; // 当前p指向的是第几个结点
    p = L;  // L指向头结点，头结点是第0个节点(不存数据)
    while (p!=NULL && j<i-1){ //循环找到第i-1个结点
        p=p->next;
        j++; 
    } 
    if(p==NULL)  //i值不合法
//        return false;
        return InsertNextNode(p, e);  //p后面插入新元素e，尾插法 
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next; //将s的next指针指向p的next指针所指的地方
    p->next = s;  //将结点s连到p之后
    return true; // 插入成功 
} 

//在第i个位置删除元素e
bool ListDelete(LinkList &L, int i, ElemType &e){
    if(i<1)
        return false;
    LNode *p;   // 指针p指向当前扫描到的结点
    int j=0;    // 当前p指向的是第几个结点
    p = L;      // L指向头结点，头结点是第0个结点(不存数据)
    while(p!=NULL && j<i-1){  //循环找到第i-1个结点
        p=p->next;
        j++; 
    } 
    if(p==NULL) //i值不合法
        return false;
    if(p->next == NULL) // 第i-1个结点之后已无其他结点
        return false;
    LNode *q=p->next;   // 令q指向被删除结点
    e = q->data;        // 用e返回元素的值~将p的数据域指向e
    p->next=q->next;    // 将*q结点从链中"断开"
    free(q);            // 释放结点q的存储空间
    return true;        // 删除成功 
} 

//按值查找，找到数据域==e的结点
LNode * LocateElem(LinkList L, ElemType e){
    LNode *p = L->next; //头结点指针赋给p
    while (p!=NULL && p->data != e)	    //从第1个结点开始查找数据域为e的结点
        p = p->next;	//如果数据域不符合，则p指针指向下一个数据
    return p;   //找到后返回该结点指针，否则返回NULL 
} 


// 求表的长度
int Length(LinkList L){
    int len = 0; //统计表长
    LNode *p = L;
    while (p->next != NULL){
        p = p->next;
        len++;
    } 
    return len;
} 

/*
按位序插入(带头结点) 
*/
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    LNode *p;   //指针p指向当前扫描到的结点
    int j=0;    // 当前p指向的是第几个结点
    p = L;      // L指向头结点，头结点是第0个结点(不存数据)
    while (p!=NULL && j<i-1){  //循环找到第i-1个结点
        p=p->next;
        j++; 
    } 
    if(p==NULL)     //i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next=p->next;
    p->next=s;  //将结点s连到p之后
    return true; //插入成功
    
}

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList; 

/*
按位序插入(不带头结点)
*/
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    if(i==1){   //插入第1个结点的操作与其他结点操作不同
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next=L;
        L=s;   //头指针指向新结点
        return true; 
    }
    LNode *p;   //指针p指向当前扫描到的结点
    int j=1;    // 当前p指向的是第几个结点
    p = L;      // p指向第1个结点(注意：不是头结点)
    while (p!=NULL && j<i-1){   //循环找到第i-1个结点
        p=p->next;
        j++; 
    } 
    if(p=NULL)  //i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next=p->next;
    p->next=s;
    return true; //插入成功 
}


/*
指定结点的后插操作
*/ 
//后插操作:在p结点之后插入元素e
bool InsertNextNode (LNode *p, ElemType e){
    if (p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s==NULL)    //内存分配失败,可不写，但内存不足时可能分配失败 
        return false; 
    s->data = e;    //用结点s保存数据元素e
    s->next=p->next;
    p->next=s;      // 将结点s连到p之后
    return true; 
} 


//在第i个位置插入元素e(带头结点) 
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    LNode *p; //指针p指向当前扫描到的节点
    int j=0; //当前p指向的是第几个结点
    p = L;  //L指向头结点，头结点是第0个结点(不存数据)
    while(p!=NULL && j<i-1){    //循环找到第i-1个结点
        p=p->next;
        j++; 
    } 
    if(p==NULL) //i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;    //将结点s连到p之后
    return true;    //插入成功 
// 以上代码可改为调用InsertNextNode(p, e) 
return InsertNextNode(p, e);

}

typedef struct LNodel{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;


//后插操作:在p结点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e){
    if (p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s==NULL)    //内存分配失败 
        return false;
    s->data = e;    //用结点s保存数据元素e 
    s->next=p->next;
    p->next=s;  //将结点s连到p之后
    return true; 
} 


/*
指定结点的前插操作
*/
//前插操作:在p结点之前插入元素e
bool InsertPriorNode(LNode *p, ElemType e){
    if (p==NULL)
        return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    if (s==NULL)    //内存分配失败
        return false;
    s->next=p->next;
    p->next=s;      //新结点s连到p之后 
    s->data=p->data; //将p中元素复制到s中
    p->data=e;      //将p中元素覆盖为e
    return true 
} 


 
//王道书中前插操作:在p结点之前插入元素e
bool InsertPriorNode (LNode *p, LNode *s){
    if(p==NULL || s==NULL)
        return false;
    s->next=p->next;
    p->next=s;  //s连到p之后
    ElemType temp=p->data;  //交换数据域部分
    p->data=s->data;
    s->data=temp;
    return true; 
}


/*
按位序删除(带头结点) 
*/ 
bool ListDelete(LinkList &L, int i, ElemType &e){
    if(i<1)
        return false;
    LNode *p;   //指针p指向当前扫描到的结点
    int j=0;    //当前p指向的是第几个结点
    p=L;        //L指向头结点，头结点是第0个结点(不存数据)
    while (p!=NULL && j<i-1){//循环找到第i-1个结点
        p=p->next;
        j++; 
    } 
    if(p==NULL) //i值不合法
        return false;
    if(p->next == NULL) //第i-1个结点之后已无其他结点
        return false;
    LNode *q=p->next;   //令q指向被删除结点
    e = q->data;        // 用e返回元素的值
    p->next=q->next;    //将*q结点从链中"断开"
    free(q);            //释放结点的存储空间
    return true;        //删除成功     
}

bool DeleteNode (LNode *p){
    if (p==NULL)
        return false;
    LNode *q=p->next;  //令q指向*p的后继结点
    p->data=p->next->data   //和后继结点交换数据域
    p->next=q->next;    //将*q结点从链中"断开"
    free(q);            //释放后继结点的存储空间 
    return true; 
}


/*尾插法建立单链表*/
typedef struct LNode{       //定义单链表结点类型 
    ElemType data;          //每个结点存放一个数据元素 
    struct LNode *next;     //指针指向下一个结点 
}LNode, *LinkList;


//初始化一个单链表(带头结点)
bool InitList(LinkList &L){
    L=(LNode *) malloc(sizeof(LNode));  //分配一个头结点
    if (L==NULL)
        return false;
    L-->next = NULL;    // 头结点之后展示还没有结点
    return true; 
} 

void test(){
    LinkList L; //声明一个指向单链表的指针
    //初始化一个空表
    InitList(L);
    //....后续代码... 
}

/*尾插法建立单链表的算法*/
LinkList List_TailInsert(LinkList &L){  //正向建立单链表 
    int x;  //设元素为整型 
    L=(LinkList)malloc(sizeof(LNode));  //建立头结点
    LNode *s, *r=L; //r为表尾指针~~~添加一个尾结点~~~s为头指针
    scanf("%d", &x); //输入结点的值
    while(x!=9999){
        s=(LNode *)malloc(sizeof(LNode));   //创建新结点，在r结点之后插入元素x 
        s->data=x;	//~~~s的数据域指向x值
        r->next=s;	//~~~r的next指针指向s值
        r=s;    //r指向新的表尾结点，永远保持r指向最后一个结点
        scanf("%d", &x); 
    }
    r->next=NULL;   //尾结点指针置空
    return L; 
}

/*头插法建立单链表*/
//后插操作: 在p结点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e){
    if (p==NULL)
        return false;
    LNode *s = (LNode *)malloc(siezof(LNode));
    if (s==NULL)    //内存分配失败
        return false;
    s->data=e;  //用结点s保存数据元素e
    s->next=p->next;    
    p->next=s;  //将结点s连到p之后
    return true; 
} 


LinkList List_HeadInsert(LinkList &L){  //逆向建立单链表
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof(LNode));  //创建头结点
    L->next=NULL;       //初始为空链表，如果没有这句，可能会指向脏数据
    scanf("%d", &x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));    //创建新结点
        s->data=x;
        s->next=L->next;
        L->next=s;  //将新结点插入表中，L为头指针
        scanf("%d", &x); 
    }     
    return L;
    
}

/*双链表*/
typedef struct DNode{       //定义双链表结点类型 
    ElemType data;          //数据域 
    struct DNode *prior, *next; //前驱和后继指针 
}DNode, *DLinklist;


/*双链表的初始化(带头结点)*/
//初始化双链表
bool InitDLinkList(DLinklist, &L){	// DLinklist等价于DNode *
    L = (DNode *)malloc(sizeof(DNode)); //分配一个头结点
    if (L==NULL)
        return false;
    L->prior=NULL;      //头结点的prior永远指向NULL 
    L->next=NULL;       //头结点之后暂时还没有结点 
    return true;
} 


void testDLinkList(){    
    //初始化双链表
    DLinklist L;
    INitDLinkList(L); 
	// 后续代码
}

/*双链表的插入*/
//在p结点之后插入s结点
bool InsertNextNode(DNode *p, DNode *s){
	if (p==NULL || s==NULL)	//非法参数
		return false;
	s->next=p->next;	// (1)s结点的next指针，指向与p结点的next指针相同的位置
	if (p->next != NULL) //如果p结点有后继结点~如果p结点此时没有后继结点，就不用修改后继结点的前向指针
		p->next->prior=s; // (2)修改后继结点的前向指针
	s->prior=p;	// (3)s结点的前向指针，指向p结点
	p->next=s;	// (4)第4步必须在(1)(2)之后，将p结点的后向指针，指向s结点
	return true;
}

/*双链表的删除*/
//删除p结点的后继结点
bool DeleteNextDNode(DNode *p){
	if (p==NULL)	return false;
	DNode *q = p->next;	//找到p的后继结点q
	if (q==NULL)	return false;	//p没有后继
	p->next=q->next;	//p结点的next指针，指向与q结点的next指针相同的位置，p指向NULL
	if (q->next!=NULL)
		q->next->prior=p;	//尝试修改q结点后继结点的前向指针，但q结点的后继结点不存在，不满足，故跳过
	free(q);			// 释放结点空间
	return true;
}

//释放双链表
void DestroyList(Dlinklist &L){
	//循环释放各个数据结点
	while (L->next != NULL) //用一个while循环，将结点从头结点开始删除，直到NULL
		DeleteNextDNode(L);
	free(L);	//释放头结点
	L=NULL;		//头指针指向NULL
}

/*双链表的遍历*/
//后向遍历
while(p != NULL){
	//对结点p做相应处理，如打印
	p=p->next;
}
//前向遍历
while(p != NULL){
	//对结点p做相应处理，如打印
	p=p->next;
}
//前向遍历(跳过头结点)
while(p->prior != NULL){	//跳过头结点，只想对数据结点进行处理
	//对结点p做相应处理，如打印
	p=p->next;
}





//判断双链表是否为空(带头结点)
bool Empty(DLinklist L){
    if (L->next==NULL)
        return true;
    else
        return false;
}

typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DLinklist;

/*静态链表*/
//基本操作的实现
#define MaxSize 10  //静态链表的最大长度 
typedef struct {    //静态链表结构类型的定义 
    ElemType data;  //存储数据元素 
    int next;       //下一个元素的数组下标 
}SLinkList[MaxSize]; 


void testSLinkList(){
    SLinkList a;
    //...后续代码 
} 




// 对猜想的验证
#define MaxSize 10 //静态链表的最大长度
struct Node{      //静态链表结构类型的定义
    int data;     //存储数据元素      
    int next;     //下一个元素的数组下标 
};

typedef struct{ //静态链表结构类型的定义 
    int data;   //存储数据元素 
    int next;   //下一个元素的数组下标 
}SLinkList[MaxSize];

void testSLinkList(){
    struct Node x;
    printf("sizeX=%d\n", siezeof(x));
    
    struct Node a[MaxSize];
    printf("sizeA=%d\n", sizeof(a));
    
    SLinkList b;
    printf("sizeB=%d\n", sizeof(b));
}


/*基本操作---销*/
typedef struct{
    ElemType *data;
    int MaxSize;
    int length;
}SeqList;

L.data={ElemType *}malloc(sizeof(ElemType)* InitSize);
free(L.data); 




































