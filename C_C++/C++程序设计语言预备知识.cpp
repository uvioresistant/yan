include<iostream.h> //含有cout函数的原型

    int GetMax(int x, int y) /*比较两个数的大小并返回较大者*/
{
  if (x >= y)
    return x;
  else
    return y;
}

void main()
{
  cout << GetMax(5, 8); //调用函数GetMax
}

/* 访问成员 */
struct Node
{
  int data;
  Node *next;
};
Node t, *s;

/* 联合类型声明形式 */
union Uarea
{
  int data;
  int *link;
};

/* 类的声明形式 */
class Node
{
public:
  int GetData();
  void SetData(int x);

private:
  int data;
  Node *next;
};

/* 定义类的成员函数的一般格式 */
// Node类中成员函数GetData的定义:

int Node::GetData()
{
  return data;
}

/* 对象变量的声明格式 */
Node s;

/* typedef的使用 */
typedef int DataType;

/* 块语句 */
if (x >= 0)
{
  if (x > 0)
    x = 0;
}
else
{
  x++;
} //块语句解决了else配对问题

/* 2.2.2 顺序表的实现 C++模板机制 */
const int MaxSize = 100;
template <class T>
class SeqList //定义模板类SeqList
{
public:
  SeqList() { length = 0; } //无参构造函数
  SeqList(T a[], int n);    //有参构造函数
  SeqList() {}              //析构函数为空
  int Length() { return length; }
  T Get(int i);            //按位查找
  int Locate(T x);         //按值查找
  void Insert(int i, T x); //第i个位置插入值为x的元素
  T Delete(int i);         //删除第i个元素
  void PrintList();        //遍历线性表

private:
  T data[MaxSize]; //存放数据元素的数组
  int length;      //线性表的长度
};

// 2.2.2.1 顺序表有参构造函数 SeqList
template <class T>
SeqList::SeqList(T a[], int n)
{
  if (n > MaxSize)
    throw "参数非法";
  for (i = 0; i < n; i++)
    data[i] = a[i];
  length = n;
}

// 2.2.2.2 顺序表插入算法 Insert
template <class T>
void SeqList::Insert(int i, T x)
{
  if (length >= MaxSize)
    throw "上溢";
  if (i < 1 || i > length + 1)
    throw "位置异常";
  for (j = length; j >= i; j--)
    data[j] = data[j - 1]; //注意第j个元素存在数组下标为j-1处
  data[i + 1] = x;
  length++;
}

// 2.2.2.3 顺序表删除算法 Delete
template <class T>
void SeqList::Delete(int i, T x)
{
  if (length == 0)
    throw "下溢";
  if (i < 1 || i > length)
    throw "位置异常";
  x = data[i - 1];
  for (j = i; j < length; j++)
    data[j - 1] = data[j];
  length--;
  return x;
}

// 2.2.2.4 查找
// 2.2.2.4.1 按位查找
template <class T>
T SeqList::Get(int i)
{
  if (i < 1 || i > length)
    throw "查找位置非法";
  else
    return data[i - 1];
}

// 2.2.2.1.2 按值查找 Locate
template <class T>
int SeqList::Locate(T x)
{
  for (i = 0; i < length; i++)
    if (data[i] == x)
      return i + 1; //下标为i的元素等于x，返回其序号i+1
  return 0;         //退出循环，查找失败
}

/* 2.3.1 单链表 */
// 单链表的结点
template <class T>
struct Node
{
  T data;
  Node<T> *next; //<T>可以省略
};

template <class T>
class LinkList
{
public:
  LinkList()
  {
    first = new Node<T>;
    first->next = NULL;
  }                       //只有头结点的空链表
  LinkList(T a[], int n); //建立有n个元素的单链表
  LinkList();             //析构函数
  int Length();
  T Get(int i);             //取单链表中值为x的元素序号
  int Locate(T x);          //求单链表中值为x的元素符号
  void Insert(int i, Tx);   //单链表中第i个位置插入元素值为x的结点
  T Delete(int i);          //单链表中删除第i个结点
  void PrintList();         //遍历单链表，按序号依次输出各元素
  Private : Node<T> *first; //单链表的头指针
}

// 单链表按位查找算法
template <class T>
T LinkList::Get(int i)
{
  p = first->next;
  j = 1; //或p=first; j=0;
  while (p && j < i)
  {
    p = p->next; //工作指针p后移
    j++;
  }
  if (!p)
    throw "位置";
  else
    return p->data;
}

// 3.单链表插入算法
/* 伪代码：
1.工作指针p初始化;累加器j清零；工作指针p应指向头结点
2.查找第i-1个结点并使工作指针p指向该结点；
3.若查找不成功，说明插入位置不合理，抛出插入位置异常；
  否则，3.1 生成一个元素值为x的新结点s；
        3.2 将新结点s插入到结点p之后； */
template <class T>
void LinkList::Insert(int i, T x)
{
  p = first;
  j = 0;
  while (p && j < i - 1)
  {
    p = p->next;
    j++;
  }
  if (!p)
    throw '位置';
  else
  {
    s = new Node<T>;
    s->data - x;       //向内存申请一个结点s，其数据域为x
    s->next = p->next; //结点s插入到结点p之后
    p->next = s;
  }
}

// 1) 头插法建立单链表
template <class T>
LinkList::LinkList(T a[], int n)
{
  first = new Node<T>;
  first->next = NULL; //初始化一个空链表
  for (i = 0; i < n; i++)
  {
    s = new Node<T>;
    s->data = a[i];        //为每个数组元素建立一个结点
    s->next = first->next; //插入到头结点之后
    first->next = n;
  }
}

// 2)尾插法建立单链表
template <class T>
LinkList::LinkList(T a[], int n)
{
  first = new Node<T>;
  r = first;
  for (i = 0; i < n; i++)
  {
    s = new Node<T>;
    s->data = a[i];
    r->next = s;
    r = s;
  }
  r->next = NULL;
}

// 4.删除
/* 伪代码：1.工作指针p初始化；累加器j清零；//注意工作指针p要指向头结点
        2.查找第i-1个结点并使工作指针p指向该结点；
        3.若p不存在或p的后继结点不存在，抛出位置异常；
          否则，3.1 暂存被删结点和被删元素值；
                3.2 摘链，将结点p的后继结点从链表上摘下；
                3.3 释放被删结点；
                3.4 返回被删元素值； */

template <class T>
T LinkList::Delete(int i)
{
  p = first;
  j = 0;                 //工作指针p初始化
  while (p && j < i - 1) //查找第i-1个结点
  {
    p = p->next;
    j++;
  }
  if (!p || !p->next)
    throw "位置"; //结点p不存在或结点p的后继结点不存在
  else
  {
    q = p->next;
    x = q->data;       //暂存被删结点
    p->next = q->next; //摘链
    delete q;
    return x;
  }
}

//5.单链表的析构函数算法
template <class T>
LinkLIst:: LinkList()
{
  p=first;  //工作指针p初始化
  while(p)  //释放单链表的每一个结点的存储空间
  {
    q=p;    //暂存被释放结点
    p=p->next;  //工作指针p指向被释放结点的下一个结点，使单链表不断开
    delete q;
  }
}

/* 3.1.2.1.顺序栈 */
const int StackSize=10;
template <class T>  //定义模板类SeqStack
class SeqStack
{
  public;
    SeqStack(){top=-1;} //构造函数，栈的初始化
    SeqStack(){}      //构造函数
    void Push(T x);   //将元素x入栈
    T Pop();          //将栈顶元素弹出
    T GetTop(){if(top!=-1) return data[top];} //取栈顶元素(并不删除)
    bool Empty(){top==-1 ? return 1: return 0;} //判断栈是否为空
  private:
    T data[StackSize];  //存放栈元素的数组
    int top;            //栈顶指针，指示栈顶元素在数组中的下标
  
};

// 3.1.2.1.1. 入栈
template <class T>
void SeqStack::Push(T x)
{
  if(top==StackSize-1) throw "上溢";
  top++;
  data[top]=x;
}

// 3.1.2.1.2. 出栈
template <class T>
void SeqStack::Pop()
{
  if(top==-1) throw '下溢';
  x=data[top--];
  return x;
}

/* 3.1.2.3. 共享栈类声明 */
const int StackSize=100;
template <class T>
class BothStack
{
  public:
    BothStack(){top1=-1; top2=StackSize;} //构造函数，将两个栈分别初始化
    BothStack(){}
    void Push(int i, T x)
    T Pop(int i);
    T GetTop(int i);
    bool Empty(int i);
  private:
    T data[StackSize];  //存放两个栈的数组
    int top1, top2;   //栈顶指针，分别指向各自的栈顶元素在数组中的下标
};

// 3.1.2.3.1. 共享栈入栈Push
/* 1.如果栈满， 则抛出上溢异常；
2.判断是插在栈1还是栈2：
  2.1 若在栈1插入，则栈顶指针top1加1，在top1处填入x；
  2.2 若在栈2插入，则栈顶指针top2加1，在top2处填入x； */
template <class T>
void BothStack::Push(int i, T x)
{
  if(top1==top2-1) throw "上溢";
  if(i==1) data[++top1]=x;
  if(i==2) data[--top2]=x;
}


/* 3.1.3.2 链栈的实现 */
template <class T>
class LinkStack
{
  public:
    LinkStack(){top=NULL;}
    LinkStack();
    void Push(T x);
    T Pop();
    T GetTop(){if(top!=NULL) return top->data;}
    bool Empty(){top==NULL? return 1: return 0;}
  private:
    Node<T> *top; //栈顶指针即链栈的头指针
}

/* 3.1.3.2.1 链栈的插入算法C++实现 */
template <class T>
void LinkStack::Push(T x)
{
  s=new Node<T>; s->data=x; //申请一个数据域为x的结点s
  s->next=top; top=s;   //将结点s插在栈顶
}

/* 3.1.3.2.2 链栈的删除算法C++实现 */
template <class T>
T LinkStack::Pop()
{
  if(top==NULL) throw "下溢";
  x=top->data;    //暂存栈顶元素
  p=top; top=top->next; //将栈顶结点摘链
  delete p;
  return x;
}

/* 3.1.3.2.3 链栈的析构函数C++实现 */
template <class T>
LinkStack:: LinkStack()
{
  while(top)
  {
    p=top->next;
    delete top;
    top = p;
  }
}

/* 3.2.2.2. 循环队列的实现 */
const int QueueSize=100;
template <class T>
class CirQueue
{
  public:
    CirQueue(){front=rear=0;}
    CirQueue(){};
    void EnQueue(T x);
    T DeQueue();
    T GetQueue();
    bool Empty(){front==rear? return 1 : return 0;}
  private:
    T data[QueueSize];  //存放队列元素的数组
    int front.rear;     //队头和队尾指针，分别指向队头元素的前一个位置和队尾元素的位置
}

// 3.2.2.2.1. 循环队列的入队EnQueue
template <class T>
void CirQueue::EnQueue(T x)
{
  if((rear+1) % QueueSize == front) throw "上溢";
  rear=(rear+1) % QueueSize;  //队尾指针在循环意义下加1
  data[rear]=x;               //在队尾处插入元素
}

// 3.2.2.2.2. 循环队列出队DeQueue
template <class T>
T CirQueue::Dequeue()
{
  if (rear==front) throw "下溢";
  front=(front+1)%QueueSize;    //队头指针在循环意义下加1
  return data[front];
}

// 3.2.2.2.3. 读取队头元素算法GetQueue
template <class T>
T CirQueue::GetQueue
{
  if(rear==front) throw "下溢";
  i=(front+1) % QueueSize;  //不要给队头指针赋值
  return data[i];
}

/* 例3-1 递归经典问题---汉诺塔算法Hanoi */
void Hanoi(int n, char A, char B, char C)
{
  if(n==1) Move(A, C);  //Move是一个抽象操作，表示将碟子从A移到C上
    else{
      Hanoi(n-1, A, C, B);
      Move(A, C);
      Hanoi(n-1, B, A, C);
    }
}
























































