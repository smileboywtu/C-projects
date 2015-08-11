#include"iostream"
#include"queue"
using namespace std;

#define MAX 20
#define Elem char
bool visited[MAX];

struct edgeNode{
	int adjvex;
	int weight;
	edgeNode *nextNode;
};
struct headNode{
	Elem vertex;
	edgeNode *firstNode;
};
struct adjMap{
	int e;
	int n;
	headNode adjList[MAX];
};

void creatMap(adjMap* &M,int n,int e,Elem* v,int edge[][3]){
	M = new adjMap;
	M->e = e;
	M->n = n;
	int adjver1=0,adjver2=0,weight_ = 0;
	int i = 0;
	//init the headNode;
	for(i=0; i<M->n; i++){
		M->adjList[i].vertex = v[i];
		M->adjList[i].firstNode = NULL;
	}
	//insert the edge;
	for(i=0; i<M->e; i++){
		adjver1 = edge[i][0];
		adjver2 = edge[i][1];
		weight_ = edge[i][2];
		//do the first;
		edgeNode* node1 = new edgeNode;
		node1->adjvex = adjver2;
		node1->weight = weight_;
		node1->nextNode = M->adjList[adjver1].firstNode;
		M->adjList[adjver1].firstNode = node1;
		//do the next;
		edgeNode* node2 = new edgeNode;
		node2->adjvex = adjver1;
		node2->weight = weight_;
		node2->nextNode = M->adjList[adjver2].firstNode;
		M->adjList[adjver2].firstNode = node2;
	}
	
}

void broadFirstTraverse(adjMap *M){
	queue<int> q;
	int i = 0;
	for(i=0; i<M->n; i++)
		visited[i] = false;
	for(i=0; i<M->n; i++){  //visited the head;
		if(!visited[i]){	//if the head isn't visited,then go on;
			cout<<M->adjList[i].vertex<<" ";
			visited[i] = true;
			q.push(i);		
			while(!q.empty()){
				int v = q.front();
				q.pop();
				for(edgeNode* ptemp=M->adjList[v].firstNode; ptemp!=NULL; ptemp=ptemp->nextNode)//for
					if(!visited[ptemp->adjvex]){
						cout<<M->adjList[ptemp->adjvex].vertex<<" ";
						visited[ptemp->adjvex] = true;
						q.push(ptemp->adjvex);//if
					}
			}//while
		}//if
	}//for
}

////////////sort the edge first ////////////////
void bubbleSort(adjMap* M,int edge[][3]){

	int adjver=0,cost=0;

	for(int i=0; i<M->e; i++)
		for(int j=0; j<M->e-i-1; j++){
			if(edge[j][2]>edge[j+1][2]){
				 adjver = edge[j][0];
				 edge[j][0] = edge[j+1][0];
				 edge[j+1][0] = adjver;
				 adjver = edge[j][1];
				 edge[j][1] = edge[j+1][1];
				 edge[j+1][1] = adjver;
				 cost = edge[j][2];
				 edge[j][2] = edge[j+1][2];
				 edge[j+1][2] = cost;
			}
		}

}
////////Find the father /////////////
int Find(int father[],int v){

	int t = v;

	while(father[t] >= 0)
		t = father[t];

	return t;

}

void Kruscar(adjMap* M,int edge[][3]){

	int father[MAX];
	int i=0,j=0,v1f,v2f;

	//initialization
	bubbleSort(M,edge);
	for(i=0; i<M->n; i++)
		father[i] = -1;

	i=j=0;
	while(i<M->n && j<M->e){

		v1f = Find(father,edge[j][0]);
		v2f = Find(father,edge[j][1]);

		if(v1f != v2f){
			father[edge[j][1]] = edge[j][0];
			i++;
			cout<<"<"<<edge[j][0]<<","<<edge[j][1]<<"> ";
		}

		j++;

	}
		

}

int main()
{
	//init the map;
	Elem v[] = "ABCD";
	int edge[][3] = {
		{0,1,1},
		{0,3,7},
		{0,2,2},
		{1,2,3},
		{1,3,6}
	};

	adjMap* M;
	creatMap(M,4,5,v,edge);

	broadFirstTraverse(M);
	cout<<endl;

	Kruscar(M,edge);

	cout<<endl;
	return 0;
}

