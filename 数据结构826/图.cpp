/*邻接矩阵法*/ 
# define MaxVertexNum 100       //顶点数目的最大值 
typedef struct{
    char Vex[MaxVertexNum];     //顶点表~顶点中可以存放更复杂的信息 
    int Edge[MaxVertexNum][MaxVertexNum];   //邻接矩阵，边表，可改用bool型或枚举型变量表示边 
    int vexnum, arcnum;         //图的当前顶点数和边数/弧数 
}MGraph;

// 邻接矩阵法存储带权图(网)
# define MaxVertexNum 100           //顶点数目的最大值 
# define INFINITY 最大的int值       //宏定义常量"无穷"，可用int的上限值表示"无限" 
typedef char VertexType;            //顶点的数据类型 
typedef int EdgeType;               //带权图中，边上权值的数据类型 
tepedef struct{
    VertexType Vex[MaxVertexNum];   //顶点 
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //边的权 
    int vexnum, arcnum;             //图的当前顶点数和弧数 
}MGraph;

/*邻接表法(顺序+链式存储)*/
//顶点
typedef struct VNode{
    VertexType data;    //顶点信息
    ArcNode *first;     //第一条边/弧 
}VNode, AdjList[MaxVertexNum];

//边/弧
typedef struct ArcNode{
    int adjvex;             //边/弧指向哪个结点 
    struct ArcNode *next;   //指向下一条弧的指针 
    //InfoType info;        //边权值 
}ArcNode; 

//用邻接表存储的图
typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}AlGraph; 

/*图的广度优先遍历*/
bool visited[MAX_VERTEX_NUM]; //访问标记数组~初始都为false

//广度优先遍历
void BFS(Graph G, int v){	//从顶点v出发，广度优先遍历图G
	visit(v);				//访问初始顶点v
	visited[v]=TRUE;		//对v做已访问标记TRUE
	Enqueue(Q, v);			//顶点v入队列Q
	while(!isEmpty(Q)){
		Dequeue(Q, v);		//顶点v出队列
		for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
			//检测v所有邻接点
			if(!visited[w]){	//w为v的尚未访问的邻接顶点
				visit(w);		//访问顶点w
				visited[w]=TRUE;	//对w做已访问标记
				EnQueue(Q, W);		//顶点w入队列
			}
	}
}


//BFS算法(Final版)
bool visited[MAX_VERTEX_NUM]; //访问标记数组~初始都为false
//广度优先遍历
void BFSTraverse(Graph G){		//对图G进行广度优先遍历
	for(i=0; i<G.vexnum; ++i)
		visited[i]=FALSE;		//访问标记数组初始化
	InitQueue(Q);				//初始化辅助队列Q
	for(i=0; i<G.vexnum; ++i)	//从0号顶点开始遍历
		if(!visited[i])			//对每个连通分量调用一次BFS
			BFS(G, i);			//vi未访问过，从vi开始BFS
}

void BFS(Graph G, int v){	//从顶点v出发，广度优先遍历图G
	visit(v);				//访问初始顶点v
	visited[v]=TRUE;		//对v做已访问标记TRUE
	Enqueue(Q, v);			//顶点v入队列Q
	while(!isEmpty(Q)){
		Dequeue(Q, v);		//顶点v出队列
		for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
			//检测v所有邻接点
			if(!visited[w]){	//w为v的尚未访问的邻接顶点
				visit(w);		//访问顶点w
				visited[w]=TRUE;	//对w做已访问标记
				EnQueue(Q, W);		//顶点w入队列
			}
	}
}


//DFS算法(Final版)
/*图的深度优先遍历*/
bool visited[MAX_VERTEX_NUM];	//访问标记数组
void DFS(Graph G, int v){		//从顶点v出发，深度优先遍历图G
	visit(v);					//访问顶点v
	visited[v]=TRUE;			//设已访问标记
	for(w=FirstNeighbor(G, v);w>=0;w=NextNeighbor(G, v, w))
		if(!visited[w]){		//w为u的尚未访问的邻接顶点
			DFS(G, w);
		}
}

void DFS(Graph G, int v){	//从顶点v出发，深度优先遍历图G
	visit(v);				//访问顶点v	
	visited[v]=TRUE;		//设已访问标记
	for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
		if(!visited[w]){	//w为u的尚未访问的邻接顶点
			DFS(G, w);
		}
}

/*BFS算法求顶点u到其他顶点的最短路径*/
void BFS_MIN_Distance(Graph G, int u){
	//d[i]表示从u到i结点的最短路径
	for(i=0; i<G.vexnum; ++i){
		d[i]=∞;			//初始化路径长度
		path[i]=-1;		//最短路径从哪个顶点过来
	}
	d[u]=0;
	visited[u]=TRUE;
	EnQueue(Q, u);
	while(!isEmpty(Q)){		//BFS算法主过程
			DeQueue(Q, u);	//队头元素u出队
			for(w=FirstNeighbor(G,u); w>=0; w=NextNeighbor(G, u, w))
				if(!visited[w]){		//w为u的尚未访问的邻接结点
					d[w]=d[u]+1;		//路径长度加1
					path[w]=u;			//最短路径应从u到w
					visited[w]=TRUE;	//设已访问标记
					EnQueue(Q, w);		//顶点w入队
				}
	}
	
}


/*拓扑排序 解释版*/
#define MaxVertexNum 100		//图中顶点数目的最大值
typedef struct ArcNode{			//边表结点
	int adjvex;					//该弧所指向的顶点的位置
	struct ArcNode *nextarc;	//指向下一条弧的指针
	InfoType info;				//网的边权值
}ArcNode;

typedef struct VNode{			//顶点表结点
	VertexType data;			//顶点信息
	ArcNode *firstarc;			//指向第一条依附该顶点的弧的指针
}VNode,AdjList[MaxVertexNum];

typedef struct{
	AdjList vertices;			//邻接表
	int vexnum, arcnum;			//图的顶点数和弧数
}Graph;							//Graph是以邻接表存储的图类型

/*拓扑排序 王道书上的解释*/
bool TopologicalSort(Graph G){
	InitStack(S);		//初始化栈，存储入度为0的顶点
	for(int i=0; i<G.Vexnum; i++)
		if(indegree[i]==0)	//省略的对indegree数组的声明~记录当前顶点的入度
			Push(S, i);		// 将所有入度为0的顶点进栈
	int count=0;		//计数，记录当前已经输出的顶点数
	while(!IsEmpty(S)){	//栈不空，则存在入度为0的顶点
		Pop(S,i);		//栈顶元素出栈~每个顶点都需要处理一次
		print[count++]=i;	//输出顶点i~记录拓扑排序序列
		for (p=G.vertics[i].firstarc;p;p=p->nextarc){	//将所有i指向的顶点的入度减1，并且将入度减为0的顶点压入栈s
		v=p->adjvex;	//每条边都需要处理一次
		if(!(--indegree[v]))
			Push(S, v);		//入度为0，则入栈
		}
		
	}//while
	if(count<G.vexnum)
		return false;		//排序失败，有向图中有回路
	else
		return true;		//拓扑排序成功
	
}

/*逆拓扑排序的实现(DFS算法)*/
void DFSTraverse(Graph G){	//对图G进行深度优先遍历
	for(v=0; v<G.Vexnum; ++v)
		visited[v]=FALSE;		//初始化已访问标记数据
	for(v=0; v<G.vexnum; ++v)	//本代码中是从v=0开始遍历
		if(!visited[v])
			DFS(G, v);
}

void DFS(Graph G, int v){		//从顶点v出发，深度优先遍历图G
	visited[v]=TRUE;			//设已访问标记
	for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
		if(!visited[w]){		//w为u的尚未访问的邻接顶点
			DFS(G,w);
	}
	
	print(v);			//输出顶点
}

//DFS算法实现有向无环图拓扑排序
bool visited[MAX_VERTEX_NUM];	//访问标记数组
void DFSTraverse(Graph G) {
	//对图G进行遍历，访问函数为visit()
	for (v=0; v<g.vexnum; ++v)
		visited[v]=FALSE;	//初始化访问标记数组
	time=0;
	for(v=0; v<G.vexnum; ++v)	//从v=0开始遍历
		if(!visited[v]) DFS(G, v);
}

void DFS(Graph G, int v){
	visited[v]=TRUE;
	visit(v);
	for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w)
		if(!visited[w]	{	//w为u的尚未访问的邻接顶点
			DFS(G, w);
			
		}
	time=time+1; finishTime[v]=time;
}














































 
