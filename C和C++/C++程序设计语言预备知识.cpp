include <iostream.h>	//含有cout函数的原型

int GetMax(int x, int y)	/*比较两个数的大小并返回较大者*/
{
    if (x>=y) return x;
    else return y;
}

void main()
{
    cout<<GetMax(5, 8);    //调用函数GetMax
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
if(x>=0){
    if(x>0) x=0;
}
else{
    x++;
} //块语句解决了else配对问题

/* 2.2.2 顺序表的实现 C++模板机制 */
const int MaxSize=100;
template <class T>
class SeqList       //定义模板类SeqList
{
public:
  SeqList(){length=0;}  //无参构造函数
  SeqList(T a[], int n);    //有参构造函数
    SeqList(){}         //析构函数为空
  int Length(){return length;}  
  T Get(int i);         //按位查找
  int Locate(T x);      //按值查找
  void Insert(int i, T x);  //第i个位置插入值为x的元素
  T Delete(int i);      //删除第i个元素
  void PrintList();     //遍历线性表

private:
  T data[MaxSize];      //存放数据元素的数组
  int length;           //线性表的长度
};

// 2.2.2.1 顺序表有参构造函数 SeqList
template <class T>
SeqList:: SeqList(T a[], int n)
{
  if (n>MaxSize) throw "参数非法";
  for(i=0; i<n; i++)
    data[i]=a[i];
  length=n;
}

// 2.2.2.2 顺序表插入算法 Insert
template <class T>
void SeqList::Insert(int i, T x)
{
  if(length>=MaxSize) throw "上溢";
  if(i<1 || i>length+1) throw "位置异常";
  for(j=length; j>=i; j--)
    data[j]=data[j-1]; //注意第j个元素存在数组下标为j-1处
  data[i+1]=x;
  length++;
}

// 2.2.2.3 顺序表删除算法 Delete
template <class T>
void SeqList::Delete(int i, T x)
{
  if(length==0) throw "下溢";
  if(i<1||i>length) throw "位置异常";
  x=data[i-1];
  for(j=i; j<length; j++)
    data[j-1]=data[j];
  length--;
  return x;
}

// 2.2.2.4 查找
// 2.2.2.4.1 按位查找
template <class T>
T SeqList::Get(int i)
{
  if(i<1 || i>length) throw "查找位置非法";
    else return data[i-1];
}

// 2.2.2.1.2 按值查找 Locate
template <class T>
int SeqList::Locate(T x)
{
  for(i=0; i<length; i++)
    if(data[i]==x) return i+1;    //下标为i的元素等于x，返回其序号i+1
  return 0;                       //退出循环，查找失败
}























































