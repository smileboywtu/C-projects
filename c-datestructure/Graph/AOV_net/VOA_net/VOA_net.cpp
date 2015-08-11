// VOA_net.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
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
void creatPncMap(adjMap* &M,int n,int e,int edge[][3],char* v){
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
	//do it myself
	//this need a application to do it
	M->head[0].count = 0;
	M->head[1].count = 1;
	M->head[2].count = 2;
	

	//save the edge
	for(i=0; i<M->e; i++){
		adjver1 = edge[i][0];
		adjver2 = edge[i][1];
		edgeNode* tempNode = new edgeNode;
		tempNode->adjver = adjver2;
		tempNode->weight = 0;
		tempNode->nextNode = M->head[adjver1].firstNode;
		M->head[adjver1].firstNode = tempNode;
	}
}
void Topo_Sort(adjMap *M){
	/*对以带入度的邻接链表为存储结构的图G，输出其一种拓扑序列*/


	int top = -1;									/* 栈顶指针初始化*/
	int i=0,k=0,j=0;
	for (i=0; i<M->n; i++)	{ 						/* 依次将入度为0 的顶点压入链式栈*/
		if ( M->head[i]. count == 0){ 
			M->head[i].count = top;
			top = i;
		}
	}

	for (i=0; i<M->n; i++){
		if (top == -1){
			printf("The network has a cycle");
			return;
		}
		j = top;
		top = M->head[top].count;				/* 从栈中退出一个顶点并输出*/
		printf("%c",M->head[j].vertex);

		edgeNode* ptr = M->head[j].firstNode;
		while (ptr != NULL){
			k = ptr->adjver;
			M->head[k].count--;					/*当前输出顶点邻接点的入度减1*/
			if(M->head[k].count == 0){			/*新的入度为0 的顶点进栈*/
				M->head[k].count = top;
				top = k;
			}
			ptr = ptr->nextNode; /*找到下一个邻接点*/
		}

	}
}

int main(int argc, _TCHAR* argv[])
{
	char v[] = "ABC";
	int edge[][3] = {
		{0,1,2},
		{1,2,4},
		{0,2,5}
	};
	adjMap* M;
	creatPncMap(M,3,3,edge,v);

	Topo_Sort(M);
	cout<<endl;

	return 0;
}

