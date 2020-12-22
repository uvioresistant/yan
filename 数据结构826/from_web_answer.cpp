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

    for (int i = 0; i < len; i++) {

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
    while (p != NULL) {
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

int main(int argc, const char * argv[]) {

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