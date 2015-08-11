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

	for(i=0;i<G.n;i++){  
	//�洢����
	   G.adjList[i].vertex=v[i];
	   G.adjList[i].firstEdge =NULL;
	}

	
	for(k=0; k<G.e; k++) { 
	//�洢��

	    i=e[k][0];
		j=e[k][1];  // �����ڽӵ����i,j
		p=new edgeNode;  //�����߽��  
		p->adjvex=j;
		p->nextEdge=G.adjList[i].firstEdge;  //�߽����뵽��i�߱��ͷ��
		G.adjList[i].firstEdge=p;

		//��������ͼ�������ڵ�j�߱��в���߽��
		p=new edgeNode;
		p->adjvex=i;
		p->nextEdge=G.adjList[j].firstEdge;
		G.adjList[j].firstEdge=p;
	}
}

bool visited[MAXVEX];   //������ʱ�־����

void DFS(adjGraph G,int k){
	//	�Ӷ���k������ͼG���������������
	
	cout<< G.adjList[k].vertex << " "  ;  //���� 
	visited[k] = true;     //���k�����ѷ���

	//��һ�ӵ�ǰ����ĸ����ڽӵ���������������������
	for( edgeNode * p = G.adjList[k].firstEdge ;  p!=NULL ;   p=p->nextEdge )
	   if(visited[p->adjvex]==0)  DFS(G,p->adjvex);  //�ݹ����	
}


	 

void DFSTraverse(adjGraph G){
	/*��ͼG�������������������*/	 
	int i;
	for(i=0;i<G.n;i++)   //��ʼ��������Ϊ"δ����"
		visited[i]=false;
	
	for( i=0;i<G.n; i++)  //����δ���ʵĶ�����ε���DFS
		if( ! visited[i] )
			DFS (G ,i );  
		
		
		
}



void BFS (adjGraph &G){
	queue<int> Q;
	for(int i=0;i<G.n;i++)   //��ʼ��������Ϊ"δ����"
		visited[i]=false;
	for(i=0;i<G.n;i++){   //���ж��㶼Ҫ������
		if( !visited[i] )
		{    //��δ����,���ʺ��������
			cout<< G.adjList[i].vertex<<" " ;  
			visited[i]=true;
			Q.push(i);
			while( ! Q.empty() ) {  //�����в���
				int u=Q.front();    
				Q.pop();                //���׶���u����		 
					for(edgeNode * p=G.adjList[u].firstEdge;  p!=NULL; p=p->nextEdge)
					{
						//��һ����u��δ���ʵ��ڽӵ�w�����������
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