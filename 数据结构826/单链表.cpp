/*struct LNode{   //���嵥����������
    ElemType data; //ÿ���ڵ���һ������Ԫ�� 
    struct LNode *next; // ָ��ָ����һ���ڵ� 
}; 


typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

typedef struct LNode LNode;
typedef struct LNode *LinkList;
Ҫ��ʾһ��������ʱ��ֻ������һ��ͷָ��L,ָ������ĵ�һ�����
LNode*L; //����һ��ָ�������һ������ָ��
��
LinkList L; //����һ��ָ�������һ������ָ�� --����ɶ��Ը�ǿ
*/

typedef struct LNode{	//���嵥����������
    ElemType data;		//������
    struct LNode *next;	//ָ����
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

//ͷ�巨������������㷨��
LinkList List_HeadInsert(LinkList &L){ //������������
    LNode *s; int x;
    L=(LinkList)malloc(sizeof(LNode)); //����ͷ���
    L->next=NULL; //��ʼΪ������
    scanf("%d", &x); //�������ֵ
    while(x!=9999){  //����9999��ʾ���� 
        s=(LNode*)malloc(sizeof(LNode)); //�����½�㣬��ϵͳ����һ��LNode�͵Ľ�㣬ͬʱ���ý�����ʼλ�ø���ָ�����s
        s->data=x;	//~~~s��������ָ��xֵ
        s->next=L->next;	//~~~s��nextָ��ָ��ͷ����nextָ��ĵط�
        L->next=s;	//���½�������У�LΪͷָ��~~~��ͷ����nextָ�룬ָ��s���
        scanf("%d", &x); 
    } 
    
} 


typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//��ʼ��һ���յĵ�����
bool InitList(LinkList &){
    L=Null; //�ձ���ʱ��û���κν�� -��ֹ������
    return true;     
} 

void test(){
    LinkList L; //����һ��ָ�������ָ�� 
}



bool InitList(LinkList &L){
    L = (LNode *) malloc(sizeof(LNode));  //����һ��ͷ���,��malloc���صĵ�ַ���ظ�L��ָ��data 
    if (L==NULL)
        return false;
        L->next=NULL;  // ��ͷ����ָ��������ΪNULL��ͷ��㲻�洢���� 
        return true; 
}

void test(){
    LinkList L;  //����һ��ָ�������ָ��
    //��ʼ��һ���ձ�
    InitList(L)
    //... 
}

//�жϵ������Ƿ�Ϊ��(��ͷ��㣩 
bool Empty(LinkList L) {
    if (L->next == NULL)
        return true;
    else
        return false;
}


 

//��λ�����(��ͷ���)
//�ڵ�i��λ�ò���Ԫ��e(��ͷ���)
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    LNode *p;  //ָ��pָ��ǰɨ�赽�Ľ��
    int j=0;  //��ǰpָ����ǵڼ������
    p = L;  //Lָ��ͷ��� 
    while (p!=NULL && j<i-1){  //ѭ���ҵ���i-1�����
        p=p->next;
        j++; 
    }
    if(p==NULL)  //iֵ���Ϸ�~
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next=p->next;
    p->next=s;  //�����s����p֮��~������ s->next=p->next;�ߵ� 
    return true;  //����ɹ�
     
} 

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//����:1.���i=1(���ڱ�ͷ 



/*
��λ����~������Ų��ҽ��ֵ 
*/
LNode * GetElem(LinkList L, int i){ //��λ���ң����ص�i��Ԫ��(��ͷ���~��0��)
    if(i<0)
        return NULL;
    LNode *p;   //ָ��pָ��ǰɨ�赽�Ľ��
    int j=0;    // ��ǰpָ����ǵڼ������
    p = L;      // Lָ��ͷ��㣬ͷ����ǵ�0�����
    while (p!=NULL && j<i){  //ѭ���ҵ���i�����~ p��Ϊ����j<iʱ
        p=p->next;
        j++; 
    } 
    return p;
} 

// �������еİ�λ����
LNode * GetElem(LinkList L, int i){
    int j=1;	//��������ʼΪ1
    LNode *p=L->next;	//ͷ���ָ�븳��p
    if(i==0)
        return L;	//��i����0���򷵻�ͷ���
    if(i<1)
        return NULL;	//��i��Ч���򷵻�NULL
    while(p!=NULL && j<i){	//�ӵ�i����㿪ʼ�ң����ҵ�i�����
        p=p->next;
        j++;
    } 
    return p;	//���ص�i������ָ�룬��i���ڱ��򷵻�NULL
} 
 

//�ڵ�i��λ�ò���Ԫ��e(��ͷ���)
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    LNode *p = GetElem(L, i-1); //1) ָ��pָ��ǰɨ�赽�Ľ��
    int j=0; // ��ǰpָ����ǵڼ������
    p = L;  // Lָ��ͷ��㣬ͷ����ǵ�0���ڵ�(��������)
    while (p!=NULL && j<i-1){ //ѭ���ҵ���i-1�����
        p=p->next;
        j++; 
    } 
    if(p==NULL)  //iֵ���Ϸ�
//        return false;
        return InsertNextNode(p, e);  //p���������Ԫ��e��β�巨 
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next; //��s��nextָ��ָ��p��nextָ����ָ�ĵط�
    p->next = s;  //�����s����p֮��
    return true; // ����ɹ� 
} 

//�ڵ�i��λ��ɾ��Ԫ��e
bool ListDelete(LinkList &L, int i, ElemType &e){
    if(i<1)
        return false;
    LNode *p;   // ָ��pָ��ǰɨ�赽�Ľ��
    int j=0;    // ��ǰpָ����ǵڼ������
    p = L;      // Lָ��ͷ��㣬ͷ����ǵ�0�����(��������)
    while(p!=NULL && j<i-1){  //ѭ���ҵ���i-1�����
        p=p->next;
        j++; 
    } 
    if(p==NULL) //iֵ���Ϸ�
        return false;
    if(p->next == NULL) // ��i-1�����֮�������������
        return false;
    LNode *q=p->next;   // ��qָ��ɾ�����
    e = q->data;        // ��e����Ԫ�ص�ֵ~��p��������ָ��e
    p->next=q->next;    // ��*q��������"�Ͽ�"
    free(q);            // �ͷŽ��q�Ĵ洢�ռ�
    return true;        // ɾ���ɹ� 
} 

//��ֵ���ң��ҵ�������==e�Ľ��
LNode * LocateElem(LinkList L, ElemType e){
    LNode *p = L->next; //ͷ���ָ�븳��p
    while (p!=NULL && p->data != e)	    //�ӵ�1����㿪ʼ����������Ϊe�Ľ��
        p = p->next;	//��������򲻷��ϣ���pָ��ָ����һ������
    return p;   //�ҵ��󷵻ظý��ָ�룬���򷵻�NULL 
} 


// ���ĳ���
int Length(LinkList L){
    int len = 0; //ͳ�Ʊ�
    LNode *p = L;
    while (p->next != NULL){
        p = p->next;
        len++;
    } 
    return len;
} 

/*
��λ�����(��ͷ���) 
*/
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    LNode *p;   //ָ��pָ��ǰɨ�赽�Ľ��
    int j=0;    // ��ǰpָ����ǵڼ������
    p = L;      // Lָ��ͷ��㣬ͷ����ǵ�0�����(��������)
    while (p!=NULL && j<i-1){  //ѭ���ҵ���i-1�����
        p=p->next;
        j++; 
    } 
    if(p==NULL)     //iֵ���Ϸ�
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next=p->next;
    p->next=s;  //�����s����p֮��
    return true; //����ɹ�
    
}

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList; 

/*
��λ�����(����ͷ���)
*/
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    if(i==1){   //�����1�����Ĳ�����������������ͬ
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next=L;
        L=s;   //ͷָ��ָ���½��
        return true; 
    }
    LNode *p;   //ָ��pָ��ǰɨ�赽�Ľ��
    int j=1;    // ��ǰpָ����ǵڼ������
    p = L;      // pָ���1�����(ע�⣺����ͷ���)
    while (p!=NULL && j<i-1){   //ѭ���ҵ���i-1�����
        p=p->next;
        j++; 
    } 
    if(p=NULL)  //iֵ���Ϸ�
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next=p->next;
    p->next=s;
    return true; //����ɹ� 
}


/*
ָ�����ĺ�����
*/ 
//������:��p���֮�����Ԫ��e
bool InsertNextNode (LNode *p, ElemType e){
    if (p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s==NULL)    //�ڴ����ʧ��,�ɲ�д�����ڴ治��ʱ���ܷ���ʧ�� 
        return false; 
    s->data = e;    //�ý��s��������Ԫ��e
    s->next=p->next;
    p->next=s;      // �����s����p֮��
    return true; 
} 


//�ڵ�i��λ�ò���Ԫ��e(��ͷ���) 
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1)
        return false;
    LNode *p; //ָ��pָ��ǰɨ�赽�Ľڵ�
    int j=0; //��ǰpָ����ǵڼ������
    p = L;  //Lָ��ͷ��㣬ͷ����ǵ�0�����(��������)
    while(p!=NULL && j<i-1){    //ѭ���ҵ���i-1�����
        p=p->next;
        j++; 
    } 
    if(p==NULL) //iֵ���Ϸ�
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;    //�����s����p֮��
    return true;    //����ɹ� 
// ���ϴ���ɸ�Ϊ����InsertNextNode(p, e) 
return InsertNextNode(p, e);

}

typedef struct LNodel{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;


//������:��p���֮�����Ԫ��e
bool InsertNextNode(LNode *p, ElemType e){
    if (p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s==NULL)    //�ڴ����ʧ�� 
        return false;
    s->data = e;    //�ý��s��������Ԫ��e 
    s->next=p->next;
    p->next=s;  //�����s����p֮��
    return true; 
} 


/*
ָ������ǰ�����
*/
//ǰ�����:��p���֮ǰ����Ԫ��e
bool InsertPriorNode(LNode *p, ElemType e){
    if (p==NULL)
        return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    if (s==NULL)    //�ڴ����ʧ��
        return false;
    s->next=p->next;
    p->next=s;      //�½��s����p֮�� 
    s->data=p->data; //��p��Ԫ�ظ��Ƶ�s��
    p->data=e;      //��p��Ԫ�ظ���Ϊe
    return true 
} 


 
//��������ǰ�����:��p���֮ǰ����Ԫ��e
bool InsertPriorNode (LNode *p, LNode *s){
    if(p==NULL || s==NULL)
        return false;
    s->next=p->next;
    p->next=s;  //s����p֮��
    ElemType temp=p->data;  //���������򲿷�
    p->data=s->data;
    s->data=temp;
    return true; 
}


/*
��λ��ɾ��(��ͷ���) 
*/ 
bool ListDelete(LinkList &L, int i, ElemType &e){
    if(i<1)
        return false;
    LNode *p;   //ָ��pָ��ǰɨ�赽�Ľ��
    int j=0;    //��ǰpָ����ǵڼ������
    p=L;        //Lָ��ͷ��㣬ͷ����ǵ�0�����(��������)
    while (p!=NULL && j<i-1){//ѭ���ҵ���i-1�����
        p=p->next;
        j++; 
    } 
    if(p==NULL) //iֵ���Ϸ�
        return false;
    if(p->next == NULL) //��i-1�����֮�������������
        return false;
    LNode *q=p->next;   //��qָ��ɾ�����
    e = q->data;        // ��e����Ԫ�ص�ֵ
    p->next=q->next;    //��*q��������"�Ͽ�"
    free(q);            //�ͷŽ��Ĵ洢�ռ�
    return true;        //ɾ���ɹ�     
}

bool DeleteNode (LNode *p){
    if (p==NULL)
        return false;
    LNode *q=p->next;  //��qָ��*p�ĺ�̽��
    p->data=p->next->data   //�ͺ�̽�㽻��������
    p->next=q->next;    //��*q��������"�Ͽ�"
    free(q);            //�ͷź�̽��Ĵ洢�ռ� 
    return true; 
}


/*β�巨����������*/
typedef struct LNode{       //���嵥���������� 
    ElemType data;          //ÿ�������һ������Ԫ�� 
    struct LNode *next;     //ָ��ָ����һ����� 
}LNode, *LinkList;


//��ʼ��һ��������(��ͷ���)
bool InitList(LinkList &L){
    L=(LNode *) malloc(sizeof(LNode));  //����һ��ͷ���
    if (L==NULL)
        return false;
    L-->next = NULL;    // ͷ���֮��չʾ��û�н��
    return true; 
} 

void test(){
    LinkList L; //����һ��ָ�������ָ��
    //��ʼ��һ���ձ�
    InitList(L);
    //....��������... 
}

/*β�巨������������㷨*/
LinkList List_TailInsert(LinkList &L){  //������������ 
    int x;  //��Ԫ��Ϊ���� 
    L=(LinkList)malloc(sizeof(LNode));  //����ͷ���
    LNode *s, *r=L; //rΪ��βָ��~~~���һ��β���~~~sΪͷָ��
    scanf("%d", &x); //�������ֵ
    while(x!=9999){
        s=(LNode *)malloc(sizeof(LNode));   //�����½�㣬��r���֮�����Ԫ��x 
        s->data=x;	//~~~s��������ָ��xֵ
        r->next=s;	//~~~r��nextָ��ָ��sֵ
        r=s;    //rָ���µı�β��㣬��Զ����rָ�����һ�����
        scanf("%d", &x); 
    }
    r->next=NULL;   //β���ָ���ÿ�
    return L; 
}

/*ͷ�巨����������*/
//������: ��p���֮�����Ԫ��e
bool InsertNextNode(LNode *p, ElemType e){
    if (p==NULL)
        return false;
    LNode *s = (LNode *)malloc(siezof(LNode));
    if (s==NULL)    //�ڴ����ʧ��
        return false;
    s->data=e;  //�ý��s��������Ԫ��e
    s->next=p->next;    
    p->next=s;  //�����s����p֮��
    return true; 
} 


LinkList List_HeadInsert(LinkList &L){  //������������
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof(LNode));  //����ͷ���
    L->next=NULL;       //��ʼΪ���������û����䣬���ܻ�ָ��������
    scanf("%d", &x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));    //�����½��
        s->data=x;
        s->next=L->next;
        L->next=s;  //���½�������У�LΪͷָ��
        scanf("%d", &x); 
    }     
    return L;
    
}

/*˫����*/
typedef struct DNode{       //����˫���������� 
    ElemType data;          //������ 
    struct DNode *prior, *next; //ǰ���ͺ��ָ�� 
}DNode, *DLinklist;


/*˫����ĳ�ʼ��(��ͷ���)*/
//��ʼ��˫����
bool InitDLinkList(DLinklist, &L){	// DLinklist�ȼ���DNode *
    L = (DNode *)malloc(sizeof(DNode)); //����һ��ͷ���
    if (L==NULL)
        return false;
    L->prior=NULL;      //ͷ����prior��Զָ��NULL 
    L->next=NULL;       //ͷ���֮����ʱ��û�н�� 
    return true;
} 


void testDLinkList(){    
    //��ʼ��˫����
    DLinklist L;
    INitDLinkList(L); 
	// ��������
}

/*˫����Ĳ���*/
//��p���֮�����s���
bool InsertNextNode(DNode *p, DNode *s){
	if (p==NULL || s==NULL)	//�Ƿ�����
		return false;
	s->next=p->next;	// (1)s����nextָ�룬ָ����p����nextָ����ͬ��λ��
	if (p->next != NULL) //���p����к�̽��~���p����ʱû�к�̽�㣬�Ͳ����޸ĺ�̽���ǰ��ָ��
		p->next->prior=s; // (2)�޸ĺ�̽���ǰ��ָ��
	s->prior=p;	// (3)s����ǰ��ָ�룬ָ��p���
	p->next=s;	// (4)��4��������(1)(2)֮�󣬽�p���ĺ���ָ�룬ָ��s���
	return true;
}

/*˫�����ɾ��*/
//ɾ��p���ĺ�̽��
bool DeleteNextDNode(DNode *p){
	if (p==NULL)	return false;
	DNode *q = p->next;	//�ҵ�p�ĺ�̽��q
	if (q==NULL)	return false;	//pû�к��
	p->next=q->next;	//p����nextָ�룬ָ����q����nextָ����ͬ��λ�ã�pָ��NULL
	if (q->next!=NULL)
		q->next->prior=p;	//�����޸�q����̽���ǰ��ָ�룬��q���ĺ�̽�㲻���ڣ������㣬������
	free(q);			// �ͷŽ��ռ�
	return true;
}

//�ͷ�˫����
void DestroyList(Dlinklist &L){
	//ѭ���ͷŸ������ݽ��
	while (L->next != NULL) //��һ��whileѭ����������ͷ��㿪ʼɾ����ֱ��NULL
		DeleteNextDNode(L);
	free(L);	//�ͷ�ͷ���
	L=NULL;		//ͷָ��ָ��NULL
}

/*˫����ı���*/
//�������
while(p != NULL){
	//�Խ��p����Ӧ�������ӡ
	p=p->next;
}
//ǰ�����
while(p != NULL){
	//�Խ��p����Ӧ�������ӡ
	p=p->next;
}
//ǰ�����(����ͷ���)
while(p->prior != NULL){	//����ͷ��㣬ֻ������ݽ����д���
	//�Խ��p����Ӧ�������ӡ
	p=p->next;
}





//�ж�˫�����Ƿ�Ϊ��(��ͷ���)
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

/*��̬����*/
//����������ʵ��
#define MaxSize 10  //��̬�������󳤶� 
typedef struct {    //��̬����ṹ���͵Ķ��� 
    ElemType data;  //�洢����Ԫ�� 
    int next;       //��һ��Ԫ�ص������±� 
}SLinkList[MaxSize]; 


void testSLinkList(){
    SLinkList a;
    //...�������� 
} 




// �Բ������֤
#define MaxSize 10 //��̬�������󳤶�
struct Node{      //��̬����ṹ���͵Ķ���
    int data;     //�洢����Ԫ��      
    int next;     //��һ��Ԫ�ص������±� 
};

typedef struct{ //��̬����ṹ���͵Ķ��� 
    int data;   //�洢����Ԫ�� 
    int next;   //��һ��Ԫ�ص������±� 
}SLinkList[MaxSize];

void testSLinkList(){
    struct Node x;
    printf("sizeX=%d\n", siezeof(x));
    
    struct Node a[MaxSize];
    printf("sizeA=%d\n", sizeof(a));
    
    SLinkList b;
    printf("sizeB=%d\n", sizeof(b));
}


/*��������---��*/
typedef struct{
    ElemType *data;
    int MaxSize;
    int length;
}SeqList;

L.data={ElemType *}malloc(sizeof(ElemType)* InitSize);
free(L.data); 




































