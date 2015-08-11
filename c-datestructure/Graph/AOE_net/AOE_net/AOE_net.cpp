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
void Topo_Sort(adjMap *M,int etv[],int top_[],int &stackpointer){
	//init the stack pointer;
	int top = -1;									
	int i=0,k=0,j=0;
	//search the zero number
	for (i=0; i<M->n; i++)	{ 						
		if ( M->head[i]. count == 0){ 
			M->head[i].count = top;
			top = i;
		}
	}
	//do a big circle to print out the whole vertex;
	for (i=0; i<M->n; i++){
		//if the pointer is '-1',and find a circle;
		if (top == -1){
			printf("The network has a cycle!");
			return;
		}
		//pop the stack
		j = top;
		//save the list of data in top_
		top_[stackpointer++] = top;
		top = M->head[top].count;	
		//output the result
		//in this application , it's necessary to use them;
//		printf("%c",M->head[j].vertex);

		edgeNode* ptr = M->head[j].firstNode;
		//decent the count of one head;
		while (ptr != NULL){
			k = ptr->adjver;
			M->head[k].count--;		
			//push new number to the stack;
			if(M->head[k].count == 0){			
				M->head[k].count = top;
				top = k;
			}
			/*this place you'd get the early time of the event;
			*you end a adjlist;
			*you know two linked vertex,you get the weight to move from one to another;
			*you'd compare the time , and get longer;
			*how to compare?
			*you'd know when you enter a adjList ,this means the head linked to another one
			*Compare with the existed data,the desporation time(if A to B ,then do comparation with B)
			*the etv is initialized , so every time a link find,the etv is written , so just do comparation with previous data;
			*/
			if(etv[j] + ptr->weight > etv[k])
				etv[k] = etv[j] + ptr->weight;
			//move to next adjNode;
			ptr = ptr->nextNode;
		}//end while

	}//end for
}
//get the minimum time of a project
void MinTime(adjMap* M){
	int etv[MAX] = {0}; //the early time of one event;
	int ltv[MAX] = {0}; //the latest time of one event;
	int top_[MAX] = {0};
	int stackpointer = 0;
	Topo_Sort(M,etv,top_,stackpointer); //search the early time of one event;
	//then just do opposite Topo_sort , and find the ltv;
	//now we'd use stackpointer and top_,this two saved the information of Topo_Sort;

	//init the ltv
	ltv[--stackpointer] = etv[stackpointer];
	//get the latest time
	edgeNode* ptr = NULL;
	int k = 0;
	int temp = 0;
	while(stackpointer > 0){
		//pop a data
		temp = top_[--stackpointer];//another inflence ,move the stackpointer
		for(M->head[temp].firstNode; ptr; ptr=ptr->nextNode){
			k = ptr->adjver;
			if(ltv[k] - ptr->weight > ltv[temp])
				ltv[temp] = ltv[k] - ptr->weight;
		}//end for
	}
	//output the result
	int i = 0;
	cout<<"The AOE network: ";
	for(i=0; i<M->n; i++)
		if(etv[i] == ltv[i])
			cout<<M->head[i].vertex<<". ";
	cout<<endl;

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

//	Topo_Sort(M);
//	cout<<endl;
	MinTime(M);
	return 0;
}

