/*设计在单链表中删除值相同的多余结点的算法*/
LinkList DeleteSame(LinkList L)
{
    LNode *p=L->next;//从第一个节点开始
    while(p!=NULL)
    {
        LNode *s=p->next,*q=p;
        while(s!=NULL)
        {
            if(s->data==p->data)
            {
                q->next=s->next;
                s=s->next;
            }
            else
            {
                q=q->next;
                s=s->next;
            }
        }
        p=p->next;
    }
}


/*删除单链表中的重复节点（删除多余项）

小僧_ 2016-06-20 13:46:03  24886  收藏 30
分类专栏： 算法 文章标签： 删除单链表的重复节点 删除多余项 单链表
版权
题目：如何删除单链表中的重复节点（即保证每个元素只出现一次，删除多余的，且后来出现的元素）。
一个没有排序的单链表，如 list = {a, 1, x, b, e, f, f, e, a, g, h, b, m}，请去掉重复项，并保留原顺序，以上链表去掉重复项后为 newList = {a, 1, x, b, e, f, g, h, m}，请写出一个高效的算法。

思路分析：
第一种方法：因为要求算法高效，且考虑到时间比空间更重要，因此使用hash法。
步骤：
（1）建立一个hash表，key为链表中已经遍历的节点内容，初始时为空。
（2）从头开始遍历单链表中的节点。
<1> 如果节点内容已经在hash表中存在，则删除此节点，继续向后遍历。
<2> 如果节点内容不在hash表中，则保留此节点，将节点内容添加到hash表中，继续向后遍历。
（3）注意点：
<1> 删除时需要知道前一节点。
<2> 此处链表中存储的是char型变量，所以哈希表为含有256个元素的数组。
<3> 如果存储的是其他数据类型，则可以使用STL中的hash_set容器。

第二种方法：如果不能使用额外的存储空间，直接在原始链表上进行操作。（非递归）
步骤：
（1）建立指针p，用于遍历链表；
（2）建立指针q，q遍历p后面的结点，并与p数值比较；
（3）建立指针r，r保存需要删掉的结点，再把需要删掉的结点的前后结点相接。由此去掉重复值。

第三种方法：递归实现。

具体实现如下：
*/
#include <iostream>

// 单链表节点结构如下
typedef struct node
{
    char data;
    struct node *next;
} NODE;


// 尾插法创建单链表(带头节点)
NODE *createEnd(char arr[], int len)
{
    NODE *head = (NODE *)malloc(sizeof(NODE)); // 生成头节点
    head->next = NULL;
    NODE *end = head;  // 尾指针初始化

    for (int i = 0; i < len; i++)
    {

        NODE *p = (NODE *)malloc(sizeof(NODE)); // 为每个数组元素建立一个节点
        p->data = arr[i];
        end->next = p;  // 将节点p插入到终端节点之后
        end = p;
    }

    end->next = NULL;  // 单链表建立完毕，将终端节点的指针域置空

    return head;
}

// 单链表打印
void print(NODE *head)
{
    if (head == NULL) return;

    NODE *p = head->next;
    while (p != NULL)
    {
        printf("%c  ", p->data);
        p = p->next;
    }
}


// 第三种方法：递归方法
NODE *delSame_3(NODE *head)
{
    NODE *p, *temp = head; // 递归过程中head是在不断变化的，但初始时temp都指向新的head。
    if (head->next == NULL)
        return head;

    head->next = delSame_3(head->next); // 递归到head->next指向链表的尾节点；此时head指向链表倒数第二个节点。
    p = head->next; // 让p指向head的下一个节点，注意此时temp＝head；

    while (p != NULL)
    {
        if (head->data == p->data) // 单次递归中，head是不变的，每次都把head的数据和head之后所有节点的数据比较，若相同，则删除该节点。
        {
            temp->next = p->next;
            free(p);
            p = temp->next;
        }
        else
        {
            p = p->next;
            temp = temp->next; // temp初始时是指向新的head的，之后作为临时变量，随着p一起后移，始终作为p的前驱节点，是为了当p节点的数据和head数据一样时，在删除p节点时，用temp->next来保存p的后继节点。
        }
    }

    return head;
}


// 第二种方法：非递归实现去重
NODE *delSame_2(NODE *head)
{
    NODE *p,*q,*r;
    p = head->next; // 适用于有头节点的单链表；对于不带头节点的单链表，此处改为 p＝head 即可。
    while(p != NULL)    // p用于遍历链表
    {
        q = p;
        while(q->next != NULL) // q遍历p后面的结点，并与p数值比较
        {
            if(q->next->data == p->data)
            {
                r = q->next; // r保存需要删掉的结点
                q->next = r->next;   // 需要删掉的结点的前后结点相接
                free(r);
            }
            else
                q = q->next;
        }

        p = p->next;
    }

    return head;
}


// 第一种方法：hash表去重
NODE *delSame(NODE *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    const int size = 256;
    unsigned int count[size]; // 可用 unsigned int count[size] = {0}; 将数组中每一个元素都初始化为0。
    for (int i = 0; i < size; i++) // 可能上述方法，不一定对所有编译器都适用，所以采用循环的方式更稳妥。
        count[i] = 0;

    // count[(unsigned char)(head->data)] = 1; // 当使用没有头节点的单链表时，打开此行代码即可。

    NODE *p = head; // head是单链表的头节点，注意，头节点没有数据，它的存在仅仅是为了方便计算。
    NODE *q = p->next;
    NODE *r;
    while (q != NULL)
    {
        if (count[(unsigned char)(q->data)] == 0)
        {
            count[(unsigned char)(q->data)] = 1;
            p = q;
            q = q->next; // 始终让p作为q的前驱节点
        }
        else
        {
            r = q; // r存储要删除的节点
            p->next = q->next;
            q = p->next; // 始终让p作为q的前驱节点
            free(r);
        }
    }

    return head;

}

int main(int argc, const char * argv[])
{

    char arr[] = "a1xbeffeaghbm";
    int len = (int)strlen(arr);

    NODE *head = createEnd(arr, len);

    // 去重之前
    print(head);
    printf("\n");

    delSame(head);

    // 去重之后
    print(head);
    printf("\n");


    return 0;
}
/*2010.6*/
void MiniValue (LinkedList A)

//A是数据域为正整数且无序的单链表，本算法查找最小值结点且打印。若最小值结点的数值是奇数，则与后继结点值交换；否则，就删除其直接后继结点。

{
    p=A->next; //设A是头结点的头指针，p为工作指针。

    pre=p; //pre指向最小值结点，初始假定首元结点值最小。

    while(p->next!=null)//p->next是待比较的当前结点。

    {
        if(p->next->data < pre->data) pre=p->next;

        p=p->next; //后移指针

    }

    printf(“最小值=%d\n”，pre->data);

    if (pre->data%2!=0) //处理奇数

            if(pre->next!=null) //若该结点没有后继，则不必交换

    {
        t= pre->data;    //交换完毕
        pre->data=pre->next->data;
        pre->next->data=t;
    }

    else//处理偶数情况

        if(pre->next!=null)//若最小值结点是最后一个结点，则无后继

        {
            u=pre->next;    //释放后继结点空间
            pre->next=u->next;
            free(u);
            }

/*2015.17*/
//5. 在任意位置插入数据
bool Insert(ListNode* &pHead, int pos, int val){
    int count = 0;    //一定要对其初始化
    if (pos <= 0)
        return 0;
    else if (pHead == NULL){
        if (pos == 1){
            ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
            cur->val = val;
            cur->next = NULL;
            pHead = cur;
        }
        else
            return false;
    }
    else{
        ListNode* cur = pHead;
        ListNode* pNode = pHead;
        ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
        while (cur != NULL){
            ++count;
            if (pos == count){
                if (pHead == cur){
                    
                    temp->next = pHead;
                    pHead = temp;
                    temp->val = val;
                    break;
                }
                else{
                    temp->next = cur;
                    pNode->next = temp;
                    temp->val = val;
                    break;
                }

            }
            
            pNode = cur;
            cur = cur->next;
            
        }
        if (pos == count + 1)
            pNode->next = newNode(val);            
        else if (pos > count + 1){
            free(temp);
            return false;
        }        
    }
    return true;
}

//6.头插
pNode PushFront(pNode* pHead, DataType data)
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return NULL; 
	}
	else
	{
		pNode pnode = *pHead;
		while (pnode->_pNext)
		{
			pnode = pnode->_pNext;
		}
		pnode->_pNext = BuyNode(data);
	}
	return;
}


//10.尾删
pNode PopDel(pNode pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	else if ((pHead)->_pNext == NULL)
	{
		free(pHead);
		pHead = NULL;
	}
	else
	{
		pNode pTail = pHead;
		pNode pPos = pTail;
		while ( pTail->_pNext)
		{
			pPos = pTail;
			pTail = pTail->_pNext;
		}
		free(pTail);
		pTail = NULL;
		pPos->_pNext = NULL;
	}
 
}

/*2012.17*/
/*    
* Copyright (c) 2016, 烟台大学计算机与控制工程学院    
* All rights reserved.    
* 文件名称：LinkList.cpp    
* 作    者：单昕昕    
* 完成日期：2016年4月14日    
* 版 本 号：v1.0    
* 问题描述：有一个不带头节点的单链表，设计递归算法：
            （1）求以h为头指针的单链表的节点个数
            （2）反向显示以h为头指针的单链表的所有节点值
* 程序输入：数组A[n]。   
* 程序输出：n个元素的平均值。  
*/      
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <time.h>
#include <stdlib.h>
using namespace std;
//不带头节点的单链表的节点类型
typedef struct Node
{
    int data;
    struct Node *next;
} LinkList;
LinkList *h;
void Create(LinkList *&h,int a[],int n)
{
    //建立一个不带头节点的单链表
    int i;
    LinkList *s,*r;
    h=(LinkList *)malloc(sizeof(LinkList));
    h->data=a[0];
    h->next=NULL;
    r=h;
    for(i=1; i<n; ++i)
    {
        s=(LinkList *)malloc(sizeof(LinkList));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
//求以h为头指针的单链表的节点个数
int Number(LinkList *h)
{
    if(h==NULL)
        return 0;
    else
        return 1+Number(h->next);
}
//反向显示以h为头指针的单链表的所有节点值
void Display(LinkList *h)
{
    if(h==NULL)
        return ;
    else
    {
        Display(h->next);
        cout<<h->data<<" ";
        //如果是正向显示的话，cout写在Display递归上面
    }
}
int main()
{
    int a[10]= {0,1,2,3,4,5,6,7,8,9};//作为预设单链表中的data值
    Create(h,a,10);//尾插法将a数组中的值插入链表
    cout<<"以h为头指针的单链表的节点个数=";
    cout<<Number(h)<<endl;
    cout<<"反向显示以h为头指针的单链表的所有节点值"<<endl;
    Display(h);
    return 0;
}


/*2020.12,递归判断是否为二叉排序树*/
int predt = -300;	//predt小于树中的任何值，predt始终记录着当前所访问结点的前驱的值
int judBST(BTNode *bt)
{
	int b1, b2;
	if (bt == NULL)	//空树是二叉排序树
	{
		return 1;
	}
	else
	{
		b1 = judBST(bt->lchild);	//递归地判断左子树是否是二叉排序树；
		if(b1 == 0 || predt > bt->key)	//左子树不是二叉排序树/predt大于当前根结点值，则该树不是二叉排序树
			return 0;
		predt = bt->key;	//将要访问右子树根的时候，predt记录下当前结点根结点的值
		b2 = judBST(bt->rchild);	//递归地判断右子树是否为二叉排序树
		return b2;
	}
}

















