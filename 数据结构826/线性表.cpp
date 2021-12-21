/* 2.2.1.顺序表的顺序存储_静态分配 */
#define MaxSize 50      		//定义线性表的最大长度
typedef struct{
    ElemType data[MaxSize];     //顺序表的元素
    int length;                 //顺序表的当前长度
}SqlList;                       //顺序表的类型定义

/* 2.2.1.顺序表的顺序存储_动态分配 */
#define InitSize 100            //表长度的初始定义
typedef struct{
    ElemType *data;             //指示动态分配数组的指针
    int MaxSize, length;        //数组的最大容量和当前个数
}SeqList;                       //动态分配数组顺序表的类型定义

/* 2.2.2.1.顺序表的基本操作_插入 */
bool ListInsert(SqlList &L, int i, ElemType e){
    if(i<1||i>L.length+1)           //判断i的范围是否有效
        return false;
    if(L.length>=MaxSize)           //当前存储空间已满，不能插入
    for(int j=L.length;j>=i;j--)    //将第i个元素及之后的元素后移
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;                  //在位置i处放入e
    L.length++;                     //线性表长度加1
    return true;
}

/* 2.2.2.1.顺序表的基本操作_删除 */
bool ListDelete(SqlList &L, int i, ElemType &e){
    if(i<1||i>L.length)             //判断i的范围是否有效
        return false;
    e=L.data[i-1];                  //将被删除的元素赋值给e
    for(int j=i;j<L.length;j++)     //将第i个位置后的元素前移
        L.data[j-1]=L.data[j];
    L.length--;                     //线性表长度减1
    return true;
}

/* 2.2.2.1.按值查找(顺序查找) */
int LocateElem(SqlList L, ElemType e){
    int i;
    for(i=0;i<L.length;i++)
        if(L.data[i]==e)            //下标为i的元素值等于e，返回其位序i+1
            return i+1;             //退出循环，说明查找失败
    return 0;
}

/* 2.3.1.单链表结点类型描述 */
typedef struct LNode{               //定义单链表结点类型
    ElemType data;                  //数据域
    struct LNode *next;             //指针域
}LNode, *LinkList;

/* 2.3.2.建立单链表_头插法 */
LinkList List_HeadInsert(LinkList &L){      //逆向建立单链表
    LNode *s; int x;
    L=(LinkList)malloc(sizeof(LNode));      //创建头结点
    L->next=NULL;                           //初始为空链表
    scanf("%d", &x);                        //输入结点的值
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));    //创建新结点
        s->data=x;
        s->next=L->next;
        L->next=s;                           //将新结点插入表中，L为头指针
        scanf("%d", &x);
    }
    return L;
}

/* 2.3.2.建立单链表_尾插法 */
LinkList List_TailInsert(LinkList &L){      //正向建立单链表
    int x;                                  //设元素类型为整型
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s, *r=L;                         //r为表尾指针
    scanf("%d", &x);                        //输入结点的值
    while(x!=9999){                         //输入9999表示结束
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scarnf("%d", &x);
    }
    r->next=NULL;
    return L;
}

/* 2.3.3.按序号查找_结点值 */
LNode *GetElem(LinkList L, int i){
    int j=1;                                //计数，初始为1
    LNode *p=L->next;                       //头结点指针赋给p
    if(i==0)
        return L;                           //若i等于0，则返回头结点
    if(i<1)
        return NULL;                        //若i无效，则返回NULL
    while(p&&j<i){                          //从第1个结点开始找，查找第i个结点
        p=p->next;
        j++;
    }
    return p;                               //返回第i个结点的指针，若i大于表长则返回NULL
} 

/* 2.3.3.按值查找_结点值 */
LNode *LocateElem(LinkList L, ElemType e){
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e)      //从第1个结点开始查找data域为e的结点
        p=p->next;
    return p;                       //找到后，返回该结点指针，否则返回NULL
}

/* 2.3.4. 插入操作_后插 */
p=GetElem(L,i-1);                   //查找插入位置的前驱结点
s->next=p->next;
p->next=s;

/* 2.3.4. 插入操作_前插 */
// 将*s结点插入到*p之前的主要代码片段
s->next=p->next;                    //修改指针域，不能颠倒
p->next=s;
temp=p->data;                       //交换数据域部分
p->data=s->data;
s->data=temp;

/* 2.3.4. 删除操作*/
p=GetElem(L, i-1);                  //查找删除位置的前驱结点
q=p->next;                          //令q指向被删除结点
p->next=q->next;                    //将*q结点，从链中“断开”
free(q);                            //释放结点的存储空间

//删除结点*p_将其后继结点的值，赋予其自身，然后删除后继结点
q=p->next;                          //令q指向*p的后继结点
p->data=p->next->data;              //和后继结点，交换数据域
p->next=q->next;                    //将*q结点从链中"断开"
free(q);                            //释放后继结点的存储空间


/* 2.4.1.双链表的结点类型 */
typedef struct DNode{               //定义双链表结点类型
    ElemType data;                  //数据域
    struct DNode *prior, *next;     //前驱和后继指针
}DNode, *DLinkList;

/* 2.5.2.双链表的插入 */































