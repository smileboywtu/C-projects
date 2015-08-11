#include"iostream"
#include"queue"
using namespace std;

#define Elem char

//define a tree
typedef struct Tree{
	Elem data;
	Tree *Lch;
	Tree *Rch;
}bitTree,*pBitTree;

//creatTree
//just creat a root and add leaf to it;
void creatTree(pBitTree &T,Elem* &ch){
	if(*ch!='#'){
		T = new bitTree;
		T->data = *ch;
		creatTree(T->Lch,++ch);
		creatTree(T->Rch,++ch);
	}
	else 
		T = NULL;
}

//get the deep
//just do it yourself ,you can ;
int deep(pBitTree T){
	int i=0,j=0;
	if(T==NULL)
		return 0;
	if(T->Lch==NULL&&T->Rch==NULL)\
		return 1;
	i = deep(T->Lch);
	j = deep(T->Rch);
	return (i>j?i:j)+1;
}
//get the leaves
int leaves(pBitTree T){
	if(T==NULL)
		return 0;
	if(T->Lch!=NULL && T->Rch==NULL || T->Lch==NULL && T->Rch!=NULL)
		return 1;
	if(T->Lch!=NULL && T->Rch!=NULL)
		return 2;
	return leaves(T->Lch)+leaves(T->Rch);
}

//traTree
void traTree(pBitTree T){
	if(T){
		cout<<T->data<<" ";
		traTree(T->Lch);
		traTree(T->Rch);
	}
}
//Do a broadtraverse
void broadTraverse(pBitTree T){
	if(T!=NULL){
		queue<pBitTree> q;
		q.push(T);
		while(!q.empty()){
			pBitTree ptemp = q.front();
			cout<<ptemp->data<<" ";
			q.pop();
			if(ptemp->Lch!=NULL)
				q.push(ptemp->Lch);
			if(ptemp->Rch!=NULL)
				q.push(ptemp->Rch);
		}
	}

}
//fulltree
int fullTree(pBitTree T,int &flag){
	if(T==NULL)
		return 1;
	if((T->Lch!=NULL&&T->Rch==NULL) || (T->Lch==NULL&&T->Rch!=NULL))
		flag = 0;
	fullTree(T->Lch,flag);
	fullTree(T->Rch,flag);
	return flag;
}
//another way to check full tree;
//using the que ,maybe a good way
int fullTree_usingQueue(pBitTree T){
	if(T!=NULL){
		int count = 0;
		pBitTree ptemp;
		queue<pBitTree> q;
		q.push(T);
		while(!q.empty()){
			count++;
			ptemp = q.front();
			q.pop();
			if(ptemp->Lch!=NULL)
				q.push(ptemp->Lch);
			if(ptemp->Rch!=NULL)
				q.push(ptemp->Rch);
		}
		return count%2;
	}
	return 0;
}

int main(){
	
	Elem* ch = "ABE##F##C##";            //this is const string;
	pBitTree T;//creat a root
	//creat a tree
	creatTree(T,ch);
	//the traverse
	cout<<"Do a preTraverse: ";
	traTree(T);
	cout<<endl;
	cout<<"Do a broadTraverse: ";
	broadTraverse(T);
	cout<<endl;
	//the deep and leaves
	cout<<"The deep of the tree: "<<deep(T)<<endl;
	cout<<"The leaves of the tree: "<<leaves(T)<<endl;
	int flag = 1;
	fullTree(T,flag);
	cout<<"Is a full tree: "<<flag<<endl;
	cout<<"Another way to check fullTree(1 ref full) : "<<fullTree_usingQueue(T)<<endl;

	return 1;
}