#include "queue"
#include "iostream"

using namespace std;
const int MAXVEX=50;

typedef struct edgeNode  {  
   //边结点类型
	int    adjvex;       // 邻接点的位置
	edgeNode * nextEdge; // 指向下条边的指针
	float  weight;       //权
} edgeNode ;


typedef struct headNode { 
	//头结点类型
	char  vertex ;        // 顶点信息
	edgeNode  *firstEdge; // 指向第一条依附该顶点的边
} headNode;

typedef struct{                
	//邻接表类型
	headNode adjList[MAXVEX];  //顶点向量
	int n;                     //顶点数
	int e;                    //边数
} adjGraph;


void createAdjlist(adjGraph &G, char v[],int n, int e[][2] , int m){
	//通过图的顶点信息v[n],边信息e[m][2]来生成图的邻接表存储结构G

	int i,j,k;
	edgeNode *p;

	G.n = n;     //设置顶点和边数
	G.e = m;  

	for(i=0;i<G.n;i++){  
	//存储顶点
	   G.adjList[i].vertex=v[i];
	   G.adjList[i].firstEdge =NULL;
	}

	
	for(k=0; k<G.e; k++) { 
	//存储边

	    i=e[k][0];
		j=e[k][1];  // 两个邻接点序号i,j
		p=new edgeNode;  //建立边结点  
		p->adjvex=j;
		p->nextEdge=G.adjList[i].firstEdge;  //边结点插入到第i边表的头部
		G.adjList[i].firstEdge=p;

		//对于无向图，还需在第j边表中插入边结点
		p=new edgeNode;
		p->adjvex=i;
		p->nextEdge=G.adjList[j].firstEdge;
		G.adjList[j].firstEdge=p;
	}
}

bool visited[MAXVEX];   //顶点访问标志向量

void DFS(adjGraph G,int k){
	//	从顶点k出发对图G进行深度优先搜索
	
	cout<< G.adjList[k].vertex << " "  ;  //访问 
	visited[k] = true;     //标记k顶点已访问

	//逐一从当前顶点的各个邻接点出发，进行深度优先搜索
	for( edgeNode * p = G.adjList[k].firstEdge ;  p!=NULL ;   p=p->nextEdge )
	   if(visited[p->adjvex]==0)  DFS(G,p->adjvex);  //递归调用	
}


	 

void DFSTraverse(adjGraph G){
	/*对图G进行深度优先搜索遍历*/	 
	int i;
	for(i=0;i<G.n;i++)   //初始化各顶点为"未访问"
		visited[i]=false;
	
	for( i=0;i<G.n; i++)  //对尚未访问的顶点逐次调用DFS
		if( ! visited[i] )
			DFS (G ,i );  
		
		
		
}



void BFS (adjGraph &G){
	queue<int> Q;
	for(int i=0;i<G.n;i++)   //初始化各顶点为"未访问"
		visited[i]=false;
	for(i=0;i<G.n;i++){   //所有顶点都要被访问
		if( !visited[i] )
		{    //尚未访问,访问后令其入队
			cout<< G.adjList[i].vertex<<" " ;  
			visited[i]=true;
			Q.push(i);
			while( ! Q.empty() ) {  //若队列不空
				int u=Q.front();    
				Q.pop();                //队首顶点u出队		 
					for(edgeNode * p=G.adjList[u].firstEdge;  p!=NULL; p=p->nextEdge)
					{
						//逐一访问u尚未访问的邻接点w，并令其入队
						int w=p->adjvex;	
						if( !visited[w] )
						{		
							cout << G.adjList[w].vertex       <<" ";
							visited[w]=true;
							Q.push(w) ;  
						}
					}
			}//while
				
		}//if
	}//for
}











void main()
{
	char v[]="ABCDE";
	int e[][2]={ 
		{0,1},
		{0,3},
		{1,2},
		{1,4},
		{2,3},
		{2,4}
	};

	adjGraph g;
	createAdjlist(g,v,5,e,6);


	DFSTraverse(g);

	cout<<endl;
	
	BFS(g);
	

	
	cout<<endl;

}