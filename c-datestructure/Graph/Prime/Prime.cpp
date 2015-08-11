#include"iostream"
using namespace std;

#define MAX 20

struct edgeNode{
	int adjver;
	int weight;
	edgeNode* nextNode;
};
struct headNode{
	int count;					//add this to mark the indegree;
	char vertex;
	edgeNode* firstNode;
};
struct adjMap{
	headNode head[MAX];
	int n;
	int e;
};
void creatPncMap(adjMap* &M,int n,int e,int edge[][4],char* v){
	//init the Map
	M = new adjMap;
	M->n = n;
	M->e = e;
	//do the creation
	int i = 0;
	int adjver1 = 0,adjver2 = 0;
	//save the vertex
	for(i=0; i<M->n; i++){
		M->head[i].vertex = v[i];
		M->head[i].firstNode = NULL;
	}
	//save the edge
	for(i=0; i<M->e; i++){
		//do one side
		adjver1 = edge[i][1];
		adjver2 = edge[i][2];
		int weight_ = edge[i][3];
		edgeNode* tempNode = new edgeNode;
		tempNode->adjver = adjver2;
		tempNode->weight = weight_;
		//		M->head[adjver1].count = edge[i][0];
		tempNode->nextNode = M->head[adjver1].firstNode;
		M->head[adjver1].firstNode = tempNode;
		//do another side
		//creat a NP Map
		tempNode = new edgeNode;
		tempNode->adjver = adjver1;
		tempNode->weight = weight_;
		tempNode->nextNode = M->head[adjver2].firstNode;
		M->head[adjver2].firstNode = tempNode;
	}
}
bool empty(adjMap* M,int v_u[]){
	int i = 0;
	for(i=0; i<M->n; i++)
		if(v_u[i] == 1)
			return false;
		return true;
}
void Prime(adjMap* M){
	int i=0;
	int u[MAX] = {0};
	int v_u[MAX] = {0};
	//init the two vertex circle
	for(i=0; i<M->n; i++)
		v_u[i] = 1;
	u[0] = 1;
	v_u[0] = 0;
	cout<<M->head[0].vertex<<", ";
	//then serch the minest edge(weight) in u cricle
	while(!empty(M,v_u)){
		edgeNode* ptr = NULL;
		int min = 100;
		int adjtemp = 0;
		for(i=0; i<M->n; i++){
			if(u[i]){
				for(ptr=M->head[i].firstNode; ptr; ptr=ptr->nextNode)
					if(min > ptr->weight){
						//none use of the vertex
						if(v_u[ptr->adjver] == 0)
							continue;
						min = ptr->weight;
						adjtemp = ptr->adjver;
					}//end if
			}//end if
		}
		//output the result
		v_u[adjtemp] = 0;
		u[adjtemp] = 1;
		cout<<M->head[adjtemp].vertex<<", ";
	}
}

int main()
{
	char v[] = "ABC";
	int edge[][4] = {			//first save the count,then the first asdver,then the next adjver,then the weight;
		{0,0,1,2},
		{1,1,2,4},
		{2,0,2,5}
	};
	adjMap* M;
	creatPncMap(M,3,3,edge,v);
	Prime(M);
	cout<<endl;

	return 0;
}

