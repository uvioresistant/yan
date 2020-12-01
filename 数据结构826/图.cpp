/*�ڽӾ���*/ 
# define MaxVertexNum 100       //������Ŀ�����ֵ 
typedef struct{
    char Vex[MaxVertexNum];     //�����~�����п��Դ�Ÿ����ӵ���Ϣ 
    int Edge[MaxVertexNum][MaxVertexNum];   //�ڽӾ��󣬱߱��ɸ���bool�ͻ�ö���ͱ�����ʾ�� 
    int vexnum, arcnum;         //ͼ�ĵ�ǰ�������ͱ���/���� 
}MGraph;

// �ڽӾ��󷨴洢��Ȩͼ(��)
# define MaxVertexNum 100           //������Ŀ�����ֵ 
# define INFINITY ����intֵ       //�궨�峣��"����"������int������ֵ��ʾ"����" 
typedef char VertexType;            //������������� 
typedef int EdgeType;               //��Ȩͼ�У�����Ȩֵ���������� 
tepedef struct{
    VertexType Vex[MaxVertexNum];   //���� 
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //�ߵ�Ȩ 
    int vexnum, arcnum;             //ͼ�ĵ�ǰ�������ͻ��� 
}MGraph;

/*�ڽӱ�(˳��+��ʽ�洢)*/
//����
typedef struct VNode{
    VertexType data;    //������Ϣ
    ArcNode *first;     //��һ����/�� 
}VNode, AdjList[MaxVertexNum];

//��/��
typedef struct ArcNode{
    int adjvex;             //��/��ָ���ĸ���� 
    struct ArcNode *next;   //ָ����һ������ָ�� 
    //InfoType info;        //��Ȩֵ 
}ArcNode; 

//���ڽӱ�洢��ͼ
typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}AlGraph; 

/*ͼ�Ĺ�����ȱ���*/
bool visited[MAX_VERTEX_NUM]; //���ʱ������~��ʼ��Ϊfalse

//������ȱ���
void BFS(Graph G, int v){	//�Ӷ���v������������ȱ���ͼG
	visit(v);				//���ʳ�ʼ����v
	visited[v]=TRUE;		//��v���ѷ��ʱ��TRUE
	Enqueue(Q, v);			//����v�����Q
	while(!isEmpty(Q)){
		Dequeue(Q, v);		//����v������
		for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
			//���v�����ڽӵ�
			if(!visited[w]){	//wΪv����δ���ʵ��ڽӶ���
				visit(w);		//���ʶ���w
				visited[w]=TRUE;	//��w���ѷ��ʱ��
				EnQueue(Q, W);		//����w�����
			}
	}
}


//BFS�㷨(Final��)
bool visited[MAX_VERTEX_NUM]; //���ʱ������~��ʼ��Ϊfalse
//������ȱ���
void BFSTraverse(Graph G){		//��ͼG���й�����ȱ���
	for(i=0; i<G.vexnum; ++i)
		visited[i]=FALSE;		//���ʱ�������ʼ��
	InitQueue(Q);				//��ʼ����������Q
	for(i=0; i<G.vexnum; ++i)	//��0�Ŷ��㿪ʼ����
		if(!visited[i])			//��ÿ����ͨ��������һ��BFS
			BFS(G, i);			//viδ���ʹ�����vi��ʼBFS
}

void BFS(Graph G, int v){	//�Ӷ���v������������ȱ���ͼG
	visit(v);				//���ʳ�ʼ����v
	visited[v]=TRUE;		//��v���ѷ��ʱ��TRUE
	Enqueue(Q, v);			//����v�����Q
	while(!isEmpty(Q)){
		Dequeue(Q, v);		//����v������
		for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
			//���v�����ڽӵ�
			if(!visited[w]){	//wΪv����δ���ʵ��ڽӶ���
				visit(w);		//���ʶ���w
				visited[w]=TRUE;	//��w���ѷ��ʱ��
				EnQueue(Q, W);		//����w�����
			}
	}
}


//DFS�㷨(Final��)
/*ͼ��������ȱ���*/
bool visited[MAX_VERTEX_NUM];	//���ʱ������
void DFS(Graph G, int v){		//�Ӷ���v������������ȱ���ͼG
	visit(v);					//���ʶ���v
	visited[v]=TRUE;			//���ѷ��ʱ��
	for(w=FirstNeighbor(G, v);w>=0;w=NextNeighbor(G, v, w))
		if(!visited[w]){		//wΪu����δ���ʵ��ڽӶ���
			DFS(G, w);
		}
}

void DFS(Graph G, int v){	//�Ӷ���v������������ȱ���ͼG
	visit(v);				//���ʶ���v	
	visited[v]=TRUE;		//���ѷ��ʱ��
	for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
		if(!visited[w]){	//wΪu����δ���ʵ��ڽӶ���
			DFS(G, w);
		}
}

/*BFS�㷨�󶥵�u��������������·��*/
void BFS_MIN_Distance(Graph G, int u){
	//d[i]��ʾ��u��i�������·��
	for(i=0; i<G.vexnum; ++i){
		d[i]=��;			//��ʼ��·������
		path[i]=-1;		//���·�����ĸ��������
	}
	d[u]=0;
	visited[u]=TRUE;
	EnQueue(Q, u);
	while(!isEmpty(Q)){		//BFS�㷨������
			DeQueue(Q, u);	//��ͷԪ��u����
			for(w=FirstNeighbor(G,u); w>=0; w=NextNeighbor(G, u, w))
				if(!visited[w]){		//wΪu����δ���ʵ��ڽӽ��
					d[w]=d[u]+1;		//·�����ȼ�1
					path[w]=u;			//���·��Ӧ��u��w
					visited[w]=TRUE;	//���ѷ��ʱ��
					EnQueue(Q, w);		//����w���
				}
	}
	
}


/*�������� ���Ͱ�*/
#define MaxVertexNum 100		//ͼ�ж�����Ŀ�����ֵ
typedef struct ArcNode{			//�߱���
	int adjvex;					//�û���ָ��Ķ����λ��
	struct ArcNode *nextarc;	//ָ����һ������ָ��
	InfoType info;				//���ı�Ȩֵ
}ArcNode;

typedef struct VNode{			//�������
	VertexType data;			//������Ϣ
	ArcNode *firstarc;			//ָ���һ�������ö���Ļ���ָ��
}VNode,AdjList[MaxVertexNum];

typedef struct{
	AdjList vertices;			//�ڽӱ�
	int vexnum, arcnum;			//ͼ�Ķ������ͻ���
}Graph;							//Graph�����ڽӱ�洢��ͼ����

/*�������� �������ϵĽ���*/
bool TopologicalSort(Graph G){
	InitStack(S);		//��ʼ��ջ���洢���Ϊ0�Ķ���
	for(int i=0; i<G.Vexnum; i++)
		if(indegree[i]==0)	//ʡ�ԵĶ�indegree���������~��¼��ǰ��������
			Push(S, i);		// ���������Ϊ0�Ķ����ջ
	int count=0;		//��������¼��ǰ�Ѿ�����Ķ�����
	while(!IsEmpty(S)){	//ջ���գ���������Ϊ0�Ķ���
		Pop(S,i);		//ջ��Ԫ�س�ջ~ÿ�����㶼��Ҫ����һ��
		print[count++]=i;	//�������i~��¼������������
		for (p=G.vertics[i].firstarc;p;p=p->nextarc){	//������iָ��Ķ������ȼ�1�����ҽ���ȼ�Ϊ0�Ķ���ѹ��ջs
		v=p->adjvex;	//ÿ���߶���Ҫ����һ��
		if(!(--indegree[v]))
			Push(S, v);		//���Ϊ0������ջ
		}
		
	}//while
	if(count<G.vexnum)
		return false;		//����ʧ�ܣ�����ͼ���л�·
	else
		return true;		//��������ɹ�
	
}

/*�����������ʵ��(DFS�㷨)*/
void DFSTraverse(Graph G){	//��ͼG����������ȱ���
	for(v=0; v<G.Vexnum; ++v)
		visited[v]=FALSE;		//��ʼ���ѷ��ʱ������
	for(v=0; v<G.vexnum; ++v)	//���������Ǵ�v=0��ʼ����
		if(!visited[v])
			DFS(G, v);
}

void DFS(Graph G, int v){		//�Ӷ���v������������ȱ���ͼG
	visited[v]=TRUE;			//���ѷ��ʱ��
	for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
		if(!visited[w]){		//wΪu����δ���ʵ��ڽӶ���
			DFS(G,w);
	}
	
	print(v);			//�������
}

//DFS�㷨ʵ�������޻�ͼ��������
bool visited[MAX_VERTEX_NUM];	//���ʱ������
void DFSTraverse(Graph G) {
	//��ͼG���б��������ʺ���Ϊvisit()
	for (v=0; v<g.vexnum; ++v)
		visited[v]=FALSE;	//��ʼ�����ʱ������
	time=0;
	for(v=0; v<G.vexnum; ++v)	//��v=0��ʼ����
		if(!visited[v]) DFS(G, v);
}

void DFS(Graph G, int v){
	visited[v]=TRUE;
	visit(v);
	for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w)
		if(!visited[w]	{	//wΪu����δ���ʵ��ڽӶ���
			DFS(G, w);
			
		}
	time=time+1; finishTime[v]=time;
}














































 
