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



























 
