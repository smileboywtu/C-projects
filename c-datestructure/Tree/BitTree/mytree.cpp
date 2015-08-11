#include "iostream"
#include "queue"
#include"windows.h"
using namespace std;

// define the tree
typedef struct  BiTNode 
{
	char data ; 
	BiTNode * lch;
	BiTNode * rch;
} * BiTree;


//create the tree
void createT(BiTree &t,char* &in )
{
	char ch;
	ch=*in++;
	if(ch=='#')
		t=NULL;
	else
	{
		t=new BiTNode;
		t->data=ch;
		createT(t->lch,in);
		createT(t->rch,in);
	}
}

//traverse
void preTra(BiTree t)
{
	if(t)
	{
		cout<<t->data<<"  " ;
		preTra(t->lch);		
		preTra(t->rch);
	}
}

//traverse
void inTra(BiTree t)
{
	if(t)
	{
		
		inTra(t->lch);		
		cout<<t->data<<"  " ;
		inTra(t->rch);
	}
}
//special traverse
void leveltra(BiTree t){
	queue<BiTree> q;
	BiTree p;
	q.push(t);
	while(!q.empty()){
		p = q.front();
		cout<<" "<<p->data;
		q.pop();	//no returned values;
		if(p->lch != NULL)
			q.push(p->lch);//enter the queue
		if(p->rch != NULL)
			q.push(p->rch);//enter the queue
	}
}

int leaf(BiTree t)
{  
	if(t==NULL)
		return 0;
	if(t->lch==NULL && t->rch==NULL)
		return 1;
	return leaf(t->lch)+leaf(t->rch);
}

//get the leaves
void leaves(BiTree t, int &n)
{
	if(t)
	{
		if(t->lch==NULL && t->rch==NULL)
			n++;
		leaves(t->lch,n);
		leaves(t->rch,n);
	}
}
//The depth of the tree
int DeepTree(BiTree t){
	int i = 0,j = 0;
	if(t == NULL)
		return 0;
	if(t->lch == NULL && t->rch == NULL)
		return 1;
	i = DeepTree(t->lch);
	j = DeepTree(t->rch);

	return (i>j? i:j)+1;
}
//copy the tree
void CopyTree(BiTree t1,BiTree &t2){
	if(t1){
		t2 = new BiTNode;
		t2->data = t1->data;
		CopyTree(t1->lch,t2->lch);
		CopyTree(t1->rch,t2->rch);
	}
	else
		t2 = NULL;
}
//Compare the two tree
int Compare(BiTree t1,BiTree t2){
	if(t1 == NULL && t2 ==NULL)
		return 1;
	if(t1 != NULL && t2 != NULL){
		if(t1->data == t2->data && Compare(t1->lch,t2->lch) && Compare(t1->rch,t2->rch) )
			return 1;
		else
			return 0;
	}
	return 0;
}
//exchang the child
void exchange(BiTree &t){
		BiTree temp;
		if(t){
			temp = t->lch;
			t->lch = t->rch;
			t->rch = temp;
			exchange(t->lch);
			exchange(t->rch);
		}
}

//destory the tree
void destory(BiTree t){
	if(t){
		destory(t->lch);
		destory(t->rch);
		delete(t);
	}
}


void main()
{
	char* in="ab#de##f##c##";
	BiTree t,t1;
	
	
	createT(t,in);
	//traverse 
	printf("Traverse from the head:\t");
	preTra(t);
	
	cout<<endl;
	//traverse
	printf("Traverse from the mid:\t ");
	inTra(t);
	cout<<endl;
	//special traverse
	printf("Level traverse:\t");
	leveltra(t);
	
	cout<<endl;
	//copy the tree
	CopyTree(t,t1);
	printf("The copied one :\t");
	inTra(t1);
	cout<<endl;
	//get the depth of the tree
	printf("The depth of the tree is:\t%d",DeepTree(t));
	cout<<endl;
	printf("The result of the comparation:\t%d\n",Compare(t,t1));
	//the result of the exchange
	exchange(t1);
	printf("After exchanging:\t");
	inTra(t1);
	cout<<endl;
	//fulltree
	printf("FullTree:\t%d\n",FullTree(t1));


	system("pause");
}



