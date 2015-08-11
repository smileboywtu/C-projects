#include"iostream"
#include"queue"

using namespace std;

#define MAX 20
bool visited[MAX];

//edgenode
typedef struct edgeNode{
	int adjver;
	int weight;
	edgeNode *nextNode;
}edgeNode;

//the headNode
typedef struct headNode{
	char vertex;
	edgeNode *firstAdj;
}headNode;

//the AdjList
typedef struct{
	int e;//the edge;
	int n;//the point
	headNode adjList[MAX];//the list;
	//this maybe the kind;
}adjMap;
//creat the A-Map
void creatAdjMap(adjMap &m,int n,int edge,int e[][2],char *v){
	m.n = n;
	m.e = edge;
	for(int i=0; i<m.n; i++){//to storage the vertex ,using m.n
		m.adjList[i].vertex = v[i];
		m.adjList[i].firstAdj = NULL;
	}//initilize the headNode;
	int adjver1 = 0,adjver2 = 0; 
	for(int j=0; j<m.e; j++){//to storage the edge; using m.e
		adjver1 = e[j][0];
		adjver2 = e[j][1];//to take off the data related;
		
		edgeNode *temp1 = new edgeNode;
		temp1->adjver = adjver2;
		temp1->nextNode = m.adjList[adjver1].firstAdj;
		m.adjList[adjver1].firstAdj = temp1; 
		//to make a double link,like a to b,b to a;
		
		edgeNode *temp2 = new edgeNode;
		temp2->adjver = adjver1;
		temp2->nextNode = m.adjList[adjver2].firstAdj;
		m.adjList[adjver2].firstAdj = temp2;
	}//to creat the adjList for the A-map;
}

//just do the traverse;
//visited a line,do a visit for every adjver and scan a new line;
void DSP(adjMap m,int v){
	cout<<m.adjList[v].vertex<<" ";
	visited[v] = true;//visit the node and mark the location;
	
	for(edgeNode *temp3=m.adjList[v].firstAdj; temp3!=NULL; temp3 = temp3->nextNode)
		if(!visited[temp3->adjver])
			DSP(m,temp3->adjver);
}
void DSFTraverse(adjMap m){
	for(int i=0; i<m.n; i++)
		visited[i] = false;
	for(int k=0; k<m.n; k++)
		if(!visited[k])
			DSP(m,k);
		cout<<endl;
}
/*
void BFS (adjMap m){
queue<int> q;
int tempv = 0;
//init the marks
for(int i=0; i<m.n; i++)
visited[i] = false;

  for(int j=0; j<m.n; j++){
		if(!visited[j]){
		visited[j] = true;
		cout<<m.adjList[j].vertex<<" ";
		q.push(j);
		while(!q.empty()){
		tempv = q.front();
		q.pop();
		for(edgeNode *tempN=m.adjList[tempv].firstAdj; tempN!=NULL; tempN=tempN->nextNode)
		if(!visited[tempN->adjver]){
		cout<<m.adjList[tempN->adjver].vertex<<" ";
		visited[tempN->adjver] = true;
		q.push(tempN->adjver);
		}
		}
		}
		
		  }
		  cout<<endl;
}*/

// I just do it myself;
//push the data into the queue and just visit the vertex and return;
void broadFirstSearch(adjMap m){
	queue<int> q;
	for(int i=0; i<m.n; i++)
		visited[i] = false;		//initialize the marks
	for(int j=0; j<m.n; j++){
		if(!visited[j]){
			cout<<m.adjList[j].vertex<<" ";
			visited[j] = true;
			q.push(j);						//go to the first line and start;
			while(!q.empty()){
				int vtem = q.front();
				q.pop();				//get the head of the queue
				for(edgeNode *ptemp=m.adjList[vtem].firstAdj; ptemp!=NULL; ptemp=ptemp->nextNode)
					if(!visited[ptemp->adjver]){
						cout<<m.adjList[ptemp->adjver].vertex<<" ";
						visited[ptemp->adjver] = true;
						q.push(ptemp->adjver);
					}
			}
		}
	}
	cout<<endl;
	
}

void main(){
	
	char v[] = "ABCDEF";
	int e[][2] = {
		{0,1},
		{1,3},
		{0,2},
		{2,4},
		{4,5}
	};
	
	adjMap m;
	
	//creat a adjlist;
	creatAdjMap(m,6,5,e,v);
	//traverse;
	DSFTraverse(m);
	//	BFS(m);
	broadFirstSearch(m);
	
}