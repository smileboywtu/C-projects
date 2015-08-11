#include "queue"
#include "iostream"

using namespace std;
const int MAXVEX=50;

typedef struct edgeNode  {  
   //�߽������
	int    adjvex;       // �ڽӵ��λ��
	edgeNode * nextEdge; // ָ�������ߵ�ָ��
	float  weight;       //Ȩ
} edgeNode ;


typedef struct headNode { 
	//ͷ�������
	char  vertex ;        // ������Ϣ
	edgeNode  *firstEdge; // ָ���һ�������ö���ı�
} headNode;

typedef struct{                
	//�ڽӱ�����
	headNode adjList[MAXVEX];  //��������
	int n;                     //������
	int e;                    //����
} adjGraph;


void createAdjlist(adjGraph &G, char v[],int n, int e[][2] , int m){
	//ͨ��ͼ�Ķ�����Ϣv[n],����Ϣe[m][2]������ͼ���ڽӱ�洢�ṹG

	int i,j,k;
	edgeNode *p;

	G.n = n;     //���ö���ͱ���
	G.e = m;  

	//using the headNode to storage head;
	for(i=0;i<G.n;i++){  
	//�洢����
	   G.adjList[i].vertex = v[i];
	   G.adjList[i].firstEdge = NULL;
	}

	
	for(k=0; k<G.e; k++) { 
	//�洢��

	    i = e[k][0];
		j = e[k][1];  // �����ڽӵ����i,j
		p = new edgeNode;  //�����߽��  
		p->adjvex = j;
		p->nextEdge = G.adjList[i].firstEdge;  //�߽����뵽��i�߱��ͷ��
		G.adjList[i].firstEdge = p;

		//��������ͼ�������ڵ�j�߱��в���߽��
		p = new edgeNode;
		p->adjvex = i;
		p->nextEdge = G.adjList[j].firstEdge;
		G.adjList[j].firstEdge = p;
	}
}



//Traverse
//DepthFirstSearch
bool visited[MAXVEX];			//the visited marks
//int (*visitFunc)(int v);				//the pointer to the method visit;

//visit the data
//so difficult a program;
int visit(adjGraph g,int v){
	printf("The data is : %c\n",g.adjList[v].vertex);
	return 1;
}


void DFS(adjGraph g,int v){
	
	visited[v] = true;
	visit(g,v);
	for(edgeNode *node=g.adjList[v].firstEdge;  node!=NULL; node=node->nextEdge)
	   if(visited[node->adjvex]==false)	 //if(!visited[v])
		   DFS(g,node->adjvex);			 //�ݹ����	
}

void DFSTraverse(adjGraph g){
	for(int v=0; v<g.n; v++)
		visited[v] = false;				//initialization
	for(v=0; v<g.n; v++)				//����
		if(!visited[v])
			DFS(g,v);
}
//BFS
void BFS(adjGraph &G){
	queue<int> Q;
	for(int i=0;i<G.n;i++)   //��ʼ��������Ϊ"δ����"
		visited[i]=false;
	for(i=0;i<G.n;i++){   //���ж��㶼Ҫ������

		if( !visited[i] ){
		    //��δ����,���ʺ��������
			cout<< G.adjList[i].vertex<<" " ;  
			visited[i]=true;
			Q.push(i);
			while( ! Q.empty() ) {  //�����в���
				int u=Q.front();    
				Q.pop();                //���׶���u����		 
					for(edgeNode *p=G.adjList[u].firstEdge;  p!=NULL; p=p->nextEdge)
					{
						//��һ����u��δ���ʵ��ڽӵ�w�����������
						int w = p->adjvex;	
						if( !visited[w] ){	
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
	char v[]="ABCDEFG";
	int  e[][2]={ 
		{0,1},
		{0,3},
		{1,2},
		{2,3},
	};

	adjGraph g;
	createAdjlist(g,v,7,e,4);


	DFSTraverse(g);

	cout<<endl;
	
	BFS(g);
	

	
	cout<<endl;

}